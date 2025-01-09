/*
 * LED_CFG.c
 *
 * Created: 1/2/2025
 *  Author: Omar Alaa
 */ 


#include "LED_CFG.h"
#include "PORT_INTERFACING.h"



/* 
 * Array of LED configurations.
 * This array contains the port and pin mappings for each LED in the system.
 * Each entry corresponds to an LED and specifies its hardware connection.
 */
HLED_sLedCfg_t HLED_sArrLedCfg[HLED_NUM_OF_LEDS] = 
{
    /* LED_0 Configuration: Connected to PORTA, PIN0 */
    [LED_0] = {   
                .port = MPORT_enuPORTA,  /* Port A */
                .pin = MPORT_enuPIN0    /* Pin 0 */
              },

    /* LED_1 Configuration: Connected to PORTA, PIN1 */
    [LED_1] = {   
                .port = MPORT_enuPORTA,  /* Port A */
                .pin = MPORT_enuPIN1    /* Pin 1 */
              },  

    /* LED_2 Configuration: Connected to PORTA, PIN2 */
    [LED_2] = {   
                 .port = MPORT_enuPORTA, /* Port A */
                 .pin = MPORT_enuPIN2   /* Pin 2 */
              },

    /* LED_3 Configuration: Connected to PORTA, PIN3 */
    [LED_3] = {   
                 .port = MPORT_enuPORTA, /* Port A */
                 .pin = MPORT_enuPIN3   /* Pin 3 */
              },

    /* LED_4 Configuration: Connected to PORTA, PIN4 */
    [LED_4] = {   
                 .port = MPORT_enuPORTA, /* Port A */
                 .pin = MPORT_enuPIN4   /* Pin 4 */
              },

    /* LED_5 Configuration: Connected to PORTA, PIN5 */
    [LED_5] = {   
                 .port = MPORT_enuPORTA, /* Port A */
                 .pin = MPORT_enuPIN5   /* Pin 5 */
              },

    /* LED_6 Configuration: Connected to PORTD, PIN0 */
    [LED_6] = {   
                 .port = MPORT_enuPORTD, /* Port D */
                 .pin = MPORT_enuPIN0   /* Pin 0 */
              },

    /* LED_7 Configuration: Connected to PORTA, PIN7 */
    [LED_7] = {   
                 .port = MPORT_enuPORTA, /* Port A */
                 .pin = MPORT_enuPIN7   /* Pin 7 */
              }
};






	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
											 