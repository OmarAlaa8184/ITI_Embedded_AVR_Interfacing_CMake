/*
 * SWITCH_INTERFACING.h
 *
 * Created: 1/2/2025
 *  Author: Omar Alaa
 */ 



#ifndef SWITCH_INTERFACING_H_
#define SWITCH_INTERFACING_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "SWITCH_CFG.h"


typedef enum
{ 
	HSWITCH_enuOK,
	HSWITCH_enuNOK,
	HSWITCH_enuINVALID_SWITCH_NUM,
	HSWITCH_enuSTATE,
	HSWITCH_enuNULL_PTR
	
}HSWITCH_enuErrorStatus_t;




void HSWITCH_vInit(void);

HSWITCH_enuErrorStatus_t HSWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8* Add_pu8State);













#endif /* SWITCH_INTERFACING_H_ */