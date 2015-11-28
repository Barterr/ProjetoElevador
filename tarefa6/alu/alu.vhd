------------------------------------------------------------------------------
-- ALU design.
------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.all;
USE ieee.numeric_std.all;
USE ieee.std_logic_1164.all;

------------------------------------------------------------------------------
-- Entity declarations.
------------------------------------------------------------------------------

ENTITY alu IS
   PORT (
	clk        : in std_logic;
      datain : in std_logic_vector (10 DOWNTO 0);
      dataout : out std_logic_vector (7 DOWNTO 0)
 );

BEGIN
END ENTITY alu;

------------------------------------------------------------------------------
-- Architecture definitions.
------------------------------------------------------------------------------

ARCHITECTURE behaviour OF alu IS

   SIGNAL aBus : std_logic_vector (3 DOWNTO 0);
   SIGNAL bBus : std_logic_vector (3 DOWNTO 0);
   SIGNAL qBus : std_logic_vector (3 DOWNTO 0);
   SIGNAL opCode : std_logic_vector (2 DOWNTO 0);
   SIGNAL C : std_logic;
   SIGNAL Z : std_logic;
   SIGNAL N : std_logic;
   SIGNAL V : std_logic;

BEGIN
   operation: PROCESS (clk, opCode, aBus, bBus )
      VARIABLE Cin : STD_LOGIC;
      VARIABLE sum : unsigned (4 DOWNTO 0);

   BEGIN
      -- ALU op. code decoder.
      CASE opCode IS
         WHEN "000" =>
            -- a PLUS b
            sum := ( '0' & unsigned( aBus ) ) + ( '0' & unsigned( bBus ) );
            Cin := sum( 4 );
            V <= ( ( aBus( 3 ) XNOR bBus( 3 ) ) XOR qBus( 3 ) );
            qBus <= std_logic_vector( sum( 3 downto 0 ) );

         WHEN "001" =>
            -- a MINUS b
            sum := ( '0' & unsigned( aBus ) ) - ( '0' & unsigned( bBus ) );
            Cin := sum( 4 );
            V <= ( ( aBus( 3 ) XNOR bBus( 3 ) ) XOR qBus( 3 ) );
            qBus <= std_logic_vector( sum( 3 downto 0 ) );

         WHEN "010" =>
            -- a AND b
            qBus <= aBus AND bBus;

         WHEN "011" =>
            -- a OR b
            qBus <= aBus OR bBus;

         WHEN "100" =>
            -- a XOR b
            qBus <= aBus XOR bBus;

         WHEN "101" =>
            -- A
            qBus <= not( aBus );

         WHEN others =>
            -- NOP
            qBus <= std_logic_vector( to_unsigned( 0, 4 ) );

      END CASE;

      C <= Cin;
	if qBus = "0000" then
		Z <= '1';
	else
		Z <= '0';
	end if;
     -- Z <= '1' when ( qBus = "0000" ) else '0' );
      N <= qBus( 3 );
   END PROCESS operation;

   -- Interface connections.
   opCode <= datain(10 downto 8);
   aBus <= datain(7 downto 4);
   bBus <= datain(3 downto 0);

   dataout(7) <= Z;
   dataout(6) <= N;
   dataout(5) <= V;
   dataout(4) <= C;
   dataout(3 downto 0) <= qBus;

END ARCHITECTURE behaviour;
