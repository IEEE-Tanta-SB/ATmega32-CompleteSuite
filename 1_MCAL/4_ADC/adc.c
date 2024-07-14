/*
 * ADC.c
 *
 * Created: 15/7/2023 12:28:34 PM
 *  Author: MAI
 */

/*******************************************
			 Section :INCLUDES
*******************************************/
#include "ADC.h"

/**************************************************
			 Section :Global Variables
**************************************************/
ADC_Config_t G_ADC_cfg;
void(*GP_IRQ_Callback)(void);

/******************************************************************
				Section :APIS supported by "ADC driver"
******************************************************************/
void ADC_INIT(ADC_Config_t* ADC_CFG)
{
	G_ADC_cfg = *ADC_CFG;
	// 1: select voltage source
	ADMUX |= ADC_CFG->ADC_Voltage_Reference;

	// 2: select ADC result presentation
	ADMUX |= ADC_CFG->ADC_Result_Presentation;

	// 3: select ADC_prescaler
	ADCSRA |= ADC_CFG->ADC_Prescaler;

	// 4: select ADC IRQ
	ADCSRA |= ADC_CFG->ADC_IRQ;
	if (ADC_CFG->ADC_IRQ == ADC_IRQ_Enable)
	{
		sei();
	}

	// 5: select enable ADC
	ADCSRA |= (1<<ADEN);
	// 6: select start conversion
	if(ADC_CFG->ADC_Mode == ADC_Mode_free_running_mode)
	{
		SET_BIT(ADCSRA , ADSC);
	}

}

