/*******************************************************************************
 * File Name: gpio.h
 *
 * Description: Header file for GPIO driver for ATmega32 microcontroller.
 * Provides macros, type definitions, and function prototypes for GPIO pin and port manipulation.
 *
 * Authors: IEEE-Tanta Student Branch
 *          Hussein El-Shamy
 *
 * Last Update: 24 May 2024
 ******************************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

#include "../Common/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8

#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
    PIN_INPUT, PIN_OUTPUT
} GPIO_PinDirectionType;

typedef enum
{
    PORT_INPUT, PORT_OUTPUT = 0xFF
} GPIO_PortDirectionType;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/**
 * @brief Setup the direction of the specified pin (input/output).
 *
 * @param port_num Port number (0 to 3).
 * @param pin_num Pin number (0 to 7).
 * @param direction Direction of the pin (PIN_INPUT or PIN_OUTPUT).
 *
 * @note If the input port number or pin number is not correct, the function will not handle the request.
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction);

/**
 * @brief Write a value (Logic High/Logic Low) on the specified pin.
 *
 * @param port_num Port number (0 to 3).
 * @param pin_num Pin number (0 to 7).
 * @param value Value to write (0 or 1).
 *
 * @note If the pin is configured as input, this function will enable/disable the internal pull-up resistor.
 * @note If the input port number or pin number is not correct, the function will not handle the request.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);

/**
 * @brief Read and return the value of the specified pin.
 *
 * @param port_num Port number (0 to 3).
 * @param pin_num Pin number (0 to 7).
 *
 * @return Value of the pin (0 or 1).
 * @note If the input port number or pin number is not correct, the function will return Logic Low (0).
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num);

/**
 * @brief Setup the direction of all pins in the specified port (input/output).
 *
 * @param port_num Port number (0 to 3).
 * @param direction Direction for the port (PORT_INPUT or PORT_OUTPUT).
 *
 * @note If the input port number is not correct, the function will not handle the request.
 */
void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction);

/**
 * @brief Write a value to all pins in the specified port.
 *
 * @param port_num Port number (0 to 3).
 * @param value Value to write to the port.
 *
 * @note If any pin in the port is configured as input, this will activate/deactivate the internal pull-up resistor.
 * @note If the input port number is not correct, the function will not handle the request.
 */
void GPIO_writePort(uint8 port_num, uint8 value);

/**
 * @brief Read and return the value of the specified port.
 *
 * @param port_num Port number (0 to 3).
 *
 * @return Value of the port.
 * @note If the input port number is not correct, the function will return a ZERO value.
 */
uint8 GPIO_readPort(uint8 port_num);

#endif /* GPIO_H_ */
