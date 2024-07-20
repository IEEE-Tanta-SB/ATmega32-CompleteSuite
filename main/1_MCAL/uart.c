/******************************************************************************
 * File: uart.c
 * Description: This file contains the implementation of UART driver for ATmega32
 * Author: Mai Farahat
 ******************************************************************************/


/*******************************************
 *           Section : INCLUDES
 *******************************************/
#include "uart.h"

/******************************************************************
 *           Section : APIS supported by "UART driver"
 ******************************************************************/

/**
 * @brief Initializes the UART with the specified baud rate.
 *
 * @param[in] baud_rate The desired baud rate for UART communication.
 *
 * This function configures the UART baud rate, frame format (default 8-bit data, no parity),
 * and enables the UART transmitter and receiver.
 */
void UART_Init(uint32_t baud_rate)
{
    // Calculate the UBRR value for the given baud rate
    uint16_t ubrr_value = (uint16_t)(((F_CPU / (baud_rate * 16UL))) - 1);

    // Set the UBRR value for the baud rate
    UBRRH = (ubrr_value >> 8);
    UBRRL = (uint8_t)ubrr_value;

    // Set normal mode (U2X = 0)
    CLEAR_BIT(UCSRA, U2X);

    // Configure frame format (No parity, 8-bit data by default)

    // Enable UART transmitter and receiver
    SET_BIT(UCSRB, TXEN);
    SET_BIT(UCSRB, RXEN);
}

/**
 * @brief Sends a single byte of data over UART.
 *
 * @param[in] data The byte of data to be sent.
 *
 * This function waits until the UART data register is empty and then sends the data.
 */
void UART_Send(uint8_t data)
{
    // Wait for the transmit buffer to be empty
    while (!READ_BIT(UCSRA, UDRE));
    // Send the data byte
    UDR = data;
}

/**
 * @brief Receives a single byte of data from UART.
 *
 * @return The received byte of data.
 *
 * This function waits until data is received and then returns the received byte.
 */
uint8_t UART_Recieve(void)
{
    // Wait for data to be received
    while (!READ_BIT(UCSRA, RXC));
    // Return the received byte from the UART data register
    return UDR;
}

/**
 * @brief Sends a 32-bit unsigned integer over UART.
 *
 * @param[in] num The 32-bit unsigned integer to be sent.
 *
 * This function sends the integer as four separate bytes over UART.
 */
void UART_SendNumberU32(uint32_t num)
{
    uint8_t *p = (uint8_t *)&num;
    UART_Send(p[0]);
    UART_Send(p[1]);
    UART_Send(p[2]);
    UART_Send(p[3]);
}

/**
 * @brief Receives a 32-bit unsigned integer from UART.
 *
 * @return The received 32-bit unsigned integer.
 *
 * This function receives four bytes from UART and combines them into a 32-bit integer.
 */
uint32_t UART_RecieveNumberU32(void)
{
    uint32_t num;
    uint8_t *p = (uint8_t *)&num;
    p[0] = UART_Recieve();
    p[1] = UART_Recieve();
    p[2] = UART_Recieve();
    p[3] = UART_Recieve();
    return num;
}

/**
 * @brief Sends a null-terminated string over UART.
 *
 * @param[in] str Pointer to the null-terminated string to be sent.
 *
 * This function sends each character of the string until it encounters the end of the string,
 * followed by the default stop character.
 */
void UART_SendString(uint8_t* str)
{
    uint8_t i;
    for (i = 0; str[i] != '\0'; i++)
    {
        UART_Send(str[i]);
    }
    UART_Send(DefaultStop);
}

/**
 * @brief Receives a string from UART.
 *
 * @param[out] Buff Pointer to the buffer where the received string will be stored.
 *
 * This function receives characters from UART until it encounters the default stop character,
 * then appends a null terminator to the end of the string.
 */
void UART_RecString(uint8_t* Buff)
{
    uint8_t i = 0;
    Buff[i] = UART_Recieve();
    while (Buff[i] != DefaultStop)
    {
        i++;
        Buff[i] = UART_Recieve();
    }
    Buff[i] = '\0';
}
