#include "display.h"

void display::display_process() {
  
  wait();
  while(1){
    cout << "\tdisplay: (" << in1.read() << ")" << endl;
    wait();
  }
}