/******************************************************************************
 * File: adc.c
 * Description: This file contains the implementation of ADC driver for ATmega32
 * Author: Mai Farahat
 ******************************************************************************/

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

void ADC_DEINIT(void)
{
	ADMUX =  0x00;
	ADCSRA = 0x00;
}

void ADC_Read_Channel(channel_select_t* channel , uint16_t* result ,Polling_Mechanism_t* polling ){
	// clear selected channel to select another channel
	CLEAR_BIT(ADMUX , MUX0);
	CLEAR_BIT(ADMUX , MUX1);
	CLEAR_BIT(ADMUX , MUX2);
	CLEAR_BIT(ADMUX , MUX3);
	CLEAR_BIT(ADMUX , MUX4);

	//1: select channel
	ADMUX |= ((uint8_t)channel << MUX0);

	//2: make pin as an input
	CLEAR_BIT(DDRA , (uint8_t)channel);

	//3: start conversion
	if (G_ADC_cfg.ADC_Mode == ADC_Mode_single_conversion)
	{
		SET_BIT(ADCSRA , ADSC);
	}

	//4: wait until ADC conversion complete
	if (polling == polling_enable)
	{
		while (!READ_BIT(ADCSRA , ADIF));
		//5: read conversion result
		if (G_ADC_cfg.ADC_Result_Presentation == ADC_Result_Presentation_Left)
		{
			*result =(((ADCL & 0XC0) >> 6 ) | (ADCH << 2)) ;
		}else if (G_ADC_cfg.ADC_Result_Presentation == ADC_Result_Presentation_Right)
		{
			*result =(ADCL | ((ADCH & 0x03) << 8)) ;
		}
	}
	//6: clear ADIF flag
	CLEAR_BIT(ADCSRA , ADIF);
}
