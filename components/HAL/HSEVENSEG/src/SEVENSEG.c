/*
 * SEVENSEG.C
 *
 * Created: 1/5/2025
 *  Author: Omar Alaa
 */ 

#include "DIO_INTERFACING.h"
#include "PORT_INTERFACING.h"
#include "SEVENSEG_INTERFACING.h"
#include "SEVENSEG_CFG.h"

/* 
 * Array that maps each digit (0-9) and the dot to the corresponding value to display on the 7-segment display.
 * This array holds the 7-segment patterns for digits 0 to 9 and the dot. 
 */
u8 HSEVENSEG_arrValuesMap[] = {
                             HSEVENSEG_0,    /* 0 */
                             HSEVENSEG_1,    /* 1 */
                             HSEVENSEG_2,    /* 2 */
                             HSEVENSEG_3,    /* 3 */
                             HSEVENSEG_4,    /* 4 */
                             HSEVENSEG_5,    /* 5 */
                             HSEVENSEG_6,    /* 6 */
                             HSEVENSEG_7,    /* 7 */
                             HSEVENSEG_8,    /* 8 */
                             HSEVENSEG_9,    /* 9 */
                             HSEVENSEG_dot   /* Dot */
                          };

/* 
 * External configuration array that contains the configuration for each 7-segment display.
 * It includes the pin mappings and the operating mode (Common Cathode or Common Anode).
 */
extern HSEVENSEG_sSEVENSEGCfg_t HSEVENSEG_sArrSEVENSEGCfg[HSEVENSEG_NUM_OF_SEVENSEGS];

/* 
 * Function to initialize all 7-segment displays.
 * This function sets up the pins for each display, determines if the display uses common cathode or common anode, 
 * and sets the appropriate initial pin states (LOW for common cathode or HIGH for common anode).
 */
void HSEVENSEG_vInit(void)
{
    u8 Local_u8Port = 0;       
    u8 Local_u8Pin = 0;  

    /* Loop through each 7-segment display */
    for (u8 Local_u8Counter = 0; Local_u8Counter < HSEVENSEG_NUM_OF_SEVENSEGS; Local_u8Counter++)
    {
        /* Loop through each pin (a, b, c, d, e, f, g, dot) of the current display */
        for (u8 Local_u8Counter1 = 0; Local_u8Counter1 < HSEVENSEG_NUM_OF_PINS; Local_u8Counter1++)
        {
            /* Set pin direction to output */
            MPORT_enuSetPinDirection(HSEVENSEG_sArrSEVENSEGCfg[Local_u8Counter].PortPin[Local_u8Counter1], MPORT_OUTPUT_PIN);

            /* Check the mode (Common Cathode or Common Anode) and initialize pin states accordingly */
            if (HSEVENSEG_sArrSEVENSEGCfg[Local_u8Counter].HSEVENSEG_MODE == HSEVENSEG_MODE_COMMON_CATHODE)
            {
                /* For common cathode, set pin low */
                Local_u8Port = HSEVENSEG_sArrSEVENSEGCfg[Local_u8Counter].PortPin[Local_u8Counter1] >> 4;
                Local_u8Pin = HSEVENSEG_sArrSEVENSEGCfg[Local_u8Counter].PortPin[Local_u8Counter1] & 0x0F;
                MDIO_enuSetPinValue(Local_u8Port, Local_u8Pin, MDIO_enuLOW_PIN);
            }
            else
            {
                /* For common anode, set pin high */
                Local_u8Port = HSEVENSEG_sArrSEVENSEGCfg[Local_u8Counter].PortPin[Local_u8Counter1] >> 4;
                Local_u8Pin = HSEVENSEG_sArrSEVENSEGCfg[Local_u8Counter].PortPin[Local_u8Counter1] & 0x0F;
                MDIO_enuSetPinValue(Local_u8Port, Local_u8Pin, MDIO_enuHIGH_PIN);
            }
        }             
    }
}

