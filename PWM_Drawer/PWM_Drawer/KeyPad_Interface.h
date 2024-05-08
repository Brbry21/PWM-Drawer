/*
 * KeyPad_Interface.h
 *
 * Created: 1/29/2024 11:35:29 AM
 *  Author: Lenovo
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

void KeyPad_Void_Init(void);

void KeyPad_Void_Get_Key(u8* copy_u8_get_value);

static void chooseRow(char x);

char GET_KEY();
//void KeyPad_Void_Get_Key_Value(u8* get_u8_key_value);


#endif /* KEYPAD_INTERFACE_H_ */