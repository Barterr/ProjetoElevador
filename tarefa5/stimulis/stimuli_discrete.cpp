#include "stimuli.h"

void stimuli::stimuli_process()  {

	scv_smart_ptr<int> values("values");
	scv_bag<int> dist("bag");
	dist.add(1,1);
	dist.add(2,1);
	dist.add(99,1);
	dist.add(200,1);
	dist.add(201,1);
	dist.add(202,1);
	dist.add(203,1);
	dist.add(204,1);
	dist.add(205,1);
	dist.add(206,1);
	dist.add(207,1);
	dist.add(208,1);
	dist.add(209,1);
	dist.add(210,1);
	dist.add(211,1);
	dist.add(212,1);
	dist.add(213,1);
	dist.add(214,1);
	dist.add(215,1);
	dist.add(216,1);
	dist.add(217,1);
	dist.add(218,1);
	dist.add(219,1);
	dist.add(220,1);
	dist.add(221,1);
	dist.add(222,1);
	dist.add(223,1);
	dist.add(224,1);
	dist.add(225,1);
	dist.add(226,1);
	dist.add(227,1);
	dist.add(228,1);
	dist.add(229,1);
	dist.add(230,1);
	dist.add(231,1);
	dist.add(232,1);
	dist.add(233,1);
	dist.add(234,1);
	dist.add(235,1);
	dist.add(236,1);
	dist.add(237,1);
	dist.add(238,1);
	dist.add(239,1);
	dist.add(240,1);
	dist.add(241,1);
	dist.add(242,1);
	dist.add(243,1);
	dist.add(244,1);
	dist.add(245,1);
	dist.add(246,1);
	dist.add(247,1);
	dist.add(248,1);
	dist.add(249,1);
	dist.add(250,1);
	dist.add(1000,1);

	values->set_mode(dist);

	scv_random::set_global_seed(1);
   
	while (true) {
		values->next();
		cout << "\tStimuli (Discrete): (" << *values;
		out1.write(*values);
		values->next();
		cout << "," << *values << ")  ";
		out2.write(*values);
	  
		wait();
	}
}