#include "usart.h"

/******************************************************************************/
void usart_Init(void){
  
  CLK_PCKENR1_bit.PCKEN15 = 1; // Usart Clock
  
  PC_DDR_bit.DDR2 = 0;         // Rx InPut pin
  PC_DDR_bit.DDR3 = 1;         // TX OutPut pin
  
  USART1_BRR2 = 0x03;          // Usart speed 9600
  USART1_BRR1 = 0x68;
  
  USART1_CR2_bit.REN=1;        // Rx Enabled
  USART1_CR2_bit.TEN=1;        // Tx Enabled
  
  USART1_CR2_RIEN=1;           // Interrupt Rx Enable, enabled interrupt main function!!!
  
  
// #pragma vector=USART_R_OR_vector
//__interrupt void USART1_RXE(void)
//{
//          you code interrupt

}
/******************************************************************************/
void usart_send_char(char c){
  
  while(!(USART1_SR_bit.TXE)); 
  USART1_DR=c;

}
/******************************************************************************/
void usart_send_string(char* str){
  
  unsigned char i = 0;
  
  while(str[i])
  usart_send_char(str[i++]);
   
}
/******************************************************************************/
  
  
  
  
  