/*
 * interrupt.h
 *
 * Created: 7/15/2024 1:16:24 PM
 *  Author: Manal Nabil
 */


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
/*******************************************
			 Section :INCLUDES
*******************************************/

#include "../4_Common/Platform_Config.h"

/******************************************************************
				Section :Macro Configuration References
******************************************************************/

#define NULL ((void*)0)

#define LOW_LEVEL 0
#define ANY_LOGICAL_CHANGE 1
#define FALLING_EDGE 2
#define RISING_EDGE 3

#define INT_0 0
#define INT_1 1
#define INT_2 2

void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));

/******************************************************************
				Section :User Type Definition (Structures)
******************************************************************/

typedef struct
{
    uint8_t interrupt_channel;
    uint8_t Sense_control;
}external_interruptConfiguration_t;

/******************************************************************
				Section :APIS supported by "INTERRUPT driver"
******************************************************************/

void Enable_Global_Interrupt           ();
void Disable_Global_Interrupt          ();
void EXTI_EnableInterrupt              (uint8_t Line);
void EXTI_DisableInterrupt             (uint8_t Line);
void EXTI_SetSignalLatch               (external_interruptConfiguration_t *confg);
void EXTI_FlagStatus                   (external_interruptConfiguration_t *confg , uint8_t *state);
void EXTI_ClearFlag                    (uint8_t interrupt_channel);
void EXTI_voidSetCallBack              ( void (*Copy_pvoidCallBack)(void) , external_interruptConfiguration_t *confg );


#endif /* INTERRUPT_H_ */
