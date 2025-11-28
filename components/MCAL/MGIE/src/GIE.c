/*
 * GIE.c
 *
 * Created: 2/10/2025
 *  Author: Omar Alaa
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_INTERFACING.h"
#include "GIE_PRIV.h"

void GIE_voidEnable(void)  /* Function to enable global interrupts */
{
    SET_BIT(SREG, SREG_I_BIT);  /* Set the I-bit in the Status Register to enable interrupts */
}

void GIE_voidDisable(void)  /* Function to disable global interrupts */
{
    CLR_BIT(SREG, SREG_I_BIT);  /* Clear the I-bit in the Status Register to disable interrupts */
}

