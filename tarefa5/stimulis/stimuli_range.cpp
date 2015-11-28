#include "stimuli.h"

void stimuli::stimuli_process()  {

	scv_smart_ptr<int> values("values");
	//set simple keeponly/keepout range
	values->keep_only(1, 1000);
	values->keep_out(3, 98);
	values->keep_out(101, 199);
	values->keep_out(251, 999);

	scv_random::set_global_seed(1);
 
	while (true) {
		values->next();
		cout << "\tStimuli (Keep Only/Out): (" << *values;
		out1.write(*values);
		values->next();
		cout << "," << *values << ")  ";
		out2.write(*values);
		
		wait();
	}
}