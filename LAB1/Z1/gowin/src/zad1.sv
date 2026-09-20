module zad1 (
    input   logic A,
    input   logic B,
    input   logic C,
    output  logic Y
);

always_comb begin
    Y = (~A & B & C) | ~(A | ~C);
end

endmodule