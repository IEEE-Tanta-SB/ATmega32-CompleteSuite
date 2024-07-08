/*
 * Platform_Types.h
 *
 *  Created on: Apr 14, 2023
 *      Author: mohamed belal
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_


#ifndef _Bool
#define _Bool unsigned char
#endif

#ifndef FALSE
#define FLASE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#define CPU_TYPE                        CPU_TYPE_32
#define CPU_BIT_ORDER                   MSB_FIRST
#define CPU_BYTE_ORDER                  HIGH_BYTE_FIRST

typedef _Bool                           boolean;


typedef unsigned char                   uint8_t;
typedef unsigned short                  unit16_t;
typedef unsigned long                   uint32_t;
typedef unsigned long long              uint64_t;

typedef signed char                     sint8_t;
typedef signed short                    sint16_t;
typedef signed long                     sint32_t;
typedef signed long long                sint64_t;

typedef volatile unsigned char          vuint8_t;
typedef volatile unsigned short         vunit16_t;
typedef volatile unsigned long          vuint32_t;
typedef volatile unsigned long long     vuint64_t;

typedef volatile signed char            vsint8_t;
typedef volatile signed short           vsint16_t;
typedef volatile signed long            vsint32_t;
typedef volatile signed long long       vsint64_t;





#endif /* PLATFORM_TYPES_H_ */