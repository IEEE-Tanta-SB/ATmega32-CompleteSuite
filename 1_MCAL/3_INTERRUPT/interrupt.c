/*
 * interrupt.c
 *
 * Created: 7/15/2024 1:16:39 PM
 *  Author: Manal Nabil
 */
#include "interrupts.h"

void (*EXTI_CallBack[3]) (void) = { NULL } ;
void external_interrupts_enable()
{
    SET_BIT(SREG , 7);
}
void external_interrupt0_enable()
{
    SET_BIT(GICR , 6);
}
void external_interrupt1_enable()
{
    SET_BIT(GICR , 7);
}
void external_interrupt2_enable()
{
    SET_BIT(GICR , 5);
}

void external_interrupts_configuration(external_interruptConfiguration_t *confg)
{
    if (confg->interrupt_channel == INT_0)
    {
        if (confg->Sense_control == LOW_LEVEL)
        {
            CLEAR_BIT(MCUCR , 0);
            CLEAR_BIT(MCUCR , 1);
        }
        else if (confg->Sense_control == ANY_LOGICAL_CHANGE)
        {
            SET_BIT(MCUCR , 0);
            CLEAR_BIT(MCUCR , 1);
        }
        else if (confg->Sense_control == FALLING_EDGE)
        {
            CLEAR_BIT(MCUCR , 0);
            SET_BIT(MCUCR , 1);
        }
        else if (confg->Sense_control == RISING_EDGE)
        {
            SET_BIT(MCUCR , 0);
            SET_BIT(MCUCR , 1);
        }

    }
    else if (confg->interrupt_channel == INT_1)
    {
        if (confg->Sense_control == LOW_LEVEL)
        {
            CLEAR_BIT(MCUCR , 2);
            CLEAR_BIT(MCUCR , 3);
        }
        else if (confg->Sense_control == ANY_LOGICAL_CHANGE)
        {
            SET_BIT(MCUCR , 2);
            CLEAR_BIT(MCUCR , 3);
        }
        else if (confg->Sense_control == FALLING_EDGE)
        {
            CLEAR_BIT(MCUCR , 2);
            SET_BIT(MCUCR , 3);
        }
        else if (confg->Sense_control == RISING_EDGE)
        {
            SET_BIT(MCUCR , 2);
            SET_BIT(MCUCR , 3);
        }
    }
    else if (confg->interrupt_channel == INT_2)
    {
        if (confg->Sense_control == FALLING_EDGE)
        {
            CLEAR_BIT(MCUCSR , 6);
        }
        else if (confg->Sense_control == RISING_EDGE)
        {
            SET_BIT(MCUCSR , 6);
        }
    }
}
