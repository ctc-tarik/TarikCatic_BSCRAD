#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_fst_c.h>
#include "Vzad1.h"
#include "Vzad1___024root.h"

#define MAX_SIM_TIME 4000
vluint64_t sim_time = 0;

double sc_time_stamp() {
    return sim_time;
}

int main(int argc, char** argv, char** env) {
    Vzad1 *dut = new Vzad1;

    Verilated::traceEverOn(true);
    VerilatedFstC *m_trace = new VerilatedFstC;

    dut->trace(m_trace, 5);
    m_trace->open("waveform.fst");


	while (sim_time < MAX_SIM_TIME) {
       
		if(sim_time == 0)
		{
			dut->A = 0;
			dut->B = 0;
			dut->C = 0;
		}
		
		if(sim_time == 500)
		{
			dut->A = 1;
			dut->B = 0;
			dut->C = 0;
		}
		
		if(sim_time == 1000)
		{
			dut->A = 0;
			dut->B = 1;
			dut->C = 0;
		}
		
		if(sim_time == 1500)
		{
			dut->A = 1;
			dut->B = 1;
			dut->C = 0;
		}
			if(sim_time == 2000)
		{
			dut->A = 0;
			dut->B = 0;
			dut->C = 1;
		}
		
		if(sim_time == 2500)
		{
			dut->A = 1;
			dut->B = 0;
			dut->C = 1;
		}
		
		if(sim_time == 3000)
		{
			dut->A = 0;
			dut->B = 1;
			dut->C = 1;
		}
		if(sim_time == 3500)
		{
			dut->A = 1;
			dut->B = 1;
			dut->C = 1;
		}

       dut->eval();
       m_trace->dump(sim_time);
       sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}
