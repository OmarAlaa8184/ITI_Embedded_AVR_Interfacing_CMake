/*
 * LCD_INTERFACING.h
 *
 * Created: 4/2/2025
 *  Author: Omar Alaa
 */ 



#ifndef LCD_INTERFACING_H_
#define LCD_INTERFACING_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "LCD_CFG.h"

#define HLCD_DDRAM_ADDRESS  0x40  /* Define the DDRAM address offset */
#define HLCD_DDRAM_DB7_msk  0x80  /* Define the mask for the DB7 bit in DDRAM address */

typedef enum
{ 
    HLCD_8BIT_MODE,  /* 8-bit mode for LCD */
    HLCD_4BIT_MODE,  /* 4-bit mode for LCD */
    
} HLCD_enuMODE_t;  /* Enumeration for LCD modes */

typedef enum
{ 
    HLCD_0,  /* LCD 0 */
    HLCD_1,  /* LCD 1 */
    HLCD_2,  /* LCD 2 */
    HLCD_3,  /* LCD 3 */
        
} HLCD_enuNumberOfLCDS_t;  /* Enumeration for number of LCDs */

typedef enum
{ 
    HLCD_ROW0,  /* Row 0 */
    HLCD_ROW1,  /* Row 1 */
        
} HLCD_enuNumberOfRows_t;  /* Enumeration for LCD rows */

typedef enum
{ 
    HLCD_Col0,  /* Column 0 */
    HLCD_Col1,  /* Column 1 */
    HLCD_Col2,  /* Column 2 */
    HLCD_Col3,  /* Column 3 */
    HLCD_Col4,  /* Column 4 */
    HLCD_Col5,  /* Column 5 */
    HLCD_Col6,  /* Column 6 */
    HLCD_Col7,  /* Column 7 */
    HLCD_Col8,  /* Column 8 */
    HLCD_Col9,  /* Column 9 */
    HLCD_Col10, /* Column 10 */
    HLCD_Col11, /* Column 11 */
    HLCD_Col12, /* Column 12 */
    HLCD_Col13, /* Column 13 */
    HLCD_Col14, /* Column 14 */
    HLCD_Col15, /* Column 15 */
        
} HLCD_enuNumberOfCols_t;  /* Enumeration for LCD columns */

typedef enum
{ 
    HLCD_RS,     /* Register Select pin */
    HLCD_RW,     /* Read/Write pin */
    HLCD_ENABLE, /* Enable pin */
    HLCD_D0,     /* Data pin 0 */
    HLCD_D1,     /* Data pin 1 */
    HLCD_D2,     /* Data pin 2 */
    HLCD_D3,     /* Data pin 3 */
    HLCD_D4,     /* Data pin 4 */
    HLCD_D5,     /* Data pin 5 */
    HLCD_D6,     /* Data pin 6 */
    HLCD_D7,     /* Data pin 7 */
    
} HLCD_enuPinsName_t;  /* Enumeration for LCD pin names */

typedef enum
{ 
    HLCD_enuOK,                /* Operation successful */
    HLCD_enuNOK,               /* Operation failed */
    HLCD_enuINVALID_LCD_NUM,   /* Invalid LCD number */
    HLCD_enuINVALID_LCD_COL,   /* Invalid LCD column */
    HLCD_enuINVALID_LCD_ROW,   /* Invalid LCD row */
    HLCD_enuINVALID_INPUT,     /* Invalid input */
    HLCD_enuSTATE,             /* LCD state */
    HLCD_enuNULL_PTR           /* Null pointer error */
    
} HLCD_enuErrorStatus_t;  /* Enumeration for error status */

typedef struct 
{
    HLCD_enuPinsName_t PortPin[HLCD_NUM_OF_PINS];  /* Array to store pin configurations */
    HLCD_enuMODE_t MODE;  /* LCD mode (8-bit or 4-bit) */

} HLCD_sLCDCfg_t;  /* Structure for LCD configuration */

void HLCD_vInit(void);  /* Function to initialize the LCD */

void HLCD_enuWriteCommand(u8 Copy_u8Command);  /* Function to write a command to the LCD */

void HLCD_enuWriteData(u8 Copy_u8Data);  /* Function to write data to the LCD */

HLCD_enuErrorStatus_t HLCD_enuWriteString(u8* Copy_u8String);  /* Function to write a string to the LCD */

HLCD_enuErrorStatus_t HLCD_enuWriteNumber(u32 Copy_u8Number);  /* Function to write a number to the LCD */

HLCD_enuErrorStatus_t HLCD_enuGoToXY(HLCD_enuNumberOfRows_t Copy_u8X, HLCD_enuNumberOfCols_t Copy_u8Y);  /* Function to set the cursor position on the LCD */









#endif /* LCD_INTERFACING_H_ */