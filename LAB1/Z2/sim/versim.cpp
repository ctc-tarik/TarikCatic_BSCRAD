#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_fst_c.h>
#include "Vzad2.h"
#include "Vzad2___024root.h"

#define MAX_SIM_TIME 16000
vluint64_t sim_time = 0;

double sc_time_stamp() {
    return sim_time;
}

int main(int argc, char** argv, char** env) {
    Vzad2 *dut = new Vzad2;

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
			dut->D = 0;
			dut->E = 0;
		}

		if(sim_time == 500)
		{
			dut->A = 0;
			dut->B = 0;
			dut->C = 0;
			dut->D = 0;
			dut->E = 1;
		}

		if(sim_time == 1000)
		{
			dut->A = 0;
			dut->B = 0;
			dut->C = 0;
			dut->D = 1;
			dut->E = 0;
		}

		if(sim_time == 1500)
		{
			dut->A = 0;
			dut->B = 0;
			dut->C = 0;
			dut->D = 1;
			dut->E = 1;
		}

		if(sim_time == 2000)
		{
			dut->A = 0;
			dut->B = 0;
			dut->C = 1;
			dut->D = 0;
			dut->E = 0;
		}

		if(sim_time == 2500)
		{
			dut->A = 0;
			dut->B = 0;
			dut->C = 1;
			dut->D = 0;
			dut->E = 1;
		}

		if(sim_time == 3000)
		{
			dut->A = 0;
			dut->B = 0;
			dut->C = 1;
			dut->D = 1;
			dut->E = 0;
		}

		if(sim_time == 3500)
		{
			dut->A = 0;
			dut->B = 0;
			dut->C = 1;
			dut->D = 1;
			dut->E = 1;
		}

		if(sim_time == 4000)
		{
			dut->A = 0;
			dut->B = 1;
			dut->C = 0;
			dut->D = 0;
			dut->E = 0;
		}

		if(sim_time == 4500)
		{
			dut->A = 0;
			dut->B = 1;
			dut->C = 0;
			dut->D = 0;
			dut->E = 1;
		}

		if(sim_time == 5000)
		{
			dut->A = 0;
			dut->B = 1;
			dut->C = 0;
			dut->D = 1;
			dut->E = 0;
		}

		if(sim_time == 5500)
		{
			dut->A = 0;
			dut->B = 1;
			dut->C = 0;
			dut->D = 1;
			dut->E = 1;
		}

		if(sim_time == 6000)
		{
			dut->A = 0;
			dut->B = 1;
			dut->C = 1;
			dut->D = 0;
			dut->E = 0;
		}

		if(sim_time == 6500)
		{
			dut->A = 0;
			dut->B = 1;
			dut->C = 1;
			dut->D = 0;
			dut->E = 1;
		}

		if(sim_time == 7000)
		{
			dut->A = 0;
			dut->B = 1;
			dut->C = 1;
			dut->D = 1;
			dut->E = 0;
		}

		if(sim_time == 7500)
		{
			dut->A = 0;
			dut->B = 1;
			dut->C = 1;
			dut->D = 1;
			dut->E = 1;
		}

		if(sim_time == 8000)
		{
			dut->A = 1;
			dut->B = 0;
			dut->C = 0;
			dut->D = 0;
			dut->E = 0;
		}

		if(sim_time == 8500)
		{
			dut->A = 1;
			dut->B = 0;
			dut->C = 0;
			dut->D = 0;
			dut->E = 1;
		}

		if(sim_time == 9000)
		{
			dut->A = 1;
			dut->B = 0;
			dut->C = 0;
			dut->D = 1;
			dut->E = 0;
		}

		if(sim_time == 9500)
		{
			dut->A = 1;
			dut->B = 0;
			dut->C = 0;
			dut->D = 1;
			dut->E = 1;
		}

		if(sim_time == 10000)
		{
			dut->A = 1;
			dut->B = 0;
			dut->C = 1;
			dut->D = 0;
			dut->E = 0;
		}

		if(sim_time == 10500)
		{
			dut->A = 1;
			dut->B = 0;
			dut->C = 1;
			dut->D = 0;
			dut->E = 1;
		}

		if(sim_time == 11000)
		{
			dut->A = 1;
			dut->B = 0;
			dut->C = 1;
			dut->D = 1;
			dut->E = 0;
		}

		if(sim_time == 11500)
		{
			dut->A = 1;
			dut->B = 0;
			dut->C = 1;
			dut->D = 1;
			dut->E = 1;
		}

		if(sim_time == 12000)
		{
			dut->A = 1;
			dut->B = 1;
			dut->C = 0;
			dut->D = 0;
			dut->E = 0;
		}

		if(sim_time == 12500)
		{
			dut->A = 1;
			dut->B = 1;
			dut->C = 0;
			dut->D = 0;
			dut->E = 1;
		}

		if(sim_time == 13000)
		{
			dut->A = 1;
			dut->B = 1;
			dut->C = 0;
			dut->D = 1;
			dut->E = 0;
		}

		if(sim_time == 13500)
		{
			dut->A = 1;
			dut->B = 1;
			dut->C = 0;
			dut->D = 1;
			dut->E = 1;
		}

		if(sim_time == 14000)
		{
			dut->A = 1;
			dut->B = 1;
			dut->C = 1;
			dut->D = 0;
			dut->E = 0;
		}

		if(sim_time == 14500)
		{
			dut->A = 1;
			dut->B = 1;
			dut->C = 1;
			dut->D = 0;
			dut->E = 1;
		}

		if(sim_time == 15000)
		{
			dut->A = 1;
			dut->B = 1;
			dut->C = 1;
			dut->D = 1;
			dut->E = 0;
		}

		if(sim_time == 15500)
		{
			dut->A = 1;
			dut->B = 1;
			dut->C = 1;
			dut->D = 1;
			dut->E = 1;
		}

       dut->eval();
       m_trace->dump(sim_time);
       sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}