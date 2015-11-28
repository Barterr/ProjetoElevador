#include "stimuli.h"

void stimuli::stimuli_process()  {

	scv_bag<pair<int,int> > dist;
	dist.add(pair<int,int>(1,2),100);
	dist.add(pair<int,int>(99,100),100);
	dist.add(pair<int,int>(200,250),100);
	dist.add(pair<int,int>(1000,1000),100);

	scv_smart_ptr<int> values("values");
	values->set_mode(dist);

	scv_random::set_global_seed(1);
   
	while (true) {
		values->next();
		cout << "\tStimuli (Range): (" << *values;
		out1.write(*values);
		values->next();
		cout << "," << *values << ")  ";
		out2.write(*values);
	  
		wait();
	}
}