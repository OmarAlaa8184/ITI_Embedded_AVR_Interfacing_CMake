#ifndef BIT_MATH_H
#define BIT_MATH_H


/* 
 * Macro to set a specific bit in a variable 
 * VAR: the variable 
 * BIT_NO: the bit number to be set
 */
#define SET_BIT(VAR, BIT_NO)      (VAR |= (1 << BIT_NO))

/* 
 * Macro to clear a specific bit in a variable 
 * VAR: the variable 
 * BIT_NO: the bit number to be cleared
 */
#define CLR_BIT(VAR, BIT_NO)      (VAR &= (~(1 << BIT_NO)))

/* 
 * Macro to toggle a specific bit in a variable 
 * VAR: the variable 
 * BIT_NO: the bit number to be toggled
 */
#define TOGGLE_BIT(VAR, BIT_NO)   (VAR ^= (1 << BIT_NO))

/* 
 * Macro to get the value of a specific bit in a variable 
 * VAR: the variable 
 * BIT_NO: the bit number to be retrieved
 */
#define GET_BIT(VAR, BIT_NO)      (((VAR >> BIT_NO) & 1))


/********************High Nibble***************************************/


/* 
 * Macro to set the high nibble in a variable 
 * VAR: the variable 
 * This macro sets the upper four bits of the variable to 1
 */
#define SET_HIGH_NIB(VAR)       (VAR |= (0xF0))

/* 
 * Macro to clear the high nibble in a variable 
 * VAR: the variable 
 * This macro sets the upper four bits of the variable to 0
 */
#define CLR_HIGH_NIB(VAR)       (VAR &= (~(0xF0)))

/* 
 * Macro to toggle the high nibble in a variable 
 * REG: the variable 
 * This macro toggles the upper four bits of the variable
 */
#define TOGGLE_HIGH_NIB(VAR)      (VAR ^= (0xF0))

/* 
 * Macro to get the value of the high nibble in a variable 
 * REG: the variable 
 * This macro retrieves the upper four bits of the variable and shifts them to the lower four bits
 */
#define GET_HIGH_NIB(VAR)         (((VAR & 0xF0) >> 4))



/************************Low Nibble******************************************/

/* 
 * Macro to set the low nibble in a variable 
 * VAR: the variable 
 * This macro sets the low four bits of the variable to 1
 */
#define SET_LOW_NIB(VAR)       (VAR |= (0x0F))

/* 
 * Macro to clear the LOW nibble in a variable 
 * VAR: the variable 
 * This macro sets the low four bits of the variable to 0
 */
#define CLR_LOW_NIB(VAR)       (VAR &= (~(0x0F)))

/* 
 * Macro to toggle the LOW nibble in a variable 
 * REG: the variable 
 * This macro toggles the LOW four bits of the variable
 */
#define TOGGLE_LOW_NIB(VAR)      (VAR ^= (0x0F))

/* 
 * Macro to get the value of the LOW nibble in a variable 
 * REG: the variable 
 * This macro retrieves the LOW four bits of the variable and shifts them to the lower four bits
 */
#define GET_LOW_NIB(VAR)         ((VAR & 0x0F))



/*********************************Assign a Value To Register************************************************/
 
    
/* 
 * Macro to assign a value to the high nibble in a register 
 * REG: the register 
 * VALUE: the value to be assigned to the high nibble
 * This macro assigns the lower four bits of VALUE to the high nibble of REG
 */
#define ASSIGN_HIGH_NIB(REG, VALUE)   (REG = (REG & 0x0F) | ((VALUE & 0x0F) << 4))

/* 
 * Macro to assign a value to the low nibble in a register 
 * REG: the register 
 * VALUE: the value to be assigned to the low nibble
 * This macro assigns the lower four bits of VALUE to the low nibble of REG
 */
#define ASSIGN_LOW_NIB(REG, VALUE)    (REG = (REG & 0x0F) | ((VALUE & 0x0F)))

/* 
 * Macro to right shift a register by a specified number of positions 
 * REG: the register 
 * NO: the number of positions to shift
 */
#define RSHFT_REG(REG, NO)            (REG >> (NO))

/* 
 * Macro to left shift a register by a specified number of positions 
 * REG: the register 
 * NO: the number of positions to shift
 */
#define LSHFT_REG(REG, NO)            (REG << (NO))

/* 
 * Macro to perform a circular right shift on a register by a specified number of positions 
 * REG: the register 
 * NO: the number of positions to shift
 * This macro shifts the bits to the right and wraps the overflow bits to the left
 */
#define CRSHFT_REG(REG, NO)           (REG = (REG >> (NO)) | (REG << (8 - (NO))))

/* 
 * Macro to perform a circular left shift on a register by a specified number of positions 
 * REG: the register 
 * NO: the number of positions to shift
 * This macro shifts the bits to the left and wraps the overflow bits to the right
 */
#define CLSHFT_REG(REG, NO)           (REG = (REG << (NO)) | (REG >> (8 - (NO))))

/* 
 * Macro to write a specific value (1 or 0) to a particular bit in a register 
 * REG: the register 
 * BIT: the bit number to be modified 
 * VAL: the value to be written (1 or 0)
 * This macro clears the required bit and then inserts the new value
 */
#define WRITE_BIT(REG, BIT, VAL) ( (REG) = ( ( (REG) & (~(1 << (BIT))) ) | ( (VAL) << (BIT) ) ) )

/* 
 * Macro to write the value of the whole register in one operation 
 * REG: the register 
 * VAL: the value to be written
 */
#define WRITE_REG(REG, VAL) ( (REG) = (VAL) )


#endif
