/*
 * LCD.C
 *
 * Created: 1/28/2025
 *  Author: Omar Alaa
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_INTERFACING.h"
#include "PORT_INTERFACING.h"
#include "LCD_INTERFACING.h"
#include "LCD_CFG.h"


extern HLCD_sLCDCfg_t HLCD_sArrLcdCfg[HLCD_NUM_OF_LCDS];  /* Declare the external array of LCD configurations */

void HLCD_vInit(void)  /* Function to initialize the LCD */
{
    for (u8 Local_u8Counter = 0; Local_u8Counter < HLCD_NUM_OF_LCDS; Local_u8Counter++)  /* Loop through each LCD */
    {
        for (u8 Local_u8Counter1 = 0; Local_u8Counter1 < HLCD_NUM_OF_PINS; Local_u8Counter1++)  /* Loop through each pin */
        {
            if (HLCD_sArrLcdCfg[Local_u8Counter].MODE == HLCD_8BIT_MODE)  /* Check if the LCD is in 8-bit mode */
            {
                MPORT_enuSetPinDirection(HLCD_sArrLcdCfg[Local_u8Counter].PortPin[Local_u8Counter1], MPORT_OUTPUT_PIN);  /* Set pin direction to output */
                MDIO_enuSetPinValue((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[Local_u8Counter1]) >> 4,
                                    (HLCD_sArrLcdCfg[Local_u8Counter].PortPin[Local_u8Counter1]) & 0x0F,
                                    MDIO_enuLOW_PIN);  /* Set pin value to low */
            }
        }
        _delay_ms(40);  /* Delay for initialization */
        // Function set
        HLCD_enuWriteCommand(0x38);  /* Send function set command */
        _delay_us(40);  /* Delay for command execution */
        // Display on/off
        HLCD_enuWriteCommand(0x0F);  /* Send display on/off command */
        _delay_us(40);  /* Delay for command execution */
        // Display clear
        HLCD_enuWriteCommand(0x01);  /* Send display clear command */
        _delay_ms(2);  /* Delay for command execution */
        // Entry mode set
        HLCD_enuWriteCommand(0x06);  /* Send entry mode set command */
        _delay_us(50);  /* Delay for command execution */
    }
}

void HLCD_enuWriteCommand(u8 Copy_u8Command)  /* Function to write a command to the LCD */
{
    u8 Local_u8Variable = 0;
    for (u8 Local_u8Counter = 0; Local_u8Counter < HLCD_NUM_OF_LCDS; Local_u8Counter++)  /* Loop through each LCD */
    {
        MDIO_enuSetPinValue(((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[HLCD_RW]) >> 4),
                            ((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[HLCD_RW]) & 0x0F),
                            MDIO_enuLOW_PIN);  /* Set RW pin to low */

        MDIO_enuSetPinValue(((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[HLCD_RS]) >> 4),
                            ((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[HLCD_RS]) & 0x0F),
                            MDIO_enuLOW_PIN);  /* Set RS pin to low */

        for (u8 Local_u8Counter1 = HLCD_D0; Local_u8Counter1 <= HLCD_D7; Local_u8Counter1++)  /* Loop through each data pin */
        {
            Local_u8Variable = GET_BIT(Copy_u8Command, (Local_u8Counter1 - HLCD_D0));  /* Get the bit value */
            MDIO_enuSetPinValue(((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[Local_u8Counter1]) >> 4),
                                ((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[Local_u8Counter1]) & 0x0F),
                                Local_u8Variable);  /* Set the pin value */
        }

        MDIO_enuSetPinValue(((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[HLCD_ENABLE]) >> 4),
                            ((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[HLCD_ENABLE]) & 0x0F),
                            MDIO_enuHIGH_PIN);  /* Set enable pin to high */
        _delay_ms(20);  /* Delay for command execution */
        MDIO_enuSetPinValue(((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[HLCD_ENABLE]) >> 4),
                            ((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[HLCD_ENABLE]) & 0x0F),
                            MDIO_enuLOW_PIN);  /* Set enable pin to low */
        _delay_ms(10);  /* Delay for command execution */
    }
}

void HLCD_enuWriteData(u8 Copy_u8Data)  /* Function to write data to the LCD */
{
    u8 Local_u8Variable = 0;
    for (u8 Local_u8Counter = 0; Local_u8Counter < HLCD_NUM_OF_LCDS; Local_u8Counter++)  /* Loop through each LCD */
    {
        MDIO_enuSetPinValue(((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[HLCD_RW]) >> 4),
                            ((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[HLCD_RW]) & 0x0F),
                            MDIO_enuLOW_PIN);  /* Set RW pin to low */
        MDIO_enuSetPinValue(((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[HLCD_RS]) >> 4),
                            ((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[HLCD_RS]) & 0x0F),
                            MDIO_enuHIGH_PIN);  /* Set RS pin to high */

        for (u8 Local_u8Counter1 = HLCD_D0; Local_u8Counter1 <= HLCD_D7; Local_u8Counter1++)  /* Loop through each data pin */
        {
            Local_u8Variable = GET_BIT(Copy_u8Data, (Local_u8Counter1 - HLCD_D0));  /* Get the bit value */
            MDIO_enuSetPinValue(((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[Local_u8Counter1]) >> 4),
                                ((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[Local_u8Counter1]) & 0x0F),
                                Local_u8Variable);  /* Set the pin value */
        }

        MDIO_enuSetPinValue(((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[HLCD_ENABLE]) >> 4),
                            ((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[HLCD_ENABLE]) & 0x0F),
                            MDIO_enuHIGH_PIN);  /* Set enable pin to high */
        _delay_ms(20);  /* Delay for data execution */
        MDIO_enuSetPinValue(((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[HLCD_ENABLE]) >> 4),
                            ((HLCD_sArrLcdCfg[Local_u8Counter].PortPin[HLCD_ENABLE]) & 0x0F),
                            MDIO_enuLOW_PIN);  /* Set enable pin to low */
        _delay_ms(20);  /* Delay for data execution */
    }
}

