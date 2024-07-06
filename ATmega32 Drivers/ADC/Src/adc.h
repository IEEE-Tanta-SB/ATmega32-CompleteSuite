/*******************************************************************************
 * File Name: adc.h
 *
 * Description: Header file for ADC driver for ATmega32 microcontroller.
 *
 * Authors: IEEE-Tanta Student Branch
 *          Hussein El-Shamy
 *
 * Last Update: 24 May 2024
 ******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "../Common/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum {
	AREF, AVCC, REVERSED, INTERNAL
} ADC_ReferenceVolatge;

typedef enum {
	F_CPU_2, F_CPU__2, F_CPU_4, F_CPU_8, F_CPU_16, F_CPU_32, F_CPU_64, F_CPU_128
} ADC_Prescaler;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType *Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

/*
 * Description :
 * Function to set the ADC pre-scaler
 * */
void ADC_setPrescaler(const ADC_Prescaler divisionFactor);

/*
 * Description :
 * Function to set the ADC Reference Volt
 * */
void ADC_setReferenceVolt(const ADC_ReferenceVolatge ref);

/*
 * Description :
 * Function to disable ADC and reset its registers
 */
void ADC_deInit(void);

/*
 * Description :
 * Function to enable ADC interrupt
 */
void ADC_interruptsEnable(void);

/*
 * Description :
 * Function to enable ADC Auto Trigger
 */
void ADC_autoTriggerEnable(void);


#endif /* ADC_H_ */
