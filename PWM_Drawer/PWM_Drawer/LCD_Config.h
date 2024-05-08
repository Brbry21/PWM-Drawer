/*
 * LCD_Config.h
 *
 * Created: 1/28/2024 8:19:57 AM
 *  Author: Lenovo
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_



/* LCD Control Ports:
*
* LCD_RS_Port
* LCD_RW_Port
* LCD_Enable_Port
*
*/

#define LCD_Control_Ports		    PORTA

/* LCD Control Pins:
*
* LCD_RS_Pin
* LCD_RW_Pin
* LCD_Enable_Pin
*
*/

#define LCD_RS_Pin					PIN0	
#define LCD_RW_Pin					PIN1
#define LCD_Enable_Pin				PIN2


/* Which half port select in function
*
* First_half
* Second_half
*
*/



/*  CGRAM Pins 
*
* CGRAM_PIN6						
* CGRAM_PIN7						
*
*/

#define CGRAM_PIN6					PIN6
#define CGRAM_PIN7					PIN7

/* LCD Modes:
*
* Mode_4_Bit
* Mode_8_Bit
*
*/


#define LCD_Mode					Mode_4_Bit

/* LCD Data Port Select:
*
* PortA
* PortB
* PortC
* PortD
*
*/

#define LCD_Data_Ports				PORTA

/*LCD Select Pins for 4 Bit Mode: 
*
* LCD_D0_Pin
* LCD_D1_Pin
* LCD_D2_Pin
* LCD_D3_Pin
* LCD_D4_Pin
* LCD_D5_Pin
* LCD_D6_Pin
* LCD_D7_Pin
*
*/
#define LCD_D0_Pin					PIN0
#define LCD_D1_Pin					PIN1
#define LCD_D2_Pin					PIN2
#define LCD_D3_Pin					PIN3
#define LCD_D4_Pin					PIN4
#define LCD_D5_Pin					PIN5
#define LCD_D6_Pin					PIN6
#define LCD_D7_Pin					PIN7

/*LCD ROWS:
*							
* ROW1
* ROW2
* ROW3
* ROW4
* ROW5
* ROW6
* ROW7
* ROW8
* ROW9
* ROW10
* ROW11
* ROW12
* ROW13
* ROW14
* ROW15
* ROW16
*
*/

/*Columns:
*
* COL1
* COL2
*
*/






































#endif /* LCD_CONFIG_H_ */