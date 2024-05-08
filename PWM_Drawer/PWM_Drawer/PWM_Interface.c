#include "STD_Type.h"
#include "Bit_Wise.h"
#include "DIO_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"

// Custom characters for your PWM waveform and Symbols
const u8 PWM_HIGH_CHAR[7] = { 0x1F,0x00,0x00,0x00,0x00,0x00,0x00};
const u8 PWM_LOW_CHAR[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x1F};
const u8 PWM_HIGHTOLOW_CHAR[8] = {0x1F,0x01,0x01,0x01,0x01,0x01,0x01};
const u8 PWM_LOWTOHIGH_CHAR[8] = {0x1F,0x10,0x10,0x10,0x10,0x10,0x10};
const u8 MICROSECONDS_SYMBOL[8] = {0x12,0x12,0x12,0x12,0x1E,0x13,0x10};
const u8 SECONDS_SYMBOL[8] = {0x00,0x00,0x1F,0x10,0x1F,0x01,0x1F};
const u8 PERCENTAGE_SYMBOL[8] = {0x00,0x19,0x02,0x04,0x08,0x12,0x00};

void PWM_Info(u8 dutyCycle, u8 frequency, u8 timeSingleCycle_us){
	
	// Display frequency in KHz on upper left side of LCD
	LCD_Void_GO_TO_X_Y(0, 0); // Go to position (0,0)
	LCD_Void_Send_Number(frequency); // Display frequency
	LCD_Void_GO_TO_X_Y(3, 0); // Go to position (0,0)
	LCD_Void_Send_String("KHz"); // Display frequency
	
	// Display time of a single cycle in microseconds on lower left side of LCD
	LCD_Void_GO_TO_X_Y(8, 0); // Go to position (1,0)
	LCD_Void_Send_Number(timeSingleCycle_us); // Display time
	LCD_Void_Send_Special_Char(9,0,4,MICROSECONDS_SYMBOL);
	LCD_Void_Send_Special_Char(10,0,5,SECONDS_SYMBOL);
	
	// Display duty cycle on upper right side of LCD
	LCD_Void_GO_TO_X_Y(13, 0); // Go to position (0,15)
	LCD_Void_Send_Number(dutyCycle); // Display duty cycle
	LCD_Void_Send_Special_Char(15,0,6,PERCENTAGE_SYMBOL);
}	
	
void displayPWMWaveform(u8 dutyCycle) {
	u8 waveform[16]; // 16 characters + null terminator
	
	// Calculate number of characters for high and low parts of PWM
	u8 highChars = dutyCycle * 8 / 100;
	u8 lowChars = 8 - highChars;
	if(dutyCycle != 100 && dutyCycle!= 0){
		// Fill the waveform array with appropriate characters
		for (u8 i = 0; i < highChars-1; i++) {
			waveform[i] = PWM_HIGH_CHAR;
		}
		for (u8 i = highChars -1; i < highChars; i++) {
			waveform[i] = PWM_HIGHTOLOW_CHAR;
		}
		for (u8 i = highChars; i < 8-1; i++) {
			waveform[i] = PWM_LOW_CHAR;
		}
		for (u8 i = 7; i < 8; i++) {
			waveform[i] = PWM_LOWTOHIGH_CHAR;
		}
		for (u8 i = 8; i < highChars+7; i++) {
			waveform[i] = PWM_HIGH_CHAR;
		}
		for (u8 i = highChars+7; i < highChars+8; i++) {
			waveform[i] = PWM_HIGHTOLOW_CHAR;
		}
		for (u8 i = 8+highChars; i < 15; i++) {
			waveform[i] = PWM_LOW_CHAR;
		}
		for (u8 i = 15; i < 16; i++) {
			waveform[i] = PWM_LOWTOHIGH_CHAR;
		}
		//waveform[16] = '\0'; // Null terminator for string
		
		// Display the waveform on the LCD
		for (int i = 0; i < 16; i++) {
			if (waveform[i]==PWM_HIGH_CHAR)
			{
				LCD_Void_Send_Special_Char(i, 1, 1, waveform[i]);
			}else if (waveform[i]==PWM_HIGHTOLOW_CHAR)
			{
				LCD_Void_Send_Special_Char(i, 1, 2, waveform[i]);
			}else if (waveform[i]==PWM_LOW_CHAR)
			{
				LCD_Void_Send_Special_Char(i, 1, 0, waveform[i]);
			}else if (waveform[i]==PWM_LOWTOHIGH_CHAR)
			{
				LCD_Void_Send_Special_Char(i, 1, 3, waveform[i]);
			}
		}
	}
	else if (dutyCycle==100)
	{
		for (int i = 0; i <= 16; i++) {
			LCD_Void_Send_Special_Char(i, 1, 1, PWM_HIGH_CHAR);
		}
	}
	else if (dutyCycle==0)
	{
		for (int i = 0; i <= 16; i++) {
			LCD_Void_Send_Special_Char(i, 1, 0, PWM_LOW_CHAR);
		}
	}
}