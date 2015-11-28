#include "stimuli.h"

struct ptr_struct {
	int val1;
	int val2;
};

SCV_EXTENSIONS(ptr_struct) {
	public: 
		scv_extensions<int> val1;
		scv_extensions<int> val2;

		SCV_EXTENSIONS_CTOR(ptr_struct) {
			SCV_FIELD(val1);
			SCV_FIELD(val2);
		}
};

class my_class : public scv_constraint_base {
	public:
		scv_smart_ptr<ptr_struct> p;

	SCV_CONSTRAINT_CTOR(my_class){
		SCV_CONSTRAINT((p->val1()>=1 && p->val1()<=100) && !(p->val1()>=3 && p->val1()<=98) ||(p->val1()>=200 && p->val1()<=250) || p->val1()==1000);
		SCV_CONSTRAINT((p->val2()>=1 && p->val2()<=100) && !(p->val2()>=3 && p->val2()<=98) ||(p->val2()>=200 && p->val2()<=250) || p->val2()==1000);
	}
};

void stimuli::stimuli_process()  {
			
	my_class values("values");
	scv_random::set_global_seed(1);

	while (true) {
		values.next();

		cout << "\tStimuli (Constrained): (" << (values.p->val1);
		cout << "," << (values.p->val2) << ")  ";

		out1.write((values.p->val1));
		out2.write((values.p->val2));
  
		wait();
	}
}