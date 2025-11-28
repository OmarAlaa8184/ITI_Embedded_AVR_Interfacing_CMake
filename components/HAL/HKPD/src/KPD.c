/*
 * KPD.C
 *
 * Created: 1/28/2025
 *  Author: Omar Alaa
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_INTERFACING.h"
#include "PORT_INTERFACING.h"
#include "KPD_INTERFACING.h"
#include "KPD_CFG.h"


extern HKPD_sKPDCfg_t HKPD_struKPDCfg;  /* Declare the external keypad configuration structure */

extern u8 Global_u8Arr[HKPD_NUM_OF_ROWS][HKPD_NUM_OF_COLS];  /* Declare the external keypad values array */

void HKPD_vInit(void)  /* Function to initialize the keypad */
{
    for (u8 Local_u8Counter = 0; Local_u8Counter < HKPD_NUM_OF_COLS; Local_u8Counter++)  /* Loop through each column */
    {
        MPORT_enuSetPinMode(HKPD_struKPDCfg.PortPinCols[Local_u8Counter], MPORT_enuINPUT_PULLUP);  /* Set column pin mode to input with pull-up */
    }

    for (u8 Local_u8Counter = 0; Local_u8Counter < HKPD_NUM_OF_ROWS; Local_u8Counter++)  /* Loop through each row */
    {
        MPORT_enuSetPinMode(HKPD_struKPDCfg.PortPinROWS[Local_u8Counter], MPORT_enuOUTPUT_PIN);  /* Set row pin mode to output */
        MDIO_enuSetPinValue(HKPD_struKPDCfg.PortPinROWS[Local_u8Counter] >> 4,
                            HKPD_struKPDCfg.PortPinROWS[Local_u8Counter] & 0x0F,
                            MDIO_enuHIGH_PIN);  /* Set row pin value to high */
    }
}

HKPD_enuErrorStatus_t HKPD_enuGetKey(u8* Add_pu8KeyValue)  /* Function to get the key value */
{
    HKPD_enuErrorStatus_t Ret_enuError = HKPD_enuNOK;  /* Initialize error status to NOK (Not OK) */
    u8 Local_Addu8InputValue = 0;  /* Variable to store input value */
    u8 Local_u8Flag = 0;  /* Flag to indicate key press detected */

    if (Add_pu8KeyValue == NULL)  /* Check if the input pointer is NULL */
    {
        Ret_enuError = HKPD_enuNULL_PTR;  /* Set error status to NULL pointer */
    }
    else
    {
        Ret_enuError = HKPD_enuOK;  /* Set error status to OK */

        for (u8 Local_u8CounterRow = 0; Local_u8CounterRow < HKPD_NUM_OF_ROWS; Local_u8CounterRow++)  /* Loop through each row */
        {
            MDIO_enuSetPinValue(HKPD_struKPDCfg.PortPinROWS[Local_u8CounterRow] >> 4,
                                HKPD_struKPDCfg.PortPinROWS[Local_u8CounterRow] & 0x0F,
                                MDIO_enuLOW_PIN);  /* Set row pin value to low */

            for (u8 Local_u8CounterCol = 0; Local_u8CounterCol < HKPD_NUM_OF_COLS; Local_u8CounterCol++)  /* Loop through each column */
            {
                MDIO_enuGetPinValue(HKPD_struKPDCfg.PortPinCols[Local_u8CounterCol] >> 4,
                                    HKPD_struKPDCfg.PortPinCols[Local_u8CounterCol] & 0x0F,
                                    &Local_Addu8InputValue);  /* Get column pin value */

                _delay_ms(10);  /* Delay for debounce */

                if (Local_Addu8InputValue == 0)  /* Check if key is pressed */
                {
                    *Add_pu8KeyValue = Global_u8Arr[Local_u8CounterRow][Local_u8CounterCol];  /* Set the key value */

                    while (Local_Addu8InputValue == 0)  /* Wait until key is released */
                    {
                        MDIO_enuGetPinValue(HKPD_struKPDCfg.PortPinCols[Local_u8CounterCol] >> 4,
                                            HKPD_struKPDCfg.PortPinCols[Local_u8CounterCol] & 0x0F,
                                            &Local_Addu8InputValue);  /* Get column pin value */
                    }

                    Local_u8Flag = 1;  /* Set flag to indicate key press detected */
                    break;  /* Exit the column loop */
                }
            }

            MDIO_enuSetPinValue(HKPD_struKPDCfg.PortPinROWS[Local_u8CounterRow] >> 4,
                                HKPD_struKPDCfg.PortPinROWS[Local_u8CounterRow] & 0x0F,
                                MDIO_enuHIGH_PIN);  /* Set row pin value to high */

            if (Local_u8Flag == 1)  /* Check if key press detected */
            {
                break;  /* Exit the row loop */
            }
        }
    }
    return Ret_enuError;  /* Return the error status */
}