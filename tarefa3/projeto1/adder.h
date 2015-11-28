#ifndef ADDER_H
#define ADDER_H
#include <systemc.h>

SC_MODULE(adder){

	sc_in<int> in1;
	sc_in<int> in2;
	sc_out<int> out1;
	
	
	void adder_process();
	
	SC_CTOR(adder){
	
		SC_THREAD(adder_process);
		sensitive << in1 << in2;
	}
};
#endif
	