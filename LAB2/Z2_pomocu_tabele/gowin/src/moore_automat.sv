module moore_automat (
    input  logic       U,
    input  logic       Cp,
    input  logic       reset,
    output logic       Z,
    output logic [1:0] stanje
);

    logic [1:0] sljed_stanje;

    always_ff @(posedge reset or posedge Cp) begin
        if (reset == 1'b1) begin
            stanje <= 2'd0;
        end
        else begin
            stanje <= sljed_stanje;
        end
    end

    always_comb begin
        case (stanje)
            2'd0: begin 
                Z = 1'b0;
                sljed_stanje = (U == 1'b0) ? 2'd3 : 2'd1;
            end
            2'd1: begin
                Z = 1'b1;
                sljed_stanje = (U == 1'b0) ? 2'd0 : 2'd2;
            end
            2'd2: begin
                Z = 1'b1;
                sljed_stanje = (U == 1'b0) ? 2'd1 : 2'd3;
            end
            2'd3: begin
                Z = 1'b0;
                sljed_stanje = (U == 1'b0) ? 2'd0 : 2'd2;
            end
            default: begin
                Z = 1'b0;
                sljed_stanje = 2'd0;
            end
        endcase
    end

endmodule : moore_automat