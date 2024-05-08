/*
 * Timer_0_Interface.c
 *
 * Created: 2/1/2024 6:07:51 PM
 *  Author: Lenovo
 */ 

#include "STD_Type.h"
#include "Bit_Wise.h"
#include "DIO_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "Timer_0_Private.h"
#include "Timer_0_Config.h"
#include "Timer_0_Interface.h"

volatile static u16 private_ctcCounter;

static void (*private_pCallBackOVF)(void)=NULL;
static void (*private_pCallBackCTC)(void)=NULL;

void TIMER0_Init(void)
{
	#if TIMER0_MODE == TIMER0_NORMAL_MODE
	//Select Mode = Normal Mode
	CLR_BIT(TCCR0_REG, WGM00);
	CLR_BIT(TCCR0_REG, WGM01);
	
	//Init Timer With Preload Value
	TCNT0_REG = TIMER0_PRELOAD_VALUE;
	
	//Enable OVF Interrupt
	SET_BIT(TIMSK_REG,TOIE0);
	
	#elif TIMER0_MODE == TIMER0_CTC_MODE
	//Select Mode = CTC Mode
	CLR_BIT(TCCR0_REG, WGM00);
	SET_BIT(TCCR0_REG, WGM01);
	
	//Enable OC Interrupt
	SET_BIT(TIMSK_REG,OCIE0);
	
	#elif TIMER0_MODE == TIMER0_FAST_PWM_MODE
	//Select Mode = FAST PWM Mode
	SET_BIT(TCCR0_REG, WGM00);
	SET_BIT(TCCR0_REG, WGM01);
	
	//Select Non Inverting PWM
	CLR_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
	
	/*//Select Mode = Non Inverting Mode
	CLR_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);*/
	#endif
	      
}

void TIMER0_start(void){
	//Select Prescaler Value = 64
	SET_BIT(TCCR0_REG,CS00);
	SET_BIT(TCCR0_REG,CS01);
	CLR_BIT(TCCR0_REG,CS02);
}
void TIMER0_stop(void){
	//Select Prescaler Value = 0
	CLR_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	CLR_BIT(TCCR0_REG,CS02);
}



void TIMER0_SetCompareMatchValue(u8 copy_u8_compareValue)
{
	OCR0_REG = copy_u8_compareValue;
}

void Timer_0_Void_Start_Timer(void)
{
	#if		Timer_0_Prescaler_Select == No_Clock_Source

	CLR_BIT(TCCR0_REG,Timer_0_CS00_Pin);
	CLR_BIT(TCCR0_REG,Timer_0_CS01_Pin);
	CLR_BIT(TCCR0_REG,Timer_0_CS02_Pin);

	#elif	Timer_0_Prescaler_Select == No_Prescaler
	
	SET_BIT(TCCR0_REG,Timer_0_CS00_Pin);
	CLR_BIT(TCCR0_REG,Timer_0_CS01_Pin);
	CLR_BIT(TCCR0_REG,Timer_0_CS02_Pin);
	
	#elif	Timer_0_Prescaler_Select == Prescaler_8
	
	CLR_BIT(TCCR0_REG,Timer_0_CS00_Pin);
	SET_BIT(TCCR0_REG,Timer_0_CS01_Pin);
	CLR_BIT(TCCR0_REG,Timer_0_CS02_Pin);
	
	#elif	Timer_0_Prescaler_Select == Prescaler_64
	
	SET_BIT(TCCR0_REG,Timer_0_CS00_Pin);
	SET_BIT(TCCR0_REG,Timer_0_CS01_Pin);
	CLR_BIT(TCCR0_REG,Timer_0_CS02_Pin);
	
	#elif	Timer_0_Prescaler_Select == Prescaler_256
	
	CLR_BIT(TCCR0_REG,Timer_0_CS00_Pin);
	CLR_BIT(TCCR0_REG,Timer_0_CS01_Pin);
	SET_BIT(TCCR0_REG,Timer_0_CS02_Pin);
	
	#elif	Timer_0_Prescaler_Select == Prescaler_1024
	
	SET_BIT(TCCR0_REG,Timer_0_CS00_Pin);
	CLR_BIT(TCCR0_REG,Timer_0_CS01_Pin);
	SET_BIT(TCCR0_REG,Timer_0_CS02_Pin);
	
	#elif	Timer_0_Prescaler_Select == External_Clock_Source_Failing_Edge
	
	CLR_BIT(TCCR0_REG,Timer_0_CS00_Pin);
	SET_BIT(TCCR0_REG,Timer_0_CS01_Pin);
	SET_BIT(TCCR0_REG,Timer_0_CS02_Pin);
	
	#elif	Timer_0_Prescaler_Select == External_Clock_Source_Rising_Edge
	
	SET_BIT(TCCR0_REG,Timer_0_CS00_Pin);
	SET_BIT(TCCR0_REG,Timer_0_CS01_Pin);
	SET_BIT(TCCR0_REG,Timer_0_CS02_Pin);
	
#endif
}

void Timer_0_Void_Set_Call_Back_Function(void (*copy_pointer_Timer_0) (void))
{
	if (copy_pointer_Timer_0 != NULL)
	{
		
		#if		Timer_0_Waveform_Generation_Mode == Timer_0_Normal_Mode
		
		Private_Pointer_Call_Back_Timer_0_Normal_Mode = copy_pointer_Timer_0;
		
		#elif	Timer_0_Waveform_Generation_Mode == Timer_0_CTC_Mode
		
		Private_Pointer_Call_Back_Timer_0_CTC_Mode = copy_pointer_Timer_0;
		
#endif

	}
	
}

void TIMER0_setDelay_ms_usingCTC(u16 copy_u8_delay_ms)
{
	// under condition tick time 4 MS
	OCR0_REG = 249;
	private_ctcCounter = copy_u8_delay_ms;
}

void TIMER0_Set_Duty_Cycle(u8 copy_u8_duty_cycle)
{
	if(copy_u8_duty_cycle){
	OCR0_REG= ((copy_u8_duty_cycle * 256)/100)-1;
	}
}

void TIMER0_setCallBackCTC(void(*ptrToFun)(void)){
	if (ptrToFun!=NULL)
	{
		private_pCallBackCTC = ptrToFun;
	}
}


void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)
{
	static u16 loc_u16_counter=0;
	loc_u16_counter++;
	
	if (loc_u16_counter == private_ctcCounter)
	{
		loc_u16_counter=0;
		/* Call action */
		if (private_pCallBackCTC != NULL)
		{
			private_pCallBackCTC();
		}
	}
}

void __vector_11(void) __attribute__ ((signal));
void __vector_11(void)
{
	static u16 loc_u16_counter=0;
	loc_u16_counter++;
	
	if (loc_u16_counter == Timer_0_Overflow_Counter_Value)
	{
		TCNT0_REG = Timer_0__Overflow_Preload_Value;
		loc_u16_counter=0;
		/* Call action */
		if (private_pCallBackOVF != NULL)
		{
			private_pCallBackOVF();
		}
	}
}