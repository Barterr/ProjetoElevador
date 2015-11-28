library ieee;
library work;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;

entity top is
end top;

architecture top_bhv of top is

component alu
   port (
	clk        : in std_logic;
	datain     : in std_logic_vector (10 downto 0);
	dataout    : out std_logic_vector (7 downto 0)
   );
end component;
	signal clk        : std_logic := '0';
	signal datain     : std_logic_vector (10 downto 0);
	signal dataout    : std_logic_vector (7 downto 0);

begin

  clk <= not clk after 100 ns;

  alu1 : alu port map (clk, datain, dataout);

end top_bhv;
