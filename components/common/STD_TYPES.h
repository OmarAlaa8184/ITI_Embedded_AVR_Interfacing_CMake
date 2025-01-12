#ifndef STD_TYPES_H
#define STD_TYPES_H

/* Type definitions for signed and unsigned 8-bit integers */
typedef signed char         s8;   /* Signed 8-bit integer */
typedef unsigned char       u8;   /* Unsigned 8-bit integer */

/* Type definitions for signed and unsigned 16-bit integers */
typedef short signed int    s16;  /* Signed 16-bit integer */
typedef short unsigned int  u16;  /* Unsigned 16-bit integer */

/* Type definitions for signed and unsigned 32-bit integers */
typedef long signed int     s32;  /* Signed 32-bit integer */
typedef long unsigned int   u32;  /* Unsigned 32-bit integer */

/* Type definitions for 32-bit and 64-bit floating point numbers */
typedef double              f64;  /* 64-bit floating point number */
typedef float               f32;  /* 32-bit floating point number */

/* Definition of NULL pointer */
#define NULL  ((void *)0x00)


#endif
