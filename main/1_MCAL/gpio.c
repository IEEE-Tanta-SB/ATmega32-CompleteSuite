/******************************************************************************
 * File: gpio.c
 * Description: This file contains the implementation of GPIO driver for ATmega32
 * Author: Hussein El-Shamy
 ******************************************************************************/

/********************************************************************************
 *						INCLUDING NECESSARY HEADER FILES						*
 ********************************************************************************/

#include "gpio.h"

/*********************************************************************************
 *                 		   Public Functions Definition                           *
 ********************************************************************************/

/**
 * @brief Configures the direction of a specified pin.
 *
 * @param[in] port_num The port number to which the pin belongs.
 * @param[in] pin_num The pin number to be configured.
 * @param[in] direction The direction to be set (input or output).
 */
void GPIO_setupPinDirection(uint8_t port_num, uint8_t pin_num,
		GPIO_PinDirectionType direction) {

	/**
	 * @brief Configures the direction of a specified pin.
	 *
	 * @param[in] port_num The port number to which the pin belongs.
	 * @param[in] pin_num The pin number to be configured.
	 * @param[in] direction The direction to be set (input or output).
	 */
	void GPIO_setupPinDirection(uint8_t port_num, uint8_t pin_num, GPIO_PinDirectionType direction) {
	    volatile uint8_t *ddr_reg = NULL;

	    /* Check if the pin number and port number are within valid range */
	    if ((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS)) {
	        /* Invalid pin or port number, do nothing */
	        return;
	    }

	    /* Determine the DDR register based on the port number */
	    switch (port_num) {
	        case PORTA_ID:
	            ddr_reg = &DDRA;
	            break;
	        case PORTB_ID:
	            ddr_reg = &DDRB;
	            break;
	        case PORTC_ID:
	            ddr_reg = &DDRC;
	            break;
	        case PORTD_ID:
	            ddr_reg = &DDRD;
	            break;
	        default:
	            return; /* Invalid port number, do nothing */
	    }

	    /* Set or clear the bit in the DDR register based on the direction */
	    if (direction) {
	        SET_BIT(*ddr_reg, pin_num);
	    } else {
	        CLEAR_BIT(*ddr_reg, pin_num);
	    }
	}
}

/**
 * @brief Writes a value to a specified pin.
 *
 * @param[in] port_num The port number to which the pin belongs.
 * @param[in] pin_num The pin number to be written to.
 * @param[in] value The value to be written to the pin (high or low).
 */
void GPIO_writePin(uint8_t port_num, uint8_t pin_num, uint8_t value) {

    volatile uint8_t *port_reg = NULL;

    /* Check if the pin number and port number are within valid range */
    if ((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS)) {
        /* Invalid pin or port number, do nothing */
        return;
    }

    /* Determine the PORT register based on the port number */
    switch (port_num) {
        case PORTA_ID:
            port_reg = &PORTA;
            break;
        case PORTB_ID:
            port_reg = &PORTB;
            break;
        case PORTC_ID:
            port_reg = &PORTC;
            break;
        case PORTD_ID:
            port_reg = &PORTD;
            break;
        default:
            return; /* Invalid port number, do nothing */
    }

    /* Set or clear the bit in the PORT register based on the value */
    if (value) {
        SET_BIT(*port_reg, pin_num);
    } else {
        CLEAR_BIT(*port_reg, pin_num);
    }

}

/**
 * @brief Reads the value of a specified pin.
 *
 * @param[in] port_num The port number to which the pin belongs.
 * @param[in] pin_num The pin number to be read.
 *
 * @return The current value of the pin (high or low).
 */
uint8_t GPIO_readPin(uint8_t port_num, uint8_t pin_num) {

	volatile uint8_t *pin_reg = NULL;
	uint8_t pinValue = LOGIC_LOW;

	/* Check if the pin number and port number are within valid range */
	if ((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS)) {
		/* Invalid pin or port number, return LOGIC_LOW */
		return pinValue;
	}

	/* Determine the PIN register based on the port number */
	switch (port_num) {
	case PORTA_ID:
		pin_reg = &PINA;
		break;
	case PORTB_ID:
		pin_reg = &PINB;
		break;
	case PORTC_ID:
		pin_reg = &PINC;
		break;
	case PORTD_ID:
		pin_reg = &PIND;
		break;
	default:
		return pinValue; /* Invalid port number, return LOGIC_LOW */
	}

	/* Read the value of the pin from the PIN register */
	pinValue = GET_BIT(*pin_reg, pin_num);

	return pinValue;
}

/**
 * @brief Configures the direction of all pins in a specified port.
 *
 * @param[in] port_num The port number to be configured.
 * @param[in] direction The direction to be set for the port (input or output).
 */
void GPIO_setupPortDirection(uint8_t port_num, GPIO_PortDirectionType direction) {

    volatile uint8_t *ddr_reg = NULL;

    /* Determine the DDR register based on the port number */
    switch (port_num) {
        case PORTA_ID:
            ddr_reg = &DDRA;
            break;
        case PORTB_ID:
            ddr_reg = &DDRB;
            break;
        case PORTC_ID:
            ddr_reg = &DDRC;
            break;
        case PORTD_ID:
            ddr_reg = &DDRD;
            break;
        default:
            return; /* Invalid port number, do nothing */
    }

    /* Set the direction for the port */
    *ddr_reg = direction;
}

/**
 * @brief Writes a value to all pins in a specified port.
 *
 * @param[in] port_num The port number to which the value will be written.
 * @param[in] value The value to be written to the port.
 */
void GPIO_writePort(uint8_t port_num, uint8_t value) {

    volatile uint8_t *port_reg = NULL;

    /* Determine the PORT register based on the port number */
    switch (port_num) {
        case PORTA_ID:
            port_reg = &PORTA;
            break;
        case PORTB_ID:
            port_reg = &PORTB;
            break;
        case PORTC_ID:
            port_reg = &PORTC;
            break;
        case PORTD_ID:
            port_reg = &PORTD;
            break;
        default:
            return; /* Invalid port number, do nothing */
    }

    /* Write the value to the PORT register */
    *port_reg = value;
}

/**
 * @brief Reads the value of all pins in a specified port.
 *
 * @param[in] port_num The port number to be read.
 *
 * @return The current value of the port.
 */
uint8_t GPIO_readPort(uint8_t port_num) {
	// Function implementation goes here
	return 0; // Placeholder return value
}
