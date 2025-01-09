/*
 * DIO_CFG.c
 *
 * Created: 12/25/2024 2:19:11 PM
 *  Author: Omar Alaa
 */ 



#include "DIO_INTERFACING.h"
#include "DIO_CFG.h"

/*  
*    array of type enum use to control the configuration of pins 
*    by using enum (MDIO_enuPINConfigration) and fulfill the array
*    using three opitions : 1-MDIO_enuOUTPUT_PIN
*                           2-MDIO_enuINPUT_PULLUP
*                           3-MDIO_enuINPUT_PULLDOWN:not supported in avr 
*/

MDIO_enuPINConfigration MDIO_enuArrPinConfig[MDIO_NUM_OF_PORTS * MDIO_NUM_OF_PINS]=
{ 
  /*PORTA PINS*/
	 MDIO_enuOUTPUT_PIN,
	 MDIO_enuOUTPUT_PIN,
	 MDIO_enuOUTPUT_PIN,
	 MDIO_enuOUTPUT_PIN,
	 0,
	 0,
	 0,
	 0,
  /*PORTB PINS*/
	 MDIO_enuOUTPUT_PIN,
	 MDIO_enuOUTPUT_PIN,
	 MDIO_enuOUTPUT_PIN,
	 MDIO_enuOUTPUT_PIN,
	 0,
	 0,
	 0,
	 0,
  /*PORTC PINS*/
	 MDIO_enuOUTPUT_PIN,
	 0,
	 0,
	 0,
	 0,
	 0,
	 0,
	 0,
  /*PORTD PINS*/
	 MDIO_enuINPUT_PULLUP,
	 0,
	 0,
	 MDIO_enuINPUT_PULLUP ,
	 MDIO_enuINPUT_PULLUP ,
	 MDIO_enuINPUT_PULLUP,
	 0,
	 0
	 
};
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
											 