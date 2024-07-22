/******************************************************************************
 * File: main.c
 * Description: This file contains the main function, which serves as the entry
 *              point for the program.
 ******************************************************************************/
#include "1_MCAL/spi.h"

int main(void)
{


    SPI_VoidInit(SPI_ENABLE, SPI_MASTER, SPI_DATA_MSP_FIRST, SPI_INTERRUPT_ENABLE);
    SPI_CLK_VoidInit(SPI_RISING_LEADING_FALLING_TRAILING,SPI_SETUP_LEADING_SAMPLE_TRAILING, SPI_FREQ_DIVIDED_BY_16);


    uint8_t dataSend = 0x12;
        uint8_t receivedData;

        while (1)
        {
            SPI_uint8_tTranceive(dataSend, &receivedData);
            _delay_ms(1000);
        }
    return 0;
}
