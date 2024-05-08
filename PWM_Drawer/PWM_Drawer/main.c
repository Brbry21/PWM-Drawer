#include "PWM_Interface.h"
	
int main(void)
{
	u8 dutyCycle = 50;
	LCD_Void_Init();
	// Calculate frequency in KHz
	u8 frequency = 16000000 / 64000; // Assuming prescaler = 64 and PWM mode is set
	// Calculate time of a single cycle in microseconds
	u8 timeSingleCycle_us = (1000 / frequency);
	DIO_Void_Set_Pin_Direction(PORTB,PIN3,OUTPUT);
	TIMER0_Init();
	TIMER0_SetCompareMatchValue((dutyCycle*256)/100);
	TIMER0_start();
	LCD_Void_Send_Command(0x01);
	
    while (1)
    {
		LCD_Void_Send_Command(0x01);
		PWM_Info(dutyCycle,frequency,timeSingleCycle_us);
		displayPWMWaveform(dutyCycle);

		 _delay_ms(100); // Delay to refresh the LCD periodically
	 }
		
    
}

