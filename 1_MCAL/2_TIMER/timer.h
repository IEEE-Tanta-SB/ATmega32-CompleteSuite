/******************************************************************************
 * File: timer.h
 * Description: This is the header file of TIMER driver for ATmega32
 * Author: Mohamed Belal
 ******************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_

/* ========================================================================================= */
/* ======================================= Includes ======================================== */
/* ========================================================================================= */
#include "./../../utils/Atmeg32_Config.h"
#include "./../../MCAL/DIO.h"


/* ========================================================================================= */
/* =========================== User Type Definition (Structures) =========================== */
/* ========================================================================================= */
typedef struct  
{
	/* ==== Timer_Mode ====
	 * specifies Timer Mode (Normal | CTC | PWM) 
	 * this parameter must be set base on @ref Timer0_Mode_Define
	 * */
	uint8_t		Timer_Mode;
	
	/* ==== Timer_Clock_Source ====
	 * specifies Timer Clock Source (PreScaler with internal clock only | External)   
	 * this parameter must be set base on @ref Timer_Clock_Source_Define
	 * */
	uint8_t		Timer_Clock_Source;
	
	/* ==== IRQ_Enable ====
	 * specifies Enable or Disable IRQ 
	 * this parameter must be set base on @ref IRQ_Enable_Define
	 * */
	uint8_t		IRQ_Enable;



	/* ==== (*P_IRQ_CallBack)(void) ====
	 * set the C Function which will be called once IRQ Happens
	 * */
	void (*P_IRQ_CallBack)(void);
	
}TIMER0_Config_t;


/* ========================================================================================= */
/* ============================= Macros Configuration References =========================== */
/* ========================================================================================= */

//-------------------------------------
//		@ref Timer0_Mode_Define
//-------------------------------------
#define Timer0_Mode_Normal						(uint8_t)(0)		  // 0b0000
#define Timer0_Mode_CTC							(uint8_t)(0x1<<WGM01) // 0b0001
#define Timer0_Mode_PWM_NONINVERTING			(uint8_t)(0xD<<WGM01) // 0b1101
#define Timer0_Mode_PWM_INVERTING				(uint8_t)(0xF<<WGM01) // 0b1111


//-------------------------------------
//		@ref Timer_Clock_Source_Define
//-------------------------------------	
#define Timer_Clock_Source_NO_CLOCK					(uint8_t)(0b000<<CS00)	
#define Timer_Clock_Source_NO_PRESCALING			(uint8_t)(0b001<<CS00)
#define Timer_Clock_Source_PRESCALING_8				(uint8_t)(0b010<<CS00)
#define Timer_Clock_Source_PRESCALING_64			(uint8_t)(0b011<<CS00)
#define Timer_Clock_Source_PRESCALING_256			(uint8_t)(0b100<<CS00)
#define Timer_Clock_Source_PRESCALING_1024			(uint8_t)(0b101<<CS00)
#define Timer_Clock_Source_External_Falling_Edge	(uint8_t)(0b110<<CS00)
#define Timer_Clock_Source_External_Rising_Edge		(uint8_t)(0b111<<CS00)


//-------------------------------------
//		@ref IRQ_Enable_Define
//-------------------------------------
#define IRQ_Enable_NON								((uint8_t)(0))
#define IRQ_Enable_OCIE0							((uint8_t)(1<<OCIE0))
#define IRQ_Enable_TOIE0							((uint8_t)(1<<TOIE0))



/* ========================================================================================= */
/* ========================= APIs Supported by "MCAL Timer0 DRIVER" ======================== */
/* ========================================================================================= */
void MCAL_Timer0_Init(TIMER0_Config_t* timer0_cfg);
void MCAL_Timer0_DeInit(void);

void MCAL_Timer0_GetCounterValue(uint8_t* TicksNumber);
void MCAL_Timer0_SetCompareValue(uint8_t TicksNumber);

void MCAL_Timer0_PWM_DutyCycle(uint8_t DutyCycle);



#endif /* TIMER_H_ */