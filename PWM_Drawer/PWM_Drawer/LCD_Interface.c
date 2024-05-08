/*
 * LCD_Interface.c
 *
 * Created: 1/28/2024 8:20:54 AM
 *  Author: Lenovo
 */ 

#define F_CPU 16000000UL
#include "STD_Type.h"
#include "Bit_Wise.h"
#include "DIO_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "KeyPad_Config.h"
#include "KeyPad_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "util/delay.h"
 
static void  Private_Write_Half_Port(u8 copy_higher_or_lower_half,u8 copy_u8_data){
	// first it reads higher or lower part of port and turn it high or low in pins d4 to d7
	switch (copy_higher_or_lower_half)
	{
		case Lower_half:
		if (READ_BIT(copy_u8_data,PIN0)==1)
		{
			DIO_Void_Set_Pin_Value(LCD_Data_Ports,LCD_D4_Pin,HIGH);
		}
		else
		{
			DIO_Void_Set_Pin_Value(LCD_Data_Ports,LCD_D4_Pin,LOW);
		}
		if (READ_BIT(copy_u8_data,PIN1)==1)
		{
			DIO_Void_Set_Pin_Value(LCD_Data_Ports,LCD_D5_Pin,HIGH);
		}
		else
		{
			DIO_Void_Set_Pin_Value(LCD_Data_Ports,LCD_D5_Pin,LOW);
		}
		if (READ_BIT(copy_u8_data,PIN2)==1)
		{
			DIO_Void_Set_Pin_Value(LCD_Data_Ports,LCD_D6_Pin,HIGH);
		}
		else
		{
			DIO_Void_Set_Pin_Value(LCD_Data_Ports,LCD_D6_Pin,LOW);
		}
		if (READ_BIT(copy_u8_data,PIN3)==1)
		{
			DIO_Void_Set_Pin_Value(LCD_Data_Ports,LCD_D7_Pin,HIGH);
		}
		else
		{
			DIO_Void_Set_Pin_Value(LCD_Data_Ports,LCD_D7_Pin,LOW);
		}
		
		break;
		
		case Higher_half:
		if (READ_BIT(copy_u8_data,PIN4)==1)
		{
			DIO_Void_Set_Pin_Value(LCD_Data_Ports,LCD_D4_Pin,HIGH);
		}
		else
		{
			DIO_Void_Set_Pin_Value(LCD_Data_Ports,LCD_D4_Pin,LOW);
		}
		if (READ_BIT(copy_u8_data,PIN5)==1)
		{
			DIO_Void_Set_Pin_Value(LCD_Data_Ports,LCD_D5_Pin,HIGH);
		}
		else
		{
			DIO_Void_Set_Pin_Value(LCD_Data_Ports,LCD_D5_Pin,LOW);
		}
		if (READ_BIT(copy_u8_data,PIN6)==1)
		{
			DIO_Void_Set_Pin_Value(LCD_Data_Ports,LCD_D6_Pin,HIGH);
		}
		else
		{
			DIO_Void_Set_Pin_Value(LCD_Data_Ports,LCD_D6_Pin,LOW);
		}
		if (READ_BIT(copy_u8_data,PIN7)==1)
		{
			DIO_Void_Set_Pin_Value(LCD_Data_Ports,LCD_D7_Pin,HIGH);
		}
		else
		{
			DIO_Void_Set_Pin_Value(LCD_Data_Ports,LCD_D7_Pin,LOW);
		}
		break;
	}
	
	
}

static void  Private_Set_Enable(void){
	
	//Set Enable pin to high after that delay 1 mile second then low 
	DIO_Void_Set_Pin_Value(LCD_Control_Ports,LCD_Enable_Pin,HIGH) ;
	_delay_ms(2) ;
	DIO_Void_Set_Pin_Value(LCD_Control_Ports,LCD_Enable_Pin,LOW) ;
	
}


