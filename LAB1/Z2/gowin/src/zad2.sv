module zad2 (
    input logic A,
    input logic B,
    input logic C,
    input logic D,
    input logic E,
    output logic Y
);

always_comb begin
    Y = (~A & B & C & D) | ~(A | ~E) | (B & ~C & D & ~E);
end

endmodule