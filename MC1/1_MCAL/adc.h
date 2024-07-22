/******************************************************************************
 * File: adc.h
 * Description: This is the header file of ADC driver for ATmega32
 * Author: Mai Farahat
 ******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

/*******************************************
 *           Section : INCLUDES
 *******************************************/
#include "../4_Common/Platform_Config.h"

/**********************************************************************
 *           Section : User Type Definition (Structures)
 **********************************************************************/

/**
 * @brief Configuration structure for the ADC driver.
 *
 * This structure defines the configuration parameters for initializing the ADC.
 */
typedef struct
{
    /**
     * @brief ADC operating mode.
     *
     * Select the ADC mode based on @ref ADC_Mode_Define.
     *
     * @note This parameter must be set according to @ref ADC_Mode_Define.
     */
    uint8_t ADC_Mode;

    /**
     * @brief ADC voltage reference.
     *
     * Select the ADC voltage source based on @ref ADC_Voltage_Reference_Define.
     *
     * @note This parameter must be set according to @ref ADC_Voltage_Reference_Define.
     */
    uint8_t ADC_Voltage_Reference;

    /**
     * @brief ADC result presentation.
     *
     * Select ADC output result presentation (right or left) based on @ref ADC_Result_Presentation_Define.
     *
     * @note This parameter must be set according to @ref ADC_Result_Presentation_Define.
     */
    uint8_t ADC_Result_Presentation;

    /**
     * @brief ADC prescaler.
     *
     * Determine the division factor between the XTAL frequency and input clock to the ADC.
     *
     * @note This parameter must be set according to @ref ADC_Prescaler_Define.
     */
    uint8_t ADC_Prescaler;

    /**
     * @brief ADC interrupt enable/disable.
     *
     * Enable or disable the ADC interrupt based on @ref ADC_IRQ_Define.
     *
     * @note This parameter must be set according to @ref ADC_IRQ_Define.
     */
    uint8_t ADC_IRQ;

    /**
     * @brief Pointer to the interrupt callback function.
     *
     * Set the C function that will be called once an ADC interrupt occurs.
     */
    void(*P_IRQ_Callback)(void);

} ADC_Config_t;

/******************************************************************
 *           Section : Macro Configuration References
 ******************************************************************/

/* @ref ADC_Mode_Define */
#define ADC_Mode_free_running_mode    (uint8_t)(1) /**< ADC free running mode. */
#define ADC_Mode_single_conversion    (uint8_t)(0) /**< ADC single conversion mode. */

/* @ref ADC_Voltage_Reference_Define */
#define ADC_Voltage_Reference_AREF    (uint8_t)(0) /**< External voltage reference. */
#define ADC_Voltage_Reference_AVCC    (uint8_t)(0b01 << REFS0) /**< AVCC with external capacitor at AREF pin. */
#define ADC_Voltage_Reference_Internal (uint8_t)(0b11 << REFS0) /**< Internal 2.56V voltage reference. */

/* @ref ADC_Result_Presentation_Define */
#define ADC_Result_Presentation_Right (uint8_t)(0) /**< Right-adjusted ADC result. */
#define ADC_Result_Presentation_Left  (uint8_t)(1 << ADLAR) /**< Left-adjusted ADC result. */

/* @ref ADC_Prescaler_Define */
#define ADC_Prescaler_2    (uint8_t)(0b001 << ADPS0) /**< ADC prescaler 2. */
#define ADC_Prescaler_4    (uint8_t)(0b010 << ADPS0) /**< ADC prescaler 4. */
#define ADC_Prescaler_8    (uint8_t)(0b011 << ADPS0) /**< ADC prescaler 8. */
#define ADC_Prescaler_16   (uint8_t)(0b100 << ADPS0) /**< ADC prescaler 16. */
#define ADC_Prescaler_32   (uint8_t)(0b101 << ADPS0) /**< ADC prescaler 32. */
#define ADC_Prescaler_64   (uint8_t)(0b110 << ADPS0) /**< ADC prescaler 64. */
#define ADC_Prescaler_128  (uint8_t)(0b111 << ADPS0) /**< ADC prescaler 128. */

/* @ref ADC_IRQ_Define */
#define ADC_IRQ_Enable     (uint8_t)(1 << ADIE) /**< Enable ADC interrupt. */
#define ADC_IRQ_Disable    (uint8_t)(0) /**< Disable ADC interrupt. */

/******************************************************************
 *           Section : Enum Definitions
 ******************************************************************/

/**
 * @brief Enum for selecting ADC channels.
 */
typedef enum {
    ADC0 = 0, /**< ADC channel 0. */
    ADC1,     /**< ADC channel 1. */
    ADC2,     /**< ADC channel 2. */
    ADC3,     /**< ADC channel 3. */
    ADC4,     /**< ADC channel 4. */
    ADC5,     /**< ADC channel 5. */
    ADC6,     /**< ADC channel 6. */
    ADC7      /**< ADC channel 7. */
} channel_select_t;

/**
 * @brief Enum for ADC polling mechanism.
 */
typedef enum {
    polling_disable = 0, /**< Disable polling. */
    polling_enable      /**< Enable polling. */
} Polling_Mechanism_t;

/******************************************************************
 *           Section : APIS supported by "ADC driver"
 ******************************************************************/

/**
 * @brief Initializes the ADC with the given configuration.
 *
 * @param[in] ADC_CFG Pointer to the ADC configuration structure.
 *
 * This function sets up the ADC with the specified mode, voltage reference, result presentation,
 * prescaler, and interrupt settings.
 */
void ADC_INIT(ADC_Config_t* ADC_CFG);

/**
 * @brief Deinitializes the ADC.
 *
 * This function resets the ADC settings to their default values.
 */
void ADC_DEINIT(void);

/**
 * @brief Reads the specified ADC channel.
 *
 * @param[in] channel Pointer to the channel selection enum.
 * @param[out] result Pointer to a variable where the conversion result will be stored.
 * @param[in] polling Pointer to the polling mechanism enum.
 *
 * This function starts an ADC conversion for the specified channel and waits for the result if
 * polling is enabled.
 */
void ADC_Read_Channel(channel_select_t* channel, uint16_t* result, Polling_Mechanism_t* polling);

#endif /* ADC_H_ */
