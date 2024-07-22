/******************************************************************************
 * File: interrupt.c
 * Description: This file contains the implementation of external interrupt driver for ATmega32
 * Author: Manal Nabil
 ******************************************************************************/

#include "interrupt.h"

// Array of pointers to callback functions for external interrupts
void (*EXTI_CallBack[3]) (void) = { NULL };

/**
 * @brief Enables global interrupts.
 */
void Enable_Global_Interrupt()
{
    SET_BIT(SREG, Global_Interrupt_Enable);
}

/**
 * @brief Disables global interrupts.
 */
void Disable_Global_Interrupt()
{
    CLEAR_BIT(SREG, Global_Interrupt_Enable);
}

/**
 * @brief Enables a specific external interrupt.
 *
 * @param[in] Line The interrupt line to enable (INT_0, INT_1, or INT_2).
 */
void EXTI_EnableInterrupt(uint8_t Line)
{
    switch(Line)
    {
        case INT_0: SET_BIT(GICR, 6); break;
        case INT_1: SET_BIT(GICR, 7); break;
        case INT_2: SET_BIT(GICR, 5); break;
    }
}

/**
 * @brief Disables a specific external interrupt.
 *
 * @param[in] Line The interrupt line to disable (INT_0, INT_1, or INT_2).
 */
void EXTI_DisableInterrupt(uint8_t Line)
{
    switch(Line)
    {
        case INT_0: CLEAR_BIT(GICR, 6); break;
        case INT_1: CLEAR_BIT(GICR, 7); break;
        case INT_2: CLEAR_BIT(GICR, 5); break;
    }
}

/**
 * @brief Sets the signal latch for an external interrupt.
 *
 * @param[in] confg Pointer to the configuration structure for the external interrupt.
 */
void EXTI_SetSignalLatch(external_interruptConfiguration_t *confg)
{
    if (confg->interrupt_channel == INT_0)
    {
        if (confg->Sense_control == LOW_LEVEL)
        {
            CLEAR_BIT(MCUCR, ISC00);
            CLEAR_BIT(MCUCR, ISC01);
        }
        else if (confg->Sense_control == ANY_LOGICAL_CHANGE)
        {
            SET_BIT(MCUCR, ISC00);
            CLEAR_BIT(MCUCR, ISC01);
        }
        else if (confg->Sense_control == FALLING_EDGE)
        {
            CLEAR_BIT(MCUCR, ISC00);
            SET_BIT(MCUCR, ISC01);
        }
        else if (confg->Sense_control == RISING_EDGE)
        {
            SET_BIT(MCUCR, ISC00);
            SET_BIT(MCUCR, ISC01);
        }
    }
    else if (confg->interrupt_channel == INT_1)
    {
        if (confg->Sense_control == LOW_LEVEL)
        {
            CLEAR_BIT(MCUCR, ISC10);
            CLEAR_BIT(MCUCR, ISC11);
        }
        else if (confg->Sense_control == ANY_LOGICAL_CHANGE)
        {
            SET_BIT(MCUCR, ISC10);
            CLEAR_BIT(MCUCR, ISC11);
        }
        else if (confg->Sense_control == FALLING_EDGE)
        {
            CLEAR_BIT(MCUCR, ISC10);
            SET_BIT(MCUCR, ISC11);
        }
        else if (confg->Sense_control == RISING_EDGE)
        {
            SET_BIT(MCUCR, ISC10);
            SET_BIT(MCUCR, ISC11);
        }
    }
    else if (confg->interrupt_channel == INT_2)
    {
        if (confg->Sense_control == FALLING_EDGE)
        {
            CLEAR_BIT(MCUCSR, ISC2);
        }
        else if (confg->Sense_control == RISING_EDGE)
        {
            SET_BIT(MCUCSR, ISC2);
        }
    }
}

/**
 * @brief Gets the status of an interrupt flag.
 *
 * @param[in] confg Pointer to the configuration structure for the external interrupt.
 * @param[out] state Pointer to the variable where the flag status will be stored.
 */
void EXTI_FlagStatus(external_interruptConfiguration_t *confg, uint8_t *state)
{
    if (confg->interrupt_channel == INT_0)
    {
        *state = READ_BIT(GIFR, 6);
    }
    else if (confg->interrupt_channel == INT_1)
    {
        *state = READ_BIT(GIFR, 7);
    }
    else if (confg->interrupt_channel == INT_2)
    {
        *state = READ_BIT(GIFR, 5);
    }
}

/**
 * @brief Clears an interrupt flag.
 *
 * @param[in] interrupt_channel The interrupt channel to clear (INT_0, INT_1, or INT_2).
 */
void EXTI_ClearFlag(uint8_t interrupt_channel)
{
    if (interrupt_channel == INT_0)
    {
        SET_BIT(GIFR, 6);
    }
    else if (interrupt_channel == INT_1)
    {
        SET_BIT(GIFR, 7);
    }
    else if (interrupt_channel == INT_2)
    {
        SET_BIT(GIFR, 5);
    }
}

/**
 * @brief Sets a callback function for an external interrupt.
 *
 * @param[in] Copy_pvoidCallBack Pointer to the callback function.
 * @param[in] confg Pointer to the configuration structure for the external interrupt.
 */
void EXTI_voidSetCallBack(void (*Copy_pvoidCallBack)(void), external_interruptConfiguration_t *confg)
{
    if(Copy_pvoidCallBack != NULL)
    {
        EXTI_CallBack[confg->interrupt_channel] = Copy_pvoidCallBack;
    }
}

/**
 * @brief Interrupt service routine for INT0.
 */
void __vector_1(void)
{
    if(EXTI_CallBack[0] != NULL)
    {
        EXTI_CallBack[0]();
        EXTI_ClearFlag(INT_0);
    }
}

/**
 * @brief Interrupt service routine for INT1.
 */
void __vector_2(void)
{
    if(EXTI_CallBack[1] != NULL)
    {
        EXTI_CallBack[1]();
        EXTI_ClearFlag(INT_1);
    }
}

/**
 * @brief Interrupt service routine for INT2.
 */
void __vector_3(void)
{
    if(EXTI_CallBack[2] != NULL)
    {
        EXTI_CallBack[2]();
        EXTI_ClearFlag(INT_2);
    }
}