HLCD_enuErrorStatus_t HLCD_enuWriteString(u8* Copy_u8String)  /* Function to write a string to the LCD */
{
    u8 Local_u8Counter = 0;
    HLCD_enuErrorStatus_t Ret_enuError = HLCD_enuNOK;  /* Initialize error status to NOK (Not OK) */

    if (Copy_u8String == NULL)  /* Check if the input string is NULL */
    {
        Ret_enuError = HLCD_enuNULL_PTR;  /* Set error status to NULL pointer */
    }
    else
    {
        Ret_enuError = HLCD_enuOK;  /* Set error status to OK */
        while (Copy_u8String[Local_u8Counter] != '\0')  /* Loop through each character in the string */
        {
            if (Local_u8Counter > HLCD_NUM_OF_COLUMNS)  /* Check if the string exceeds the number of columns */
            {
                Ret_enuError = HLCD_enuINVALID_LCD_COL;  /* Set error status to invalid column */
                break;
            }
            else
            {
                HLCD_enuWriteData(Copy_u8String[Local_u8Counter]);  /* Write the character to the LCD */
                Local_u8Counter++;  /* Increment the counter */
            }
        }
    }

    return Ret_enuError;  /* Return the error status */
}

HLCD_enuErrorStatus_t HLCD_enuWriteNumber(u32 Copy_u8Number)  /* Function to write a number to the LCD */
{
    u8 Local_u8Digits = 0;
    u32 Local_u8Temp0 = Copy_u8Number;
    HLCD_enuErrorStatus_t Ret_enuError = HLCD_enuNOK;  /* Initialize error status to NOK (Not OK) */

    while (Local_u8Temp0 != 0)  /* Calculate the number of digits in the number */
    {
        Local_u8Temp0 /= 10;  /* Divide the number by 10 */
        Local_u8Digits++;  /* Increment the digit count */
    }

    if (Local_u8Digits > HLCD_NUM_OF_COLUMNS)  /* Check if the number exceeds the number of columns */
    {
        Ret_enuError = HLCD_enuINVALID_LCD_COL;  /* Set error status to invalid column */
    }
    else
    {
        Ret_enuError = HLCD_enuOK;  /* Set error status to OK */
        Local_u8Temp0 = Copy_u8Number;  /* Reset the temporary variable */
        u8 Local_u8Temp1[HLCD_NUM_OF_COLUMNS];  /* Array to store the digits */

        for (u8 Local_u8Counter = 0; Local_u8Counter < Local_u8Digits; Local_u8Counter++)  /* Loop through each digit */
        {
            Local_u8Temp1[Local_u8Counter] = Local_u8Temp0 % 10;  /* Get the last digit */
            Local_u8Temp0 /= 10;  /* Remove the last digit */
        }

        for (u8 Local_u8Counter = Local_u8Digits; Local_u8Counter > 0; Local_u8Counter--)  /* Loop through each digit in reverse order */
        {
            HLCD_enuWriteData(Local_u8Temp1[Local_u8Counter - 1] + '0');  /* Write the digit to the LCD */
        }
    }

    return Ret_enuError;  /* Return the error status */
}

HLCD_enuErrorStatus_t HLCD_enuGoToXY(HLCD_enuNumberOfRows_t Copy_u8X, HLCD_enuNumberOfCols_t Copy_u8Y)  /* Function to set the cursor position on the LCD */
{
    HLCD_enuErrorStatus_t Ret_enuError = HLCD_enuNOK;  /* Initialize error status to NOK (Not OK) */
    u8 Local_u8Location = 0;

    if (Copy_u8X > HLCD_NUM_OF_ROWS)  /* Check if the row is valid */
    {
        Ret_enuError = HLCD_enuINVALID_LCD_ROW;  /* Set error status to invalid row */
    }
    else if (Copy_u8Y > HLCD_NUM_OF_COLUMNS)  /* Check if the column is valid */
    {
        Ret_enuError = HLCD_enuINVALID_LCD_COL;  /* Set error status to invalid column */
    }
    else
    {
        Ret_enuError = HLCD_enuOK;  /* Set error status to OK */
        if (Copy_u8X == HLCD_ROW0)  /* Check if the row is 0 */
        {
            Local_u8Location = Copy_u8Y;  /* Set the location to the column */
        }
        else
        {
            Local_u8Location = Copy_u8Y + HLCD_DDRAM_ADDRESS;  /* Set the location to the column plus the DDRAM address offset */
        }

        HLCD_enuWriteCommand(HLCD_DDRAM_DB7_msk | Local_u8Location);  /* Send the command to set the cursor position */
    }

    return Ret_enuError;  /* Return the error status */
}