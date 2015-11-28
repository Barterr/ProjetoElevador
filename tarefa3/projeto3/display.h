#ifndef DISPLAY_H
#define DISPLAY_H

#include<systemc.h>

 SC_MODULE (display){
	sc_in<int> input;
 	sc_in<bool> clk;
	
	void display_process();
	
	SC_CTOR(display){
		SC_CTHREAD(display_process,clk.pos());
	}
};
	
#endif