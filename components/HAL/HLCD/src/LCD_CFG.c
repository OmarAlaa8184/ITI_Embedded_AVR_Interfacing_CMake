/*
 * LCD_CFG.c
 *
 * Created: 4/2/2025
 *  Author: Omar Alaa
 */ 


#include "LCD_CFG.h"
#include "LCD_INTERFACING.h"
#include "PORT_INTERFACING.h"

/* Define and initialize the array of LCD configurations */
HLCD_sLCDCfg_t HLCD_sArrLcdCfg[HLCD_NUM_OF_LCDS] =  
{
    [HLCD_0] = {  /* Configuration for LCD 0 */
        .PortPin = {  /* Initialize the pin configurations */
            [HLCD_RS] = PIN_A0,     /* Register Select pin connected to PIN_A0 */
            [HLCD_RW] = PIN_A1,     /* Read/Write pin connected to PIN_A1 */
            [HLCD_ENABLE] = PIN_A2, /* Enable pin connected to PIN_A2 */
            [HLCD_D0] = PIN_D0,     /* Data pin 0 connected to PIN_D0 */
            [HLCD_D1] = PIN_D1,     /* Data pin 1 connected to PIN_D1 */
            [HLCD_D2] = PIN_D2,     /* Data pin 2 connected to PIN_D2 */
            [HLCD_D3] = PIN_D3,     /* Data pin 3 connected to PIN_D3 */
            [HLCD_D4] = PIN_D4,     /* Data pin 4 connected to PIN_D4 */
            [HLCD_D5] = PIN_D5,     /* Data pin 5 connected to PIN_D5 */
            [HLCD_D6] = PIN_D6,     /* Data pin 6 connected to PIN_D6 */
            [HLCD_D7] = PIN_D7,     /* Data pin 7 connected to PIN_D7 */
        },
        .MODE = HLCD_8BIT_MODE  /* Set the LCD mode to 8-bit */
    },
};
