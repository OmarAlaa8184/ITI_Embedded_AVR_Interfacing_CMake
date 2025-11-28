/*
 * KPD_INTERFACING.h
 *
 * Created: 1/28/2025
 *  Author: Omar Alaa
 */ 



#ifndef KPD_INTERFACING_H_
#define KPD_INTERFACING_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "KPD_CFG.h"

#define HKPD_MAX_NUM_OF_ROWS 4  /* Define the maximum number of rows in the keypad matrix */
#define HKPD_MAX_NUM_OF_COLS 4  /* Define the maximum number of columns in the keypad matrix */

typedef enum
{ 
    HKPD_ROW0,  /* Row 0 */
    HKPD_ROW1,  /* Row 1 */
    HKPD_ROW2,  /* Row 2 */
    HKPD_ROW3,  /* Row 3 */
        
} HKPD_enuNumberOfRows_t;  /* Enumeration for keypad rows */

typedef enum
{ 
    HKPD_Col0,  /* Column 0 */
    HKPD_Col1,  /* Column 1 */
    HKPD_Col2,  /* Column 2 */
    HKPD_Col3   /* Column 3 */
        
} HKPD_enuNumberOfCols_t;  /* Enumeration for keypad columns */

typedef enum
{ 
    HKPD_enuOK,                /* Operation successful */
    HKPD_enuNOK,               /* Operation failed */
    HKPD_enuINVALID_KPD_NUM,   /* Invalid keypad number */
    HKPD_enuINVALID_KPD_COL,   /* Invalid keypad column */
    HKPD_enuINVALID_KPD_ROW,   /* Invalid keypad row */
    HKPD_enuINVALID_INPUT,     /* Invalid input */
    HKPD_enuSTATE,             /* Keypad state */
    HKPD_enuNULL_PTR           /* Null pointer error */
    
} HKPD_enuErrorStatus_t;  /* Enumeration for error status */

typedef struct 
{
    HKPD_enuNumberOfRows_t PortPinROWS[HKPD_NUM_OF_ROWS];  /* Array to store row pins */
    HKPD_enuNumberOfCols_t PortPinCols[HKPD_NUM_OF_COLS];  /* Array to store column pins */

} HKPD_sKPDCfg_t;  /* Structure for keypad configuration */

void HKPD_vInit(void);  /* Function to initialize the keypad */

HKPD_enuErrorStatus_t HKPD_enuGetKey(u8* Add_pu8KeyValue);  /* Function to get the key value */













#endif /* KPD_INTERFACING_H_ */