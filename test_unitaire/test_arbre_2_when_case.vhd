library IEEE ;
use IEEE.std_logic_1164.ALL ;
use ieee.numeric_std.all;

entity ALU is
	port(	A,B		: in STD_LOGIC_VECTOR(7 downto 0) ;
		CMD		: in STD_LOGIC_VECTOR(2 downto 0) ;
		Zero		: out std_logic; 
		S		: out STD_LOGIC_VECTOR(7 downto 0) ;
		rst 	:in STD_LOGIC);
end ALU;

architecture A of ALU is

signal result: unsigned (8 downto 0);
signal a_u: unsigned (7 downto 0);
signal b_u: unsigned (7 downto 0);

begin

zero<= '1' when result(7 downto 0) = "00000000" else '0';

S<= std_logic_vector(result(7 downto 0));
a_u<= unsigned(a);
b_u<= unsigned(b);

 result<= "000000000" when CMD ="000"; 
 result<= '0'  when  CMD ="011";
 result<= '0' & a_u  when  CMD ="011" else '0' ; 	
 result<=  a_u - '0' when  CMD ="010" else a_u;
 result<= '0' + a_u  when CMD ="001" else a_u & b_u;
 result<= '0' * b_u  when CMD ="001" else "11111111";
 result<= a_u XOR '0' when CMD ="100";
 result<=  a_u AND '0' when CMD ="110";
 result<= a_u OR '0' when CMD ="101";

 process(rst)
begin 
	
	if rst='1' then	
	a_u <="00000000";
	b_u <="00000000";
	S <= "00000000";
	result <= "000000000";
	elsif rst='0' then
	a_u<= unsigned(a); 
	b_u<= unsigned(b);
		case CMD is 
			when "000" => result <= "000000000"	
			when "011" => result <= '0'
			when "010" => result <= '0' & a_u 
			when "001" => result <= '0' + a_u
			when "100" => result <= a_u - '0'
			when "110" => result <= '0' * b_u 
			when "101" => result <= a_u XOR '0'
			when "111" => result <= a_u AND '0'
			when others => result <=  a_u OR '0';
		end case;
	S<= std_logic_vector(result(7 downto 0)); 
	end if;
	
end process; 

end A;
    
    

