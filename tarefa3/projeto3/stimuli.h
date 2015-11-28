#include "systemc.h"
SC_MODULE(stimuli){
	sc_out<int> out1;
	sc_out<int> out2;
 	sc_in<bool> clk;
 
 	void stimuli_process();
 
 	SC_CTOR(stimuli){
 		SC_CTHREAD(stimuli_process,clk.pos());
 	}
};
