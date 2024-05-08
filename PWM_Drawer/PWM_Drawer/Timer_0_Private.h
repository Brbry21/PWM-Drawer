/*
 * Timer_0_Private.h
 *
 * Created: 1/31/2024 2:41:54 PM
 *  Author: Lenovo
 */ 


#ifndef TIMER_0_PRIVATE_H_
#define TIMER_0_PRIVATE_H_

/* MACROS FOR TIMER MODE CONFIGURATIONS */
#define TIMER0_NORMAL_MODE 1
#define TIMER0_CTC_MODE 2
#define TIMER0_FAST_PWM_MODE 3

/* Timer/Counter Control Register Timer0 */

#define	TCCR0_REG					*((volatile u8*)0x53)							

/* Timer/Counter Control Register Pins
*
* Timer_0_CS00_Pin	
* Timer_0_CS01_Pin	
* Timer_0_CS02_Pin	
* Timer_0_WGM01_Pin	
* Timer_0_COM00_Pin	
* Timer_0_COM01_Pin	
* Timer_0_WGM00_Pin	
* Timer_0_FOC0_Pin	
*
*/

#define CS00					0
#define CS01					1
#define CS02					2
#define WGM01					3
#define COM00					4	
#define COM01					5
#define WGM00					6
#define FOC0					7

/* Timer/Counter Register Timer0 */

#define  TCNT0_REG							*((volatile u8*) 0x52)

/* Output Compare Register Timer 0*/

#define  OCR0_REG							*((volatile u8*) 0x5C)

/* Timer/Counter Interrupt Mask Register Timer 0 */

#define  TIMSK_REG							*((volatile u8*) 0x59)
#define  TOIE0                              0
#define  OCIE0                              1

/* Timer/Counter Interrupt Flag Register Timer 0 */

#define  TIFR_REG							*((volatile u8*) 0x58)
#define  TOV0                               0
#define  OCF0                               1


#endif /* TIMER_0_PRIVATE_H_ */