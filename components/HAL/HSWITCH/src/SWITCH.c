/*
 * SWITCH.C
 *
 * Created: 1/2/2025
 *  Author: Omar Alaa
 */ 

#include "DIO_INTERFACING.h"
#include "PORT_INTERFACING.h"
#include "SWITCH_INTERFACING.h"
#include "SWITCH_CFG.h"


extern  HSWITCH_sSWITCHCfg_t HSWITCH_sArrSWITCHCfg[HSWITCH_NUM_OF_SWITCHES];

void HSWITCH_vInit(void)
{
 
  u8 Local_u8CurrPortPin =0;
 
  for(u8 Local_u8Conter=0;Local_u8Conter < HSWITCH_NUM_OF_SWITCHES;Local_u8Conter++)
  {

    Local_u8CurrPortPin=(((HSWITCH_sArrSWITCHCfg[Local_u8Conter].port)<<4)+(HSWITCH_sArrSWITCHCfg[Local_u8Conter].pin));
     
    MPORT_enuSetPinMode(Local_u8CurrPortPin,MPORT_enuINPUT_PULLUP);
  }
 

}


HSWITCH_enuErrorStatus_t HSWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8* Add_pu8State)
{
    HSWITCH_enuErrorStatus_t Ret_enuError=HSWITCH_enuNOK;

    if (Copy_u8SwitchName <SWITCH_0 || Copy_u8SwitchName>SWITCH_2 )
    {
        Ret_enuError=HSWITCH_enuINVALID_SWITCH_NUM;
    }
    else if (Add_pu8State==NULL)
    {
        Ret_enuError=HSWITCH_enuNULL_PTR;
    }
    else
    {   
        Ret_enuError=HSWITCH_enuOK;

        MDIO_enuGetPinValue(HSWITCH_sArrSWITCHCfg[Copy_u8SwitchName].port,HSWITCH_sArrSWITCHCfg[Copy_u8SwitchName].pin ,Add_pu8State);
    }
    
    return Ret_enuError;
}