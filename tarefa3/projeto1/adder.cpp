#include "adder.h"


void adder::adder_process(){
	int arg1;
	int arg2;
	int sum;	
	while(true){
		arg1 = in1.read();
		arg2 = in2.read();
		sum = arg1+arg2;
		out1.write(sum);
		wait();
	}
}
		