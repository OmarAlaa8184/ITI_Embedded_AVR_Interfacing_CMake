/*
 * SEVENSEG_INTERFACING.h
 *
 * Created: 1/5/2025
 *  Author: Omar Alaa
 */ 



#ifndef SEVENSEG_INTERFACING_H_
#define SEVENSEG_INTERFACING_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "SEVENSEG_CFG.h"


/* 
 * Enumeration to represent error statuses for the 7-segment display operations.
 * Each enum value corresponds to a specific error or success state.
 */
typedef enum
{ 
	HSEVENSEG_enuOK,                     /* Operation succeeded */
	HSEVENSEG_enuNOK,                    /* Operation failed */
	HSEVENSEG_enuINVALID_SEVENSEG_NUM,   /* Invalid 7-segment display number (out of range) */
	HSEVENSEG_enuINVALID_INPUT,          /* Invalid input value (e.g., out of range or incorrect format) */
	HSEVENSEG_enuSTATE                   /* Invalid state (e.g., unable to set the state) */
	
} HSEVENSEG_enuErrorStatus_t;

/* 
 * Function to initialize the 7-segment displays.
 * This function configures the necessary settings to prepare the 7-segment displays for use.
 */
void HSEVENSEG_vInit(void);

/* 
 * Function to set a value (digit) to a specific 7-segment display.
 * 
 * @param Copy_enuSevenSegNum: The number of the 7-segment display (e.g., 0, 1, 2, etc.).
 * @param Copy_u8Value: The digit to display on the 7-segment (e.g., 0-9).
 */
void HSEVENSEG_vSetValue(u8 Copy_enuSevenSegNum, u8 Copy_u8Value);

/* 
 * Function to set a multi-digit value to the 7-segment displays.
 * The function will split the value into its individual digits and display them across multiple displays.
 * 
 * @param Copy_u16Value: The multi-digit value (e.g., 1234) to display on the 7-segment displays.
 * @return HSEVENSEG_enuErrorStatus_t: The result of the operation (e.g., success or error status).
 */
HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuSetMultiDigitValue(u16 Copy_u16Value);













#endif /* SEVENSEG_INTERFACING_H_ */