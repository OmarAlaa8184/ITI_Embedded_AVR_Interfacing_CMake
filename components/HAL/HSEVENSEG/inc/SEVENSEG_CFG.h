/*
 * HSEVENSEG_CFG.h
 *
 * Created: 1/5/2025
 *  Author: Omar Alaa
 */ 


#ifndef SEVENSEG_CFG_H_
#define SEVENSEG_CFG_H_

#include "STD_TYPES.h"

/* 
 * Define the total number of 7-segment displays in the system.
 * Define the total number of pins per 7-segment display.
 * Define the maximum number of digits that a 7-segment display can represent.
 */
#define  HSEVENSEG_NUM_OF_SEVENSEGS    4
#define  HSEVENSEG_NUM_OF_PINS         8
#define  HSEVENSEG_MAX_NUM_OF_DIGITS   4

/* 
 * Enumeration for the identifiers of individual 7-segment displays.
 * These identifiers represent each display in the system.
 */
#define  SEVENSEG_0      0  
#define  SEVENSEG_1      1
#define  SEVENSEG_2      2
#define  SEVENSEG_3      3

/* 
 * Enumeration for the operating modes of a 7-segment display:
 *   - Common Cathode
 *   - Common Anode
 */
typedef enum
{ 
	HSEVENSEG_MODE_COMMON_CATHODE,
	HSEVENSEG_MODE_COMMON_ANODE	
	
} HSEVENSEG_enuMODE_t;

/* 
 * Enumeration for the names of the pins of a 7-segment display.
 * Each pin corresponds to a segment (a-g) or the dot (dp).
 */
typedef enum
{ 
    HSEVENSEG_PIN_a,  /* Segment 'a' */
    HSEVENSEG_PIN_b,  /* Segment 'b' */
    HSEVENSEG_PIN_c,  /* Segment 'c' */
    HSEVENSEG_PIN_d,  /* Segment 'd' */
    HSEVENSEG_PIN_e,  /* Segment 'e' */
    HSEVENSEG_PIN_f,  /* Segment 'f' */
    HSEVENSEG_PIN_g,  /* Segment 'g' */
    HSEVENSEG_PIN_dot /* Dot (dp) */
	
} HSEVENSEG_enuPinsName_t;

/* 
 * Enumeration mapping the values (0-9) to their corresponding bit patterns.
 * Each bit pattern represents the segments (a-g, dot) that need to be turned ON.
 * These values are in hexadecimal format for easy representation.
 */
typedef enum
{ 
    HSEVENSEG_0 = 0x3F,  /* Display '0' */
    HSEVENSEG_1 = 0x06,  /* Display '1' */
    HSEVENSEG_2 = 0x5B,  /* Display '2' */
    HSEVENSEG_3 = 0x4F,  /* Display '3' */
    HSEVENSEG_4 = 0x66,  /* Display '4' */
    HSEVENSEG_5 = 0x6D,  /* Display '5' */
    HSEVENSEG_6 = 0x7D,  /* Display '6' */
    HSEVENSEG_7 = 0x07,  /* Display '7' */
    HSEVENSEG_8 = 0x7F,  /* Display '8' */
    HSEVENSEG_9 = 0x6F,  /* Display '9' */
    HSEVENSEG_dot = 0x80 /* Dot (dp) */
	
} HSEVENSEG_enuValuesMap_t;

/* 
 * Structure to define the configuration for a 7-segment display:
 *   - PortPin: Array of pin mappings for each segment (a-g, dot).
 *   - HSEVENSEG_MODE: The operating mode of the 7-segment display 
 *                     (Common Cathode or Common Anode).
 */
typedef struct 
{
   HSEVENSEG_enuPinsName_t PortPin[HSEVENSEG_NUM_OF_PINS]; /* Pin configuration for each segment */
   HSEVENSEG_enuMODE_t HSEVENSEG_MODE;                    /* Operating mode of the display */

} HSEVENSEG_sSEVENSEGCfg_t;




#endif /* SEVENSEG_CFG_H_ */