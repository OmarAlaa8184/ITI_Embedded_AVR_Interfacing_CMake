/*
 * PORT_CFG.c
 *
 * Created: 1/1/2024 
 * Author: Omar Alaa
 */ 



#include "PORT_INTERFACING.h"
#include "PORT_CFG.h"

/*  
*    array of type enum use to control the configuration of pins 
*    by using enum (MPORT_enuPINConfigration) and fulfill the array
*    using three opitions : 1-MDIO_enuOUTPUT_PIN
*                           2-MDIO_enuINPUT_PULLUP
*                           3-MDIO_enuINPUT_PULLDOWN:not supported in avr 
*/

MPORT_enuPINConfigration MPORT_enuArrPinConfig[MPORT_NUM_OF_PORTS * MPORT_NUM_OF_PINS]=
{ 
  /*PORTA PINS*/
	 MPORT_enuOUTPUT_PIN,
	 MPORT_enuOUTPUT_PIN,
	 MPORT_enuOUTPUT_PIN,
	 MPORT_enuOUTPUT_PIN,
	 MPORT_enuOUTPUT_PIN,
	 MPORT_enuOUTPUT_PIN,
	 MPORT_enuOUTPUT_PIN,
	 MPORT_enuOUTPUT_PIN,
  /*PORTB PINS*/
	 0,
	 0,
	 0,
	 0,
	 0,
	 0,
	 0,
	 0,
  /*PORTC PINS*/
	 0,
	 0,
	 0,
	 0,
	 0,
	 0,
	 0,
	 0,
  /*PORTD PINS*/
	 0,
	 0,
	 0,
	 0 ,
	 0 ,
	 0,
	 0,
	 0
	 
};
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
											 