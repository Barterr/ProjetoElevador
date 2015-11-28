#ifndef ADDER_H
#define ADDER_H
#include <systemc.h>

SC_MODULE(adder){

	sc_in<int> in1;
	sc_in<int> in2;
	sc_out<int> out1;
 	sc_in<bool>clk;
	sc_event inc;
	int sum;
	
	void do_sum();
	void do_inc();
	
	SC_CTOR(adder){
	
		SC_CTHREAD(do_sum,clk.pos());
		
		SC_THREAD(do_inc);
		sensitive << inc;
	}
};
#endif