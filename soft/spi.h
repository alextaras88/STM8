#pragma once

#include "main.h"
/******************************************************************************/
// CS REMAP 0
#define SPI_CS_LOW    PB_ODR &= ~MASK_PB_ODR_ODR4;
#define SPI_CS_HIGH   PB_ODR |= MASK_PB_ODR_ODR4;

// ONLY NO EXTERNAL CRYSTAL !!! PA2, PA3 - OSC PINS!!!
//#define SPI_CS_LOW    PC_ODR &= ~MASK_PC_ODR_ODR5;
//#define SPI_CS_HIGH   PC_ODR |= MASK_PC_ODR_ODR5;
/******************************************************************************/
void gpio_spi_Init(void);
void spi_Init(void);
void spi_write_data(unsigned char data);
unsigned char spi_read_data(unsigned char data);

void spi_write_buffer(unsigned char *buff, unsigned char n);
/******************************************************************************/