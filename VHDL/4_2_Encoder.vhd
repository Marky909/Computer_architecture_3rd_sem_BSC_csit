--Design
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ENCODER_SOURCE is
    Port ( 
        I : in STD_LOGIC_VECTOR (3 downto 0);
        Y : out STD_LOGIC_VECTOR (1 downto 0)
    );
end ENCODER_SOURCE;

architecture dataflow of ENCODER_SOURCE is
begin
    Y(0) <= I(1) or I(3);  -- Output bit 0 depends on inputs I(1) or I(3)
    Y(1) <= I(2) or I(3);  -- Output bit 1 depends on inputs I(2) or I(3)
end dataflow;

--Testbench--

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity encoder_tb is
end entity;

architecture tb of encoder_tb is
    component ENCODER_SOURCE is
        Port ( 
            I : in STD_LOGIC_VECTOR (3 downto 0);
            Y : out STD_LOGIC_VECTOR (1 downto 0)
        );
    end component;

    signal I : STD_LOGIC_VECTOR (3 downto 0);
    signal Y : STD_LOGIC_VECTOR (1 downto 0);

begin
    uut: ENCODER_SOURCE port map (
        I => I,
        Y => Y
    );

    stim: process
    begin
        -- Apply test inputs
        I <= "0001";  -- Test case 1
        wait for 20 ns;
        
        I <= "0010";  -- Test case 2
        wait for 20 ns;
        
        I <= "0100";  -- Test case 3
        wait for 20 ns;
        
        I <= "1000";  -- Test case 4
        wait for 20 ns;
        
        wait;  -- Wait indefinitely after all tests
    end process;

end tb;
