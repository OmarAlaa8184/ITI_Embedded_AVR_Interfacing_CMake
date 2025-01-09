/*
 * PORT.C
 *
 * Created: 1/1/2024 
 *  Author: Omar Alaa
 */ 


#include "PORT_INTERFACING.h"
#include "PORT_CFG.h"


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
	
} MPORT_structPortRegElement_t;

/*
*
*   handle the address of pin register of portA 
*   by using the struct (MPORT_structPortRegElement_t)
*   and make casting to the address  
*/

#define MPORT_PORT_REG_BASE_ADD  ((volatile MPORT_structPortRegElement_t*)(0x39))

/*
*
*   macro to handel the calculation of change the port 
*   
*/

#define MPORT_GET_PORT_ADD(PORT_NUM)     ((((MPORT_structPortRegElement_t*)(MPORT_PORT_REG_BASE_ADD)) - (((MPORT_enuPortNum)PORT_NUM))))

/* 
*
* extern the array from PORT_CFG.c
*
*/

extern MPORT_enuPINConfigration MPORT_enuArrPinConfig[MPORT_NUM_OF_PORTS*MPORT_NUM_OF_PINS];


/* Function to initialize all GPIO pins with their configurations */
void MPORT_vInit(void)
{
    MPORT_enuPortNum Local_enuPortNum;
    MPORT_enuPinNum Local_enuPinNum;

    /* Loop through all pins in all ports */
    for (u8 Local_u8Conter = 0; Local_u8Conter < ((MPORT_NUM_OF_PORTS * MPORT_NUM_OF_PINS)); Local_u8Conter++)
    {
        /* Calculate the port number and pin number */
        Local_enuPortNum = Local_u8Conter / MPORT_NUM_OF_PINS;
        Local_enuPinNum = Local_u8Conter % MPORT_NUM_OF_PINS;
        
        /* Configure the pin with its predefined configuration */
        MPORT_enuSetPinConfigration(Local_enuPortNum, Local_enuPinNum, MPORT_enuArrPinConfig[Local_u8Conter]);
    }
}


/* Function to set the configuration of a specific pin */
MPORT_enuErrorStatus_t MPORT_enuSetPinConfigration(MPORT_enuPortNum Copy_enuPortNum, MPORT_enuPinNum Copy_enuPinNum, MPORT_enuPINConfigration Copy_enuConfigration)
{
    MPORT_enuErrorStatus_t Ret_enuError = MPORT_enuNOK;

    /* Get the address of the port register */
    MPORT_structPortRegElement_t *Local_strPtrCurrPort = MPORT_GET_PORT_ADD(Copy_enuPortNum);

    /* Validate the port number */
    if (Copy_enuPortNum > MPORT_enuPORTD)
    {
        Ret_enuError = MPORT_enuINVALID_PORT;
    }
    /* Validate the pin number */
    else if (Copy_enuPinNum > MPORT_enuPIN7)
    {
        Ret_enuError = MPORT_enuINVALID_PIN;
    }
    /* Validate the configuration */
    else if (Copy_enuConfigration > MPORT_enuOUTPUT_PIN)
    {
        Ret_enuError = MPORT_enuSTATE;
    }
    else
    {
        Ret_enuError = MPORT_enuOK;

        /* Configure the pin as output */
        if (Copy_enuConfigration == MPORT_enuOUTPUT_PIN)
        {
            SET_BIT(Local_strPtrCurrPort->DDR, Copy_enuPinNum);
        }
        /* Configure the pin as input with pull-up */
        else if (Copy_enuConfigration == MPORT_enuINPUT_PULLUP)
        {
            CLR_BIT(Local_strPtrCurrPort->DDR, Copy_enuPinNum);
            SET_BIT(Local_strPtrCurrPort->PORT, Copy_enuPinNum);
        }
        /* Configure the pin as input with pull-down */
        else if (Copy_enuConfigration == MPORT_enuINPUT_PULLDOWN)
        {
            CLR_BIT(Local_strPtrCurrPort->DDR, Copy_enuPinNum);
            CLR_BIT(Local_strPtrCurrPort->PORT, Copy_enuPinNum);
        }
    }
    return Ret_enuError;
}

