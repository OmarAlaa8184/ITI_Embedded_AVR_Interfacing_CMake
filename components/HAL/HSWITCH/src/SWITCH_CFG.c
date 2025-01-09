/*
 * SWITCH_CFG.c
 *
 * Created: 1/2/2025
 *  Author: Omar Alaa
 */ 


#include "SWITCH_CFG.h"
#include "PORT_INTERFACING.h"



HSWITCH_sSWITCHCfg_t HSWITCH_sArrSWITCHCfg[HSWITCH_NUM_OF_SWITCHES]=
{
    [SWITCH_0]={   
                .port=MPORT_enuPORTB,
                .pin=MPORT_enuPIN0
            },

    [SWITCH_1]={   
                .port=MPORT_enuPORTA,
                .pin=MPORT_enuPIN1
            },  

    [SWITCH_2]={   
                 .port=MPORT_enuPORTA,
                 .pin=MPORT_enuPIN2
            }

};





	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
											 