<'
import tb;

extend data_struct {
  keep a < 16;
  keep b < 16;
  keep control < 6;

  event input_cover;
  cover input_cover is {
    item a;
    item b;
    item control;
  
    cross a, b, control;
  };

  post_generate() is also {
    emit input_cover;
  };  

};

extend sys {
  keep inputs.size() == 40;

    run() is also {
        start verify.verify();
    };
};

extend verify {
    verify() @alu_clk is {
        for each (inp) in sys.inputs do {	
            data_inp$ = pack(NULL,inp);
            wait cycle;

	    inp.carry = data_out$ >> 4;
	    inp.overflow = data_out$ >> 5;
	    inp.negative = data_out$ >> 6;
	    inp.zero = data_out$ >> 7;
            inp.result = data_out$;

            print inp;
            print data_out$;
	    print sys.time;
--------------Write Checks here----------------------------------
	if inp.control == 0 and ((inp.a + inp.b) <= 15 ){
	  check that inp.result == (inp.a + inp.b) else
	    dut_error("Addition operation error!")
	};
	if inp.control == 0 and ((inp.a + inp.b) > 15 ){
	  check that inp.result == (inp.a + inp.b - 16) else
	    dut_error("Addition with overflow operation error!")
	};
	if inp.control == 1 and inp.carry == 1 {
	  check that inp.result == (inp.a - inp.b + 16) else
	    dut_error("Subtraction with overflow operation error!")
	};
	if inp.control == 1 and inp.carry == 0 {
	  check that inp.result == (inp.a - inp.b) else
	    dut_error("Subtraction operation error!")
	};
	if inp.control == 2 {
	  check that inp.result == (inp.a & inp.b) else
	    dut_error("AND operation error!")
	};
	if inp.control == 3 {
	  check that inp.result == (inp.a | inp.b) else
	    dut_error("OR operation error!")
	};
	if inp.control == 4 {
	  check that inp.result == (inp.a ^ inp.b) else
	    dut_error("XOR operation error!")
	};
	if inp.control == 5 {
	  check that inp.result == (~inp.a) else
	    dut_error("NOT operation error!")
	};
	if inp.control >= 6 {
	     dut_error("OTHERS operation error!")
	};


-----------------------------------------------------------------
            wait cycle;
        };
        stop_run();
    };
};
'>