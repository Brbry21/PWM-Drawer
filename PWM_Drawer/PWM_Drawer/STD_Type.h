/*
 * STD_Type.h
 *
 * Created: 1/26/2024 11:20:50 PM
 *  Author: Lenovo
 */ 


#ifndef STD_TYPE_H_
#define STD_TYPE_H_

/* only postive data  */

typedef unsigned char             u8  ;
typedef unsigned short int       u16  ;
typedef unsigned  int            u32  ;
typedef unsigned long long int   u64  ;
/* postive data & negative data */

typedef signed char            s8  ;
typedef signed short int       s16  ;
typedef signed  int            s32  ;
typedef signed long long int   s64  ;

/* floating data type  */
typedef  float   f32  ;
typedef  double   f64  ;

/*boolan*/
typedef enum {False, True} BOOL ;
#define NULL     ((void*)0)



#endif /* STD_TYPE_H_ */