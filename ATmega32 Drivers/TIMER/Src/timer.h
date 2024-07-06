/*******************************************************************************
 * File Name: timer.h
 *
 * Description: Header file for Timer driver for ATmega32 microcontroller.
 *
 * Authors: IEEE-Tanta Student Branch
 *          Hussein El-Shamy
 *
 * Last Update: 24 May 2024
 ******************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_

#include "../Common/common_macros.h"
#include "../Common/std_types.h"
#include "../Common/gpio.h"

/********************************************************************************
 *								 TYPE DEFINITON 								*
 ********************************************************************************/

typedef enum {
	NO_CLOCK,
	F_CPU_CLOCK,
	F_CPU_8,
	F_CPU_64,
	F_CPU_256,
	F_CPU_1024,
	EXTERNAL_FALLING,
	EXTERNAL_RISING
} Timer_Prescaler;

typedef enum
{
	NORMAL_MODE,
	CTC_MODE=4,
}Timer_Mode;

typedef struct
{
	uint16 initial_value;
	uint16 compare_value ;
	Timer_Prescaler prescaler;
	Timer_Mode mode;
}Timer_ConfigType;


/*********************************************************************************
 *                              Functions Prototypes                             *
 ********************************************************************************/

/************************************ Timer 1 ***********************************/

void TIMER1_init(const Timer_ConfigType * Config_Ptr);

void TIMER1_deInit(void);

void TIMER1_setCallBack(void(*a_ptr)(void));

/************************************ Timer 2 ***********************************/

void TIMER2_init(const Timer_ConfigType * Config_Ptr);

void TIMER2_deInit(void);

void TIMER2_setCallBack(void(*a_ptr)(void));

/************************************ Timer 3 ***********************************/

void TIMER3_init(const Timer_ConfigType * Config_Ptr);

void TIMER3_deInit(void);

void TIMER3_setCallBack(void(*a_ptr)(void));

#endif /* TIMER_H_ */
