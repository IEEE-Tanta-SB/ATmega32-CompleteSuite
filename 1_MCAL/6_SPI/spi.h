/******************************************************************************
 * File: spi.h
 * Description: This is the header file of UART driver for ATmega32
 * Author: Nada Ehab
 ******************************************************************************/


#ifndef SPI_H_
#define SPI_H_


/*******************************************
 *           Section : INCLUDES
 *******************************************/
#include "../4_Common/Platform_Config.h"

/******************************************************************
 *           Section : Set Timeout
 ******************************************************************/

#define SPI_uint32TIMEOUT    10000ul

/******************************************************************
 *           Section : Enum Definitions
 ******************************************************************/

/**
 * @brief Enum for Error State.
 */

typedef enum {
	OK,
	NOT_OK
} SPI_State;

/**
 * @brief Enum for selecting SPI data orders.
 */

typedef enum {
    SPI_DATA_LSB_FIRST,
    SPI_DATA_MSP_FIRST
} SPI_DataOrder;


/**
 * @brief Enum for Master/Slave Selection.
 */ 

typedef enum {
    SPI_MASTER,
    SPI_SLAVE
} SPI_Mode;


/**
 * @brief Enum for Clock Polarity.
 */  

typedef enum {
    SPI_RISING_LEADING_FALLING_TRAILING,
    SPI_FALLING_LEADING_RISING_TRAILING
} SPI_ClockPolarity;

/**
 * @brief Enum for Clock Phase.
 */  

typedef enum {
    SPI_SAMPLE_LEADING_SETUP_TRAILING,
    SPI_SETUP_LEADING_SAMPLE_TRAILING
} SPI_ClockPhase;


/**
 * @brief Enum for Clock Rate Division.
 */  

typedef enum {
    SPI_FREQ_DIVIDED_BY_2,
    SPI_FREQ_DIVIDED_BY_4,
    SPI_FREQ_DIVIDED_BY_8,
    SPI_FREQ_DIVIDED_BY_16,
    SPI_FREQ_DIVIDED_BY_32,
    SPI_FREQ_DIVIDED_BY_64,
    SPI_FREQ_DIVIDED_BY_128
} SPI_ClockRate;


/**
 * @brief Enum for SPI Interrupt Enable.
 */   

typedef enum {
    SPI_INTERRUPT_DISABLE,
    SPI_INTERRUPT_ENABLE
} SPI_InterruptEnable;


/**
 * @brief Enum for SPI Enable.
 */   

typedef enum {
    SPI_DISABLE,
    SPI_ENABLE
} SPI_Enable;

/**
 * @brief Enum for function state.
 */

typedef enum {
	 IDLE , BUSY
} SPI_FunState;

/**********************************************************************
 *           Section : User Type Definition (Structures)
 **********************************************************************/

typedef struct
{
    uint8_t* Copy_u8TData;
    uint8_t* Copy_u8RData;
    uint8_t Copy_u8BufferSize;
    void(*NotificationFuncn)(void);
}SPI_BUFFER;


/******************************************************************
 *           Section : APIS supported by "SPI driver"
 ******************************************************************/

/**
 * @brief Initializes the SPI with the specified settings.
 *
 * @param[in] spi_enable           Enable or disable the SPI module.
 * @param[in] MasterSlaveMode      Set the SPI to master or slave mode.
 * @param[in] dataOrder            Set the data order (MSB first or LSB first).
 * @param[in] spi_interruptEnable  Enable or disable SPI interrupt.
 */
void SPI_VoidInit(SPI_Enable spi_enable ,SPI_Mode MasterSlaveMode ,SPI_DataOrder dataOrder, SPI_InterruptEnable spi_interruptEnable);

/**
 * @brief Initializes the SPI clock with the specified settings.
 *
 * @param[in] clkPriority  Set the clock polarity (idle state of clock line).
 * @param[in] ClkPhase     Set the clock phase (data sampling on leading or trailing edge).
 * @param[in] ClkRate      Set the clock rate (speed of SPI clock).
 */

void SPI_CLK_VoidInit (SPI_ClockPolarity clkPriority, SPI_ClockPhase ClkPhase, SPI_ClockRate ClkRate);


/**
 * @brief Transmits and receives a byte of data via SPI.
 *
 * @param[in] CopyData    The data byte to be transmitted.
 * @param[out] CopyData   Pointer to where the received data byte will be stored.
 *
 * @return SPI_State      The status of the SPI transmission.
 */

SPI_State SPI_ uint8_tTranceive ( uint8_t CopyData ,  uint8_t * CopyData) ;

/**
 * @brief Synchronously transmits and receives a buffer of data via SPI.
 *
 * @param[in]  Copy_u8TData     Pointer to the buffer of data to be transmitted.
 * @param[out] Copy_u8RData     Pointer to the buffer where received data will be stored.
 * @param[in]  Copy_u8BufferSize The size of the buffer (number of bytes to be transmitted/received).
 */

SPI_State SPI_BufferTranceiverSynch (uint8_t* Copy_u8TData , uint8_t * Copy_u8RData , uint8_t Copy_u8BufferSize) ;

/**
 * @brief Asynchronously transmits and receives a buffer of data via SPI.
 *
 * @param[in] spi_buffer  Pointer to a structure containing the buffer and other relevant settings for asynchronous SPI communication.
 *
 * @return SPI_State     The status of the SPI operation.
 */

SPI_State SPI_u8BufferTranceiverAsynch (SPI_BUFFER * spi_buffer) ;





#endif
