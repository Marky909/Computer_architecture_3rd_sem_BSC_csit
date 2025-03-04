-- VHDL code for Parity Checker

-- Header file declaration

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

-- Entity declaration

ENTITY parity IS
    PORT (
        IE : IN STD_LOGIC; -- Even input IE active high
        IO : IN STD_LOGIC; -- Odd input IO active high
        OE : OUT STD_LOGIC; -- Even output OE active high
        OO : OUT STD_LOGIC; -- Odd output OO active high
        D : IN STD_LOGIC_VECTOR(3 DOWNTO 0));
END ENTITY;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE parity_arch OF parity IS
    SIGNAL TEMP : STD_LOGIC;
BEGIN
    TEMP <= D(0) XOR D(1) XOR D(2) XOR D(3);
    OE <= TEMP XOR IE;
    OO <= TEMP XOR IO;
END parity_arch;