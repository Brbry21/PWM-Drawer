/*
 * KeyPad_Interface.c
 *
 * Created: 1/29/2024 11:35:58 AM
 *  Author: Lenovo
 */ 

#include "STD_Type.h"
#include "Bit_Wise.h"
#include "DIO_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "KeyPad_Config.h"
#include "KeyPad_Interface.h"
#include <util/delay.h>



void KeyPad_Void_Init(void)
{

	/* Set All Columns Pins to Output */
	DIO_Void_Set_Pin_Direction(Keypad_Column_0_Port,Keypad_Column_0_Pin,OUTPUT);
	DIO_Void_Set_Pin_Direction(Keypad_Column_1_Port,Keypad_Column_1_Pin,OUTPUT);
	DIO_Void_Set_Pin_Direction(Keypad_Column_2_Port,Keypad_Column_2_Pin,OUTPUT);
	DIO_Void_Set_Pin_Direction(Keypad_Column_3_Port,Keypad_Column_3_Pin,OUTPUT);
	
	/* Set All Columns Pins to High */
	DIO_Void_Set_Pin_Value(Keypad_Column_0_Port,Keypad_Column_0_Pin,HIGH);
	DIO_Void_Set_Pin_Value(Keypad_Column_1_Port,Keypad_Column_1_Pin,HIGH);
	DIO_Void_Set_Pin_Value(Keypad_Column_2_Port,Keypad_Column_2_Pin,HIGH);
	DIO_Void_Set_Pin_Value(Keypad_Column_3_Port,Keypad_Column_3_Pin,HIGH);
	
	/* Set All Rows Pins to Input */
	DIO_Void_Set_Pin_Direction(Keypad_Row_0_Port,Keypad_Row_0_Pin,INPUT);
	DIO_Void_Set_Pin_Direction(Keypad_Row_1_Port,Keypad_Row_1_Pin,INPUT);
	DIO_Void_Set_Pin_Direction(Keypad_Row_2_Port,Keypad_Row_2_Pin,INPUT);
	DIO_Void_Set_Pin_Direction(Keypad_Row_3_Port,Keypad_Row_3_Pin,INPUT);
	
	/* Set Internal Pull Up To All Input Pins*/
	DIO_Void_Active_Internal_Pull_UP_Resistor(Keypad_Row_0_Port,Keypad_Row_0_Pin);
	DIO_Void_Active_Internal_Pull_UP_Resistor(Keypad_Row_1_Port,Keypad_Row_1_Pin);
	DIO_Void_Active_Internal_Pull_UP_Resistor(Keypad_Row_2_Port,Keypad_Row_2_Pin);
	DIO_Void_Active_Internal_Pull_UP_Resistor(Keypad_Row_3_Port,Keypad_Row_3_Pin);
	
}

void KeyPad_Void_Get_Key(u8* copy_u8_get_value)
{
	*copy_u8_get_value = Keypad_Not_Pressed;
	u8 Loc_Row_counter;u8 Loc_Column_Counter;
	u8 Keypad_Column_Ports[4]={Keypad_Column_0_Port,Keypad_Column_1_Port,Keypad_Column_2_Port,Keypad_Column_3_Port};
	u8 Keypad_Column_Pins[4]={Keypad_Column_0_Pin,Keypad_Column_1_Pin,Keypad_Column_2_Pin,Keypad_Column_3_Pin};
	u8 Keypad_Row_Ports[4]={Keypad_Row_0_Port,Keypad_Row_1_Port,Keypad_Row_2_Port,Keypad_Row_3_Port};
	u8 Keypad_Row_Pins[4]={Keypad_Row_0_Pin,Keypad_Row_1_Pin,Keypad_Row_2_Pin,Keypad_Row_3_Pin};
	u8 Loc_Key_Value;	
	u8 Loc_State_Value=0;
	u8 Loc_Keypad_Key_Value[4][4]=Keypad_Key_Value;
	
	for (Loc_Column_Counter=0;Loc_Column_Counter<4;Loc_Column_Counter++)
	{
		// Active each Column 
		DIO_Void_Set_Pin_Value(Keypad_Column_Ports[Loc_Column_Counter],Keypad_Column_Pins[Loc_Column_Counter],LOW);
		
		for(Loc_Row_counter=0;Loc_Row_counter<4;Loc_Row_counter++)
		{
			DIO_Void_Read_Pin_Value(Keypad_Row_Ports[Loc_Row_counter],Keypad_Row_Pins[Loc_Row_counter],&Loc_Key_Value);

				//Pressed			
				if (Loc_Key_Value ==0
				)
				{
					*copy_u8_get_value=Loc_Keypad_Key_Value[Loc_Row_counter][Loc_Column_Counter];
					while(Loc_Key_Value==0)
					{
						DIO_Void_Read_Pin_Value(Keypad_Row_Ports[Loc_Row_counter],Keypad_Row_Pins[Loc_Row_counter],&Loc_Key_Value);
					}
					
					Loc_State_Value=1;
					break;
				}
			}
			if (Loc_State_Value==1)
			{
				Loc_State_Value=0;
				break;
			}
			// Deactive current Column 
			DIO_Void_Set_Pin_Value(Keypad_Column_Ports[Loc_Column_Counter],Keypad_Column_Pins[Loc_Column_Counter],HIGH);
		}
}

