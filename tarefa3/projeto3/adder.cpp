#include "adder.h"


void adder::do_sum(){
	int arg1;
	int arg2;

	while(true){
		arg1 = in1.read();
		arg2 = in2.read();
		sum = arg1+arg2;
		inc.notify();
		wait();
	}
}

void adder::do_inc(){
	while(true){
		sum++;
		out1.write(sum);
		wait();
	}
}