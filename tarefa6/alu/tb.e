<'
unit verify {
    clk : in simple_port of bit is instance;
    data_inp : out simple_port of uint(bits:11) is instance;
    data_out : in simple_port of uint(bits:8) is instance;

    keep bind(clk,external);
    keep clk.hdl_path() == "clk";
    
    keep bind(data_inp,external);
    keep data_inp.hdl_path() == "datain";
    
    keep bind(data_out,external);
    keep data_out.hdl_path() == "dataout";

    event alu_clk is fall(clk$) @sim;

};

struct data_struct {
    %b               : uint (bits : 4);
    %a               : uint (bits : 4);

    %control         : uint (bits : 3);
 
    !result          : uint (bits : 4);
    !carry           : bit;
    !overflow        : bit;
    !negative        : bit;
    !zero      	     : bit;

};

 
extend sys {
    inputs: list of data_struct;
    keep soft inputs.size() == 10; 
    
    verify is instance;
    keep verify.hdl_path() == "top";
   
};
'>