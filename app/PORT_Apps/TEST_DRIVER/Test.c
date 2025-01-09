


#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_INTERFACING.h"
#include "PORT_INTERFACING.h"
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
	/*MDIO_enuSetPinConfigration(MDIO_enuPORTA, MDIO_enuPIN0,MDIO_enuOUTPUT_PIN);
	MDIO_enuSetPinConfigration(MDIO_enuPORTB, MDIO_enuPIN0,MDIO_enuINPUT_PULLUP);*/

     MPORT_enuSetPinDirection(PIN_D0,MPORT_OUTPUT_PIN);
     MPORT_enuSetPinMode(PIN_C0,MPORT_enuINPUT_PULLUP);

	while (1)
	{
		MDIO_enuGetPinValue(MDIO_enuPORTC,MDIO_enuPIN0,&Add_pu8PinValue);
		
		if(Add_pu8PinValue == 1)
		{
			MDIO_enuSetPinValue( MDIO_enuPORTD,MDIO_enuPIN0,MDIO_enuLOW_PIN);
		}
		else
		{
			MDIO_enuSetPinValue( MDIO_enuPORTD,MDIO_enuPIN0,MDIO_enuHIGH_PIN);
			
		}
		
	}
}
