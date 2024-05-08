/*
 * DIO_Private.h
 *
 * Created: 1/26/2024 11:29:34 PM
 *  Author: Lenovo
 */ 

#include "STD_Type.h"

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/* Port A */

#define PORTA_Reg		*((volatile u8*) 0x3B)
#define DDRA_Reg		*((volatile u8*) 0x3A)
#define PINA_Reg		*((volatile u8*) 0x39)

/* Port B */

#define PORTB_Reg		*((volatile u8*) 0x38)
#define DDRB_Reg		*((volatile u8*) 0x37)
#define PINB_Reg		*((volatile u8*) 0x36)

/* Port C */

#define PORTC_Reg		*((volatile u8*) 0x35)
#define DDRC_Reg		*((volatile u8*) 0x34)
#define PINC_Reg		*((volatile u8*) 0x33)

/* Port D */

#define PORTD_Reg		*((volatile u8*) 0x32)
#define DDRD_Reg		*((volatile u8*) 0x31)
#define PIND_Reg		*((volatile u8*) 0x30)



#endif /* DIO_PRIVATE_H_ */