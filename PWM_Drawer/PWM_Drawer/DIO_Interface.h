/*
 * DIO_Interface.h
 *
 * Created: 1/26/2024 11:31:39 PM
 *  Author: Lenovo
 */ 

#include "STD_Type.h"

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

void DIO_Void_Set_Pin_Direction(u8 copy_u8_port,u8 copy_u8_pin,u8 copy_u8_output_or_input);

void DIO_Void_Set_Pin_Value(u8 copy_u8_port,u8 copy_u8_pin,u8 copy_u8_high_or_low);

void DIO_Void_Toggle_Pin(u8 copy_u8_port,u8 copy_u8_pin);

void DIO_Void_Set_Pin_Direction_And_Pin_Value(u8 copy_u8_port,u8 copy_u8_pin,u8 copy_u8_output_or_input,u8 copy_u8_high_or_low);

void DIO_Void_Read_Pin_Value(u8 copy_u8_port,u8 copy_u8_pin,u8* copy_u8_value);

void DIO_Void_Active_Internal_Pull_UP_Resistor(u8 copy_u8_port,u8 copy_u8_pin);



#endif /* DIO_INTERFACE_H_ */