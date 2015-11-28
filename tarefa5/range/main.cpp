#include "systemc.h"
#include "adder.h"
#include "display.h"
#include "stimuli.h"

int sc_main( int argc, char *argv[] )  {
  // Remove deprecated warnings
  sc_core::sc_report_handler::set_actions( "/IEEE_Std_1666/deprecated", sc_core::SC_DO_NOTHING );


  // Signals
  sc_signal<int> arg1;
  sc_signal<int> arg2;
  sc_signal<int> sum;
  
  // Clock
  sc_clock clk( "clock", 10, 0.5 );
  
  // Module
  stimuli *S;
  adder *A;
  display *D;
  
  // Module instantiations and Mapping
  S = new stimuli("stimuli");
  //(*S) (arg1, arg2, clk);
  A = new adder("adder");
  //(*A) (arg1, arg2, sum);
  D = new display ("display");
  //(*D) (sum);
  
  S->clk(clk);
  S->out1(arg1);
  S->out2(arg2);
  
  A->in1(arg1);
  A->in2(arg2);
  A->out1(sum);
  
  D->in1(sum);
  
  sc_trace_file *tf;
  tf = sc_create_vcd_trace_file("trace");
  sc_trace(tf, clk, "clk_sig"); 
  sc_trace(tf, arg1, "arg1"); 
  sc_trace(tf, arg2, "arg2"); 
  sc_trace(tf, sum, "sum"); 

  // Start of the Simulation
  sc_start(1000, SC_NS);
  return 0; 
};                                                                     
