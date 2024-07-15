/*
 * atmega32_memoryMap.h
 *
 *  Created: 9/4/2023 7:07:46 PM
 *  Author: Mohamed Belal
 */ 

#ifndef ATMEGA32_MEMORYMAP_H_
#define ATMEGA32_MEMORYMAP_H_
#include "Platform_Types.h"



/*  
 * =============================================
 *                     GPIOA 
 * =============================================
 */
#define  PORTA			*(volatile uint8_t *)(0x3B)
#define  DDRA			*(volatile uint8_t *)(0x3A)
#define  PINA			*(volatile uint8_t *)(0x39)


/*  
 * =============================================
 *                     GPIOB 
 * =============================================
 */
#define  PORTB			*(volatile uint8_t *)(0x38)
#define  DDRB			*(volatile uint8_t *)(0x37)
#define  PINB			*(volatile uint8_t *)(0x36)


/*  
 * =============================================
 *                     GPIOC 
 * =============================================
 */
#define  PORTC			*(volatile uint8_t *)(0x35)
#define  DDRC			(*(volatile uint8_t *)(0x34))
#define  PINC			*(volatile uint8_t *)(0x33)



/*  
 * =============================================
 *                     GPIOD 
 * =============================================
 */
#define  PORTD			*(volatile uint8_t *)(0x32)
#define  DDRD			*(volatile uint8_t *)(0x31)
#define  PIND			*(volatile uint8_t *)(0x30)



/*  
 * =============================================
 *                     TIMER0 
 * =============================================
 */
#define  TCCRO			*(volatile uint8_t *)(0x53)
#define  CS00			0
#define  CS01			1
#define  CS02			2
#define  WGM01			3
#define  COM00			4
#define  COM01			5
#define  WGM00			6
#define  FOC0			7


#define  TCNT0			*(volatile uint8_t *)(0x52)
#define  OCR0			*(volatile uint8_t *)(0x5C)

#define  TIMSK			*(volatile uint8_t *)(0x59)
#define  TOIE0			0
#define  OCIE0			1


#define  TIFR			*(volatile uint8_t *)(0x58)



/*  
 * =============================================
 *                     WatchDog 
 * =============================================
 */
#define  WDTCR			*(volatile uint8_t *)(0x41)
#define  WDP0			 (1<<0)
#define  WDP1			 (1<<1)
#define  WDP2			 (1<<2)
#define  WDE			 (1<<3)
#define  WDTOE			 (1<<4)


/*  
 * =============================================
 *                     ADC 
 * =============================================
 */
#define  ADMUX			*(volatile uint8_t *)(0x27)
#define  MUX0			0
#define  MUX1			1
#define  MUX2			2
#define  MUX3			3
#define  MUX4			4
#define  ADLAR			5
#define  REFS0			6
#define  REFS1			7

#define  ADCSRA			*(volatile uint8_t *)(0x26)
#define  ADPS0			0
#define  ADPS1			1
#define  ADPS2			2
#define  ADIE			3
#define  ADIF			4
#define  ADATE			5
#define  ADSC			6
#define  ADEN			7



#define  ADCH			*(volatile uint8_t *)(0x25)

#define  ADCL			*(volatile uint8_t *)(0x24)




/*  
 * =============================================
 *                     UART 
 * =============================================
 */
#define  UDR			*(volatile uint8_t *)(0x2C)




#define  UCSRA			*(volatile uint8_t *)(0x2B)
#define  MPCM			0
#define  U2X			1
#define  PE				2
#define  DOR			3
#define  FE				4
#define  UDRE			5
#define  TXC			6
#define  RXC			7


#define  UCSRB			*(volatile uint8_t *)(0x2A)
#define  TXB8			0
#define  RXB8			1
#define  UCSZ2			2
#define  TXEN			3
#define  RXEN			4
#define  UDRIE			5
#define  TXCIE			6
#define  RXCIE			7


#define  UBRRL			*(volatile uint8_t *)(0x29)

#define  UCSRC			*(volatile uint8_t *)(0x40)
#define  UBRRH			*(volatile uint8_t *)(0x40)
#define  UCPOL			0
#define  UCSZ0			1
#define  UCSZ1			2
#define  USBS			3
#define  UPM0			4
#define  UPM1			5
#define  UMSEL			6
#define  URSEL			7





/*  
 * =============================================
 *                     SPI 
 * =============================================
 */
#define  SPCR			*(volatile uint8_t *)(0x2D)
#define  SPR0			0
#define  SPR1			1
#define  CPHA			2
#define  CPOL			3
#define  MSTR			4
#define  DORD			5
#define  SPE			6
#define  SPIE			7


#define  SPSR			*(volatile uint8_t *)(0x2E)
#define  SPI2X			0
#define  WCOL			6
#define  SPIF			7



#define  SPDR			*(volatile uint8_t *)(0x2F)






/*  
 * =============================================
 *                     I2C 
 * =============================================
 */

#define TWBR			(*(volatile uint8_t *)(0x20))

#define TWCR			(*(volatile uint8_t *)(0x56))
#define TWIE			0

#define TWEN			2
#define TWWC			3
#define TWSTO			4
#define TWSTA			5
#define TWEA			6
#define TWINT			7



#define TWSR			(*(volatile uint8_t *)(0x21))
#define TWPS0			0
#define TWPS1			1

#define TWS3			3
#define TWS4			4
#define TWS5			5
#define TWS6			6
#define TWS7			7


#define TWDR			(*(volatile uint8_t *)(0x23))
#define TWAR			(*(volatile uint8_t *)(0x22))





// -----------------------------------------------------------------------



#define  UDR			*(volatile uint8_t *)(0x2C)

#define  UCSRA			*(volatile uint8_t *)(0x2B)
#define  U2X			1							// Double the USART Transmission Speed
#define  UDRE			5							//  USART Data Register Empty => The UDRE Flag indicates if the transmit buffer (UDR) is ready to receive new data
#define  RXC			7							//  USART Receive Complete => This flag bit is set when there are unread data in the receive buffer


#define  UCSRB			*(volatile uint8_t *)(0x2A)
#define  TXEN			3							// Receiver Enable
#define  RXEN			4							// Transmitter Enable
#define  UCSZ2			2							// Character Size



#define  UCSRC			*(volatile uint8_t *)(0x40)
#define  UMSEL			6							// USART Mode Select  => 0:Asynchronous Operation
#define  UPM0			4							// Parity Mode   => 0 Disabled
#define  UPM1			5							// Parity Mode   => 0 Disabled
#define  UCSZ0			1							// Character Size
#define  UCSZ1			2							// Character Size


#define  UBRRL			*(volatile uint8_t *)(0x29)
#define  UBRRH			*(volatile uint8_t *)(0x40)



#endif /* ATMEGA32_MEMORYMAP_H_ */
