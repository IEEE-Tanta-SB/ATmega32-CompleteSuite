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
