#include "display.h"

void display::display_process(){

	int result;
	
	while(true){
		result = input.read();
		cout << "\tresult: " << result;
		wait();
	}
}