void LCD_Void_Send_Command(u8 copy_u8_command){
	
	/* SET RS PIN IN LCD  TO SEND COMMAND */
	DIO_Void_Set_Pin_Value(LCD_Control_Ports,LCD_RS_Pin,LOW) ;
	/* SET RW PIN IN LCD  TO Write COMMAND */
	DIO_Void_Set_Pin_Value(LCD_Control_Ports,LCD_RW_Pin,LOW) ;
	
	#if  LCD_MODE == Mode_4_Bit
	/* Send Command Higher 4 bit */
	Private_Write_Half_Port(Higher_half,copy_u8_command) ;
	/* Set pin Enable High --> delay --> Low */
	Private_Set_Enable() ;
	/* Send Command Lower 4 bit */
	Private_Write_Half_Port(Lower_half,copy_u8_command) ;
	/* Set pin Enable High --> delay --> Low */
	Private_Set_Enable() ;
	#elif LCD_MODE == Mode_8_Bit
	/* send command  */
	DIO_Void_Set_Pin_Value(LCD_Data_Ports,copy_u8_command) ;
	/* Set pin Enable High --> delay --> Low */
	Private_Set_Enable() ;
	#endif
	
}

void LCD_Void_Send_Char(u8 copy_u8_data){
	
	/* SET RS PIN IN LCD  TO SEND COMMAND */
	DIO_Void_Set_Pin_Value(LCD_Control_Ports,LCD_RS_Pin,HIGH) ;
	/* SET RW PIN IN LCD  TO Write COMMAND */
	DIO_Void_Set_Pin_Value(LCD_Control_Ports,LCD_RW_Pin,LOW) ;
	#if  LCD_MODE == Mode_4_Bit
	/* Send Command Higher 4 bit */
	Private_Write_Half_Port(Higher_half,copy_u8_data) ;
	/* Set pin Enable High --> delay --> Low */
	Private_Set_Enable() ;
	/* Send Command Lower 4 bit */
	Private_Write_Half_Port(Lower_half,copy_u8_data) ;
	/* Set pin Enable High --> delay --> Low */
	Private_Set_Enable() ;
	#elif LCD_MODE == Mode_8_Bit
	/* send data  */
	DIO_Void_Set_Pin_Value(LCD_Data_Ports,copy_u8_data) ;
	/* Set pin Enable High --> delay --> Low */
	Private_Set_Enable() ;
	#endif
	
	
}

void LCD_Void_Init(void){
	
	/* set all Control pins direction as output */
	
	DIO_Void_Set_Pin_Direction(LCD_Control_Ports,LCD_RS_Pin,OUTPUT);
	DIO_Void_Set_Pin_Direction(LCD_Control_Ports,LCD_RW_Pin,OUTPUT);
	DIO_Void_Set_Pin_Direction(LCD_Control_Ports,LCD_Enable_Pin,OUTPUT);
	
	/* set all Data pins direction as output */
	
	DIO_Void_Set_Pin_Direction(LCD_Data_Ports,LCD_D4_Pin,OUTPUT);
	DIO_Void_Set_Pin_Direction(LCD_Data_Ports,LCD_D5_Pin,OUTPUT);
	DIO_Void_Set_Pin_Direction(LCD_Data_Ports,LCD_D6_Pin,OUTPUT);
	DIO_Void_Set_Pin_Direction(LCD_Data_Ports,LCD_D7_Pin,OUTPUT);
	
	_delay_ms(40) ;
	
	#if LCD_MODE ==  Mode_4_Bit
	/* SEND  function set  */
	Private_Write_Half_Port(Lower_half,0b0010) ;
	/* Set pin Enable High --> delay --> Low */
	Private_Set_Enable() ;
	Private_Write_Half_Port(Lower_half,0b0010) ;
	/* Set pin Enable High --> delay --> Low */
	Private_Set_Enable() ;
	/* Set pin Enable High --> delay --> Low */
	Private_Write_Half_Port(Lower_half,0b1000) ;
	Private_Set_Enable() ;
	#elif LCD_MODE == Mode_8_Bit
	/* SEND  function set  */
	LCD_Void_Send_Command(0x3C) ;
	#endif
	/* send ON/OFF Command  */
	LCD_Void_Send_Command(0x0C) ;
	/* send  CLR command  */
	LCD_Void_Send_Command(1) ;

}

void LCD_Void_Send_String(s8* add_u8_str){
	
	s8 Loc_u8_in=0 ;
	while(add_u8_str[Loc_u8_in] != '\0'){
		
		LCD_Void_Send_Char(add_u8_str[Loc_u8_in]) ;
		Loc_u8_in++ ;
	}
	
	
}

