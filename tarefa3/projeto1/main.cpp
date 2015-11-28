#include "systemc.h"
#include "adder.h"
#include "stimuli.h"
#include "display.h"

int sc_main( int argc, char *argv[] )  {
	// Signals
	sc_signal<int> arg1;
	sc_signal<int> arg2;
	sc_signal<int> sum;
	
	// Clock
	sc_clock clk("clk",10,SC_NS);

	// Module
	stimuli S ("STIMULI");
	adder A ("ADDER");
	display D ("DISPLAY");

	// Module instantiations and Mapping
	S.clk(clk);
	S.out1(arg1);
	S.out2(arg2);

	A.in1(arg1);
	A.in2(arg2);
	A.out1(sum);

	D.input(sum);

	sc_trace_file *tf;
	tf = sc_create_vcd_trace_file("trace");
	sc_trace(tf, clk, "clk_sig"); 
	sc_trace(tf, arg1, "arg1"); 
	sc_trace(tf, arg2, "arg2"); 
	sc_trace(tf, sum, "sum"); 

	// Start of the Simulation
	sc_start(200,SC_NS);
	return 0; 
};                                                                     
