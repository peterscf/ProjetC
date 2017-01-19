library IEEE ;
use IEEE.std_logic_1164.ALL ;

entity arbiter is
port (	clk 	: in std_logic ;
	resetn	: in std_logic ;
	R	: in std_logic_vector(1 to 3) ;
	ACK	: out std_logic_vector(1 to 3) );
end arbiter ;


architecture behaviour of arbiter is

type state_arbiter is (Idle, Proc1, Proc2, Proc3) ;
signal current_state : state_arbiter ;
signal next_state : state_arbiter ;

begin
P_state : process (clk, resetn)

begin

if (resetn ='0') then current_state <= Idle;
elsif(clk'event and clk='1') then current_state <= next_state;
end if;

end process P_state ;


P_Next_State_output : process (current_state, R)
begin

case current_state is
	when Idle => 	ACK <= "000";
			if (R(1)='1') then next_state <= PROC1;
			elsif (R(1 to 2) = "01") then next_state <= PROC2;
			elsif (R="001") then next_state <= PROC3;
			else next_state <= Idle;
			end if;
	when PROC1 => 	ACK(1) <= '1';
			if (R(1)='1') then next_state <= PROC1;
			else next_state <= Idle;
			end if;
	when PROC2 => 	ACK(2) <= '1';
			if (R(2)='1') then next_state <= PROC2;
			else next_state <= Idle;
			end if;
	when PROC3 => 	ACK(3) <= '1';
			if (R(3)='1') then next_state <= PROC3;
			else next_state <= Idle;
			end if;
end case;

end process P_Next_State_output ;

end behaviour ;
