
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_INTERFACING.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Task3.h"


int main(void)
{ 

    while (1) 
    {
	  SW_LE_INT();
    }
}

void SW_LE_INT(void)
{
     u8 Add_pu8PinValue;
	 u8 Add_pu8PinValue1;
	 u8 Add_pu8PinValue2;
     MDIO_vInit();

    while (1) 
    {
	  
	  MDIO_enuGetPinValue(MDIO_enuPORTD,MDIO_enuPIN3,&Add_pu8PinValue);
	  MDIO_enuGetPinValue(MDIO_enuPORTD,MDIO_enuPIN0,&Add_pu8PinValue1);
	  MDIO_enuGetPinValue(MDIO_enuPORTD,MDIO_enuPIN5,&Add_pu8PinValue2);
	  
	  if(Add_pu8PinValue == 1)
	  {
		  MDIO_enuSetPinValue( MDIO_enuPORTA,MDIO_enuPIN0,MDIO_enuLOW_PIN);
	  }
	  else
	  {
		  MDIO_enuSetPinValue( MDIO_enuPORTA,MDIO_enuPIN0,MDIO_enuHIGH_PIN);
	  }
	  

	  if(Add_pu8PinValue1 == 1)
	  {
		  MDIO_enuSetPinValue( MDIO_enuPORTA,MDIO_enuPIN2,MDIO_enuLOW_PIN);
	  }
	  else
	  {
		  MDIO_enuSetPinValue( MDIO_enuPORTA,MDIO_enuPIN2,MDIO_enuHIGH_PIN);
	  }
	  

	  if(Add_pu8PinValue2 == 1)
	  {
		  MDIO_enuSetPinValue( MDIO_enuPORTC,MDIO_enuPIN0,MDIO_enuLOW_PIN);
	  }
	  else
	  {
		  MDIO_enuSetPinValue( MDIO_enuPORTC,MDIO_enuPIN0,MDIO_enuHIGH_PIN);
	  }
	  
    }

}