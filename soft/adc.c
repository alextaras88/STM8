#include "adc.h"

/******************************************************************************/
void adc_Init(unsigned char ch){
  
  CLK_PCKENR2_bit.PCKEN20 = 1;          // ADC1 Clock
  ADC1_CR1_bit.ADON = 1;                // ADC1 ON
  ADC1_CR1_bit.RES = 0;                 // 0-12 bit, 1-10 bit, 2-8 bit, 3-6 bit
  ADC1_SQR1_bit.DMAOFF = 1;             // DMA OFF
  ADC1_SQR4 = (1<<ch);                  // ADC Channel , PA6
  
}
/******************************************************************************/
unsigned int adc_GetValue(void){
  
  unsigned int value = 0;

  ADC1_CR1_bit.START = 1;               // Start Conversion
  while ((ADC1_SR && ADC1_SR_EOC) == 0);// Wait Conversion
  
  value = ADC1_DRH<<8;
  value = value|ADC1_DRL;
  
  return value;
}
/******************************************************************************/

