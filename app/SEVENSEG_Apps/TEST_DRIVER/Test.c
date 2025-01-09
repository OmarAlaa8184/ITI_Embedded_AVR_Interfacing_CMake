


#define F_CPU 8000000UL
#include <util/delay.h>
#include "SEVENSEG_INTERFACING.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Test.h"


int main(void)
{ 

    while (1) 
    {
	  SEVENSEG();
	  
    }
}


void SEVENSEG (void)
{
	 HSEVENSEG_vInit();
     //HSEVENSEG_vSetValue(SEVENSEG_0,3);
     //HSEVENSEG_vSetValue(SEVENSEG_1,2);
    HSEVENSEG_enuSetMultiDigitValue(41);
}
