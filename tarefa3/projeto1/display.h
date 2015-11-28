#ifndef DISPLAY_H
#define DISPLAY_H

#include<systemc.h>

 SC_MODULE (display){
	sc_in<int> input;
	
	void display_process();
	
	SC_CTOR(display){
		SC_THREAD(display_process);
		sensitive << input;
	}
};
	
#endif