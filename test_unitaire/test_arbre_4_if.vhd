library IEEE ;
use IEEE.std_logic_1164.ALL ;
use ieee.numeric_std.all;

entity ALU is
	port(	rst		: in STD_LOGIC ;);
end ALU;

architecture Arc of ALU is

signal result: unsigned (8 downto 0);
signal a_u: unsigned (7 downto 0);
signal b_u: unsigned (7 downto 0);

begin

--zero<= '1' when result(7 downto 0) = "00000000" else '0';

--S<= std_logic_vector(result(7 downto 0));
--a_u<= unsigned(a);
--b_u<= unsigned(b);

 process(rst)
begin 
	
if rst ='1' then	
	a_u <="00000000";
	b_u <="00000000";
	a_u <= "00000000";
	result <= "000000000";
	
	elsif rst <="000" then
	a_u <="00000010";
	b_u <="00000010";
	
	result <= "000000010";
	elsif rst <'1' then
	a_u <="10000000";
	b_u <="10000000";

	result <= "100000000";
	elsif rst >'1' then
	a_u <="11000000";
	b_u <="11000000";
	
	result <= "110000000";
	else a_u <= "11111111";
	end if;
	
end process; 
a_u <="00000000";
	b_u <="00000000";
	a_u <= "00000000";
end Arc;
    
    

