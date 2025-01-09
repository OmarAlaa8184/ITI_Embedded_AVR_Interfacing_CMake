/*
 * SEVENSEG_CFG.c
 *
 * Created: 1/2/2025
 *  Author: Omar Alaa
 */ 


#include "SEVENSEG_CFG.h"
#include "PORT_INTERFACING.h"

HSEVENSEG_sSEVENSEGCfg_t HSEVENSEG_sArrSEVENSEGCfg[HSEVENSEG_NUM_OF_SEVENSEGS] = 
{
    [SEVENSEG_0] = {   
                      /* Configuration for the first 7-segment display (SEVENSEG_0) */
                      .PortPin = {
                          /* Mapping the segments (a to g + dot) to specific pins for the first display */
                          [HSEVENSEG_PIN_a] = PIN_A0,  /* Segment 'a' connected to PIN_A0 */
                          [HSEVENSEG_PIN_b] = PIN_A1,  /* Segment 'b' connected to PIN_A1 */
                          [HSEVENSEG_PIN_c] = PIN_B2,  /* Segment 'c' connected to PIN_A2 */
                          [HSEVENSEG_PIN_d] = PIN_B3,  /* Segment 'd' connected to PIN_A3 */
                          [HSEVENSEG_PIN_e] = PIN_C4,  /* Segment 'e' connected to PIN_A4 */
                          [HSEVENSEG_PIN_f] = PIN_C5,  /* Segment 'f' connected to PIN_A5 */
                          [HSEVENSEG_PIN_g] = PIN_D6,  /* Segment 'g' connected to PIN_A6 */
                          [HSEVENSEG_PIN_dot] = PIN_D7 /* Decimal point connected to PIN_A7 */
                      },
              
                      /* Mode configuration: This 7-segment display uses a common anode configuration */
                      .HSEVENSEG_MODE = HSEVENSEG_MODE_COMMON_ANODE
                    },    

    [SEVENSEG_1] = {   
                      /* Configuration for the second 7-segment display (SEVENSEG_1) */
                      .PortPin = {
                          /* Mapping the segments (a to g + dot) to specific pins for the second display */
                          [HSEVENSEG_PIN_a] = PIN_B0,  /* Segment 'a' connected to PIN_B0 */
                          [HSEVENSEG_PIN_b] = PIN_B1,  /* Segment 'b' connected to PIN_B1 */
                          [HSEVENSEG_PIN_c] = PIN_A2,  /* Segment 'c' connected to PIN_B2 */
                          [HSEVENSEG_PIN_d] = PIN_A3,  /* Segment 'd' connected to PIN_B3 */
                          [HSEVENSEG_PIN_e] = PIN_D4,  /* Segment 'e' connected to PIN_B4 */
                          [HSEVENSEG_PIN_f] = PIN_D5,  /* Segment 'f' connected to PIN_B5 */
                          [HSEVENSEG_PIN_g] = PIN_C6,  /* Segment 'g' connected to PIN_B6 */
                          [HSEVENSEG_PIN_dot] = PIN_C7 /* Decimal point connected to PIN_B7 */
                      },

                      /* Mode configuration: This 7-segment display uses a common anode configuration */
                      .HSEVENSEG_MODE = HSEVENSEG_MODE_COMMON_ANODE
    },      

    [SEVENSEG_2] = {   
                       /* Configuration for the third 7-segment display (SEVENSEG_2) */
                       .PortPin = {
                           /* Mapping the segments (a to g + dot) to specific pins for the third display */
                           [HSEVENSEG_PIN_a] = PIN_C0,  /* Segment 'a' connected to PIN_C0 */
                           [HSEVENSEG_PIN_b] = PIN_C1,  /* Segment 'b' connected to PIN_C1 */
                           [HSEVENSEG_PIN_c] = PIN_C2,  /* Segment 'c' connected to PIN_C2 */
                           [HSEVENSEG_PIN_d] = PIN_C3,  /* Segment 'd' connected to PIN_C3 */
                           [HSEVENSEG_PIN_e] = PIN_C4,  /* Segment 'e' connected to PIN_C4 */
                           [HSEVENSEG_PIN_f] = PIN_C5,  /* Segment 'f' connected to PIN_C5 */
                           [HSEVENSEG_PIN_g] = PIN_C6,  /* Segment 'g' connected to PIN_C6 */
                           [HSEVENSEG_PIN_dot] = PIN_C7 /* Decimal point connected to PIN_C7 */
                       },

                      /* Mode configuration: This 7-segment display uses a common anode configuration */
                      .HSEVENSEG_MODE = HSEVENSEG_MODE_COMMON_ANODE
    },

    [SEVENSEG_3] = {   
                       /* Configuration for the fourth 7-segment display (SEVENSEG_3) */
                       .PortPin = {
                           /* Mapping the segments (a to g + dot) to specific pins for the fourth display */
                           [HSEVENSEG_PIN_a] = PIN_D0,  /* Segment 'a' connected to PIN_D0 */
                           [HSEVENSEG_PIN_b] = PIN_D1,  /* Segment 'b' connected to PIN_D1 */
                           [HSEVENSEG_PIN_c] = PIN_D2,  /* Segment 'c' connected to PIN_D2 */
                           [HSEVENSEG_PIN_d] = PIN_D3,  /* Segment 'd' connected to PIN_D3 */
                           [HSEVENSEG_PIN_e] = PIN_D4,  /* Segment 'e' connected to PIN_D4 */
                           [HSEVENSEG_PIN_f] = PIN_D5,  /* Segment 'f' connected to PIN_D5 */
                           [HSEVENSEG_PIN_g] = PIN_D6,  /* Segment 'g' connected to PIN_D6 */
                           [HSEVENSEG_PIN_dot] = PIN_D7 /* Decimal point connected to PIN_D7 */
                       },

                       /* Mode configuration: This 7-segment display uses a common anode configuration */
                       .HSEVENSEG_MODE = HSEVENSEG_MODE_COMMON_ANODE
                      
            }

};

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
											 