/*
 * LCD_Interface.h
 *
 * Created: 1/28/2024 8:20:34 AM
 *  Author: Lenovo
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_Void_Init(void);

void LCD_Void_Send_Command(u8 copy_u8_command);

void LCD_Void_Send_Char(u8 copy_u8_char);

void LCD_Void_Send_String(s8* copy_u8_string);

void LCD_Void_Send_Number(s32 copy_s32_number);

void LCD_Void_GO_TO_X_Y(u8 copy_u8_x,u8 copy_u8_y);

void LCD_Void_Send_Special_Char(u8 copy_u8_x  ,u8 copy_u8_y , u8 copy_u8_pattern , u8 copy_u8_data[8]);

u16 LCD_store_display_data() ;

u8 LCD_store_display_data_one_number();
#endif /* LCD_INTERFACE_H_ */