static void chooseRow(char x){
	switch(x) {
		case 0:
		CLR_BIT(PORTC_Reg, 3);
		SET_BIT(PORTC_Reg, 4);
		SET_BIT(PORTC_Reg, 5);
		SET_BIT(PORTC_Reg, 6);
		break;
		case 1:
		SET_BIT(PORTC_Reg, 3);
		CLR_BIT(PORTC_Reg, 4);
		SET_BIT(PORTC_Reg, 5);
		SET_BIT(PORTC_Reg, 6);
		break;
		case 2:
		SET_BIT(PORTC_Reg, 3);
		SET_BIT(PORTC_Reg, 4);
		CLR_BIT(PORTC_Reg, 5);
		SET_BIT(PORTC_Reg, 6);
		break;
		case 3:
		SET_BIT(PORTC_Reg, 3);
		SET_BIT(PORTC_Reg, 4);
		SET_BIT(PORTC_Reg, 5);
		CLR_BIT(PORTC_Reg, 6);
		break;
		case 4:
		SET_BIT(PORTC_Reg, 3);
		SET_BIT(PORTC_Reg, 4);
		SET_BIT(PORTC_Reg, 5);
		SET_BIT(PORTC_Reg, 6);
		break;
	}
}

char GET_KEY(){
	char key = 0;
	chooseRow(0);
	if(READ_BIT(PINB_Reg, 4) == 0){
		key = '1';
		while(READ_BIT(PINB_Reg, 4) == 0);
		}else if(READ_BIT(PINB_Reg, 5) == 0){
		key = '2';
		while(READ_BIT(PINB_Reg, 5) == 0);
		}else if(READ_BIT(PINB_Reg, 6) == 0){
		key = '3';
		while(READ_BIT(PINB_Reg, 6) == 0);
		}else if(READ_BIT(PINB_Reg, 7) == 0){
		key = 'A';
		while(READ_BIT(PINB_Reg, 7) == 0);
	}
	_delay_ms(10);
	chooseRow(1);
	if(READ_BIT(PINB_Reg, 4) == 0){
		key = '4';
		while(READ_BIT(PINB_Reg, 4) == 0);
		}else if(READ_BIT(PINB_Reg, 5) == 0){
		key = '5';
		while(READ_BIT(PINB_Reg, 5) == 0);
		}else if(READ_BIT(PINB_Reg, 6) == 0){
		key = '6';
		while(READ_BIT(PINB_Reg, 6) == 0);
		}else if(READ_BIT(PINB_Reg, 7) == 0){
		key = 'B';
		while(READ_BIT(PINB_Reg, 7) == 0);
	}
	_delay_ms(10);
	chooseRow(2);
	if(READ_BIT(PINB_Reg, 4) == 0){
		key = '7';
		while(READ_BIT(PINB_Reg, 4) == 0);
		}else if(READ_BIT(PINB_Reg, 5) == 0){
		key = '8';
		while(READ_BIT(PINB_Reg, 5) == 0);
		}else if(READ_BIT(PINB_Reg, 6) == 0){
		key = '9';
		while(READ_BIT(PINB_Reg, 6) == 0);
		}else if(READ_BIT(PINB_Reg, 7) == 0){
		key = 'C';
		while(READ_BIT(PINB_Reg, 7) == 0);
	}
	_delay_ms(10);
	chooseRow(3);
	if(READ_BIT(PINB_Reg, 4) == 0){
		key = '*';
		while(READ_BIT(PINB_Reg, 4) == 0);
		}else if(READ_BIT(PINB_Reg, 5) == 0){
		key = '0';
		while(READ_BIT(PINB_Reg, 5) == 0);
		}else if(READ_BIT(PINB_Reg, 6) == 0){
		key = '#';
		while(READ_BIT(PINB_Reg, 6) == 0);
		}else if(READ_BIT(PINB_Reg, 7) == 0){
		key = 'D';
		while(READ_BIT(PINB_Reg, 7) == 0);
	}
	return key;
}






