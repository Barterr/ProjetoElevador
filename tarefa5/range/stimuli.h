#ifndef STIMULI_H
#define STIMULI_H
#include <systemc.h>
#include "scv.h"
void _scv_pop_constraint();

SC_MODULE( stimuli )  {
  // Ports
  sc_out<int> out1;
  sc_out<int> out2;
  sc_in_clk   clk;
  
  // Functionality
  void stimuli_process();
  
  // Constructor
  SC_CTOR( stimuli )  {
    SC_CTHREAD( stimuli_process, clk.pos() );
  } 
}; 
#endif