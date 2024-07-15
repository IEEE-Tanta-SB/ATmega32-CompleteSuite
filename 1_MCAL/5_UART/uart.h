/*
 * UART.h
 *
 * Created: 14/07/2024 7:52:41 PM
 *  Author: MAI
 */


#ifndef UART_H_
#define UART_H_


/*******************************************
			 Section :INCLUDES
*******************************************/
#include "../4_Common/Platform_Config.h"

/******************************************************************
				Section :Macro Configuration References
******************************************************************/
#define DefaultStop  '\r'

/******************************************************************
				Section :APIS supported by "UART driver"
******************************************************************/
void UART_Init(uint32_t baud_rate);

void UART_Send(uint8_t data);
uint8_t UART_Recieve(void);

void UART_SendNumberU32(uint32_t num);
uint32_t UART_RecieveNumberU32(void);

void UART_SendString(uint8_t* str);
void UART_RecString(uint8_t* Buff);

#endif /* UART_H_ */
