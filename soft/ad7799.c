#include "ad7799.h"

/******************************************************************************/
void ad7799_Reset(void){
  
  delay_ms(1);
  SPI_CS_LOW;
  spi_write_data(0xFF);
  spi_write_data(0xFF);
  spi_write_data(0xFF);
  spi_write_data(0xFF);
  SPI_CS_HIGH;
  delay_ms(500);
  
}
/******************************************************************************/
void ad7799_Init(void){
  
  SPI_CS_HIGH;
  
  delay_ms(200);
	
  ad7799_Reset();
  delay_ms(50);
	
  SPI_CS_LOW;
  delay_ms(1);
  spi_write_data(0x00);		// mode reg 0x000A
  spi_write_data(0x0A);
  delay_ms(1);
  spi_write_data(0x00);
  //spi_write_data(0x09); 	  //fADC = 16.6 Hz, 50 Hz only
  spi_write_data(0x0F); 		//fADC = 4.17 Hz
  //spi_write_data(0x05);		//fADC = 50 Hz
  //spi_write_data(0x0C);		//fADC = 10 Hz
  SPI_CS_HIGH;

}
/******************************************************************************/
uint32_t ad7799_get_data(void){
	
  unsigned char b1 = 0x00, b2 = 0x00, b3 = 0x00;
  uint32_t value = 0;
	
  SPI_CS_LOW;
  while((PB_IDR & MASK_PB_IDR_IDR7)!=0);
  spi_write_data(0x58);
  b1 = spi_read_data(0x00);
  b2 = spi_read_data(0x00);
  b3 = spi_read_data(0x00);
  SPI_CS_HIGH;
  
  value += ((uint32_t)b2<<16);
  value += ((uint32_t)b3<<8);
  value += ((uint32_t)b1<<0);
 
	
  return value;
	
}
/******************************************************************************/
void ad7799_set_ch_1(void){
  
  SPI_CS_LOW;
  delay_ms(1);
  spi_write_data(0x07);     // 0x0710 CONFIGURATION REGISTER 
  spi_write_data(0x10);
  delay_ms(1);
  spi_write_data(0x4F);
  spi_write_data(0x90);   
  SPI_CS_HIGH;
	
}
/******************************************************************************/
void ad7799_set_ch_2(void){
  
  SPI_CS_LOW;
  delay_ms(1);
  spi_write_data(0x07);     // 0x0710 CONFIGURATION REGISTER 
  spi_write_data(0x10);
  delay_ms(1);
  spi_write_data(0x4F);
  spi_write_data(0x91);   
  SPI_CS_HIGH;
	
}
/******************************************************************************/
void ad7799_set_ch_3(void){
  
  SPI_CS_LOW;
  delay_ms(1);
  spi_write_data(0x07);     // 0x0710 CONFIGURATION REGISTER 
  spi_write_data(0x10);
  delay_ms(1);
  spi_write_data(0x4F);
  spi_write_data(0x92);   
  SPI_CS_HIGH;
	
}
/******************************************************************************/
