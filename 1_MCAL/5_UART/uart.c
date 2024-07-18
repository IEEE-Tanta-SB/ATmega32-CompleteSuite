/******************************************************************************
 * File: uart.c
 * Description: This file contains the implementation of UART driver for ATmega32
 * Author: Mai Farahat
 ******************************************************************************/


/*******************************************
			 Section :INCLUDES
*******************************************/

#include"uart.h"

/******************************************************************
				Section :APIS supported by "UART driver"
******************************************************************/

void UART_Init(uint32_t baud_rate)
{

	                             /*baud rate*/

	uint16_t ubrr_value = (uint16_t)(((F_CPU / (baud_rate * 16UL))) - 1);

	UBRRH = (ubrr_value>>8);

	UBRRL = (uint8_t)ubrr_value;

	//normal mode
	CLEAR_BIT(UCSRA,U2X);

						         /*frame*/

	// No parity - 8 bit data is defined by default


						        /*Enable*/
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);

}

void UART_Send(uint8_t data)
{
	while(!READ_BIT(UCSRA,UDRE));
	UDR = data;
}
uint8_t UART_Recieve(void)
{
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
}

void UART_SendNumberU32(uint32_t num)
{
	uint8_t *p =& num;
	UART_Send(p[0]);
	UART_Send(p[1]);
	UART_Send(p[2]);
	UART_Send(p[3]);
}
uint32_t UART_RecieveNumberU32(void)
{
	uint32_t num;
	uint8_t* p =& num;
	p[0] = UART_Recieve();
	p[1] = UART_Recieve();
	p[2] = UART_Recieve();
	p[3] = UART_Recieve();
	return num;

}

void UART_SendString(uint8_t* str)
{
	uint8_t i;
	for(i=0;i<str[i];i++)
	{
		UART_Send(str[i]);
	}
	UART_Send(DefaultStop);
}
void UART_RecString(uint8_t* Buff)
{
	uint8_t i = 0;
	Buff[i] = UART_Recieve();
	while(Buff[i] != DefaultStop)
	{
		i++;
		Buff[i] = UART_Recieve();
	}
	Buff[i] = '\0';
}
