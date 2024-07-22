/******************************************************************************
 * File: main.c
 * Description: This file contains the main function, which serves as the entry
 *              point for the program.
 ******************************************************************************/

#include "1_MCAL/spi.h"
#include "1_MCAL/interrupt.h"

#define LED_PIN 0
void SPI_Slave_Init(void) ;


void SPI_Notification(void)
{
    if (SPI_pu8TData[0] == 0x12)
    {
        PORTC |= (1 << LED_PIN);
    }
    else
    {
        PORTC &= ~(1 << LED_PIN);
    }
}

int main(void)
{
    SPI_Slave_Init();
    sei();
    while (1)
    {

    }
}


void SPI_Slave_Init(void)
{
	 SPI_VoidInit(SPI_ENABLE, SPI_SLAVE, SPI_DATA_MSP_FIRST, SPI_INTERRUPT_ENABLE);
	    SPI_CLK_VoidInit(SPI_RISING_LEADING_FALLING_TRAILING,SPI_SETUP_LEADING_SAMPLE_TRAILING, SPI_FREQ_DIVIDED_BY_16);
    DDRC |= (1 << LED_PIN);
}
