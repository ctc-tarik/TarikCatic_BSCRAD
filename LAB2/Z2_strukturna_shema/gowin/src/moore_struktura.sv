module T_ff (
    input  logic T,
    input  logic Cp,
    input  logic reset,
    output logic Q
);

    always_ff @(posedge reset or posedge Cp) begin
        if (reset == 1'b1) begin
            Q <= 1'b0;
        end
        else begin
            Q <= T ^ Q;
        end
    end

endmodule : T_ff


module moore_struktura (
    input  logic       U,
    input  logic       Cp,
    input  logic       reset,
    output logic       Z,
    output logic [1:0] stanje      // trenutno stanje automata (Q1,Q0) - vidljivo u simulaciji
);

    logic Q1, Q0;
    logic T1, T2;

    T_ff flipflop1 (.T(T1), .Cp(Cp), .reset(reset), .Q(Q1));
    T_ff flipflop2 (.T(T2), .Cp(Cp), .reset(reset), .Q(Q0));

    always_comb begin
        T1 = (Q1 & ~U) | (~Q0 & ~U) | (Q0 & U & ~Q1);
        T2 = 1'b1;

        Z = Q1 ^ Q0;
        stanje = {Q1, Q0};
    end

endmodule : moore_struktura