#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_fst_c.h>
#include "Vmealy_struktura.h"
#include "Vmealy_struktura___024root.h"

#define MAX_SIM_TIME 1450
#define CLK_PERIOD   100   // period takta u ns (posedge Cp na svakih 100 ns)
vluint64_t sim_time = 0;

double sc_time_stamp() {
    return sim_time;
}

int main(int argc, char** argv, char** env) {
    Vmealy_struktura *dut = new Vmealy_struktura;

    Verilated::traceEverOn(true);
    VerilatedFstC *m_trace = new VerilatedFstC;

    dut->trace(m_trace, 5);
    m_trace->open("waveform.fst");

    while (sim_time < MAX_SIM_TIME) {

        // Generisanje takta Cp - simetrican signal sa periodom CLK_PERIOD
        if (sim_time % CLK_PERIOD == 0)              dut->Cp = 1;
        if (sim_time % CLK_PERIOD == CLK_PERIOD / 2)  dut->Cp = 0;

        // Inicijalni reset automata u stanje a0 (Q1=0, Q0=0)
        if (sim_time == 0) {
            dut->reset = 1;
            dut->U     = 0;
        }
        if (sim_time == 20) {
            dut->reset = 0;
        }

        // Prolazak kroz kompletan ciklus a0->a1->a2->a3->a0 uz U=0 (x1)
        // (U je vec 0 od sim_time=0, prva tranzicija se desava na posedge-u t=100)

        // Provjera samopetlje i povratka u a0 uz U=1 (x2) iz svakog stanja
        if (sim_time == 460) dut->U = 1; // a0,U=1 -> ocekivano a0 (samopetlja), Z=y2
        if (sim_time == 560) dut->U = 0; // a0,U=0 -> ocekivano a1, Z=y1
        if (sim_time == 660) dut->U = 1; // a1,U=1 -> ocekivano a0, Z=y2
        if (sim_time == 760) dut->U = 0; // a0,U=0 -> ocekivano a1, Z=y1
        if (sim_time == 860) dut->U = 0; // a1,U=0 -> ocekivano a2, Z=y2
        if (sim_time == 960) dut->U = 1; // a2,U=1 -> ocekivano a0, Z=y3
        if (sim_time == 1060) dut->U = 0; // a0,U=0 -> ocekivano a1, Z=y1
        if (sim_time == 1160) dut->U = 0; // a1,U=0 -> ocekivano a2, Z=y2
        if (sim_time == 1260) dut->U = 0; // a2,U=0 -> ocekivano a3, Z=y2
        if (sim_time == 1360) dut->U = 1; // a3,U=1 -> ocekivano a0, Z=y2

        dut->eval();
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}