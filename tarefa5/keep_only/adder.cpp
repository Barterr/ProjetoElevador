#include "adder.h"

void adder::adder_process() {
  int  tmp1;
  int  tmp2;    
  int  tmp3;
  wait();
    while ( true )  {
      tmp1 = in1.read();
      tmp2 = in2.read();
      tmp3 = tmp1 + tmp2;
      out1.write( tmp3 );        
      cout << "\t\tadder: (" << tmp1 << "+" << tmp2 << "=" << tmp3 << ")";
      wait();
    }
  }
