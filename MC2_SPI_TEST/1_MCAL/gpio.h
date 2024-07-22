/******************************************************************************
 * File: goio.h
 * Description: This is the header file of GPIO driver for ATmega32
 * Author: Hussein El-Shamy
 ******************************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

/********************************************************************************
*						INCLUDING NECESSARY HEADER FILES						*
********************************************************************************/

#include "../4_Common/Platform_Config.h"

/********************************************************************************
*						DEFINTIONS and STATIC CONFIGURATION 					*
********************************************************************************/

#define NUM_OF_PORTS 			4
#define NUM_OF_PINS_PER_PORT 	8

#define PORTA_ID				0
#define PORTB_ID				1
#define PORTC_ID				2
#define PORTD_ID				3

#define PIN0_ID					0
#define PIN1_ID					1
#define PIN2_ID					2
#define PIN3_ID					3
#define PIN4_ID					4
#define PIN5_ID					5
#define PIN6_ID					6
#define PIN7_ID					7

/*********************************************************************************
 *                               Types Declaration                               *
 ********************************************************************************/

typedef enum{
	PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirectionType;

typedef enum{
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;

/*********************************************************************************
 *                              Functions Prototypes                             *
 ********************************************************************************/

/**
 * @brief Configures the direction of a specified pin.
 *
 * @param[in] port_num The port number to which the pin belongs.
 * @param[in] pin_num The pin number to be configured.
 * @param[in] direction The direction to be set (input or output).
 */
void GPIO_setupPinDirection(uint8_t port_num, uint8_t pin_num, GPIO_PinDirectionType direction);

/**
 * @brief Writes a value to a specified pin.
 *
 * @param[in] port_num The port number to which the pin belongs.
 * @param[in] pin_num The pin number to be written to.
 * @param[in] value The value to be written to the pin (high or low).
 */
void GPIO_writePin(uint8_t port_num, uint8_t pin_num, uint8_t value);

/**
 * @brief Reads the value of a specified pin.
 *
 * @param[in] port_num The port number to which the pin belongs.
 * @param[in] pin_num The pin number to be read.
 *
 * @return The current value of the pin (high or low).
 */
uint8_t GPIO_readPin(uint8_t port_num, uint8_t pin_num);

/**
 * @brief Configures the direction of all pins in a specified port.
 *
 * @param[in] port_num The port number to be configured.
 * @param[in] direction The direction to be set for the port (input or output).
 */
void GPIO_setupPortDirection(uint8_t port_num, GPIO_PortDirectionType direction);

/**
 * @brief Writes a value to all pins in a specified port.
 *
 * @param[in] port_num The port number to which the value will be written.
 * @param[in] value The value to be written to the port.
 */
void GPIO_writePort(uint8_t port_num, uint8_t value);

/**
 * @brief Reads the value of all pins in a specified port.
 *
 * @param[in] port_num The port number to be read.
 *
 * @return The current value of the port.
 */
uint8_t GPIO_readPort(uint8_t port_num);


#endif /* GPIO_H_ */
