/*
 * Layered architecture.c
 *
 * Created: 12/17/2024 1:22:57 PM
 * Author : Omar Alaa
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_INTERFACING.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "7segtest.h"


int main(void)
{ 

    while (1) 
    {
	  segtest();
	  
    }
}


void segtest(void)
{
	 MDIO_enuSetPortConfigration(MDIO_enuPORTA,MDIO_enuOUTPUT_PORT);

     MDIO_enuSetPortValue(MDIO_enuPORTA, MDIO_enuLOW_PORT);

}


