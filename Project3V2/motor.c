/*
 * motor.c
 *
 *  Created on: May 18, 2023
 *      Author: Doha
 */

#include "motor.h"
#include"timer.h"
#include "GPIO.h"
#include "common_macros.h"
#include"std_types.h"

void DcMotor_Init(void)
{
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);

	//STOP the motor at the begging
	GPIO_writePin(PORTB_ID,PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID,PIN1_ID, LOGIC_LOW);

}
 void DcMotor_Rotate(DcMotor_State state,uint8 speed)
 {

	 speed=(double)speed/100*255;
	 Timer0_PWM_Init(speed);
	 if(state==CW)
	 {
		 GPIO_writePin(PORTB_ID,PIN0_ID, LOGIC_LOW);
		 GPIO_writePin(PORTB_ID,PIN1_ID, LOGIC_HIGH);
	 }
	 else if(state==A_CW)
	 {
		 GPIO_writePin(PORTB_ID,PIN0_ID, LOGIC_HIGH);
		 GPIO_writePin(PORTB_ID,PIN1_ID, LOGIC_LOW);
	 }
	 else if(state==STOP)
	 {
		 GPIO_writePin(PORTB_ID,PIN0_ID, LOGIC_LOW);
		 GPIO_writePin(PORTB_ID,PIN1_ID, LOGIC_LOW);
	 }



 }