void LCD_Void_GO_TO_X_Y(u8 copy_u8_x , u8 copy_u8_y){
	
	u8 Loc_u8_DDRAMaddress=0 ;
	if(copy_u8_y==0){
		
		Loc_u8_DDRAMaddress=copy_u8_x ;
	}
	else if (copy_u8_y==1){
		Loc_u8_DDRAMaddress=copy_u8_x+0x40 ;
		
	}
	
	/* set DDRAM  */
	SET_BIT(Loc_u8_DDRAMaddress,7) ;
	LCD_Void_Send_Command(Loc_u8_DDRAMaddress) ;
}
void LCD_Void_Send_Special_Char(u8 copy_u8_x  ,u8 copy_u8_y , u8 copy_u8_pattern , u8 copy_u8_data[8])
{
	u8 Loc_u8_in;
	u8 Loc_u8_CGRAMadd=copy_u8_pattern*8 ;
	
	/*  set CGRAM  */
	SET_BIT(Loc_u8_CGRAMadd,6) ;
	CLR_BIT(Loc_u8_CGRAMadd,7) ;
	
	LCD_Void_Send_Command(Loc_u8_CGRAMadd);
	/* Write data in CGRAM  */
	for(Loc_u8_in = 0 ; Loc_u8_in<8 ; Loc_u8_in++){
		
		LCD_Void_Send_Char(copy_u8_data[Loc_u8_in]);
	}
	
	/* back to ddram to dispaly data*/
	LCD_Void_GO_TO_X_Y(copy_u8_x,copy_u8_y) ;
	
	LCD_Void_Send_Char(copy_u8_pattern)  ;
	
}

void LCD_Void_Send_Number(s32 Number) {
	s8 i;
	s8 c=0;
	s8 value[10];
	if (Number == 0){
		LCD_Void_Send_Char('0');
	}
	else if (Number < 0){
		LCD_Void_Send_Char('-');
		Number= -Number;
	}
	while(1){
		if(Number == 0)
		{break;}
		else{
			value[c] = (Number % 10) + '0';
			Number = Number/10;
			c++;
			
		}
		
	}
	for(i = c - 1;i>=0;i--){
		LCD_Void_Send_Char(value[i]);
	}
}


