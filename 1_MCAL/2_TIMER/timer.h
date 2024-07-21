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





#endif /* TIMER_H_ */