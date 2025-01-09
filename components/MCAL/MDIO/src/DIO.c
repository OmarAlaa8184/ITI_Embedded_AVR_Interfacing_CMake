/*
 * DIO.C
 *
 * Created: 12/17/2024 1:28:38 PM
 *  Author: Omar Alaa
 */ 


#include "DIO_INTERFACING.h"
#include "DIO_CFG.h"


/* 
*   struct contain 3 parameters to generate new type   
*   and use it to handel the three registers of each port
*
*/

typedef struct
{
	 u8 PIN;
	 u8 DDR;
	 u8 PORT;
	
} MDIO_structPortRegElement_t;

/*
*
*   handle the address of pin register of portA 
*   by using the struct (MDIO_structPortRegElement_t)
*   and make casting to the address  
*/

#define MDIO_PORT_REG_BASE_ADD  ((volatile MDIO_structPortRegElement_t*)(0x39))

/*
*
*   macro to handel the calculation of change the port 
*   
*/

#define MDIO_GET_PORT_ADD(PORT_NUM)   ((((MDIO_structPortRegElement_t*)(MDIO_PORT_REG_BASE_ADD)) - (((MDIO_enuPortNum)PORT_NUM))))

/* 
*
* extern the array from DIO_CFG.c
*
*/

extern MDIO_enuPINConfigration MDIO_enuArrPinConfig[MDIO_NUM_OF_PORTS*MDIO_NUM_OF_PINS];


/* Function to initialize all GPIO pins with their configurations */
void MDIO_vInit(void)
{
    MDIO_enuPortNum Local_enuPortNum;
    MDIO_enuPinNum Local_enuPinNum;
    
    /* Loop through all pins in all ports */
    for (u8 Local_u8Conter = 0; Local_u8Conter < ((MDIO_NUM_OF_PORTS * MDIO_NUM_OF_PINS)); Local_u8Conter++)
    {
        /* Calculate the port number and pin number */
        Local_enuPortNum = Local_u8Conter / MDIO_NUM_OF_PINS;
        Local_enuPinNum = Local_u8Conter % MDIO_NUM_OF_PINS;
        
        /* Configure the pin with its predefined configuration */
        MDIO_enuSetPinConfigration(Local_enuPortNum, Local_enuPinNum, MDIO_enuArrPinConfig[Local_u8Conter]);
    }
}

/* Function to set the configuration of a specific pin */
MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(MDIO_enuPortNum Copy_enuPortNum, MDIO_enuPinNum Copy_enuPinNum, MDIO_enuPINConfigration Copy_enuConfigration)
{
    MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
    MDIO_structPortRegElement_t *Local_strPtrCurrPort = MDIO_GET_PORT_ADD(Copy_enuPortNum);

    /* Validate port number */
    if (Copy_enuPortNum > MDIO_enuPORTD)
    {
        Ret_enuError = MDIO_enuINVALID_PORT;
    }
    /* Validate pin number */
    else if (Copy_enuPinNum > MDIO_enuPIN7)
    {
        Ret_enuError = MDIO_enuINVALID_PIN;
    }
    /* Validate pin configuration */
    else if (Copy_enuConfigration > MDIO_enuOUTPUT_PIN)
    {
        Ret_enuError = MDIO_enuSTATE;
    }
    else
    {
        Ret_enuError = MDIO_enuOK;
        
        /* Configure the pin as output */
        if (Copy_enuConfigration == MDIO_enuOUTPUT_PIN)
        {
            SET_BIT(Local_strPtrCurrPort->DDR, Copy_enuPinNum);
        }
        /* Configure the pin as input with pull-up */
        else if (Copy_enuConfigration == MDIO_enuINPUT_PULLUP)
        {
            CLR_BIT(Local_strPtrCurrPort->DDR, Copy_enuPinNum);
            SET_BIT(Local_strPtrCurrPort->PORT, Copy_enuPinNum);
        }
        /* Configure the pin as input with pull-down */
        else if (Copy_enuConfigration == MDIO_enuINPUT_PULLDOWN)
        {
            CLR_BIT(Local_strPtrCurrPort->DDR, Copy_enuPinNum);
            CLR_BIT(Local_strPtrCurrPort->PORT, Copy_enuPinNum);
        }
    }
    return Ret_enuError;
}

