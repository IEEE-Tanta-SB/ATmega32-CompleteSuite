/******************************************************************************
 * File: Platform_Config.h
 * Description: ATmega32 Configurations
 * Author: Mohamed Belal
 ******************************************************************************/

#ifndef ATMEG32_CONFIG_H_
#define ATMEG32_CONFIG_H_

/* =============================================
 *                     Clock
 * ============================================= */
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

/* =============================================
 *                  AVR header 
 * ============================================= */

#include "Platform_MemoryMap.h"
#include "Common_Macros.h"
#include "Platform_Types.h"
#include <util/delay.h>
#include "avr/interrupt.h"

#endif /* ATMEG32_CONFIG_H_ */
