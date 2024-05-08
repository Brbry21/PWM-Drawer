/*
 * DIO_Interface.c
 *
 * Created: 1/26/2024 11:32:04 PM
 *  Author: Lenovo
 */ 

#include "STD_Type.h"
#include "Bit_Wise.h"
#include "DIO_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"

void DIO_Void_Set_Pin_Direction(u8 copy_u8_port,u8 copy_u8_pin,u8 copy_u8_output_or_input)
{
	switch (copy_u8_port)
	{
		case PORTA:
		if (copy_u8_output_or_input == OUTPUT)
		{
			SET_BIT(DDRA_Reg,copy_u8_pin);
		}
		else if(copy_u8_output_or_input == INPUT)
		{
			CLR_BIT(DDRA_Reg,copy_u8_pin);
		}
		break;
		
		case PORTB:
		if (copy_u8_output_or_input == OUTPUT)
		{
			SET_BIT(DDRB_Reg,copy_u8_pin);
		}
		else if(copy_u8_output_or_input == INPUT)
		{
			CLR_BIT(DDRB_Reg,copy_u8_pin);
		}
		break;
		
		case PORTC:
		if (copy_u8_output_or_input == OUTPUT)
		{
			SET_BIT(DDRC_Reg,copy_u8_pin);
		}
		else if(copy_u8_output_or_input == INPUT)
		{
			CLR_BIT(DDRC_Reg,copy_u8_pin);
		}
		break;
		
		case PORTD:
		if (copy_u8_output_or_input == OUTPUT)
		{
			SET_BIT(DDRD_Reg,copy_u8_pin);
		}
		else if(copy_u8_output_or_input == INPUT)
		{
			CLR_BIT(DDRD_Reg,copy_u8_pin);
		}
		break;
	}
}

void DIO_Void_Set_Pin_Value(u8 copy_u8_port,u8 copy_u8_pin,u8 copy_u8_high_or_low)
{
	switch (copy_u8_port)
	{
		case PORTA:
		if (copy_u8_high_or_low == HIGH)
		{
			SET_BIT(PORTA_Reg,copy_u8_pin);
		}
		else
		{
			CLR_BIT(PORTA_Reg,copy_u8_pin);
		}
		break;
		
		case PORTB:
		if (copy_u8_high_or_low == HIGH)
		{
			SET_BIT(PORTB_Reg,copy_u8_pin);
		}
		else if(copy_u8_high_or_low == LOW)
		{
			CLR_BIT(PORTB_Reg,copy_u8_pin);
		}
		break;
		
		case PORTC:
		if (copy_u8_high_or_low == HIGH)
		{
			SET_BIT(PORTC_Reg,copy_u8_pin);
		}
		else if(copy_u8_high_or_low == LOW)
		{
			CLR_BIT(PORTC_Reg,copy_u8_pin);
		}
		break;
		
		case PORTD:
		if (copy_u8_high_or_low == HIGH)
		{
			SET_BIT(PORTD_Reg,copy_u8_pin);
		}
		else if(copy_u8_high_or_low == LOW)
		{
			CLR_BIT(PORTD_Reg,copy_u8_pin);
		}
		break;
	}
}

void DIO_Void_Toggle_Pin(u8 copy_u8_port,u8 copy_u8_pin)
{
	switch (copy_u8_port)
	{
		case PORTA:
		TOGGLE_BIT(PORTA_Reg,copy_u8_pin);
		break;
		
		case PORTB:
		TOGGLE_BIT(PORTB_Reg,copy_u8_pin);
		break;
		
		case PORTC:
		TOGGLE_BIT(PORTC_Reg,copy_u8_pin);
		break;
		
		case PORTD:
		TOGGLE_BIT(PORTD_Reg,copy_u8_pin);
		break;
	}
}

void DIO_Void_Set_Pin_Direction_And_Pin_Value(u8 copy_u8_port,u8 copy_u8_pin,u8 copy_u8_output_or_input,u8 copy_u8_high_or_low)
{
	DIO_Void_Set_Pin_Direction(copy_u8_port,copy_u8_pin,copy_u8_output_or_input);
	DIO_Void_Set_Pin_Value(copy_u8_port,copy_u8_pin,copy_u8_high_or_low);
}

void DIO_Void_Read_Pin_Value(u8 copy_u8_port,u8 copy_u8_pin,u8* copy_u8_value)
{
	
	switch (copy_u8_port)
	{
		case PORTA:
		*copy_u8_value=READ_BIT(PINA_Reg,copy_u8_pin);
		break;
		
		case PORTB:
		*copy_u8_value=READ_BIT(PINB_Reg,copy_u8_pin);
		break;
		
		case PORTC:
		*copy_u8_value=READ_BIT(PINC_Reg,copy_u8_pin);
		break;
		
		case PORTD:
		*copy_u8_value=READ_BIT(PIND_Reg,copy_u8_pin);
		break;
	}
}

void DIO_Void_Active_Internal_Pull_UP_Resistor(u8 copy_u8_port,u8 copy_u8_pin)
{
	switch (copy_u8_port)
	{
		case PORTA:
		SET_BIT(PORTA_Reg,copy_u8_pin);
		break;
		
		case PORTB:
		SET_BIT(PORTB_Reg,copy_u8_pin);
		break;
		
		case PORTC:
		SET_BIT(PORTC_Reg,copy_u8_pin);
		break;
		
		case PORTD:
		SET_BIT(PORTD_Reg,copy_u8_pin);
		break;
	}
}