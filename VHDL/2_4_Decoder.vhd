library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity DECODER_SOURCE is
    Port ( 
        I : in STD_LOGIC_VECTOR (1 downto 0);  -- 2-bit input
        Y : out STD_LOGIC_VECTOR (3 downto 0)  -- 4-bit output
    );
end DECODER_SOURCE;

architecture dataflow of DECODER_SOURCE is
begin
    Y(0) <= '1' when I = "00" else '0';  -- Output 0 for input "00"
    Y(1) <= '1' when I = "01" else '0';  -- Output 1 for input "01"
    Y(2) <= '1' when I = "10" else '0';  -- Output 2 for input "10"
    Y(3) <= '1' when I = "11" else '0';  -- Output 3 for input "11"
end dataflow;

--Testbench--
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity decoder_tb is
end entity;

architecture tb of decoder_tb is
    component DECODER_SOURCE is
        Port ( 
            I : in STD_LOGIC_VECTOR (1 downto 0);  -- 2-bit input
            Y : out STD_LOGIC_VECTOR (3 downto 0)  -- 4-bit output
        );
    end component;

    signal I : STD_LOGIC_VECTOR (1 downto 0);  -- 2-bit input
    signal Y : STD_LOGIC_VECTOR (3 downto 0);  -- 4-bit output

begin
    uut: DECODER_SOURCE port map (
        I => I,
        Y => Y
    );

    stim: process
    begin
        -- Apply test inputs
        I <= "00";  -- Test case 1
        wait for 20 ns;
        
        I <= "01";  -- Test case 2
        wait for 20 ns;
        
        I <= "10";  -- Test case 3
        wait for 20 ns;
        
        I <= "11";  -- Test case 4
        wait for 20 ns;
        
        wait;  -- Wait indefinitely after all tests
    end process;

end tb;
