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

/**********************************************************************
 *           Section : User Type Definition (Structures)
 **********************************************************************/

typedef struct
{
    SPI_InterruptEnable SPI_u8InterruptEnable;
    SPI_Enable SPI_u8SPIEnable;
    SPI_DataOrder SPI_u8DataOrder;
    SPI_Mode SPI_u8MasterSlaveSelect;
    SPI_ClockPolarity SPI_u8ClockPolarity;
    SPI_ClockPhase SPI_u8ClockPhase;
    SPI_ClockRate SPI_u8ClockRate;
} SPI_CONFIG;


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

void SPI_VoidInit(SPI_Enable spi_enable ,SPI_Mode MasterSlaveMode ,SPI_DataOrder dataOrder, SPI_InterruptEnable spi_interruptEnable);

void SPI_CLK_VoidInit (SPI_ClockPolarity clkPriority, SPI_ClockPhase ClkPhase, SPI_ClockRate ClkRate);





#endif