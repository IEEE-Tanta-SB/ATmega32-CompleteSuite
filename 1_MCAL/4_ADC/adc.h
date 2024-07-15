/*
 * ADC.h
 *
 * Created: 15/7/2023 12:28:34 PM
 *  Author: MAI
 */

#ifndef ADC_H_
#define ADC_H_

/*******************************************
			 Section :INCLUDES
*******************************************/
#include "../4_Common/Platform_Config.h"

/**********************************************************************
			 Section :User Type Definition(Structures)
**********************************************************************/
typedef struct
{
	/*		ADC_Mode
	* select ADC mode
	* this parameter must be set base on @ref ADC_Mode_Define
	*/
	uint8_t ADC_Mode;

	/*		ADC_Voltage_Reference
	* select ADC voltage source
	* this parameter must be set base on @ref ADC_Voltage_Reference_Define
	* ADMUX => bit( 6 , 7 ) => REFS0 , REFS1
	*/
	uint8_t ADC_Voltage_Reference;

	/*		ADC_Result_Presentation
	* select ADC output result presentation(right or left)
	* this parameter must be set base on @ref ADC_Result_Presentation_Define
	* ADMUX  => bit( 5 ) => ADLAR
	*/
	uint8_t ADC_Result_Presentation;
	/*		ADC_Prescaler
	* these bits determine the division factor between the XTAL frequency and input clock to the ADC
	* this parameter must be set base on @ref ADC_Prescaler_Define
	* ADCSRA  => bit( 0,1,2 ) => ADPS0,ADPS1,ADPS2
	*/
	uint8_t ADC_Prescaler;
	/*		ADC_IRQ
	* these bits Enable or Disable Interrupt
	* this parameter must be set base on @ref ADC_IRQ_Define
	* ADCSRA  => bit( 3 ) => ADIE
	*/
	uint8_t ADC_IRQ;

	/*		P_IRQ_Callback
	* set the c function will be called once IRQ happened
	*/
	void(*P_IRQ_Callback)(void);


}ADC_Config_t;

/******************************************************************
				Section :Macro Configuration References
******************************************************************/

/*				@ref ADC_Mode_Define               */
#define ADC_Mode_free_running_mode		(uint8_t)(1)
#define ADC_Mode_single_conversion		(uint8_t)(0)

/*				@ref ADC_Voltage_Reference_Define               */

#define ADC_Voltage_Reference_AREF		(uint8_t)(0)
#define ADC_Voltage_Reference_AVCC		(uint8_t)(0b01<<REFS0)
#define ADC_Voltage_Reference_Internal	(uint8_t)(0b11<<REFS0)

/*				@ref ADC_Result_Presentation_Define               */

#define ADC_Result_Presentation_Right		(uint8_t)(0)
#define ADC_Result_Presentation_Left		(uint8_t)(1<<ADLAR)

/*				@ref ADC_Prescaler_Define               */
#define ADC_Prescaler_2		    (uint8_t)(0b001<<ADPS0)
#define ADC_Prescaler_4		    (uint8_t)(0b010<<ADPS0)
#define ADC_Prescaler_8		    (uint8_t)(0b011<<ADPS0)
#define ADC_Prescaler_16		(uint8_t)(0b100<<ADPS0)
#define ADC_Prescaler_32		(uint8_t)(0b101<<ADPS0)
#define ADC_Prescaler_64		(uint8_t)(0b110<<ADPS0)
#define ADC_Prescaler_128		(uint8_t)(0b111<<ADPS0)

/*				@ref ADC_ADC_IRQ_Define               */
#define ADC_IRQ_Enable	    (uint8_t)(1<<ADIE)
#define ADC_IRQ_Disable		(uint8_t)(0)


/******************************************************************
				Section :    enum
******************************************************************/
typedef enum{
	ADC0 = 0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
	}channel_select_t;

typedef enum{
	polling_disable = 0,
	polling_enable,

}Polling_Mechanism_t;

/******************************************************************
				Section :APIS supported by "ADC driver"
******************************************************************/

void ADC_INIT(ADC_Config_t* ADC_CFG);
void ADC_DEINIT(void);
void ADC_Read_Channel(channel_select_t* channel , uint16_t* result ,Polling_Mechanism_t* polling );

#endif /* ADC_H_ */
