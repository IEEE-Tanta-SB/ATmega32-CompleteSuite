/******************************************************************************
 * File: twi.c
 * Description: This file contains the implementation of TWI driver for ATmega32
 * Author: Manal Nabil
 ******************************************************************************/

#include "twi.h"

/**
 * @brief Initializes the TWI (Two Wire Interface) hardware as a master.
 *
 * This function sets up the TWI hardware in master mode with the specified prescaler.
 *
 * @param[in] Prescaler The prescaler value to configure the TWI clock.
 */
void TWI_MasterInit(uint8_t Prescaler)
{
	/*Set Bit Rate*/
	TWBR= (uint8_t) (((F_CPU/SCL_Clock)-16) / (2*Prescaler));

	/*Set Prescaller*/
	if (Prescaler==PRESCALER_1)
	{
		TWSR=0;
	}
	else if(Prescaler==PRESCALER_4)
	{
		TWSR=1;
	}
	else if (Prescaler==PRESCALER_16)
	{
		TWSR=2;
	}
	else if (Prescaler==PRESCALER_64)
	{
		TWSR=3;
	}

	/*Enable Acknowledge bit*/
	SET_BIT(TWCR,TWCR_TWEA);

	/*Enable TWI*/
	SET_BIT(TWCR,TWEN);
}

/**
 * @brief Initializes the TWI (Two Wire Interface) hardware as a slave.
 *
 * This function sets up the TWI hardware in slave mode with the specified address.
 *
 * @param[in] Address The address to be assigned to the TWI slave device.
 */
void TWI_SlaveInit(uint8_t Address)
{
	/*Set Slave Address*/
	if (Address!=NULL)
	{
		TWAR = Address<<1;
	}

	/*Enable Acknowledge bit*/
	SET_BIT(TWCR,TWCR_TWEA);

	/*Enable TWI*/
	SET_BIT(TWCR,TWEN);
}

/**
 * @brief Sends a start condition on the TWI bus.
 *
 * This function initiates a start condition to signal the beginning of a TWI communication.
 */
void TWI_Start(void)
{
	/*Send START*/
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);

	/*Wait for TWINT Flag set*/
	while (!(TWCR & (1<<TWINT)));

	/* Check value of TWI Status Register*/
	while((TWSR & 0xF8) != START);
}

/**
 * @brief Sends a repeated start condition on the TWI bus.
 *
 * This function initiates a repeated start condition to signal the beginning of a new TWI communication sequence
 * without releasing the bus.
 */
void TWI_RepeatStart(void)
{
	/*Send Repeated START*/
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);

	/*Wait for TWINT Flag set*/
	while (!(TWCR & (1<<TWINT)));

	/* Check value of TWI Status Register*/
	while((TWSR & 0xF8) != REPEATED_START);
}

/* Master section */

/**
 * @brief Sends the slave address with a write request.
 *
 * This function sends the specified slave address along with a write request on the TWI bus.
 *
 * @param[in] Address The address of the slave device.
 */
void TWI_SendSlaveAddWithW(uint8_t Address)
{
	/*Send Slave Address*/
	TWDR = (Address<<1);

	/*Write request*/
	CLEAR_BIT(TWDR,0);

	/*Clear Start Condition*/
	CLEAR_BIT(TWCR,TWSTA);

	/* start transmission of address*/
	SET_BIT(TWCR,TWINT);

	/*Wait for TWINT Flag set*/
	while (!(TWCR & (1<<TWINT)));

	/* Check value of TWI Status Register*/
	while((TWSR & 0xF8) != MT_SLA_W_ACK);
}
