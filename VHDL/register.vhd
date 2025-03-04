Library IEEE;
use IEEE.std_logic_1164.all;
entity reg_a is
port ( signal rega_input :in  std_logic_vector(7 downto 0) ;
signal writ: in std_logic;
signal reset: in std_logic;
signal clk: in std_logic;
signal rega_output: out std_logic_vector(7 downto 0) 
 );
end reg_a;
architecture sim of reg_a is
 begin
process(clk) is
   begin
 if rising_edge(clk) then
if(writ='1') then  
rega_output<=rega_input;
  elsif(reset='1') then
  rega_output<="00000000";          
end if;
      end if;
        end process;
end sim;