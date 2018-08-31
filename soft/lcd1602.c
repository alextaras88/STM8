#include "lcd1602.h"
/******************************************************************************/

/******************************************************************************/
void lcd1602_GPIOInit(void){
  
  // PE0 - OutPut  A0
  PE_DDR_bit.DDR0 = 1;          // PE0 - OutPut
  PE_CR1_bit.C10 = 1;           // Push-Pull
  PE_CR2_bit.C20 = 1;           // Speed to 10 MHz
  
  // PE1 - OutPut  E
  PE_DDR_bit.DDR1 = 1;          // PE1 - OutPut
  PE_CR1_bit.C11 = 1;           // Push-Pull
  PE_CR2_bit.C21 = 1;           // Speed to 10 MHz
  
  // PE2 - OutPut  D04
  PE_DDR_bit.DDR2 = 1;          // PE2 - OutPut
  PE_CR1_bit.C12 = 1;           // Push-Pull
  PE_CR2_bit.C22 = 1;           // Speed to 10 MHz
  
  // PE3 - OutPut  D05 
  PE_DDR_bit.DDR3 = 1;          // PE3 - OutPut
  PE_CR1_bit.C13 = 1;           // Push-Pull
  PE_CR2_bit.C23 = 1;           // Speed to 10 MHz
  
  // PE4 - OutPut  D06
  PE_DDR_bit.DDR4 = 1;          // PE4 - OutPut
  PE_CR1_bit.C14 = 1;           // Push-Pull
  PE_CR2_bit.C24 = 1;           // Speed to 10 MHz
  
  // PE5 - OutPut  D07
  PE_DDR_bit.DDR5 = 1;          // PE5 - OutPut
  PE_CR1_bit.C15 = 1;           // Push-Pull
  PE_CR2_bit.C25 = 1;           // Speed to 10 MHz


}
/******************************************************************************/
void lcd1602_WriteData(unsigned char data){
   
  if(((data >> 3)&0x01)==1) {D07_HIGH;} else {D07_LOW;}
  if(((data >> 2)&0x01)==1) {D06_HIGH;} else {D06_LOW;}
  if(((data >> 1)&0x01)==1) {D05_HIGH;} else {D05_LOW;}
  if((data&0x01)==1) {D04_HIGH;} else {D04_LOW;}

}
/******************************************************************************/
void lcd1602_Command(unsigned char data){
  
   A0_LOW;
   lcd1602_WriteData(data>>4);
   E_HIGH;
   delay_us(15);
   E_LOW;
   lcd1602_WriteData(data);
   E_HIGH;
   delay_us(15);
   E_LOW;

}
/******************************************************************************/
void lcd1602_Data(unsigned char data){
  
   A0_HIGH;
   lcd1602_WriteData(data>>4);
   E_HIGH;
   delay_us(15);
   E_LOW;
   lcd1602_WriteData(data);
   E_HIGH;
   delay_us(15);
   E_LOW;
}
/******************************************************************************/
void lcd1602_Init(void){
  
  lcd1602_GPIOInit();
  
  delay_ms(200);
  lcd1602_WriteData(0x30);
  E_HIGH;
  delay_us(15);
  E_LOW;
  delay_ms(2);
  lcd1602_WriteData(0x30);
  E_HIGH;
  delay_us(15);
  E_LOW;
  delay_ms(2);
  lcd1602_WriteData(0x30);
  E_HIGH;
  delay_us(15);
  E_LOW;
  delay_ms(2);
  
  lcd1602_WriteData(0x20);
  E_HIGH;
  delay_us(15);
  E_LOW;
  delay_ms(2);
  
  lcd1602_Command(0x28);
  delay_ms(2);
  lcd1602_Command(0x0C);
  delay_ms(2);
  lcd1602_Command(0x01);
  delay_ms(2);
  lcd1602_Command(0x06);
  delay_ms(2);
  lcd1602_Command(0x02);
  delay_ms(2);
  
}
void lcd1602_Clear(void){
  
  lcd1602_Command(0x01);
  delay_ms(4);
  
}
/******************************************************************************/
void lcd1602_SendChar(char data){
  
  lcd1602_Data((char) data);
  delay_us(10);
  
}
/******************************************************************************/
void lcd1602_String (char *str){
  
  unsigned char i = 0;
  
  while(str[i])
  lcd1602_SendChar(str[i++]);
  
}
/******************************************************************************/
void lcd1602_SetPos(unsigned char x, unsigned char y){

  switch(y){
    
    case 0:
      lcd1602_Command(x|0x80);
      delay_ms(2);
      break;

    case 1:
      lcd1602_Command((0x40+x)|0x80);
      delay_ms(2);
      break;

    case 2:
      lcd1602_Command((0x14+x)|0x80);
      delay_ms(2);
      break;

    case 3:
      lcd1602_Command((0x54+x)|0x80);
      delay_ms(2);
      break;

        }

}
/******************************************************************************/
void lcd1602_DataString(uint32_t  data){
  
  lcd1602_SendChar((data%100000000)/10000000 + 0x30);
  lcd1602_SendChar((data%10000000)/1000000 + 0x30);
  lcd1602_SendChar((data%1000000)/100000 + 0x30);
  lcd1602_SendChar((data%100000)/10000 + 0x30);
  lcd1602_SendChar((data%10000)/1000 + 0x30);
  lcd1602_SendChar((data%1000)/100 + 0x30);
  lcd1602_SendChar((data%100)/10 + 0x30);
  lcd1602_SendChar(data%10 + 0x30);

}
/******************************************************************************/