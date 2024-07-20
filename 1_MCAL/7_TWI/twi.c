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
