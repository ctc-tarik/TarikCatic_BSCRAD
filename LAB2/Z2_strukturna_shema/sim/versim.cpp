#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_fst_c.h>
#include "Vmoore_struktura.h"
#include "Vmoore_struktura___024root.h"

#define MAX_SIM_TIME 900
#define CLK_PERIOD   100   // period takta u ns (posedge Cp na svakih 100 ns)
vluint64_t sim_time = 0;

double sc_time_stamp() {
    return sim_time;
}

int main(int argc, char** argv, char** env) {
    Vmoore_struktura *dut = new Vmoore_struktura;

    Verilated::traceEverOn(true);
    VerilatedFstC *m_trace = new VerilatedFstC;

    dut->trace(m_trace, 5);
    m_trace->open("waveform.fst");

    while (sim_time < MAX_SIM_TIME) {

        // Generisanje takta Cp - simetrican signal sa periodom CLK_PERIOD
        if (sim_time % CLK_PERIOD == 0)              dut->Cp = 1;
        if (sim_time % CLK_PERIOD == CLK_PERIOD / 2)  dut->Cp = 0;

        // Inicijalni reset automata u stanje b0 (00)
        if (sim_time == 0) {
            dut->reset = 1;
            dut->U     = 1;
        }
        if (sim_time == 20) {
            dut->reset = 0;
        }

        // Sekvenca koja pokriva svih 8 kombinacija (stanje x ulaz) tacno jednom:
        // b0,U1->b1 | b1,U1->b2 | b2,U1->b3 | b3,U1->b2 |
        // b2,U0->b1 | b1,U0->b0 | b0,U0->b3 | b3,U0->b0
        if (sim_time == 460) dut->U = 0; // prekidac U=1 -> U=0 nakon 4. takta

        dut->eval();
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}