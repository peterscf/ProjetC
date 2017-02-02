library IEEE ;
use IEEE.std_logic_1164.ALL ;
use ieee.numeric_std.all;

entity counter is
	port (	resetn, en, up_down : in std_logic;
		count : out std_logic_vector (3 downto 0));
end counter;

Architecture B of counter is 

begin 

process ( resetn)

variable c : unsigned (3 downto 0); 

begin
	if resetn = '0' then C:="0000"; 
	elsif (cresetn = '1') then
		if (en ='1') then
			if (up_down='1') then 
				c:= c+"0001"; 
			elsif (up_down='0') then 
				c:= c- "0001"; 
			end if;
		end if;
	end if;
count <= std_logic_vector(c); 

end process;

end B;


