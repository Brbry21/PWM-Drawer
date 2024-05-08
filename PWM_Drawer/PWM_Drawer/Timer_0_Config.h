#ifndef TIMER_0_CONFIG_H_
#define TIMER_0_CONFIG_H_


/* Timer/Counter Control Register Pins:
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

#define Timer_0_CS00_Pin															PIN0
#define Timer_0_CS01_Pin															PIN1
#define Timer_0_CS02_Pin															PIN2
#define Timer_0_WGM01_Pin															PIN3
#define Timer_0_COM00_Pin															PIN4
#define Timer_0_COM01_Pin															PIN5
#define Timer_0_WGM00_Pin															PIN6
#define Timer_0_FOC0_Pin															PIN7


/*  Waveform Generation Mode:
*
* Timer_0_Normal_Mode
* Timer_0_CTC_Mode
* Timer_0_Fast_PWM
*
*/

#define TIMER0_MODE                   TIMER0_FAST_PWM_MODE

#define TIMER0_PRELOAD_VALUE          113
#define TIMER0__OVERFLOW_COUNTER      977
#define TIMER0__CTC_COUNTER           4000

#define Timer_0_Normal_Mode															0
#define	Timer_0_CTC_Mode															2
#define	Timer_0_Fast_PWM_Mode														3

#define Timer_0_Waveform_Generation_Mode											Timer_0_Fast_PWM_Mode

/* Timer 0 Compare Output Mode, Non PWM :
*
* Normal_Port_Operation_OC0_Disconected
* Toggle_OC0_On_Compare_Match
* Clear_OC0_On_Compare_Match
* Set_OC0_On_Compare_Match
*
*/

#define	Normal_Port_Operation_OC0_Disconected										0
#define	Toggle_OC0_On_Compare_Match													1	
#define	Clear_OC0_On_Compare_Match													2
#define	Set_OC0_On_Compare_Match													3

#define Timer_0_Compare_Output_Mode_Non_PWM_Mode									Normal_Port_Operation_OC0_Disconected

/*Timer 0 Compare Output Mode, Fast PWM Mode :
*
* Normal_Port_Operation_OC0_Disconected
* Reserved
* Clear_OC0_On_Compare_Match_Set_OC0_At_BOTTOM_Non_Inverting_Mode
* Set_OC0_On_Compare_Match_Clear_OC0_At_BOTTOM_Inverting_Mode
*
*/

#define	Normal_Port_Operation_OC0_Disconected										0
#define	Reserved																	1
#define	Clear_OC0_On_Compare_Match_Set_OC0_At_BOTTOM_Non_Inverting_Mode				2
#define	Set_OC0_On_Compare_Match_Clear_OC0_At_BOTTOM_Inverting_Mode					3

#define Timer_0_Compare_Output_Mode_Fast_PWM_Mode									Clear_OC0_On_Compare_Match_Set_OC0_At_BOTTOM_Non_Inverting_Mode

/* Timer 0 Clock select:
* 
* No_Clock_Source
* No_Prescaler
* Prescaler_8
* Prescaler_64
* Prescaler_256
* Prescaler_1024
* External_Clock_Source_Failing_Edge
* External_Clock_Source_Rising_Edge
*
*/

#define No_Clock_Source																0
#define No_Prescaler																1
#define Prescaler_8																	2
#define Prescaler_64																3
#define Prescaler_256																4
#define Prescaler_1024																5
#define External_Clock_Source_Failing_Edge											6
#define External_Clock_Source_Rising_Edge											7

#define Timer_0_Prescaler_Select													Prescaler_64

/* Timer/Counter Interrupt Mask Register Pins:
*
* Timer_0_TOIE0_Pin
* Timer_0_OCIE0_Pin
*
*/

#define Timer_0_TOIE0_Pin															PIN0
#define Timer_0_OCIE0_Pin															PIN1

/* Timer/Counter Interrupt Flag Register Pins:
*
* Timer_0_TOV0_Pin
* Timer_0_OCF0_Pin
*
*/

#define Timer_0_TOV0_Pin															PIN0
#define Timer_0_OCF0_Pin															PIN1


/* Timer 0 Preload Value */

#define Timer_0__Overflow_Preload_Value												112

/*Timer 0 OCR0 value */

#define Timer_0_OCR0_value															249	

/* Timer 0 OC0 Port And Pin*/

#define Timer_0_OC0_Port															PORTB
#define Timer_0_OC0_Pin																PIN3

/* Timer 0 Counter value */

#define Timer_0_Overflow_Counter_Value												977
#define Timer_0_CTC_Counter_Value													2000

#endif /* TIMER_0_CONFIG_H_ */