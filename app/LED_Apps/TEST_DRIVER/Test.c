


#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_INTERFACING.h"
#include "LED_INTERFACING.h"
#include "SWITCH_INTERFACING.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Test.h"


int main(void)
{ 

    while (1) 
    {
	  FlashLed();
	  
    }
}


void FlashLed (void)
{
	 u8 Add_pu8PinValue;
	 
	 HLED_vInit();
	 HSWITCH_vInit();
	 
	while (1)
	{
		HSWITCH_enuGetSwitchState(SWITCH_0,&Add_pu8PinValue);
		
		if(Add_pu8PinValue == 1)
		{
			HLED_enuSetLedState(LED_6,HLED_LED_OFF); 
		}
		else
		{
			HLED_enuSetLedState(LED_6,HLED_LED_ON);
			
		}
		
	}
}
