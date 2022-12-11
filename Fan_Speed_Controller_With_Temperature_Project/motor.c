/*
 * motor.c
 *
 *  Created on: May 24, 2022
 *      Author: Mohamed Ragab
 */

#include "motor.h"
#include "gpio.h"
#include "pwm.h"
void DcMotor_Init(void)
{
	/* Configure the direction Motor pins as output pins */
	GPIO_setupPinDirection(MOTOR_PINS_PORT_ID, IN1 , PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PINS_PORT_ID, IN2 , PIN_OUTPUT);
	/* Stop at the DC-Motor at the beginning through the GPIO driver*/
	GPIO_writePin(MOTOR_PINS_PORT_ID, IN1, LOGIC_LOW);
	GPIO_writePin(MOTOR_PINS_PORT_ID, IN2, LOGIC_LOW);

}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{

	/* rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value. */
	switch(state)
	{
	case 0:
		GPIO_writePin(MOTOR_PINS_PORT_ID, IN1, LOGIC_LOW);
		GPIO_writePin(MOTOR_PINS_PORT_ID, IN2, LOGIC_LOW);
		break;
	case 1:
		GPIO_writePin(MOTOR_PINS_PORT_ID, IN1, LOGIC_HIGH);
		GPIO_writePin(MOTOR_PINS_PORT_ID, IN2, LOGIC_LOW);
		break;
	case 2:
		GPIO_writePin(MOTOR_PINS_PORT_ID, IN1, LOGIC_LOW);
		GPIO_writePin(MOTOR_PINS_PORT_ID, IN2, LOGIC_HIGH);
		break;
	}
	/* Sending the required duty cycle to the PWM driver based on the required speed value.*/
	PWM_Timer0_Start(speed);
}
