/*
 * bitwise.h
 *
 *  Created: 8/26/2023 12:58:23 PM
 *  Author: Mohamed Belal
 */ 


#ifndef BITWISE_H_
#define BITWISE_H_

#define SETBIT(REGISTER,BIT)      (REGISTER |= (1<<BIT))
#define CLEARBIT(REGISTER,BIT)    (REGISTER &= ~(1<<BIT))
#define TOGGLEBIT(REGISTER,BIT)   (REGISTER ^= (1<<BIT))
#define READBIT(REGISTER,BIT)     ((REGISTER & (1<<BIT))>>BIT)



#endif /* BITWISE_H_ */