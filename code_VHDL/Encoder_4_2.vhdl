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
