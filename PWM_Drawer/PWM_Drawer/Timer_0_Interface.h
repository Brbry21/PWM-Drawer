/*
 * Timer_0_Interface.h
 *
 * Created: 1/31/2024 2:42:40 PM
 *  Author: Lenovo
 */ 


#ifndef TIMER_0_INTERFACE_H_
#define TIMER_0_INTERFACE_H_

void TIMER0_Init(void);
void TIMER0_start(void);
void TIMER0_stop(void);


void TIMER0_setDelay_ms_usingCTC(u16 copy_u8_delay_ms);

void TIMER0_setCallBackCTC(void(*ptrToFun)(void));

void Timer_0_Void_Set_Call_Back_Function(void (*copy_pointer_Timer_0) (void));

void TIMER0_Set_Duty_Cycle(u8 copy_u8_duty_cycle);

void TIMER0_SetCompareMatchValue(u8 copy_u8_compareValue);

void Timer_0_Void_Start_Timer(void);



#endif /* TIMER_0_INTERFACE_H_ */