/* 
 * Function to set a specific value on a single 7-segment display.
 * The function converts the provided digit (0-9) into its corresponding 7-segment pattern 
 * and updates the pins accordingly.
 * 
 * @param Copy_enuSevenSegNum: The index of the 7-segment display (0, 1, 2, etc.).
 * @param Copy_u8Value: The digit (0-9) to be displayed on the 7-segment display.
 */
void HSEVENSEG_vSetValue(u8 Copy_enuSevenSegNum, u8 Copy_u8Value)
{
    u8 Local_u8Temp = 0;
    u8 Local_u8Port = 0;       
    u8 Local_u8Pin = 0;           

    /* Loop through each pin of the 7-segment (a, b, c, d, e, f, g, dot) */
    for (u8 Local_u8Counter = HSEVENSEG_PIN_a; Local_u8Counter < HSEVENSEG_PIN_dot; Local_u8Counter++)
    {
        /* Get the corresponding bit for the current pin based on the selected 7-segment value */
        if (HSEVENSEG_sArrSEVENSEGCfg[Copy_enuSevenSegNum].HSEVENSEG_MODE == HSEVENSEG_MODE_COMMON_CATHODE)
        {
            /* For common cathode, the bit will be used as it is */
            Local_u8Temp = GET_BIT(HSEVENSEG_arrValuesMap[Copy_u8Value], (HSEVENSEG_sArrSEVENSEGCfg[Copy_enuSevenSegNum].PortPin[Local_u8Counter] & 0x0F));
        }
        else
        {
            /* For common anode, invert the bit */
            Local_u8Temp = !GET_BIT(HSEVENSEG_arrValuesMap[Copy_u8Value], (HSEVENSEG_sArrSEVENSEGCfg[Copy_enuSevenSegNum].PortPin[Local_u8Counter] & 0x0F));
        }

        /* Get the port and pin for the current pin of the 7-segment */
        Local_u8Port = HSEVENSEG_sArrSEVENSEGCfg[Copy_enuSevenSegNum].PortPin[Local_u8Counter] >> 4;
        Local_u8Pin = HSEVENSEG_sArrSEVENSEGCfg[Copy_enuSevenSegNum].PortPin[Local_u8Counter] & 0x0F;

        /* Set the pin value (HIGH or LOW) based on the mode */
        MDIO_enuSetPinValue(Local_u8Port, Local_u8Pin, Local_u8Temp);
    } 
}

/* 
 * Function to set a multi-digit value across multiple 7-segment displays.
 * The function will split the value into its individual digits and set each 7-segment display to display a single digit.
 * 
 * @param Copy_u16Value: The multi-digit value (e.g., 1234) to display across the 7-segment displays.
 * @return HSEVENSEG_enuErrorStatus_t: The result of the operation (success or error).
 */

HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuSetMultiDigitValue(u16 Copy_u16Value)
{
    u8 Local_u8DIGITS = 0;
    u8 Local_u8TEMP = Copy_u16Value;
    HSEVENSEG_enuErrorStatus_t Ret_enuError = HSEVENSEG_enuNOK;

    /* Count the number of digits in the value */
    while (Local_u8TEMP > 0)
    {
        Local_u8TEMP /= 10;
        Local_u8DIGITS++;
    }

    /* Check if the number of digits exceeds the available 7-segment displays */
    if (Local_u8DIGITS > HSEVENSEG_NUM_OF_SEVENSEGS)
    {
        Ret_enuError = HSEVENSEG_enuINVALID_SEVENSEG_NUM;
    }
    else
    {
        Ret_enuError = HSEVENSEG_enuOK;

        /* Set the value for each digit on the corresponding 7-segment display */
        Local_u8TEMP = Copy_u16Value;
        for (u8 Local_u8Counter = 0; Local_u8Counter < Local_u8DIGITS; Local_u8Counter++)
        {
            HSEVENSEG_vSetValue(Local_u8Counter, (Local_u8TEMP % 10));
            Local_u8TEMP /= 10;
        }
    }

    return Ret_enuError;
}
