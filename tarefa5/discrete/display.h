#ifndef DISPLAY_H
#define DISPLAY_H
#include <systemc.h>

SC_MODULE( display )  {
  // Ports
  sc_in<int> in1;
  
  // Functionality
  void display_process();
  
  // Constructor
  SC_CTOR( display )  {
    SC_THREAD( display_process );
    sensitive << in1;
  } 
};                                                                                                  

#endif