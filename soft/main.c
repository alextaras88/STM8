#include "main.h"

uint32_t adc = 0x00000000;
char str[20];
/******************************************************************************/
int main( void ){
  
  Clock_Init();
  Delay_Init();
  GPIO_Init();
  spi_Init();
  usart_Init();
  
  ad7799_Init();
  ad7799_set_ch_1();
  
  lcd1602_Init();
  lcd1602_String("STM8L152C6T6");
  
  //PC_ODR |= MASK_PC_ODR_ODR7;
  //PE_ODR |= MASK_PE_ODR_ODR7;
  
  
  while(1){
    
    adc = ad7799_get_data();
    PE_ODR ^= MASK_PE_ODR_ODR7;
    
    
  }
}
