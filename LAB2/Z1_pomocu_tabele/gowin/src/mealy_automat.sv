module mealy_automat (
    input  logic       U,
    input  logic        Cp,
    input  logic        reset,
    output logic [1:0]  Z,
    output logic [1:0]  stanje
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
                if (U == 1'b0) begin
                    Z = 2'b01;            
                    sljed_stanje = 2'd1;  
                end
                else begin
                    Z = 2'b10;            
                    sljed_stanje = 2'd0;  
                end
            end
            2'd1: begin 
                if (U == 1'b0) begin
                    Z = 2'b10;            
                    sljed_stanje = 2'd2;  
                end
                else begin
                    Z = 2'b10;            
                    sljed_stanje = 2'd0;  
                end
            end
            2'd2: begin 
                if (U == 1'b0) begin
                    Z = 2'b10;            
                    sljed_stanje = 2'd3;  
                end
                else begin
                    Z = 2'b11;            
                    sljed_stanje = 2'd0;  
                end
            end
            2'd3: begin 
                if (U == 1'b0) begin
                    Z = 2'b01;            
                    sljed_stanje = 2'd0;  
                end
                else begin
                    Z = 2'b10;            // y2
                    sljed_stanje = 2'd0;  // a0
                end
            end
            default: begin
                Z = 2'b00;
                sljed_stanje = 2'd0;
            end
        endcase
    end

endmodule : mealy_automat