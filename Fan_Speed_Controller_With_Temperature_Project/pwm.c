/*
 * pwm.c
 *
 *  Created on: May 24, 2022
 *      Author: Mohamed Ragab
 */
#include "pwm.h"
#include "avr/io.h"
#include "common_macros.h"
#include "gpio.h"
/*trigger the Timer0 with the PWM Mode.*/
void PWM_Timer0_Start(uint8 duty_cycle)
{
	/* Enable PWM mode, non inverting and F_CPU /8 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
	/*Setup the compare value based on the required input duty cycle*/
	TCNT0 = 0;
	OCR0 = (duty_cycle * 255)/100;
	/*Setup the direction for OC0 as output pin through the GPIO driver*/
	GPIO_setupPinDirection(PORTB_ID, OC0 , PIN_OUTPUT);

}
