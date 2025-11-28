/*
 * KPD_CFG.c
 *
 * Created: 1/28/2025
 *  Author: Omar Alaa
 */ 


#include "KPD_CFG.h"
#include "KPD_INTERFACING.h"
#include "PORT_INTERFACING.h"

HKPD_sKPDCfg_t HKPD_struKPDCfg =  /* Define and initialize the keypad configuration structure */
{
    .PortPinROWS = {  /* Initialize the row pins */
        [HKPD_ROW0] = PIN_B4,  /* Row 0 connected to PIN_B4 */
        [HKPD_ROW1] = PIN_B5,  /* Row 1 connected to PIN_B5 */
        [HKPD_ROW2] = PIN_B6,  /* Row 2 connected to PIN_B6 */
        [HKPD_ROW3] = PIN_B7,  /* Row 3 connected to PIN_B7 */
    },

    .PortPinCols = {  /* Initialize the column pins */
        [HKPD_Col0] = PIN_A4,  /* Column 0 connected to PIN_A4 */
        [HKPD_Col1] = PIN_A5,  /* Column 1 connected to PIN_A5 */
        [HKPD_Col2] = PIN_A6,  /* Column 2 connected to PIN_A6 */
        [HKPD_Col3] = PIN_A7,  /* Column 3 connected to PIN_A7 */
    }
};

/* Define and initialize the keypad values array */
u8 Global_u8Arr[HKPD_NUM_OF_ROWS][HKPD_NUM_OF_COLS] = 
{  
    {1, 2, 3, 4},  /* Values for row 0 */
    {5, 6, 7, 8},  /* Values for row 1 */
    {9, 10, 11, 12},  /* Values for row 2 */
    {13, 14, 15, 16},  /* Values for row 3 */
};