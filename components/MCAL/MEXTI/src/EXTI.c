/*
 * PORT_INTERFACING.h
 *
 * Created: 2/10/2024 
 *  Author: Omar Alaa
 */ 

#include "EXTI_INTERFACING.h"

static void (*MEXTI_CBF0_t) (void);  /* Callback function pointer for EXTI 0 */
static void (*MEXTI_CBF1_t) (void);  /* Callback function pointer for EXTI 1 */
static void (*MEXTI_CBF2_t) (void);  /* Callback function pointer for EXTI 2 */

#define MEXTI_MCUCR    *((volatile u8*)(0x55))  /* MCU Control Register */
#define MEXTI_MCUCSR   *((volatile u8*)(0x54))  /* MCU Control and Status Register */
#define MEXTI_GICR     *((volatile u8*)(0x5B))  /* General Interrupt Control Register */
#define MEXTI_GIFR     *((volatile u8*)(0x5A))  /* General Interrupt Flag Register */

typedef enum
{ 
    MEXTI_MCUCR_ISC00,  /* MCUCR Interrupt Sense Control 00 */
    MEXTI_MCUCR_ISC01,  /* MCUCR Interrupt Sense Control 01 */
    MEXTI_MCUCR_ISC10,  /* MCUCR Interrupt Sense Control 10 */
    MEXTI_MCUCR_ISC11,  /* MCUCR Interrupt Sense Control 11 */

} MEXTI_enuMCUCR_PinsName_t;  /* Enumeration for MCUCR pin names */

#define MEXTI_MCUCSR_ISC2 6  /* MCUCSR Interrupt Sense Control 2 */

typedef enum
{ 
    MEXTI_GICR_INT2 = 5,  /* GICR Interrupt 2 */
    MEXTI_GICR_INT0,      /* GICR Interrupt 0 */
    MEXTI_GICR_INT1,      /* GICR Interrupt 1 */

} MEXTI_enuGICR_PinsName_t;  /* Enumeration for GICR pin names */

typedef enum
{ 
    MEXTI_GIFR_INTF2 = 5,  /* GIFR Interrupt Flag 2 */
    MEXTI_GIFR_INTF0,      /* GIFR Interrupt Flag 0 */
    MEXTI_GIFR_INTF1,      /* GIFR Interrupt Flag 1 */

} MEXTI_enuGIFR_PinsName_t;  /* Enumeration for GIFR pin names */

#define MEXTI_GICR_INT2_msk              0xDF  /* Mask for disabling INT2 */
#define MEXTI_GICR_INT2_EN_msk           0x20  /* Mask for enabling INT2 */
     
#define MEXTI_GICR_INT0_msk              0xBF  /* Mask for disabling INT0 */
#define MEXTI_GICR_INT0_EN_msk           0x40  /* Mask for enabling INT0 */
     
#define MEXTI_GICR_INT1_msk              0x7F  /* Mask for disabling INT1 */
#define MEXTI_GICR_INT1_EN_msk           0x80  /* Mask for enabling INT1 */
     
#define MEXTI_MCUCR_ISC00_ISC01_msk      0xFC  /* Mask for ISC00 and ISC01 */
#define MEXTI_MCUCR_ISC10_ISC11_msk      0xF3  /* Mask for ISC10 and ISC11 */
#define MEXTI_MCUCSR_ISC2_msk            0xBF  /* Mask for ISC2 */

extern MEXTI_sEXTICfg_t MEXTI_struExtiCfg[MEXTI_NUM_OF_EXTI];  /* Declare the external array of EXTI configurations */

void MEXTI_vInit(void)  /* Function to initialize the EXTI */
{
    u8 Local_u8Temp = 0;

    for (u8 Local_u8Counter = 0; Local_u8Counter < MEXTI_NUM_OF_EXTI; Local_u8Counter++)  /* Loop through each EXTI */
    {
        if (MEXTI_struExtiCfg[Local_u8Counter].EXTINAME == MEXTI_INT0)  /* Check if the EXTI is INT0 */
        {
            Local_u8Temp = MEXTI_MCUCR;
            Local_u8Temp &= MEXTI_MCUCR_ISC00_ISC01_msk;
            Local_u8Temp |= MEXTI_struExtiCfg[Local_u8Counter].MODE;
            MEXTI_MCUCR = Local_u8Temp;
        }
        else if (MEXTI_struExtiCfg[Local_u8Counter].EXTINAME == MEXTI_INT1)  /* Check if the EXTI is INT1 */
        {
            Local_u8Temp = MEXTI_MCUCR;
            Local_u8Temp &= MEXTI_MCUCR_ISC10_ISC11_msk;
            Local_u8Temp |= ((MEXTI_struExtiCfg[Local_u8Counter].MODE) << MEXTI_MCUCR_ISC10);
            MEXTI_MCUCR = Local_u8Temp;
        }
        else if (MEXTI_struExtiCfg[Local_u8Counter].EXTINAME == MEXTI_INT2)  /* Check if the EXTI is INT2 */
        {
            Local_u8Temp = MEXTI_MCUCSR;
            Local_u8Temp &= MEXTI_MCUCSR_ISC2_msk;
            Local_u8Temp |= ((MEXTI_struExtiCfg[Local_u8Counter].MODE) << MEXTI_MCUCSR_ISC2);
            MEXTI_MCUCSR = Local_u8Temp;
        }
        else
        {
            /* Do Nothing */
        }
    }
}

