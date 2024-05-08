/*
 * KeyPad_Config.h
 *
 * Created: 1/29/2024 11:34:50 AM
 *  Author: Lenovo
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

/*Columns' Ports:
*
* Keypad_Column_0_Port
* Keypad_Column_1_Port
* Keypad_Column_2_Port
* Keypad_Column_3_Port
*
*/

#define Keypad_Column_0_Port				PORTB			
#define Keypad_Column_1_Port				PORTB
#define Keypad_Column_2_Port				PORTB
#define Keypad_Column_3_Port				PORTB

/*Columns' Pins:
*
* Keypad_Column_0_Pin
* Keypad_Column_1_Pin
* Keypad_Column_2_Pin
* Keypad_Column_3_Pin
*
*/

#define Keypad_Column_0_Pin				PIN4
#define Keypad_Column_1_Pin				PIN5
#define Keypad_Column_2_Pin				PIN6
#define Keypad_Column_3_Pin				PIN7

/*Rows' Ports:
*
* Keypad_Row_0_Port
* Keypad_Row_1_Port
* Keypad_Row_2_Port
* Keypad_Row_3_Port
*
*/

#define Keypad_Row_0_Port				PORTC
#define Keypad_Row_1_Port				PORTC
#define Keypad_Row_2_Port				PORTC
#define Keypad_Row_3_Port				PORTC

/*Rows' Pins:
*
* Keypad_Row_0_Pin
* Keypad_Row_1_Pin
* Keypad_Row_2_Pin
* Keypad_Row_3_Pin
*
*/

#define Keypad_Row_0_Pin				PIN3
#define Keypad_Row_1_Pin				PIN4
#define Keypad_Row_2_Pin				PIN5
#define Keypad_Row_3_Pin				PIN6

/*Keypad Rows:
*
* Keypad_Row_0
* Keypad_Row_1
* Keypad_Row_2
* Keypad_Row_3
*
*/

#define Keypad_Row_0					0
#define Keypad_Row_1					1
#define Keypad_Row_2					2
#define Keypad_Row_3					3

#define Keypad_Key_Value				{{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}}

#define Keypad_Not_Pressed				255


#endif /* KEYPAD_CONFIG_H_ */