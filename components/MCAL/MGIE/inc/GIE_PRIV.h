/*
 * GIE_PRIV.h
 *
 * Created: 2/10/2025 
 *  Author: Omar Alaa
 */ 


#ifndef GIE_PRIV_H_
#define GIE_PRIV_H_

#define SREG            *((volatile u8*)0x5F)  /* Define the Status Register (SREG) at address 0x5F */
#define SREG_I_BIT      (7U)                   /* Define the Interrupt Enable bit position in SREG */

#endif /* GIE_PRIV_H_ */