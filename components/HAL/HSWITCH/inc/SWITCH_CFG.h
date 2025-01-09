/*
 * SWITCH_CFG.h
 *
 * Created: 1/2/2025 
 *  Author: Omar Alaa
 */ 


#ifndef SWITCH_CFG_H_
#define SWITCH_CFG_H_

#include "STD_TYPES.h"

#define  HSWITCH_NUM_OF_SWITCHES 3

#define  SWITCH_0      0  
#define  SWITCH_1      1
#define  SWITCH_2      2


typedef struct 
{
   u8 port;
   u8 pin;

}HSWITCH_sSWITCHCfg_t;



#endif /* SWITCH_CFG_H_ */