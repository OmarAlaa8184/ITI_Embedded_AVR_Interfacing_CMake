/*
 * PORT_INTERFACING.h
 *
 * Created: 1/1/2024 
 *  Author: Omar Alaa
 */ 



#ifndef PORT_INTERFACING_H_
#define PORT_INTERFACING_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "PORT_CFG.h"

/*represent every pin with specific port */

/*PORT A*/ 

#define PIN_A0  0x00
#define PIN_A1  0x01
#define PIN_A2  0x02
#define PIN_A3  0x03
#define PIN_A4  0x04
#define PIN_A5  0x05
#define PIN_A6  0x06
#define PIN_A7  0x07

/*PORT B*/

#define PIN_B0  0x10
#define PIN_B1  0x11
#define PIN_B2  0x12
#define PIN_B3  0x13
#define PIN_B4  0x14
#define PIN_B5  0x15
#define PIN_B6  0x16
#define PIN_B7  0x17

/*PORT C*/

#define PIN_C0  0x20
#define PIN_C1  0x21
#define PIN_C2  0x22
#define PIN_C3  0x23
#define PIN_C4  0x24
#define PIN_C5  0x25
#define PIN_C6  0x26
#define PIN_C7  0x27

/*PORT D*/

#define PIN_D0  0x30
#define PIN_D1  0x31
#define PIN_D2  0x32
#define PIN_D3  0x33
#define PIN_D4  0x34
#define PIN_D5  0x35
#define PIN_D6  0x36
#define PIN_D7  0x37


#define  MPORT_LOW_PORT     0x00 
#define  MPORT_HIGH_PORT    0xFF 

#define  MPORT_INPUT_PORT   0x00
#define  MPORT_OUTPUT_PORT  0xFF

#define  MPORT_INPUT_PIN   0
#define  MPORT_OUTPUT_PIN  1

/*enum contain ports names*/

typedef enum
{
	MPORT_enuPORTA,
	MPORT_enuPORTB,
	MPORT_enuPORTC,
	MPORT_enuPORTD
	
}MPORT_enuPortNum;

/*enum contain pins names*/

typedef enum
{
	MPORT_enuPIN0,
	MPORT_enuPIN1,
	MPORT_enuPIN2,
	MPORT_enuPIN3,
	MPORT_enuPIN4,
	MPORT_enuPIN5,
	MPORT_enuPIN6,
	MPORT_enuPIN7
	
	
}MPORT_enuPinNum;

/*enum contain pins state*/

typedef enum
{
   MPORT_enuLOW_PIN ,
   MPORT_enuHIGH_PIN
	
}MPORT_enuPinState;

/*enum contain pins configration*/

typedef enum
{
	MPORT_enuINPUT_PULLUP,
	MPORT_enuINPUT_PULLDOWN,  
	MPORT_enuOUTPUT_PIN
}MPORT_enuPINConfigration;

/*enum contain ports state*/

typedef enum
{
	MPORT_enuLOW_PORT=0x00 ,
	MPORT_enuHIGH_PORT=0xFF 
	
}MPORT_enuPortState;

/*enum contain ports configration*/

typedef enum
{
	MPORT_enuINPUT_PORT=0x00,
	MPORT_enuOUTPUT_PORT=0xFF
	
}MPORT_enuPortConfigration;

/*enum contain error status*/

typedef enum
{ 
	MPORT_enuOK,
	MPORT_enuNOK,
	MPORT_enuINVALID_INPUT,
	MPORT_enuINVALID_PORT,
	MPORT_enuINVALID_PIN,
	MPORT_enuSTATE,
	MPORT_enuNULL_PTR
	
}MPORT_enuErrorStatus_t;


/*
*  
*  MPORT_vInit function use to initialize the pins configration
*
*/

void MPORT_vInit(void);

/* MPORT_enuSetPinConfigration function use to set pins configration
*  
*  take three parametares: 1-Copy_enuPortNum
*                          2-Copy_enuPinNum
*                          3-Copy_enuConfigration
*/
MPORT_enuErrorStatus_t MPORT_enuSetPinConfigration( MPORT_enuPortNum Copy_enuPortNum,MPORT_enuPinNum Copy_enuPinNum,MPORT_enuPINConfigration Copy_enuConfigration);

/* MPORT_enuSetPortConfigration function use to set ports configration
*  
*  take two parametares: 1-Copy_enuPortNum
*                        2-Copy_enuConfigration
*                          
*/

MPORT_enuErrorStatus_t MPORT_enuSetPortConfigration(MPORT_enuPortNum Copy_enuPortNum,MPORT_enuPortConfigration Copy_enuConfigration);

/* MPORT_enuSetPinDirection function use to set pins configration
*  
*  take two parametares: 1-Copy_enuPortNum (it's concatenation between port ant pin in the same variable)
*                        2-Copy_enuConfigration (INUPUT OR OUTPUT)
*                       
*/

MPORT_enuErrorStatus_t MPORT_enuSetPinDirection(u8 Copy_enuPinNum,u8 Copy_enuPinDirection);

/* MPORT_enuSetPinMode function use to set pins mode
*  
*  take two parametares: 1-Copy_enuPortNum (it's concatenation between port ant pin in the same variable)
*                        2-Copy_enuPinMode (INUPUT_pullup OR OUTPUT)
*                       
*/
MPORT_enuErrorStatus_t MPORT_enuSetPinMode(u8 Copy_enuPinNum,MPORT_enuPINConfigration Copy_enuPinMode);

#endif /* PORT_INTERFACING_H_ */