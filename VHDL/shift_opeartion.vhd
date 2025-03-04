library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;               -- Needed for shifts
entity example_shift is
end example_shift;
 
architecture behave of example_shift is
  signal r_Shift1     : std_logic_vector(3 downto 0) := "1000";
  signal r_Unsigned_L : unsigned(3 downto 0)         := "0000";
  signal r_Unsigned_R : unsigned(3 downto 0)         := "0000";
  signal r_Signed_L   : signed(3 downto 0)           := "0000";
  signal r_Signed_R   : signed(3 downto 0)           := "0000";
   
begin
 
  process is
  begin
    -- Left Shift
    r_Unsigned_L <= shift_left(unsigned(r_Shift1), 1);
    r_Signed_L   <= shift_left(signed(r_Shift1), 1);
     
    -- Right Shift
    r_Unsigned_R <= shift_right(unsigned(r_Shift1), 2);
    r_Signed_R   <= shift_right(signed(r_Shift1), 2);
 
    wait for 100 ns;
  end process;
end architecture behave;