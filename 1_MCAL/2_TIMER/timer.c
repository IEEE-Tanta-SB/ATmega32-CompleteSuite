/******************************************************************************
 * File: timer.c
 * Description: This file contains the implementation of TIMER driver for ATmega32
 * Author: Mohamed Belal
 ******************************************************************************/
/* ============================================================================ */
/* ================================= Includes ================================= */
/* ============================================================================ */
#include "Timer.h"


/* ============================================================================ */
/* ===========================  Global Variables ============================== */
/* ============================================================================ */

void (*GP_IRQ_CallBack)(void) = 0;


TIMER0_Config_t G_Timer0_ConFig;
/* ============================================================================ */
/* ==================== APIs Supported by "MCAL timer DRIVER" =================== */
/* ============================================================================ */



/*
 * ===================================
 * @FN              - MCAL_Timer0_Init
 * @brief           - initialization timer according to specific parameter
 * @param [in]      - timer0_cfg:  a pointer to TIMER_CONFIG_t structure that contains the configuration information for the specified TIMER Module
 * @retval          - none
 * @Note            - Supported for TIMER0 ONLY
 * ===================================
 * */
void MCAL_Timer0_Init(TIMER0_Config_t* timer0_cfg)
{
    G_Timer0_ConFig = *timer0_cfg;

    // 1. select Timer_Mode 
    TCCR0 |= timer0_cfg->Timer_Mode;

    if(timer0_cfg->Timer_Mode == Timer0_Mode_PWM_INVERTING ||
        timer0_cfg->Timer_Mode == Timer0_Mode_PWM_NONINVERTING
        )
    {
        // configure OC0 (PB3) as output
        DIO_SetPinDirection(DIO_PORTB,DIO_PIN3 , DIO_PIN_OUTPUT);
    }

    // 2. select Timer_Clock_Source
    TCCR0 |= timer0_cfg->Timer_Clock_Source;
        if(timer0_cfg->Timer_Clock_Source == Timer_Clock_Source_External_Falling_Edge ||
        timer0_cfg->Timer_Clock_Source == Timer_Clock_Source_External_Rising_Edge
        )
    {
        // configure T0 (PB0) as INPUT
        DIO_SetPinDirection(DIO_PORTB,DIO_PIN0 , DIO_PIN_INPUT);
    }

    // 3. select IRQ_Enable
    TIMSK |= timer0_cfg->IRQ_Enable;
    if(timer0_cfg->IRQ_Enable != IRQ_Enable_NON)
    {
        sei();
    }

    // 4. Call back ISR function
    GP_IRQ_CallBack = timer0_cfg->P_IRQ_CallBack;
}




/*
 * ===================================
 * @FN              - MCAL_Timer0_DeInit
 * @brief           - Deinitialization timer according to specific parameter
 * @retval          - none
 * @Note            - none
 * ===================================
 * */
void MCAL_Timer0_DeInit(void)
{
    TCCR0 &= ~((1<<CS00) | (1<<CS01) | (1<<CS02));
}



/*
 * ===================================
 * @FN              - MCAL_Timer0_GetCounterValue
 * @brief           - get conter value
 * @param [in]      - TicksNumber:  Value to Set in OCR(compare value must not exceed 255).
 * @retval          - none
 * @retval          - none
 * @Note            - none
 * ===================================
 * */
void MCAL_Timer0_GetCounterValue(uint8_t* TicksNumber)
{
    *TicksNumber = TCNT0;
}

