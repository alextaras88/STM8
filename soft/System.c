#include "System.h"

/******************************************************************************/
void Clock_Init(void){
  
  CLK_ECKR_bit.HSEON = 1;            // Enable HSE
   
  while(CLK_ECKR_bit.HSERDY == 1) {} // Wait HSE ready
              
  CLK_CKDIVR = 0;                    // CLK Divider = 0 - 16 MHz
  
  CLK_PCKENR1 = 0xff;                // Enable all peripheral clocks.
  CLK_PCKENR2 = 0xff;                // Enable all peripheral clocks.
                                     
  CLK_SWCR_bit.SWEN = 1;             // Reset clock switch control reg.
  CLK_SWR = 0x04;                    // HSE - source CLK
  while (CLK_SWCR_bit.SWBSY == 1){}  // Wait HSE ready swiching

}
/******************************************************************************/
void CCO_Init(void){
  
  PC_DDR_bit.DDR4 = 1; // PC4 - CCO OutPut
  PC_CR1_bit.C14 = 1;
  
  CLK_CCOR_bit.CCOSEL = 0x04; // HSE Source
  
}
/******************************************************************************/
void GPIO_Init(void){
  
  //PE7 - OutPut
  PE_DDR_bit.DDR7 = 1;          // PE7 - OutPut
  PE_CR1_bit.C17 = 1;           // Push-Pull
  PE_CR2_bit.C27 = 1;           // Speed to 10 MHz
    
  //PC7 - OutPut 
  PC_DDR_bit.DDR7 = 1;          // PC7 - OutPut
  PC_CR1_bit.C17 = 1;           // Push-Pull
  PC_CR2_bit.C27 = 1;           // Speed to 10 MHz
  
  // PC1 - InPut, User Button
    
}
/******************************************************************************/