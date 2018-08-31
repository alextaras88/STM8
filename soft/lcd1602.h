#pragma once

#include "main.h"

/******************************************************************************/
#define A0_LOW          PE_ODR &= ~MASK_PE_ODR_ODR0;
#define A0_HIGH         PE_ODR |= MASK_PE_ODR_ODR0;

#define E_LOW           PE_ODR &= ~MASK_PE_ODR_ODR1;
#define E_HIGH          PE_ODR |= MASK_PE_ODR_ODR1;

#define D04_LOW         PE_ODR &= ~MASK_PE_ODR_ODR2;
#define D04_HIGH        PE_ODR |= MASK_PE_ODR_ODR2;

#define D05_LOW         PE_ODR &= ~MASK_PE_ODR_ODR3;
#define D05_HIGH        PE_ODR |= MASK_PE_ODR_ODR3;

#define D06_LOW         PE_ODR &= ~MASK_PE_ODR_ODR4;
#define D06_HIGH        PE_ODR |= MASK_PE_ODR_ODR4;

#define D07_LOW         PE_ODR &= ~MASK_PE_ODR_ODR5;
#define D07_HIGH        PE_ODR |= MASK_PE_ODR_ODR5;
/******************************************************************************/
void lcd1602_GPIOInit(void);
void lcd1602_WriteData(unsigned char data);
void lcd1602_Command(unsigned char data);
void lcd1602_Data(unsigned char data);
void lcd1602_Init(void);
void lcd1602_Clear(void);

void lcd1602_SendChar(char data);
void lcd1602_String (char* str);
void lcd1602_SetPos(unsigned char x, unsigned char y);

void lcd1602_DataString(uint32_t data);
/******************************************************************************/