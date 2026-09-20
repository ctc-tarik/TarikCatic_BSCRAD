module i2c_ctrl (
    input logic clk,
    input logic strobe_400kHz,
    input logic areset_n,
    input logic start_transaction,
    input logic [15:0] pause_duration,
    output logic transaction_done,

    output logic scl_oe,
    input logic scl_di,
    output logic sda_oe,
    input logic sda_di,

    output logic [15:0] result_16
);

    typedef enum logic [4:0] {
        IDLE,
        START_CONFIG,
        WRITE_SLAVE_ADDR_CONFIG,
        CHECK_ACK_CONFIG,
        WRITE_POINTER_CONFIG,
        CHECK_ACK_POINTER_CONFIG,
        WRITE_CONFIG_MSB,
        CHECK_ACK_CONFIG_MSB,
        WRITE_CONFIG_LSB,
        CHECK_ACK_CONFIG_LSB,
        STOP_CONFIG,
        WAIT_CONVERSION,
        START_READ,
        WRITE_SLAVE_ADDR_READ,
        CHECK_ACK_READ,
        WRITE_POINTER_READ,
        CHECK_ACK_POINTER_READ,
        REPEATED_START,
        WRITE_SLAVE_ADDR_READ_MODE,
        CHECK_ACK_READ_MODE,
        READ_MSB,
        SEND_ACK_MSB,
        READ_LSB,
        SEND_NACK_LSB,
        STOP_READ,
        DONE
    } state_t;

    state_t state;
    logic [1:0] process_cnt;
    logic [3:0] bit_cnt;
    logic [3:0] bit_cnt_dec;
    logic ack_bit;
    logic [7:0] shift_reg;

    logic [15:0] conv_timer;

    // AIN0 vs GND, PGA = +-2.048V, single-shot, 128SPS, comparator disabled.
    // The potentiometer is powered from the same 3.3V rail as the ADS1115
    // (see top.sv), so AIN0 never exceeds ~3.3V -- safely within the
    // ADS1115's limits when it is also running on 3.3V.
    // I2C address 0x48 (SLAVE_ADDR_WRITE/READ below) requires ADDR pin
    // on the ADS1115 tied to GND (or left floating on boards that already
    // pull it to GND through an onboard resistor).
    localparam logic [7:0] SLAVE_ADDR_WRITE = 8'h90;
    localparam logic [7:0] SLAVE_ADDR_READ  = 8'h91;
    localparam logic [7:0] POINTER_CONFIG   = 8'h01;
    localparam logic [7:0] CONFIG_MSB       = 8'hC5;
    localparam logic [7:0] CONFIG_LSB       = 8'h83;
    localparam logic [7:0] POINTER_CONV     = 8'h00;

    assign bit_cnt_dec = bit_cnt - 4'd1;

    logic scl_do, sda_do;

    assign scl_oe = ~scl_do;
    assign sda_oe = ~sda_do;

    always_ff @(negedge areset_n or posedge clk) begin
        if (!areset_n) begin
            state            <= IDLE;
            process_cnt      <= 2'd0;
            bit_cnt          <= 4'd0;
            scl_do           <= 1'b1;
            sda_do           <= 1'b1;
            transaction_done <= 1'b0;
            result_16        <= 16'd0;
            shift_reg        <= 8'd0;
            conv_timer       <= 16'd0;
            ack_bit          <= 1'b0;
        end else if (strobe_400kHz) begin
            case (state)
                IDLE: begin
                    scl_do           <= 1'b1;
                    sda_do           <= 1'b1;
                    process_cnt      <= 2'd0;
                    bit_cnt          <= 4'd0;
                    transaction_done <= 1'b0;
                    if (start_transaction) begin
                        state <= START_CONFIG;
                    end
                end

                START_CONFIG: begin
                    case (process_cnt)
                        2'd0: begin
                            scl_do <= 1'b1;
                            sda_do <= 1'b1;
                            process_cnt <= 2'd1;
                        end
                        2'd1: begin
                            sda_do <= 1'b0;
                            process_cnt <= 2'd2;
                        end
                        2'd2: begin
                            scl_do <= 1'b0;
                            bit_cnt <= 4'd8;
                            process_cnt <= 2'd3;
                        end
                        2'd3: begin
                            process_cnt <= 2'd0;
                            state <= WRITE_SLAVE_ADDR_CONFIG;
                            sda_do <= SLAVE_ADDR_WRITE[7];
                        end
                    endcase
                end

                WRITE_SLAVE_ADDR_CONFIG: begin
                    case (process_cnt)
                        2'd0: begin
                            scl_do <= 1'b1;
                            process_cnt <= 2'd1;
                        end
                        2'd1: begin
                            if (scl_di) begin
                                process_cnt <= 2'd2;
                            end
                        end
                        2'd2: begin
                            scl_do <= 1'b0;
                            bit_cnt <= bit_cnt_dec;
                            process_cnt <= 2'd3;
                        end
                        2'd3: begin
                            if (bit_cnt == 0) begin
                                state <= CHECK_ACK_CONFIG;
                                sda_do <= 1'b1;
                            end else begin
                                sda_do <= SLAVE_ADDR_WRITE[bit_cnt_dec[2:0]];
                            end
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                CHECK_ACK_CONFIG: begin
                    case (process_cnt)
                        2'd0: begin
                            scl_do <= 1'b1;
                            sda_do <= 1'b1;
                            process_cnt <= 2'd1;
                        end
                        2'd1: begin
                            if (scl_di) begin
                                ack_bit <= ~sda_di;
                                process_cnt <= 2'd2;
                            end
                        end
                        2'd2: begin
                            scl_do <= 1'b0;
                            process_cnt <= 2'd3;
                        end
                        2'd3: begin
                            if (ack_bit) begin
                                ack_bit <= 1'b0;
                                state <= WRITE_POINTER_CONFIG;
                                sda_do <= POINTER_CONFIG[7];
                                bit_cnt <= 4'd8;
                            end else begin
                                state <= IDLE;
                            end
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                WRITE_POINTER_CONFIG: begin
                    case (process_cnt)
                        2'd0: begin scl_do <= 1'b1; process_cnt <= 2'd1; end
                        2'd1: begin if (scl_di) begin process_cnt <= 2'd2; end end
                        2'd2: begin scl_do <= 1'b0; bit_cnt <= bit_cnt_dec; process_cnt <= 2'd3; end
                        2'd3: begin
                            if (bit_cnt == 0) begin
                                state <= CHECK_ACK_POINTER_CONFIG;
                                sda_do <= 1'b1;
                            end else begin
                                sda_do <= POINTER_CONFIG[bit_cnt_dec[2:0]];
                            end
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                CHECK_ACK_POINTER_CONFIG: begin
                    case (process_cnt)
                        2'd0: begin scl_do <= 1'b1; sda_do <= 1'b1; process_cnt <= 2'd1; end
                        2'd1: begin if (scl_di) begin ack_bit <= ~sda_di; process_cnt <= 2'd2; end end
                        2'd2: begin scl_do <= 1'b0; process_cnt <= 2'd3; end
                        2'd3: begin
                            if (ack_bit) begin
                                ack_bit <= 1'b0;
                                state <= WRITE_CONFIG_MSB;
                                sda_do <= CONFIG_MSB[7];
                                bit_cnt <= 4'd8;
                            end else begin
                                state <= IDLE;
                            end
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                WRITE_CONFIG_MSB: begin
                    case (process_cnt)
                        2'd0: begin scl_do <= 1'b1; process_cnt <= 2'd1; end
                        2'd1: begin if (scl_di) begin process_cnt <= 2'd2; end end
                        2'd2: begin scl_do <= 1'b0; bit_cnt <= bit_cnt_dec; process_cnt <= 2'd3; end
                        2'd3: begin
                            if (bit_cnt == 0) begin
                                state <= CHECK_ACK_CONFIG_MSB;
                                sda_do <= 1'b1;
                            end else begin
                                sda_do <= CONFIG_MSB[bit_cnt_dec[2:0]];
                            end
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                CHECK_ACK_CONFIG_MSB: begin
                    case (process_cnt)
                        2'd0: begin scl_do <= 1'b1; sda_do <= 1'b1; process_cnt <= 2'd1; end
                        2'd1: begin if (scl_di) begin ack_bit <= ~sda_di; process_cnt <= 2'd2; end end
                        2'd2: begin scl_do <= 1'b0; process_cnt <= 2'd3; end
                        2'd3: begin
                            if (ack_bit) begin
                                ack_bit <= 1'b0;
                                state <= WRITE_CONFIG_LSB;
                                sda_do <= CONFIG_LSB[7];
                                bit_cnt <= 4'd8;
                            end else begin
                                state <= IDLE;
                            end
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                WRITE_CONFIG_LSB: begin
                    case (process_cnt)
                        2'd0: begin scl_do <= 1'b1; process_cnt <= 2'd1; end
                        2'd1: begin if (scl_di) begin process_cnt <= 2'd2; end end
                        2'd2: begin scl_do <= 1'b0; bit_cnt <= bit_cnt_dec; process_cnt <= 2'd3; end
                        2'd3: begin
                            if (bit_cnt == 0) begin
                                state <= CHECK_ACK_CONFIG_LSB;
                                sda_do <= 1'b1;
                            end else begin
                                sda_do <= CONFIG_LSB[bit_cnt_dec[2:0]];
                            end
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                CHECK_ACK_CONFIG_LSB: begin
                    case (process_cnt)
                        2'd0: begin scl_do <= 1'b1; sda_do <= 1'b1; process_cnt <= 2'd1; end
                        2'd1: begin if (scl_di) begin ack_bit <= ~sda_di; process_cnt <= 2'd2; end end
                        2'd2: begin scl_do <= 1'b0; process_cnt <= 2'd3; end
                        2'd3: begin
                            if (ack_bit) begin
                                ack_bit <= 1'b0;
                                state <= STOP_CONFIG;
                            end else begin
                                state <= IDLE;
                            end
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                STOP_CONFIG: begin
                    case (process_cnt)
                        2'd0: begin
                            scl_do <= 1'b1;
                            sda_do <= 1'b0;
                            process_cnt <= 2'd1;
                        end
                        2'd1: begin
                            if (scl_di) begin process_cnt <= 2'd2; end
                        end
                        2'd2: begin
                            sda_do <= 1'b1;
                            process_cnt <= 2'd3;
                        end
                        2'd3: begin
                            scl_do <= 1'b1;
                            sda_do <= 1'b1;
                            process_cnt <= 2'd0;
                            conv_timer <= pause_duration;
                            state <= WAIT_CONVERSION;
                            transaction_done <= 1'b1;
                        end
                    endcase
                end

                WAIT_CONVERSION: begin
                    if (conv_timer == 16'd0) begin
                        state <= START_READ;
                    end else begin
                        conv_timer <= conv_timer - 16'd1;
                    end

                    scl_do <= 1'b1;
                    sda_do <= 1'b1;
                end

                START_READ: begin
                    case (process_cnt)
                        2'd0: begin scl_do <= 1'b1; sda_do <= 1'b1; process_cnt <= 2'd1; end
                        2'd1: begin sda_do <= 1'b0; process_cnt <= 2'd2; end
                        2'd2: begin scl_do <= 1'b0; bit_cnt <= 4'd8; process_cnt <= 2'd3; end
                        2'd3: begin
                            process_cnt <= 2'd0;
                            state <= WRITE_SLAVE_ADDR_READ;
                            sda_do <= SLAVE_ADDR_WRITE[7];
                        end
                    endcase
                end

                WRITE_SLAVE_ADDR_READ: begin
                    case (process_cnt)
                        2'd0: begin scl_do <= 1'b1; process_cnt <= 2'd1; end
                        2'd1: begin if (scl_di) begin process_cnt <= 2'd2; end end
                        2'd2: begin scl_do <= 1'b0; bit_cnt <= bit_cnt_dec; process_cnt <= 2'd3; end
                        2'd3: begin
                            if (bit_cnt == 0) begin
                                state <= CHECK_ACK_READ;
                                sda_do <= 1'b1;
                            end else begin
                                sda_do <= SLAVE_ADDR_WRITE[bit_cnt_dec[2:0]];
                            end
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                CHECK_ACK_READ: begin
                    case (process_cnt)
                        2'd0: begin scl_do <= 1'b1; sda_do <= 1'b1; process_cnt <= 2'd1; end
                        2'd1: begin if (scl_di) begin ack_bit <= ~sda_di; process_cnt <= 2'd2; end end
                        2'd2: begin scl_do <= 1'b0; process_cnt <= 2'd3; end
                        2'd3: begin
                            if (ack_bit) begin
                                ack_bit <= 1'b0;
                                state <= WRITE_POINTER_READ;
                                sda_do <= POINTER_CONV[7];
                                bit_cnt <= 4'd8;
                            end else begin
                                state <= IDLE;
                            end
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                WRITE_POINTER_READ: begin
                    case (process_cnt)
                        2'd0: begin scl_do <= 1'b1; process_cnt <= 2'd1; end
                        2'd1: begin if (scl_di) begin process_cnt <= 2'd2; end end
                        2'd2: begin scl_do <= 1'b0; bit_cnt <= bit_cnt_dec; process_cnt <= 2'd3; end
                        2'd3: begin
                            if (bit_cnt == 0) begin
                                state <= CHECK_ACK_POINTER_READ;
                                sda_do <= 1'b1;
                            end else begin
                                sda_do <= POINTER_CONV[bit_cnt_dec[2:0]];
                            end
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                CHECK_ACK_POINTER_READ: begin
                    case (process_cnt)
                        2'd0: begin scl_do <= 1'b1; sda_do <= 1'b1; process_cnt <= 2'd1; end
                        2'd1: begin if (scl_di) begin ack_bit <= ~sda_di; process_cnt <= 2'd2; end end
                        2'd2: begin scl_do <= 1'b0; process_cnt <= 2'd3; end
                        2'd3: begin
                            if (ack_bit) begin
                                ack_bit <= 1'b0;
                                state <= REPEATED_START;
                            end else begin
                                state <= IDLE;
                            end
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                REPEATED_START: begin
                    case (process_cnt)
                        2'd0: begin
                            scl_do <= 1'b1;
                            sda_do <= 1'b1;
                            process_cnt <= 2'd1;
                        end
                        2'd1: begin
                            if (scl_di) begin process_cnt <= 2'd2; end
                        end
                        2'd2: begin
                            sda_do <= 1'b0;
                            process_cnt <= 2'd3;
                        end
                        2'd3: begin
                            scl_do <= 1'b0;
                            bit_cnt <= 4'd8;
                            process_cnt <= 2'd0;
                            state <= WRITE_SLAVE_ADDR_READ_MODE;
                            sda_do <= SLAVE_ADDR_READ[7];
                        end
                    endcase
                end

                WRITE_SLAVE_ADDR_READ_MODE: begin
                    case (process_cnt)
                        2'd0: begin scl_do <= 1'b1; process_cnt <= 2'd1; end
                        2'd1: begin if (scl_di) begin process_cnt <= 2'd2; end end
                        2'd2: begin scl_do <= 1'b0; bit_cnt <= bit_cnt_dec; process_cnt <= 2'd3; end
                        2'd3: begin
                            if (bit_cnt == 0) begin
                                state <= CHECK_ACK_READ_MODE;
                                sda_do <= 1'b1;
                            end else begin
                                sda_do <= SLAVE_ADDR_READ[bit_cnt_dec[2:0]];
                            end
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                CHECK_ACK_READ_MODE: begin
                    case (process_cnt)
                        2'd0: begin scl_do <= 1'b1; sda_do <= 1'b1; process_cnt <= 2'd1; end
                        2'd1: begin if (scl_di) begin ack_bit <= ~sda_di; process_cnt <= 2'd2; end end
                        2'd2: begin scl_do <= 1'b0; process_cnt <= 2'd3; end
                        2'd3: begin
                            if (ack_bit) begin
                                ack_bit <= 1'b0;
                                state <= READ_MSB;
                                bit_cnt <= 4'd8;
                                sda_do <= 1'b1;
                            end else begin
                                state <= IDLE;
                            end
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                READ_MSB: begin
                    case (process_cnt)
                        2'd0: begin scl_do <= 1'b1; sda_do <= 1'b1; process_cnt <= 2'd1; end
                        2'd1: begin if (scl_di) begin shift_reg[bit_cnt_dec[2:0]] <= sda_di; process_cnt <= 2'd2; end end
                        2'd2: begin scl_do <= 1'b0; bit_cnt <= bit_cnt_dec; process_cnt <= 2'd3; end
                        2'd3: begin
                            if (bit_cnt == 0) begin
                                result_16[15:8] <= shift_reg;
                                state <= SEND_ACK_MSB;
                            end
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                SEND_ACK_MSB: begin
                    case (process_cnt)
                        2'd0: begin
                            scl_do <= 1'b1;
                            sda_do <= 1'b0;
                            process_cnt <= 2'd1;
                        end
                        2'd1: begin
                            if (scl_di) begin process_cnt <= 2'd2; end
                        end
                        2'd2: begin
                            scl_do <= 1'b0;
                            process_cnt <= 2'd3;
                        end
                        2'd3: begin
                            state <= READ_LSB;
                            bit_cnt <= 4'd8;
                            sda_do <= 1'b1;
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                READ_LSB: begin
                    case (process_cnt)
                        2'd0: begin scl_do <= 1'b1; sda_do <= 1'b1; process_cnt <= 2'd1; end
                        2'd1: begin if (scl_di) begin shift_reg[bit_cnt_dec[2:0]] <= sda_di; process_cnt <= 2'd2; end end
                        2'd2: begin scl_do <= 1'b0; bit_cnt <= bit_cnt_dec; process_cnt <= 2'd3; end
                        2'd3: begin
                            if (bit_cnt == 0) begin
                                result_16[7:0] <= shift_reg;
                                state <= SEND_NACK_LSB;
                            end
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                SEND_NACK_LSB: begin
                    case (process_cnt)
                        2'd0: begin
                            scl_do <= 1'b1;
                            sda_do <= 1'b1;
                            process_cnt <= 2'd1;
                        end
                        2'd1: begin
                            if (scl_di) begin process_cnt <= 2'd2; end
                        end
                        2'd2: begin
                            scl_do <= 1'b0;
                            process_cnt <= 2'd3;
                        end
                        2'd3: begin
                            state <= STOP_READ;
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                STOP_READ: begin
                    case (process_cnt)
                        2'd0: begin scl_do <= 1'b1; sda_do <= 1'b0; process_cnt <= 2'd1; end
                        2'd1: begin if (scl_di) begin process_cnt <= 2'd2; end end
                        2'd2: begin sda_do <= 1'b1; process_cnt <= 2'd3; end
                        2'd3: begin
                            scl_do <= 1'b1;
                            sda_do <= 1'b1;
                            state <= DONE;
                            transaction_done <= 1'b1;
                            process_cnt <= 2'd0;
                        end
                    endcase
                end

                DONE: begin
                    scl_do <= 1'b1;
                    sda_do <= 1'b1;
                    state <= IDLE;
                end

                default: state <= IDLE;
            endcase
        end
    end

endmodule