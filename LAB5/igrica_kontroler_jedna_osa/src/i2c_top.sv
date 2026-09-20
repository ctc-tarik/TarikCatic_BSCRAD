module i2c_top (
    input logic clk,
    input logic areset_n,

    inout wire i2c_scl,
    inout wire i2c_sda,

    output logic led,

    output logic transaction_done,

    output logic [15:0] result_16

);

    logic [26:0] brojac;
    logic strobe_400kHz;

    always_ff @(negedge areset_n or posedge clk) begin
        if(areset_n == 1'b0)begin
            brojac <= 27'd0; 
            strobe_400kHz <= 1'b0;
        end
        else begin
            brojac <= brojac + 27'd1;
            if(brojac == 27'd68) begin
                strobe_400kHz <= 1'b1; 
                brojac <= 27'd0;
            end
            else begin
                strobe_400kHz <= 1'b0; 
            end
        end
    end

    logic start_transaction;
    logic [7:0] pause_duration; 
   

    logic scl_oe;
    logic scl_di;
    logic sda_oe;
    logic sda_di;

    assign start_transaction = 1'b1;

    assign pause_duration = 16'hFFFF;

    i2c_ctrl u_i2c_ads1115 (
        .clk             (clk),
        .strobe_400kHz   (strobe_400kHz),
        .areset_n        (areset_n),
        .start_transaction(start_transaction),
        .pause_duration  (pause_duration),
        .transaction_done(transaction_done),
        .scl_oe          (scl_oe),
        .scl_di          (scl_di),
        .sda_oe          (sda_oe),
        .sda_di          (sda_di),
        .led             (led),
        .result_16       (result_16)
    );


    assign i2c_scl = scl_oe ? 1'b0 : 1'bz; 
    assign scl_di = i2c_scl; 

    assign i2c_sda = sda_oe ? 1'b0 : 1'bz; 
    assign sda_di = i2c_sda;

endmodule