/* Function to set the state (HIGH or LOW) of a specific pin */
MDIO_enuErrorStatus_t MDIO_enuSetPinValue(MDIO_enuPortNum Copy_enuPortNum, MDIO_enuPinNum Copy_enuPinNum, MDIO_enuPinState Copy_enuState)
{
    MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
    MDIO_structPortRegElement_t *Local_strPtrCurrPort = MDIO_GET_PORT_ADD(Copy_enuPortNum);

    /* Validate port number */
    if (Copy_enuPortNum > MDIO_enuPORTD)
    {
        Ret_enuError = MDIO_enuINVALID_PORT;
    }
    /* Validate pin number */
    else if (Copy_enuPinNum > MDIO_enuPIN7)
    {
        Ret_enuError = MDIO_enuINVALID_PIN;
    }
    /* Validate pin state */
    else if (Copy_enuState > MDIO_enuHIGH_PIN)
    {
        Ret_enuError = MDIO_enuSTATE;
    }
    else
    {
        Ret_enuError = MDIO_enuOK;
        
        /* Set the pin to HIGH */
        if (Copy_enuState == MDIO_enuHIGH_PIN)
        {
            SET_BIT(Local_strPtrCurrPort->PORT, Copy_enuPinNum);
        }
        /* Set the pin to LOW */
        else if (Copy_enuState == MDIO_enuLOW_PIN)
        {
            CLR_BIT(Local_strPtrCurrPort->PORT, Copy_enuPinNum);
        }
    }
    return Ret_enuError;
}

/* Function to set the configuration of an entire port */
MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(MDIO_enuPortNum Copy_enuPortNum, MDIO_enuPortConfigration Copy_enuConfigration)
{
    MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
    MDIO_structPortRegElement_t *Local_strPtrCurrPort = MDIO_GET_PORT_ADD(Copy_enuPortNum);

    /* Validate port number */
    if (Copy_enuPortNum > MDIO_enuPORTD)
    {
        Ret_enuError = MDIO_enuINVALID_PORT;
    }
    /* Validate port configuration */
    else if (Copy_enuConfigration > MDIO_enuOUTPUT_PORT)
    {
        Ret_enuError = MDIO_enuSTATE;
    }
    else
    {
        Ret_enuError = MDIO_enuOK;

        /* Configure port as output */
        if (Copy_enuConfigration == MDIO_enuOUTPUT_PORT)
        {
            WRITE_REG(Local_strPtrCurrPort->DDR, Copy_enuConfigration);
        }
        /* Configure port as input */
        else if (Copy_enuConfigration == MDIO_enuINPUT_PORT)
        {
            WRITE_REG(Local_strPtrCurrPort->DDR, Copy_enuConfigration);
        }
    }
    return Ret_enuError;
}

/* Function to set the state (HIGH or LOW) of an entire port */
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNum Copy_enuPortNum, MDIO_enuPortState Copy_enuPortState)
{
    MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
    MDIO_structPortRegElement_t *Local_strPtrCurrPort = MDIO_GET_PORT_ADD(Copy_enuPortNum);

    /* Validate port number */
    if (Copy_enuPortNum > MDIO_enuPORTD)
    {
        Ret_enuError = MDIO_enuINVALID_PORT;
    }
    /* Validate port state */
    else if (Copy_enuPortState > MDIO_enuHIGH_PORT)
    {
        Ret_enuError = MDIO_enuSTATE;
    }
    else
    {
        Ret_enuError = MDIO_enuOK;

        /* Set port to HIGH */
        if (Copy_enuPortState == MDIO_enuHIGH_PORT)
        {
            WRITE_REG(Local_strPtrCurrPort->PORT, Copy_enuPortState);
        }
        /* Set port to LOW */
        else if (Copy_enuPortState == MDIO_enuLOW_PORT)
        {
            WRITE_REG(Local_strPtrCurrPort->PORT, Copy_enuPortState);
        }
    }
    return Ret_enuError;
}

/* Function to get the current value of a specific pin */
MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNum Copy_enuPortNum, MDIO_enuPinNum Copy_enuPinNum, u8* Add_pu8PinValue)
{
    MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
    MDIO_structPortRegElement_t *Local_strPtrCurrPort = MDIO_GET_PORT_ADD(Copy_enuPortNum);

    /* Validate port number */
    if (Copy_enuPortNum > MDIO_enuPORTD)
    {
        Ret_enuError = MDIO_enuINVALID_PORT;
    }
    /* Validate pin number */
    else if (Copy_enuPinNum > MDIO_enuPIN7)
    {
        Ret_enuError = MDIO_enuINVALID_PIN;
    }
    /* Validate pointer to store pin value */
    else if (Add_pu8PinValue == NULL)
    {
        Ret_enuError = MDIO_enuNULL_PTR;
    }
    else
    {
        Ret_enuError = MDIO_enuOK;
        /* Read the pin value */
        *Add_pu8PinValue = GET_BIT(Local_strPtrCurrPort->PIN, Copy_enuPinNum);
    }
    return Ret_enuError;
}
