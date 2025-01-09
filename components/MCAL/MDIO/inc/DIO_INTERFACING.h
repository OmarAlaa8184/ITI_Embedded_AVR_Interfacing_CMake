/*
 * IncFile1.h
 *
 * Created: 12/17/2024 1:29:13 PM
 *  Author: Omar Alaa
 */ 



#ifndef DIO_INTERFACING_H_
#define DIO_INTERFACING_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_CFG.h"


/*enum contain ports names*/

typedef enum
{
	MDIO_enuPORTA,
	MDIO_enuPORTB,
	MDIO_enuPORTC,
	MDIO_enuPORTD
	
}MDIO_enuPortNum;

/*enum contain pins names*/

typedef enum
{
	MDIO_enuPIN0,
	MDIO_enuPIN1,
	MDIO_enuPIN2,
	MDIO_enuPIN3,
	MDIO_enuPIN4,
	MDIO_enuPIN5,
	MDIO_enuPIN6,
	MDIO_enuPIN7
	
	
}MDIO_enuPinNum;

/*enum contain pins state*/

typedef enum
{
   MDIO_enuLOW_PIN ,
   MDIO_enuHIGH_PIN
	
}MDIO_enuPinState;

/*enum contain pins configration*/

typedef enum
{
	MDIO_enuINPUT_PULLUP,
	MDIO_enuINPUT_PULLDOWN,  
	MDIO_enuOUTPUT_PIN
}MDIO_enuPINConfigration;

/*enum contain ports state*/

typedef enum
{
	MDIO_enuLOW_PORT=0x00 ,
	MDIO_enuHIGH_PORT=0xFF 
	
}MDIO_enuPortState;

/*enum contain ports configration*/

typedef enum
{
	MDIO_enuINPUT_PORT=0x00,
	MDIO_enuOUTPUT_PORT=0xFF
	
}MDIO_enuPortConfigration;

/*enum contain error status*/

typedef enum
{ 
	MDIO_enuOK,
	MDIO_enuNOK,
	MDIO_enuINVALID_INPUT,
	MDIO_enuINVALID_PORT,
	MDIO_enuINVALID_PIN,
	MDIO_enuSTATE,
	MDIO_enuNULL_PTR
	
}MDIO_enuErrorStatus_t;


/*
*  
*  MDIO_vInit function use to initialize the pins configration
*
*/

void MDIO_vInit(void);

/* MDIO_enuSetPinConfigration function use to set pins configration
*  
*  take three parametares: 1-Copy_enuPortNum
*                          2-Copy_enuPinNum
*                          3-Copy_enuConfigration
*/

MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration( MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPinNum Copy_enuPinNum,MDIO_enuPINConfigration Copy_enuConfigration);

/* MDIO_enuSetPortConfigration function use to set ports configration
*  
*  take two parametares: 1-Copy_enuPortNum
*                        2-Copy_enuConfigration
*                          
*/

MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPortConfigration Copy_enuConfigration);

/* MDIO_enuSetPinValue function use to set pins value
*  
*  take three parametares: 1-Copy_enuPortNum
*                          2-Copy_enuPinNum
*                          3-Copy_enuPinState
*/

MDIO_enuErrorStatus_t MDIO_enuSetPinValue( MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPinNum Copy_enuPinNum, MDIO_enuPinState Copy_enuState);

/* MDIO_enuSetPortValue function use to set ports value
*  
*  take three parametares: 1-Copy_enuPortNum
*                          2-Copy_enuPortState
*                          
*/

MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPortState Copy_enuPortState);

/* MDIO_enuGetPinValue function use to get pins value
*  
*  take three parametares: 1-Copy_enuPortNum
*                          2-Copy_enuPinNum
*                          3-pointer to pass the address of variable
*/

MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPinNum Copy_enuPinNum,u8* Add_pu8PinValue);

/* MDIO_enuSetPortValue1 function use to get pins value
*  
*  take two parametares: 1-Copy_enuPortNum
*                        3-Copy_u8PortState
*                          
*/

MDIO_enuErrorStatus_t MDIO_enuSetPortValue1(MDIO_enuPortNum Copy_enuPortNum,u8 Copy_u8PortState);


#endif /* DIO_INTERFACING_H_ */