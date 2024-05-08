#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

#define F_CPU 16000000UL
#include "util/delay.h"
#include "Bit_Wise.h"
#include "STD_Type.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_Config.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "Timer_0_Config.h"
#include "Timer_0_Interface.h"

void PWM_Info(u8 dutyCycle,u8 frequency, u8 timeSingleCycle_us);
// Function to display PWM waveform on LCD based on duty cycle
void displayPWMWaveform(u8 dutyCycle);

#endif /* PWM_INTERFACE_H_ */