library ieee;
use ieee.std_logic_1164.all;

entity parity_chk_tb is
end parity_chk_tb;

architecture testbench of parity_chk_tb is
    signal data : bit_vector(7 downto 0);
    signal p : bit;
    signal e : bit;

    component parity_chk
        port ( data : in bit_vector(7 downto 0);
               p : in bit;
               e : out bit);
    end component;

begin
    DUT: parity_chk port map (data, p, e);

    process
    begin
        -- Case 1: Even Parity with Correct Parity Bit
        data <= "10101010";  -- 4 ones => Even Parity
        p <= '0';           -- Even Parity
        wait for 10 ns;

        -- Case 2: Even Parity with Wrong Parity Bit
        data <= "10101010";  
        p <= '1';           -- Wrong Parity Bit
        wait for 10 ns;

        -- Case 3: Odd Parity with Correct Parity Bit
        data <= "11010101";  -- 5 ones => Odd Parity
        p <= '1';           -- Odd Parity
        wait for 10 ns;

        -- Case 4: Odd Parity with Wrong Parity Bit
        data <= "11010101";
        p <= '0';           -- Wrong Parity Bit
        wait for 10 ns;

        -- Stop Simulation
        wait;
    end process;
end testbench;
