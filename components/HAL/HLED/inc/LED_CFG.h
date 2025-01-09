/*
 * LED_CFG.h
 *
 * Created: 1/2/2025
 *  Author: Omar Alaa
 */ 


#ifndef LED_CFG_H_
#define LED_CFG_H_

#include "STD_TYPES.h"

/* Define the total number of LEDs in the system */
#define HLED_NUM_OF_LEDS 8

/* Define constants for each LED identifier */
#define LED_0      0  /* LED 0 identifier */
#define LED_1      1  /* LED 1 identifier */
#define LED_2      2  /* LED 2 identifier */
#define LED_3      3  /* LED 3 identifier */
#define LED_4      4  /* LED 4 identifier */
#define LED_5      5  /* LED 5 identifier */
#define LED_6      6  /* LED 6 identifier */
#define LED_7      7  /* LED 7 identifier */

/* 
 * Define a structure to hold LED configuration 
 * Each LED has a port number and a pin number to determine its connection.
 */
typedef struct 
{
   u8 port;  /* Port number where the LED is connected */
   u8 pin;   /* Pin number on the port for the LED */
} HLED_sLedCfg_t;



#endif /* LED_CFG_H_ */