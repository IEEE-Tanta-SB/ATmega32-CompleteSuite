/******************************************************************************
 * File: adc.c
 * Description: This file contains the implementation of ADC driver for ATmega32
 * Author: Mai Farahat
 ******************************************************************************/

/*******************************************
 *           Section : INCLUDES
 *******************************************/
#include "ADC.h"

/**************************************************
 *           Section : Global Variables
 **************************************************/
ADC_Config_t G_ADC_cfg;
void(*GP_IRQ_Callback)(void);

/******************************************************************
 *           Section : APIS supported by "ADC driver"
 ******************************************************************/

/**
 * @brief Initializes the ADC with the given configuration.
 *
 * @param[in] ADC_CFG Pointer to the ADC configuration structure.
 */
void ADC_INIT(ADC_Config_t* ADC_CFG)
{
    G_ADC_cfg = *ADC_CFG;
    // 1: Select voltage source
    ADMUX |= ADC_CFG->ADC_Voltage_Reference;

    // 2: Select ADC result presentation
    ADMUX |= ADC_CFG->ADC_Result_Presentation;

    // 3: Select ADC prescaler
    ADCSRA |= ADC_CFG->ADC_Prescaler;

    // 4: Select ADC IRQ
    ADCSRA |= ADC_CFG->ADC_IRQ;
    if (ADC_CFG->ADC_IRQ == ADC_IRQ_Enable)
    {
        sei();
    }

    // 5: Enable ADC
    ADCSRA |= (1 << ADEN);
    // 6: Start conversion if in free running mode
    if (ADC_CFG->ADC_Mode == ADC_Mode_free_running_mode)
    {
        SET_BIT(ADCSRA, ADSC);
    }
}

/**
 * @brief Deinitializes the ADC, resetting its registers.
 */
void ADC_DEINIT(void)
{
    ADMUX = 0x00;
    ADCSRA = 0x00;
}

/**
 * @brief Reads the ADC value from a specific channel.
 *
 * @param[in] channel Pointer to the channel selection enum.
 * @param[out] result Pointer to the variable where the ADC result will be stored.
 * @param[in] polling Pointer to the polling mechanism enum.
 */
void ADC_Read_Channel(channel_select_t* channel, uint16_t* result, Polling_Mechanism_t* polling)
{
    // Clear selected channel to select another channel
    CLEAR_BIT(ADMUX, MUX0);
    CLEAR_BIT(ADMUX, MUX1);
    CLEAR_BIT(ADMUX, MUX2);
    CLEAR_BIT(ADMUX, MUX3);
    CLEAR_BIT(ADMUX, MUX4);

    // 1: Select channel
    ADMUX |= ((uint8_t)channel << MUX0);

    // 2: Make pin as an input
    CLEAR_BIT(DDRA, (uint8_t)channel);

    // 3: Start conversion if in single conversion mode
    if (G_ADC_cfg.ADC_Mode == ADC_Mode_single_conversion)
    {
        SET_BIT(ADCSRA, ADSC);
    }

    // 4: Wait until ADC conversion complete if polling is enabled
    if (polling == polling_enable)
    {
        while (!READ_BIT(ADCSRA, ADIF));
        // 5: Read conversion result
        if (G_ADC_cfg.ADC_Result_Presentation == ADC_Result_Presentation_Left)
        {
            *result = (((ADCL & 0xC0) >> 6) | (ADCH << 2));
        }
        else if (G_ADC_cfg.ADC_Result_Presentation == ADC_Result_Presentation_Right)
        {
            *result = (ADCL | ((ADCH & 0x03) << 8));
        }
    }
    // 6: Clear ADIF flag
    CLEAR_BIT(ADCSRA, ADIF);
}
