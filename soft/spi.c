#include "spi.h"

/******************************************************************************/
void gpio_spi_Init(void){

  // Pins REMAP = 0
  PB_DDR_DDR5 = 1; PB_CR1_C15 = 1; PB_CR2_C25 = 1;     // SCK  - PB5
  PB_DDR_DDR6 = 1; PB_CR1_C16 = 1; PB_CR2_C26 = 1;     // MOSI - PB6
  PB_DDR_DDR7 = 0; PB_CR1_C17 = 0; PB_CR2_C27 = 0;     // MISO - PB7
  PB_DDR_DDR4 = 1; PB_CR1_C17 = 1; PB_CR2_C27 = 1;     // CS   - PB4 
  
  // Pins REMAP = 1   ONLY NO EXTERNAL CRYSTAL !!! PA2, PA3 - OSC PINS!!!
  
//  PC_DDR_DDR6 = 1; PC_CR1_C16 = 1; PC_CR2_C26 = 1;     // SCK  - PC6
//  PA_DDR_DDR3 = 1; PA_CR1_C13 = 1; PA_CR2_C23 = 1;     // MOSI - PA3
//  PA_DDR_DDR2 = 0; PA_CR1_C12 = 0; PA_CR2_C22 = 0;     // MISO - PA2
//  PC_DDR_DDR5 = 1; PC_CR1_C15 = 1; PC_CR2_C25 = 1;     // CS   - PC5 
 
 
}
/******************************************************************************/
void spi_Init(void){
  
  gpio_spi_Init();
  
  SYSCFG_RMPCR1_bit.SPI1_REMAP = 0;     // SYSCFG remap control register
  
  CLK_PCKENR1_bit.PCKEN14;              // Clock SPI1   
  SPI1_CR1_bit.BR = 0x04;               // BR[2:0]: Baud rate control fSYSCLK/32
  SPI1_CR1_bit.CPOL = 1;                // CPOL 
  SPI1_CR1_bit.CPHA = 1;                // CPHA
  SPI1_CR1_bit.LSBFIRST = 0;            // MSBFIRST
  SPI1_CR2_bit.SSM = 1;                 // SSM: Software slave management enabled
  SPI1_CR2_bit.SSI = 1;                 // SSI: Internal slave select                
  SPI1_CR1_bit.MSTR = 1;                // Master configuration
  SPI1_CR2_bit.BDM = 0;                 // 2 Line SPI
  SPI1_CR2_bit.RXONLY = 0;              // Full duplex
   
  SPI1_CR1_bit.SPE = 1;                  // SPI Enable

}
/******************************************************************************/
void spi_write_data(unsigned char data){
  
  while((SPI1_SR_TXE)!=1){};
  SPI1_DR = data; 
  while((SPI1_SR_BSY)!=0){};
  
}
/******************************************************************************/
unsigned char spi_read_data(unsigned char data){
  
  unsigned char dat = 0;
  
  while((SPI1_SR_TXE)!=1){};
  SPI1_DR = data; 
  while((SPI1_SR_RXNE)!=1){};
  dat = SPI1_DR;
  while((SPI1_SR_BSY)!=0){};

  return dat;

}
/******************************************************************************/
void spi_write_buffer(unsigned char *buff, unsigned char n){
  
  unsigned int i = 0;
  
  for(i = 0; i<n; i++){
    
    spi_write_data(buff[i]);
  
  }

}
/******************************************************************************/