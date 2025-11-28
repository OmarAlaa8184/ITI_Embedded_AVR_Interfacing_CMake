/*
 * EXTI_INTERFACING.h
 *
 * Created: 2/10/2024 
 *  Author: Omar Alaa
 */ 



#ifndef EXTI_INTERFACING_H_
#define EXTI_INTERFACING_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "EXTI_CFG.h"
#include "EXTI_PRIV.h"

typedef enum
{ 
    MEXTI_INT0,  /* External Interrupt 0 */
    MEXTI_INT1,  /* External Interrupt 1 */
    MEXTI_INT2,  /* External Interrupt 2 */

} MEXTI_enuEXTIName_t;  /* Enumeration for EXTI names */

typedef enum
{ 
    MEXTI_LowLevel,     /* Low level trigger */
    MEXTI_OnChange,     /* Any logical change trigger */
    MEXTI_FallingEdge,  /* Falling edge trigger */
    MEXTI_RisingEdge    /* Rising edge trigger */
    
} MEXTI_enuSenseControl_t;  /* Enumeration for sense control modes */

typedef enum
{ 
    MEXTI_EXTI2_FallingEdge,  /* Falling edge trigger for EXTI2 */
    MEXTI_EXTI2_RisingEdge    /* Rising edge trigger for EXTI2 */
    
} MEXTI_enuSenseControlEXTI2_t;  /* Enumeration for sense control modes specific to EXTI2 */

typedef enum
{ 
    MEXTI_enuOK,              /* Operation successful */
    MEXTI_enuNOK,             /* Operation failed */
    MEXTI_enuINVALID_INPUT,   /* Invalid input */
    MEXTI_enuINVALID_EXTI,    /* Invalid EXTI */
    MEXTI_enuINVALID_PIN,     /* Invalid pin */
    MEXTI_enuSTATE,           /* EXTI state */
    MEXTI_enuNULL_PTR         /* Null pointer error */
    
} MEXTI_enuErrorStatus_t;  /* Enumeration for error status */

typedef struct 
{
    MEXTI_enuEXTIName_t EXTINAME;  /* EXTI name */
    MEXTI_enuSenseControl_t MODE;  /* Sense control mode */

} MEXTI_sEXTICfg_t;  /* Structure for EXTI configuration */

void MEXTI_vInit(void);  /* Function to initialize the EXTI */
MEXTI_enuErrorStatus_t MEXTI_enuEnableInit(MEXTI_enuEXTIName_t Copy_enuExt);  /* Function to enable the EXTI */
MEXTI_enuErrorStatus_t MEXTI_enuDisableInit(MEXTI_enuEXTIName_t Copy_enuExt);  /* Function to disable the EXTI */
MEXTI_enuErrorStatus_t MEXTI_enuSetCallBackINI0(void (*CBF_t)(void));  /* Function to set the callback for EXTI 0 */
MEXTI_enuErrorStatus_t MEXTI_enuSetCallBackINI1(void (*CBF_t)(void));  /* Function to set the callback for EXTI 1 */
MEXTI_enuErrorStatus_t MEXTI_enuSetCallBackINI2(void (*CBF_t)(void));  /* Function to set the callback for EXTI 2 */

#endif /* EXTI_INTERFACING_H_ */