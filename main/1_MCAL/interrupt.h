/******************************************************************************
 * File: interrupt.h
 * Description: This is the header file of external interrupt driver for ATmega32
 * Author: Manal Nabil
 ******************************************************************************/

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

/*******************************************
 *           Section : INCLUDES
 *******************************************/
#include "../4_Common/Platform_Config.h"

/******************************************************************
 *           Section : Macro Configuration References
 ******************************************************************/

#define NULL ((void*)0)

#define LOW_LEVEL                 0
#define ANY_LOGICAL_CHANGE        1
#define FALLING_EDGE              2
#define RISING_EDGE               3

#define Global_Interrupt_Enable   7
#define  ISC00                    0
#define  ISC01                    1
#define  ISC10                    2
#define  ISC11                    3
#define  ISC2                     6

#define INT_0                     0
#define INT_1                     1
#define INT_2                     2

/**
 * @brief Interrupt service routine for INT0.
 */
void __vector_1(void) __attribute__((signal));

/**
 * @brief Interrupt service routine for INT1.
 */
void __vector_2(void) __attribute__((signal));

/**
 * @brief Interrupt service routine for INT2.
 */
void __vector_3(void) __attribute__((signal));

/******************************************************************
 *           Section : User Type Definition (Structures)
 ******************************************************************/

/**
 * @brief Structure for external interrupt configuration.
 */
typedef struct
{
    uint8_t interrupt_channel; /**< The interrupt channel (INT_0, INT_1, or INT_2). */
    uint8_t Sense_control;     /**< The sense control (LOW_LEVEL, ANY_LOGICAL_CHANGE, FALLING_EDGE, or RISING_EDGE). */
} external_interruptConfiguration_t;

/******************************************************************
 *           Section : APIS supported by "INTERRUPT driver"
 ******************************************************************/

/**
 * @brief Enables global interrupts.
 */
void Enable_Global_Interrupt();

/**
 * @brief Disables global interrupts.
 */
void Disable_Global_Interrupt();

/**
 * @brief Enables a specific external interrupt.
 *
 * @param[in] Line The interrupt line to enable (INT_0, INT_1, or INT_2).
 */
void EXTI_EnableInterrupt(uint8_t Line);

/**
 * @brief Disables a specific external interrupt.
 *
 * @param[in] Line The interrupt line to disable (INT_0, INT_1, or INT_2).
 */
void EXTI_DisableInterrupt(uint8_t Line);

/**
 * @brief Sets the signal latch for an external interrupt.
 *
 * @param[in] confg Pointer to the configuration structure for the external interrupt.
 */
void EXTI_SetSignalLatch(external_interruptConfiguration_t *confg);

/**
 * @brief Gets the status of an interrupt flag.
 *
 * @param[in] confg Pointer to the configuration structure for the external interrupt.
 * @param[out] state Pointer to the variable where the flag status will be stored.
 */
void EXTI_FlagStatus(external_interruptConfiguration_t *confg, uint8_t *state);

/**
 * @brief Clears an interrupt flag.
 *
 * @param[in] interrupt_channel The interrupt channel to clear (INT_0, INT_1, or INT_2).
 */
void EXTI_ClearFlag(uint8_t interrupt_channel);

/**
 * @brief Sets a callback function for an external interrupt.
 *
 * @param[in] Copy_pvoidCallBack Pointer to the callback function.
 * @param[in] confg Pointer to the configuration structure for the external interrupt.
 */
void EXTI_voidSetCallBack(void (*Copy_pvoidCallBack)(void), external_interruptConfiguration_t *confg);

#endif /* INTERRUPT_H_ */
