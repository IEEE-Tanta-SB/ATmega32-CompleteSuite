/******************************************************************************
 * File: twi.h
 * Description: This is the header file of TWI driver for ATmega32
 * Author: Manal Nabil
 ******************************************************************************/

#ifndef TWI_H_
#define TWI_H_


/*******************************************
			 Section :INCLUDES
*******************************************/

#include "../4_Common/Platform_Config.h"

/******************************************************************
				Section :Macro Configuration References
******************************************************************/

/**
 * @brief values of SCL_Clock.
 */
#define SCL_Clock  400000UL
/**
 * @brief values of TWI Status Register.
 */
#define START                        0x08        /* @brief A START condition has been transmitted.*/
#define REPEATED_START               0x10        /* @brief A repeated START condition has been transmitted.*/
#define MT_SLA_W_ACK                 0x18        /* @brief SLA+W has been transmitted; ACK has been received.*/
#define MT_DATA_T_ACK                0x28        /* @brief Data byte has been transmitted; ACK has been received*/
#define MT_SLA_R_ACK                 0x40        /* @brief SLA+R has been transmitted; ACK has been received.*/
#define MT_DATA_R_ACK                0x50        /* @brief Data byte has been received; ACK has been returned.*/
#define SLA_W_ACK                    0x60        /* @brief Own SLA+W has been received; ACK has been returned.*/
#define SLA_DATA_R_ACK               0x80        /* @brief Data has been received; ACK has been returned.*/
#define SLA_R_ACK                    0xA8        /*@brief Own SLA+R has been received; ACK has been returned.*/
#define SLA_DATA_T_ACK               0xB8        /* @brief Data byte in TWDR has been transmitted; ACK has been received.*/
/**
 * @brief values of TWI Prescalers.
 */
#define PRESCALER_1                     1
#define PRESCALER_4                     4
#define PRESCALER_16                    16
#define PRESCALER_64                    64
/******************************************************************
				Section :APIS supported by "TWI driver"
******************************************************************/
/**
 * @brief Initializes the TWI (Two Wire Interface) hardware as a master.
 *
 * This function sets up the TWI hardware in master mode with the specified prescaler.
 *
 * @param[in] Prescaller The prescaler value to configure the TWI clock.
 */
void TWI_MasterInit(uint8_t Prescaller);

/**
 * @brief Initializes the TWI (Two Wire Interface) hardware as a slave.
 *
 * This function sets up the TWI hardware in slave mode with the specified address.
 *
 * @param[in] Address The address to be assigned to the TWI slave device.
 */
void TWI_SlaveInit(uint8_t Address);

/**
 * @brief Sends a start condition on the TWI bus.
 *
 * This function initiates a start condition to signal the beginning of a TWI communication.
 */
void TWI_Start(void);

/**
 * @brief Sends a repeated start condition on the TWI bus.
 *
 * This function initiates a repeated start condition to signal the beginning of a new TWI communication sequence
 * without releasing the bus.
 */
void TWI_RepeatStart(void);

/* Master section */

/**
 * @brief Sends the slave address with a write request.
 *
 * This function sends the specified slave address along with a write request on the TWI bus.
 *
 * @param[in] Address The address of the slave device.
 */
void TWI_SendSlaveAddWithW(uint8_t Address);

/**
 * @brief Writes a byte of data to the TWI bus as a master.
 *
 * This function sends a single byte of data over the TWI bus to the addressed slave device.
 *
 * @param[in] Data The byte of data to send.
 */
void TWI_MasterWriteData(uint8_t Data);

/**
 * @brief Sends the slave address with a read request.
 *
 * This function sends the specified slave address along with a read request on the TWI bus.
 *
 * @param[in] Address The address of the slave device.
 */
void TWI_SendSlaveAddWithR(uint8_t Address);

/**
 * @brief Reads a byte of data from the TWI bus as a master.
 *
 * This function reads a single byte of data from the TWI bus from the addressed slave device.
 *
 * @return uint8_t The byte of data received.
 */
uint8_t TWI_MasterReadData(void);

/* Slave section */

/**
 * @brief Writes a byte of data to the TWI bus as a slave.
 *
 * This function sends a single byte of data over the TWI bus to the master device.
 *
 * @param[in] Data The byte of data to send.
 */
void TWT_SlaveWriteData(uint8_t Data);

/**
 * @brief Reads a byte of data from the TWI bus as a slave.
 *
 * This function reads a single byte of data from the TWI bus from the master device.
 *
 * @return uint8_t The byte of data received.
 */
uint8_t TWI_SlaveReadData(void);

/**
 * @brief Sends a stop condition on the TWI bus.
 *
 * This function generates a stop condition to signal the end of a TWI communication.
 */
void TWI_Stop(void);

#endif /* TWI_H_ */
