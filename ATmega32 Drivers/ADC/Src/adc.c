/*******************************************************************************
 * File Name: adc.c
 *
 * Description: Implementation file for ADC driver for ATmega32 microcontroller.
 * Provides function definitions for ADC initialization, reading, and other
 * operations.
 *
 * Authors: IEEE-Tanta Student Branch
 *          Hussein El-Shamy
 *
 * Last Update: 24 May 2024
 ******************************************************************************/

#include "adc.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType *Config_Ptr) {
    // Implementation goes here



}

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num) {
    // Implementation goes here



    return 0;
}

/*
 * Description :
 * Function to set the ADC pre-scaler.
 */
void ADC_setPrescaler(const ADC_Prescaler divisionFactor) {
    // Implementation goes here



}

/*
 * Description :
 * Function to set the ADC Reference Voltage.
 */
void ADC_setReferenceVolt(const ADC_ReferenceVolatge ref) {
    // Implementation goes here



}

/*
 * Description :
 * Function to disable ADC and reset its registers.
 */
void ADC_deInit(void) {
    // Implementation goes here



}

/*
 * Description :
 * Function to enable ADC interrupt.
 */
void ADC_interruptsEnable(void) {
    // Implementation goes here



}

/*
 * Description :
 * Function to enable ADC Auto Trigger.
 */
void ADC_autoTriggerEnable(void) {
    // Implementation goes here



}
