/*
 * LED.C
 *
 * Created: 1/2/2025
 *  Author: Omar Alaa
 */ 

#include "DIO_INTERFACING.h"
#include "PORT_INTERFACING.h"
#include "LED_INTERFACING.h"
#include "LED_CFG.h"


/* 
 * External declaration of the LED configuration array.
 * This array contains the port and pin configuration for each LED in the system.
 */
extern HLED_sLedCfg_t HLED_sArrLedCfg[HLED_NUM_OF_LEDS];

/* 
 * Function: HLED_vInit
 * --------------------
 * Initializes the direction of all LEDs in the system.
 * Each LED's port and pin are retrieved from the configuration array and set to output.
 */
void HLED_vInit(void)
{
    u8 Local_u8CurrPortPin = 0; /* Variable to store combined port and pin information */

    /* Iterate through all LEDs in the configuration array */
    for (u8 Local_u8Conter = 0; Local_u8Conter < HLED_NUM_OF_LEDS; Local_u8Conter++)
    {
        /* Combine port and pin into a single value for the current LED */
        Local_u8CurrPortPin = (((HLED_sArrLedCfg[Local_u8Conter].port) << 4) + (HLED_sArrLedCfg[Local_u8Conter].pin));
        
        /* Set the pin direction to output for the current LED */
        MPORT_enuSetPinDirection(Local_u8CurrPortPin, MPORT_OUTPUT_PIN);
    }
}

/* 
 * Function: HLED_enuSetLedState
 * -----------------------------
 * Sets the state (ON/OFF) of a specific LED.
 * 
 * Parameters:
 *   Copy_u8LedNum - The LED number to control (e.g., LED_0 to LED_7).
 *   Copy_u8State  - The desired state of the LED (HLED_LED_ON or HLED_LED_OFF).
 * 
 * Returns:
 *   HLED_enuErrorStatus_t - Error status indicating success or failure:
 *      - HLED_enuOK for success
 *      - HLED_enuINVALID_LED_NUM if the LED number is invalid
 *      - HLED_enuSTATE if the state value is invalid
 */
HLED_enuErrorStatus_t HLED_enuSetLedState(u8 Copy_u8LedNum, u8 Copy_u8State)
{
    HLED_enuErrorStatus_t Ret_enuError = HLED_enuNOK; /* Default return error status */

    /* Validate LED number */
    if (Copy_u8LedNum > LED_7 || Copy_u8LedNum < LED_0)
    {
        Ret_enuError = HLED_enuINVALID_LED_NUM;
    }
    /* Validate LED state */
    else if (Copy_u8State > HLED_LED_ON || Copy_u8State < HLED_LED_OFF)
    {
        Ret_enuError = HLED_enuSTATE;
    }
    else
    {   
        Ret_enuError = HLED_enuOK; /* Update return status to success */
        
        /* Set the pin value for the specified LED based on the desired state */
        MDIO_enuSetPinValue(HLED_sArrLedCfg[Copy_u8LedNum].port, HLED_sArrLedCfg[Copy_u8LedNum].pin, Copy_u8State);
    }

    return Ret_enuError; /* Return the error status */
}
