#include "stimuli.h"

void stimuli::stimuli_process(){
	out1.write(1);
	out2.write(2);
	wait();
	out1.write(-3);
	out2.write(4);
	wait();
	out1.write(-5);
	out2.write(-6);
	wait();
	out1.write(7);
	out2.write(-8);
	wait();
	out1.write(9);
	out2.write(10);
	wait();
	wait();
	wait();
	wait();
	wait();
	wait();
	sc_stop();
}
		