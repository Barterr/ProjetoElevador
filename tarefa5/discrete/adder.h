#ifndef ADDER_H
#define ADDER_H
#include <systemc.h>

SC_MODULE( adder )  {
  // Ports
  sc_in<int> in1;
  sc_in<int> in2;
  sc_out<int> out1;
  
  // Functionality
  void adder_process();
  
  // Constructor
  SC_CTOR( adder )  {
    SC_THREAD( adder_process );
    sensitive << in1 << in2;
  } 
};

#endif
  