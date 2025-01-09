#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SET_BIT(VAR,BIT_NO)      (VAR |= (1<<BIT_NO))
#define CLR_BIT(VAR,BIT_NO)      (VAR &=(~(1<<BIT_NO)))
#define TOGGLE_BIT(VAR,BIT_NO)   (VAR ^=(1<<BIT_NO))
#define GET_BIT(VAR,BIT_NO)       (((VAR>>BIT_NO)&1))

/* To write 1/0 in one operation for one BIT |Clear the required bits|   |insert new values|    */

#define WRITE_BIT(REG, BIT, VAL) ( (REG) = ( ( (REG) & (~(1<<(BIT))) ) | ( (VAL) << (BIT)  ) ) )

/* To write the value of the whole register in one operation */

#define WRITE_REG(REG, VAL) ( (REG) =  (VAL) )

#endif
