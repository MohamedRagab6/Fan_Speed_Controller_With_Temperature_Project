/*
 * main.c
 *
 *  Created on: May 24, 2022
 *      Author: Mohamed Ragab
 */
#include "std_types.h"
#include "motor.h"
#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
int main (void)

{	uint8 temp;
	ADC_ConfigType ADC_Config = {INTERNAL,F_CPU_8};
	ADC_init(&ADC_Config); /*intialize ADC driver*/
	LCD_init(); /* initialize LCD driver */
	DcMotor_Init(); /*initialize motor driver*/
	/* Display this string "Temp =   C" only once on LCD at the second row */
	LCD_moveCursor(1,2);
	LCD_displayString("Temp =    C");
	while(1){
		temp = LM35_getTemperature();
		LCD_moveCursor(1,9);
		/* Display the temperature value every time at same position */
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		/* according to temprature the motor will move with different speeds */
		if (temp < 30 )
		{
			LCD_moveCursor(0,2);
			LCD_displayString("FAN is OFF");
			DcMotor_Rotate(STOP,0);

		}
		else if (temp >= 30 && temp < 60)
		{
			LCD_moveCursor(0,2);
			LCD_displayString("FAN is ON ");
			DcMotor_Rotate(C_W,25);
		}
		else if (temp >=60 && temp < 90)
		{
			LCD_moveCursor(0,2);
			LCD_displayString("FAN is ON ");
			DcMotor_Rotate(C_W,50);
		}
		else if (temp >=90 && temp < 120){
			LCD_moveCursor(0,2);
			LCD_displayString("FAN is ON ");
			DcMotor_Rotate(C_W,75);
		}
		else if (temp >=120){
			LCD_moveCursor(0,2);
			LCD_displayString("FAN is ON ");
			DcMotor_Rotate(C_W,100);
		}
	}
}