/* Function to configure the direction of an entire port */
MPORT_enuErrorStatus_t MPORT_enuSetPortConfigration(MPORT_enuPortNum Copy_enuPortNum, MPORT_enuPortConfigration Copy_enuConfigration)
{
    MPORT_enuErrorStatus_t Ret_enuError = MPORT_enuNOK;

    /* Get the address of the port register */
    MPORT_structPortRegElement_t *Local_strPtrCurrPort = MPORT_GET_PORT_ADD(Copy_enuPortNum);

    /* Validate the port number */
    if (Copy_enuPortNum > MPORT_enuPORTD)
    {
        Ret_enuError = MPORT_enuINVALID_PORT;
    }
    /* Validate the configuration */
    else if (Copy_enuConfigration > MPORT_enuOUTPUT_PORT)
    {
        Ret_enuError = MPORT_enuSTATE;
    }
    else
    {
        Ret_enuError = MPORT_enuOK;

        /* Set port as output */
        if (Copy_enuConfigration == MPORT_enuOUTPUT_PORT)
        {
            WRITE_REG(Local_strPtrCurrPort->DDR, Copy_enuConfigration);
        }
        /* Set port as input */
        else if (Copy_enuConfigration == MPORT_enuINPUT_PORT)
        {
            WRITE_REG(Local_strPtrCurrPort->DDR, Copy_enuConfigration);
        }
    }
    return Ret_enuError;      return Ret_enuError;
}

/* Function to set the direction of a specific pin */
MPORT_enuErrorStatus_t MPORT_enuSetPinDirection(u8 Copy_enuPinNum, u8 Copy_enuPinDirection)
{
    MPORT_enuErrorStatus_t Ret_enuError = MPORT_enuNOK;

    /* Get the address of the port register */
    MPORT_structPortRegElement_t *Local_strPtrCurrPort = MPORT_GET_PORT_ADD(Copy_enuPinNum >> 4);

    /* Validate the port number */
    if ((Copy_enuPinNum >> 4) > MPORT_enuPORTD)
    {
        Ret_enuError = MPORT_enuINVALID_PORT;
    }
    /* Validate the pin number */
    else if (((Copy_enuPinNum) & (0x0F)) > MPORT_enuPIN7)
    {
        Ret_enuError = MPORT_enuINVALID_PIN;
    }
    /* Validate the direction */
    else if (Copy_enuPinDirection < MPORT_INPUT_PIN || Copy_enuPinDirection > MPORT_OUTPUT_PIN)
    {
        Ret_enuError = MPORT_enuSTATE;
    }
    else
    {
        Ret_enuError = MPORT_enuOK;

        /* Set pin as output */
        if (Copy_enuPinDirection == MPORT_OUTPUT_PIN)
        {
            WRITE_BIT(Local_strPtrCurrPort->DDR, ((Copy_enuPinNum) & (0x0F)), MPORT_OUTPUT_PIN);
        }
        /* Set pin as input */
        else if (Copy_enuPinDirection == MPORT_INPUT_PIN)
        {
            WRITE_BIT(Local_strPtrCurrPort->DDR, ((Copy_enuPinNum) & (0x0F)), MPORT_INPUT_PIN);
        }
    }
    return Ret_enuError;
}

/* Function to set the mode of a specific pin */
MPORT_enuErrorStatus_t MPORT_enuSetPinMode(u8 Copy_enuPinNum, MPORT_enuPINConfigration Copy_enuPinMode)
{
    MPORT_enuErrorStatus_t Ret_enuError = MPORT_enuNOK;

    /* Get the address of the port register */
    MPORT_structPortRegElement_t *Local_strPtrCurrPort = MPORT_GET_PORT_ADD(Copy_enuPinNum >> 4);

    /* Validate the port number */
    if ((Copy_enuPinNum >> 4) > MPORT_enuPORTD)
    {
        Ret_enuError = MPORT_enuINVALID_PORT;
    }
    /* Validate the pin number */
    else if (((Copy_enuPinNum) & (0x0F)) > MPORT_enuPIN7)
    {
        Ret_enuError = MPORT_enuINVALID_PIN;
    }
    /* Validate the mode */
    else if (Copy_enuPinMode < MPORT_INPUT_PORT || Copy_enuPinMode > MPORT_OUTPUT_PORT)
    {
        Ret_enuError = MPORT_enuSTATE;
    }
    else
    {
        Ret_enuError = MPORT_enuOK;

        /* Configure pin as output */
        if (Copy_enuPinMode == MPORT_enuOUTPUT_PIN)
        {
            SET_BIT(Local_strPtrCurrPort->DDR, ((Copy_enuPinNum) & (0x0F)));
        }
        /* Configure pin as input with pull-up */
        else if (Copy_enuPinMode == MPORT_enuINPUT_PULLUP)
        {
            CLR_BIT(Local_strPtrCurrPort->DDR, ((Copy_enuPinNum) & (0x0F)));
            SET_BIT(Local_strPtrCurrPort->PORT, ((Copy_enuPinNum) & (0x0F)));
        }
        /* Configure pin as input with pull-down */
        else if (Copy_enuPinMode == MPORT_enuINPUT_PULLDOWN)
        {
            CLR_BIT(Local_strPtrCurrPort->DDR, ((Copy_enuPinNum) & (0x0F)));
            CLR_BIT(Local_strPtrCurrPort->PORT, ((Copy_enuPinNum) & (0x0F)));
        }
    }
    return Ret_enuError;
}















