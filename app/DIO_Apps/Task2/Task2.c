
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_INTERFACING.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Task2.h"


int main(void)
{ 

    while (1) 
    {
	  BinaryCounter();
    }
}

void BinaryCounter (void)
{
	u8 Add_pu8PinValue;
	MDIO_enuSetPortConfigration(MDIO_enuPORTB,MDIO_enuOUTPUT_PORT);
	MDIO_enuSetPinConfigration(MDIO_enuPORTA, MDIO_enuPIN0,MDIO_enuINPUT_PULLUP);
	u16 counter=0;
	while (1)
	{
		MDIO_enuGetPinValue(MDIO_enuPORTA,MDIO_enuPIN0,&Add_pu8PinValue);
		
		if(Add_pu8PinValue ==0 )
		{
				_delay_ms(100);
				
          if(Add_pu8PinValue ==0 )
          {
			for (u16 counter=0;counter<256;counter++)
			{
				
				MDIO_enuSetPortValue1(MDIO_enuPORTB,counter);
				_delay_ms(500);
				
			}
			counter=0;
			MDIO_enuSetPortValue1(MDIO_enuPORTB,counter);
		 }
	   }
	}
}



