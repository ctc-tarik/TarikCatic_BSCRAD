#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_fst_c.h>
#include "VPID_regulacija.h"

#define MAX_SIM_TIME 2200
#define CLK_PERIOD   100   // period takta u ns (posedge clk na svakih 100 ns)
vluint64_t sim_time = 0;

double sc_time_stamp() {
    return sim_time;
}

int main(int argc, char** argv, char** env) {
    VPID_regulacija *dut = new VPID_regulacija;

    Verilated::traceEverOn(true);
    VerilatedFstC *m_trace = new VerilatedFstC;

    dut->trace(m_trace, 5);
    m_trace->open("waveform.fst");

    while (sim_time < MAX_SIM_TIME) {

        // Generisanje takta clk - simetrican signal sa periodom CLK_PERIOD
        if (sim_time % CLK_PERIOD == 0)              dut->clk = 1;
        if (sim_time % CLK_PERIOD == CLK_PERIOD / 2)  dut->clk = 0;

        // Inicijalni reset regulatora u nulto stanje.
        // PAZNJA: "areset" je AKTIVAN-NISKO (reset dok je areset==0), za razliku
        // od "reset" signala u mealy_automat primjeru koji je aktivan-visoko.
        if (sim_time == 0) {
            dut->areset = 0;
            dut->e_in   = 0;
        }
        if (sim_time == 20) {
            dut->areset = 1;
        }

        // Test stimulus na e_in (signed 16-bitna greska).
        // Verilator prema DUT-u izlaze/ulaze siri od 8 bita mapira u obican
        // unsigned kontejner (npr. vluint16_t/SData), tj. NE zna da je e_in
        // deklarisan kao "signed" u SystemVerilogu -- to je cisto stvar
        // interpretacije bitova unutar samog modula. Zato negativne vrijednosti
        // moramo rucno upisati kao ispravan bit-uzorak dvojnog komplementa,
        // preko (uint16_t)(int16_t)(...) pretvaranja, inace bi npr. -50
        // upisano direktno moglo biti odsjeceno/pogresno protumaceno.

        if (sim_time == 100) {
            dut->e_in = 100;                          // mala pozitivna greska -> u_out treba rasti
        }
        if (sim_time == 600) {
            dut->e_in = 5000;                         // velika pozitivna greska -> provjera zasicenja (saturation) na 32767
        }
        if (sim_time == 1100) {
            dut->e_in = (uint16_t)(int16_t)(-50);     // negativna greska -> u_out treba pasti na 0
        }
        if (sim_time == 1400) {
            dut->e_in = 10;                           // mala pozitivna greska -> provjera oporavka nakon reseta integratora
        }
        if (sim_time == 1700) {
            dut->e_in = (uint16_t)(int16_t)(-1000);   // veca negativna greska -- ovdje se u waveform-u (signal d_wire)
                                                       // najbolje vidi eventualni signed/unsigned problem u mnozenju sa k1/k2
        }
        if (sim_time == 2000) {
            dut->e_in = 0;                            // vracanje na neutralnu gresku
        }

        dut->eval();
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}