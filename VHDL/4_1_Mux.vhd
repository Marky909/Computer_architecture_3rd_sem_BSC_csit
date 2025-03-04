-- Simplified 4:1 MUX Design
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;  -- Added this library for TO_INTEGER function

ENTITY mux_4to1 IS
    PORT (
        I : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        S : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
        Y : OUT STD_LOGIC
    );
END mux_4to1;

ARCHITECTURE bhv OF mux_4to1 IS
BEGIN
    Y <= I(TO_INTEGER(UNSIGNED(S)));
END bhv;

-- Minimal 4:1 MUX Testbench
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

ENTITY tb_mux_4to1 IS
END tb_mux_4to1;

ARCHITECTURE behavior OF tb_mux_4to1 IS
    COMPONENT mux_4to1 IS
        PORT (I : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
              S : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
              Y : OUT STD_LOGIC);
    END COMPONENT;
    
    SIGNAL I : STD_LOGIC_VECTOR(3 DOWNTO 0) := "1010";
    SIGNAL S : STD_LOGIC_VECTOR(1 DOWNTO 0) := "00";
    SIGNAL Y : STD_LOGIC;
    
BEGIN
    uut: mux_4to1 PORT MAP (I => I, S => S, Y => Y);

    stim: PROCESS
    BEGIN
        -- Test all select combinations once
        FOR i IN 0 TO 3 LOOP
            S <= std_logic_vector(to_unsigned(i, 2));
            WAIT FOR 10 ns;
        END LOOP;
        WAIT;
    END PROCESS;
END behavior;