MEXTI_enuErrorStatus_t MEXTI_enuEnableInit(MEXTI_enuEXTIName_t Copy_enuExt)  /* Function to enable the EXTI */
{
    u8 Local_u8Temp = 0;
    MEXTI_enuErrorStatus_t Ret_enuError = MEXTI_enuOK;

    switch (Copy_enuExt)
    {
        case MEXTI_INT0:
            Local_u8Temp = MEXTI_GICR;
            Local_u8Temp &= MEXTI_GICR_INT0_msk;
            Local_u8Temp |= MEXTI_GICR_INT0_EN_msk;
            MEXTI_GICR = Local_u8Temp;
            break;

        case MEXTI_INT1:
            Local_u8Temp = MEXTI_GICR;
            Local_u8Temp &= MEXTI_GICR_INT1_msk;
            Local_u8Temp |= MEXTI_GICR_INT1_EN_msk;
            MEXTI_GICR = Local_u8Temp;
            break;

        case MEXTI_INT2:
            Local_u8Temp = MEXTI_GICR;
            Local_u8Temp &= MEXTI_GICR_INT2_msk;
            Local_u8Temp |= MEXTI_GICR_INT2_EN_msk;
            MEXTI_GICR = Local_u8Temp;
            break;

        default:
            Ret_enuError = MEXTI_enuINVALID_EXTI;
            break;
    }
    return Ret_enuError;
}

MEXTI_enuErrorStatus_t MEXTI_enuDisableInit(MEXTI_enuEXTIName_t Copy_enuExt)  /* Function to disable the EXTI */
{
    u8 Local_u8Temp = 0;
    MEXTI_enuErrorStatus_t Ret_enuError = MEXTI_enuOK;

    switch (Copy_enuExt)
    {
        case MEXTI_INT0:
            Local_u8Temp = MEXTI_GICR;
            Local_u8Temp &= MEXTI_GICR_INT0_msk;
            Local_u8Temp |= (~(MEXTI_GICR_INT0_EN_msk));
            MEXTI_GICR = Local_u8Temp;
            break;

        case MEXTI_INT1:
            Local_u8Temp = MEXTI_GICR;
            Local_u8Temp &= MEXTI_GICR_INT1_msk;
            Local_u8Temp |= (~(MEXTI_GICR_INT1_EN_msk));
            MEXTI_GICR = Local_u8Temp;
            break;

        case MEXTI_INT2:
            Local_u8Temp = MEXTI_GICR;
            Local_u8Temp &= MEXTI_GICR_INT2_msk;
            Local_u8Temp |= (~(MEXTI_GICR_INT2_EN_msk));
            MEXTI_GICR = Local_u8Temp;
            break;

        default:
            Ret_enuError = MEXTI_enuINVALID_EXTI;
            break;
    }
    return Ret_enuError;
}

MEXTI_enuErrorStatus_t MEXTI_enuSetCallBackINI0(void (*CBF_t)(void))  /* Function to set the callback for EXTI 0 */
{
    MEXTI_enuErrorStatus_t Ret_enuError = MEXTI_enuOK;

    if (CBF_t == NULL)
    {
        Ret_enuError = MEXTI_enuNULL_PTR;
    }
    else
    {
        MEXTI_CBF0_t = CBF_t;
    }

    return Ret_enuError;
}
MEXTI_enuErrorStatus_t MEXTI_enuSetCallBackINI1(void (*CBF_t)(void))  /* Function to set the callback for EXTI 1 */
{
    MEXTI_enuErrorStatus_t Ret_enuError = MEXTI_enuOK;

    if (CBF_t == NULL)  /* Check if the callback function pointer is NULL */
    {
        Ret_enuError = MEXTI_enuNULL_PTR;  /* Set error status to NULL pointer */
    }
    else
    {
        MEXTI_CBF1_t = CBF_t;  /* Set the callback function pointer */
    }

    return Ret_enuError;  /* Return the error status */
}

MEXTI_enuErrorStatus_t MEXTI_enuSetCallBackINI2(void (*CBF_t)(void))  /* Function to set the callback for EXTI 2 */
{ 
    MEXTI_enuErrorStatus_t Ret_enuError = MEXTI_enuOK;

    if (CBF_t == NULL)  /* Check if the callback function pointer is NULL */
    {
        Ret_enuError = MEXTI_enuNULL_PTR;  /* Set error status to NULL pointer */
    }
    else
    {
        MEXTI_CBF2_t = CBF_t;  /* Set the callback function pointer */
    }

    return Ret_enuError;  /* Return the error status */
}

void __vector_1(void) __attribute__((signal));  /* ISR for EXTI 0 */
void __vector_1(void)
{
    if (MEXTI_CBF0_t != NULL)  /* Check if the callback function pointer is not NULL */
    {
        MEXTI_CBF0_t();  /* Call the callback function */
    }
}

void __vector_2(void) __attribute__((signal));  /* ISR for EXTI 1 */
void __vector_2(void)
{
    if (MEXTI_CBF1_t != NULL)  /* Check if the callback function pointer is not NULL */
    {
        MEXTI_CBF1_t();  /* Call the callback function */
    }
}

void __vector_3(void) __attribute__((signal));  /* ISR for EXTI 2 */
void __vector_3(void)
{
    if (MEXTI_CBF2_t != NULL)  /* Check if the callback function pointer is not NULL */
    {
        MEXTI_CBF2_t();  /* Call the callback function */
    }
}