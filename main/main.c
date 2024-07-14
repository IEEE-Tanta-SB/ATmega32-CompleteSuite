#include "1_MCAL/uart.h"

int main(void)
{
	uint8_t Str[20];
	uint8_t data;

	/* Initialize the UART driver with Baud-rate = 9600 bits/sec */
	UART_Init(9600);

    while(1)
    {
		data = UART_Recieve(); /* Receive Byte from Terminal */
		UART_Send(data);       /* Re-send the received byte to Terminal */
//		UART_RecString(Str);     /* Receive String from Terminal */
//	    UART_SendString(Str);        /* Re-send the string to Terminal */
    }
}
