/*
 * PORT_CFG.h
 *
 * Created: 2/10/2024 
 * Author: Omar Alaa
 */ 

 #include "EXTI_INTERFACING.h"


 MEXTI_sEXTICfg_t MEXTI_struExtiCfg[MEXTI_NUM_OF_EXTI] =  /* Define and initialize the array of EXTI configurations */
 {
     [MEXTI_INT0] = {  /* Configuration for EXTI interrupt 0 */
         .EXTINAME = MEXTI_INT0,  /* Set the EXTI name to INT0 */
         .MODE = MEXTI_FallingEdge,  /* Set the mode to falling edge */
     },
 
     [MEXTI_INT1] = {  /* Configuration for EXTI interrupt 1 */
         .EXTINAME = MEXTI_INT1,  /* Set the EXTI name to INT1 */
         .MODE = MEXTI_FallingEdge,  /* Set the mode to falling edge */
     },
 
     [MEXTI_INT2] = {  /* Configuration for EXTI interrupt 2 */
         .EXTINAME = MEXTI_INT2,  /* Set the EXTI name to INT2 */
         .MODE = MEXTI_EXTI2_FallingEdge,  /* Set the mode to falling edge for EXTI2 */
     },
 };




