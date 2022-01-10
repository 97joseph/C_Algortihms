----------------------------------------------------------------------------------
-- Engineer: Dillon Pinto
-- 
-- Create Date: 02/10/2018 01:25:16 PM
-- Design Name: ALU
-- Module Name: ALU - Behavioral

-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;




entity ALU is
    Port ( A      : in STD_LOGIC_VECTOR (7 downto 0);
           B      : in STD_LOGIC_VECTOR (7 downto 0);
           SEL    : in STD_LOGIC_VECTOR (3 downto 0);
           Cin    : in STD_LOGIC;
           RESULT : out STD_LOGIC_VECTOR (7 downto 0);
           C      : out STD_LOGIC;
           Z      : out STD_LOGIC);
end ALU;

architecture Behavioral of ALU is



begin

    proc : process(SEL,A,B,Cin)
    variable tempVar : std_logic_vector(8 downto 0):= "000000000";
    
    
    begin
    
        case(SEL) is
        
        --ADD
         when "0000" =>
            tempVar := ('0' & A) + ('0' & B);
            
         --ADDC   
         when "0001" =>
            tempVar := ('0' & A) + ('0' & B) + (x"00" & Cin);
         
         
         --sub
         when "0010" =>
            tempVar := ('0' & A) - ('0' & B);
         --subc
         when "0011" =>
            tempVar := ('0' & A) - ('0' & B) - (x"00" & Cin);
         
         --cmp 
         when "0100" =>
            tempVar := ('0' & A) - ('0' & B);
         
         --and
         when "0101" =>
            tempVar := ('0' & A) AND ('0' & B);
         
         --or
         when "0110" =>
            tempVar := ('0' & A) OR ('0' & B);
         
         --exor
         when "0111" =>
              tempVar := ('0' & A) XOR ('0' & B);
       
         --test
         when "1000" =>
            tempVar := ('0' & A) AND ('0' & B);
         
         
         
         -- lsl
         when "1001" =>
            tempVar :=  (A(7 downto 0)) & cin;

         
         
         --lsr
         when "1010" =>
            tempVar := A(0)& Cin & (A(7 downto 1));
            
            
         --rol
         when "1011" =>
            tempVar := A(7)& (A(6 downto 0)) & A(7);
         
         
         
         
         --ror
         when "1100" =>
            tempVar := A(0)& A(0) & (A(7 downto 1));
         
         
         
         
         --asr
         when "1101" => 
            tempVar := A(0)& A(7) & A(7) & (A(6 downto 1));
            
         
         
         
         --mov
         when "1110" =>
             tempVar := (Cin & B);
        
         
         --not used  sel="1111"
         when others =>
            --do nothing
         
         
         
         
        
        end case;
        
        
        C <= tempVar(8);
        
        if tempVar(7 downto 0) = x"00" then
            Z <= '1';
            
        else
            Z <= '0';
        
        end if;
        
        result <= tempVar(7 downto 0);
    end process;


end Behavioral;
