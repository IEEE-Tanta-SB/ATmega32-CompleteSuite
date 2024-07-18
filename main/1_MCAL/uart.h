/******************************************************************************
 * File: uart.h
 * Description: This is the header file of UART driver for ATmega32
 * Author: Mai Farahat
 ******************************************************************************/

#ifndef UART_H_
#define UART_H_

/*******************************************
 *           Section : INCLUDES
 *******************************************/
#include "../4_Common/Platform_Config.h"

/******************************************************************
 *           Section : Macro Configuration References
 ******************************************************************/

#define DefaultStop  '\r' /**< Default stop character used in UART communication. */

/******************************************************************
 *           Section : APIS supported by "UART driver"
 ******************************************************************/

/**
 * @brief Initializes the UART with the specified baud rate.
 *
 * @param[in] baud_rate The desired baud rate for UART communication.
 */
void UART_Init(uint32_t baud_rate);

/**
 * @brief Sends a single byte of data over UART.
 *
 * @param[in] data The byte of data to be sent.
 */
void UART_Send(uint8_t data);

/**
 * @brief Receives a single byte of data from UART.
 *
 * @return The received byte of data.
 */
uint8_t UART_Recieve(void);

/**
 * @brief Sends a 32-bit unsigned integer over UART.
 *
 * @param[in] num The 32-bit unsigned integer to be sent.
 */
void UART_SendNumberU32(uint32_t num);

/**
 * @brief Receives a 32-bit unsigned integer from UART.
 *
 * @return The received 32-bit unsigned integer.
 */
uint32_t UART_RecieveNumberU32(void);

/**
 * @brief Sends a string over UART.
 *
 * @param[in] str Pointer to the null-terminated string to be sent.
 */
void UART_SendString(uint8_t* str);

/**
 * @brief Receives a string from UART.
 *
 * @param[out] Buff Pointer to the buffer where the received string will be stored.
 */
void UART_RecString(uint8_t* Buff);

#endif /* UART_H_ */
