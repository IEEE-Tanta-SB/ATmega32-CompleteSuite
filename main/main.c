/******************************************************************************
 * File: main.c
 * Description: This file contains the main function, which serves as the entry
 *              point for the program.
 ******************************************************************************/
#include "1_MCAL/twi.h"
#include "1_MCAL/uart.h"

#define EEPROM_ADDRESS 0x50

void EEPROM_WriteByte(uint8_t addr, uint8_t data);
uint8_t EEPROM_ReadByte(uint8_t addr);

int main(void)
{
    uint8_t data_written = 10;
    uint8_t data_read;

    // Initialize UART for debugging
    UART_Init(9600);

    // Initialize I2C as master
    TWI_MasterInit(PRESCALER_1);

    // Write data to EEPROM
    EEPROM_WriteByte(0x00, data_written);

    // Read data back from EEPROM
    data_read = EEPROM_ReadByte(0x00);
    // Transmit the read data over UART for verification
    UART_Send(data_read);

    while (1)
    {


    }

    return 0;
}

void EEPROM_WriteByte(uint8_t addr, uint8_t data)
{
    TWI_Start();
    TWI_SendSlaveAddWithW(EEPROM_ADDRESS);
    TWI_MasterWriteData(addr);
    TWI_MasterWriteData(data);
    TWI_Stop();
}

uint8_t EEPROM_ReadByte(uint8_t addr)
{
    uint8_t data;

    TWI_Start();

    TWI_SendSlaveAddWithW(EEPROM_ADDRESS);



    TWI_MasterWriteData(addr);



    TWI_RepeatStart();



    TWI_SendSlaveAddWithR(EEPROM_ADDRESS);
    data = TWI_MasterReadData();
    TWI_Stop();

    return data;
}