u16 LCD_store_display_data() {
	s16 result = 0; // Static to retain value across function calls
	s16 count = 0;
	s16 numericValue[4]; // Array size changed to 4 to hold 4 digits
	s16 move = 0;
	u8 x;
	u8 Delete[] = {
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00
	};

	while (1) {
		 KeyPad_Void_Get_Key(&x);

		if (x != Keypad_Not_Pressed) {
			switch (x) {
				
				case 'B':
				
				if(move<=3){
					
					
					//case 0
					if(move==0){
						
						if(count == 1){
							LCD_Void_Send_Special_Char(move, 0, 0, Delete);
							LCD_Void_Send_Command(0x01); // Clear the LCD before displaying the result
							numericValue[0]=0;
							//LCD_Number(result);
							LCD_Void_GO_TO_X_Y(move,0);
							count--;
						}
						
						else if(count == 2){
							LCD_Void_Send_Special_Char(move, 0, 0, Delete);
							numericValue[0] = numericValue[1];
							result = numericValue[0];
							LCD_Void_Send_Command(0x01);
							LCD_Void_Send_Number(result);
							LCD_Void_GO_TO_X_Y(move,0);
							count--;
						}
						
						else if(count == 3){
							LCD_Void_Send_Special_Char(move, 0, 0, Delete);
							numericValue[0] = numericValue[1];
							numericValue[1] = numericValue[2];
							result = 10 * numericValue[0] + numericValue[1];
							LCD_Void_Send_Command(0x01);
							LCD_Void_Send_Number(result);
							LCD_Void_GO_TO_X_Y(move,0);
							count--;
						}
						
						else if(count == 4){
							LCD_Void_Send_Special_Char(move, 0, 0, Delete);
							numericValue[0] = numericValue[1];
							numericValue[1] = numericValue[2];
							numericValue[2] = numericValue[3];
							result = 100 * numericValue[0] + 10 * numericValue[1] + numericValue[2];
							LCD_Void_Send_Command(0x01);
							LCD_Void_Send_Number(result);
							LCD_Void_GO_TO_X_Y(move,0);
							count--;
						}
						
					}
					
					
					//case 1
					if(move ==1){
						
						if(count == 2){
							LCD_Void_Send_Special_Char(move, 0, 0, Delete);
							result = numericValue[0];
							LCD_Void_Send_Command(0x01);
							LCD_Void_Send_Number(result);
							LCD_Void_GO_TO_X_Y(move,0);
							count--;
							
						}
						else if(count == 3){
							LCD_Void_Send_Special_Char(move, 0, 0, Delete);
							numericValue[1] = numericValue[2];
							numericValue[2]=0;
							result = 10 * numericValue[0] + numericValue[1];
							LCD_Void_Send_Command(0x01);
							LCD_Void_Send_Number(result);
							LCD_Void_GO_TO_X_Y(move,0);
							count--;
						}
						else if(count == 4){
							LCD_Void_Send_Special_Char(move, 0, 0, Delete);
							numericValue[1] = numericValue[2];
							numericValue[2] = numericValue[3];
							result = 100 * numericValue[0] + 10 * numericValue[1] + numericValue[2];
							LCD_Void_Send_Command(0x01);
							LCD_Void_Send_Number(result);
							LCD_Void_GO_TO_X_Y(move,0);
							count--;
							
							
						}
						else {break;LCD_Void_GO_TO_X_Y(move,0);}
						
					}
					
					
					//case 2
					if(move == 2){
						
						if(count == 3){
							LCD_Void_Send_Special_Char(move, 0, 0, Delete);
							result = 10 * numericValue[0] + numericValue[1];
							LCD_Void_Send_Command(0x01);
							LCD_Void_Send_Number(result);
							LCD_Void_GO_TO_X_Y(move,0);
							count--;
						}
						
						else if(count == 4){
							LCD_Void_Send_Special_Char(move, 0, 0, Delete);
							numericValue[2] = numericValue[3];
							result = 100 * numericValue[0] + 10 * numericValue[1] + numericValue[2];
							LCD_Void_Send_Command(0x01);
							LCD_Void_Send_Number(result);
							LCD_Void_GO_TO_X_Y(move,0);
							count--;
						}
						
						else{break;LCD_Void_GO_TO_X_Y(move,0);}
						
					}
					
					
					//case 3
					if(move == 3){
						
						if(move == 3 && count == 4){
							LCD_Void_Send_Special_Char(move, 0, 0, Delete);
							result = 100 * numericValue[0] + 10 * numericValue[1] + numericValue[2] ;
							LCD_Void_Send_Command(0x01);
							LCD_Void_Send_Number(result);
							LCD_Void_GO_TO_X_Y(move,0);
							count--;
							move--;
						}
						
						else{break;LCD_Void_GO_TO_X_Y(move,0);}
						
					}

				}
				break;

				case '#':
				
				if (move < 3) {
					move++;
					LCD_Void_GO_TO_X_Y(move,0);
				}
				
				break;

				case '*':
				
				if (move > 0) {
					move--;
					LCD_Void_GO_TO_X_Y(move,0);
				}
				
				break;

				case 'C':
				
				LCD_Void_Send_Command(0x01);
				count = 0;
				move = 0;
				
				break;

				case 'D':
				
				if (count == 4) {
					result = 1000 * numericValue[0] + 100 * numericValue[1] + 10 * numericValue[2] + numericValue[3];
					if (result >= 1000 && result <= 9999) {
						count = 0;
						move = 0;
						return result;
					}
					
				}
				break;
				

				default:
				if (count < 4) {
					numericValue[move] = x - '0';
					count++;
					move++;
					LCD_Void_Send_Number(x - '0');
				}
				break;
			}
		}
	}
}












u8 LCD_store_display_data_one_number() {
	u8 result = 0; // Static to retain value across function calls
	u8 count = 0;
	u8 numericValue[1]; // Array size changed to 4 to hold 4 digits
	u8 x;
	while (1) {
		KeyPad_Void_Get_Key(&x);

		if (x != Keypad_Not_Pressed) {
			switch (x) {
				
				case 'B':
	
					if(count == 1){
						LCD_Void_Send_Command(0x01); // Clear the LCD before displaying the result
						numericValue[0]=0;
						//LCD_Number(result);
						LCD_Void_GO_TO_X_Y(count,0);
						count--;
					}
						
					else{}
				break;

				case 'C':
				
				LCD_Void_Send_Command(0x01);
				count = 0;
				break;

				case 'D':
				
				if (count == 1) {
					result =  numericValue[0];
						return result;
				}
				break;
				

				default:
				if (count < 1) {
					numericValue[count] = x - '0';
					count++;
					LCD_Void_Send_Number(x - '0');
				}
				break;
			}
		}
	}
}