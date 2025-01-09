/*
 * LED_INTERFACING.h
 *
 * Created: 1/2/2025
 *  Author: Omar Alaa
 */ 



#ifndef LED_INTERFACING_H_
#define LED_INTERFACING_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "LED_CFG.h"


/* 
 * Define an enumeration for error statuses in the HLED module.
 * Each enumerator represents a specific error or state outcome.
 */
typedef enum
{ 
    HLED_enuOK,               /* Operation completed successfully */
    HLED_enuNOK,              /* Operation failed */
    HLED_enuINVALID_LED_NUM,  /* Invalid LED number provided */
    HLED_enuSTATE             /* Invalid state provided */
} HLED_enuErrorStatus_t;

/* 
 * Define constants for LED states.
 * These constants are used to represent whether the LED is ON or OFF.
 */
#define HLED_LED_ON  1  /* LED is turned ON */
#define HLED_LED_OFF 0  /* LED is turned OFF */

/* 
 * Function prototypes for the HLED module.
 */

/* 
 * HLED_vInit
 * This function initializes the LED module. It sets up the configuration for all LEDs.
 */

void HLED_vInit(void);

/* 
 * HLED_enuSetLedState
 * This function sets the state of a specific LED (ON or OFF).
 * Parameters:
 *   - Copy_u8LedNum: The LED number to control.
 *   - Copy_u8State: The desired state of the LED (HLED_LED_ON or HLED_LED_OFF).
 * Returns:
 *   - HLED_enuOK if the operation succeeds.
 *   - Appropriate error status if the operation fails.
 */

HLED_enuErrorStatus_t HLED_enuSetLedState(u8 Copy_u8LedNum, u8 Copy_u8State);












#endif /* LED_INTERFACING_H_ */