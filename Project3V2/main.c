/*
 * main.c
 *
 *  Created on: May 3, 2023
 *      Author: Doha
 */

#include "Lm35_sensor.h"
#include "lcd.h"
#include"motor.h"
#include<util/delay.h>
#include"std_types.h"
int main()
{
	ADC_ConfigType ADC_data;
	ADC_data.prescaler=prescaler_8;
	ADC_data.ref_volt=internal_voltage;

	ADC_init(&ADC_data);
	LCD_init();
	DcMotor_Init();
	uint8 temp;
	LCD_displayString("Temp=     C");
	while(1)
	{
		temp=LM35_GetTemperature();
		LCD_moveCursor(0,7);
		if(temp>=100)
		{
			LCD_intgerToString(temp);

		}else
		{
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}

				if(temp<30)
				{
					DcMotor_Rotate( STOP, 0);
				}
				 if(temp>=30)
				{

					DcMotor_Rotate( CW, 25);
				}
				if(temp>=60)
				{

					DcMotor_Rotate( CW, 50);
				}
				 if(temp>=90)
				{

					DcMotor_Rotate( CW, 75);
				}
				 if(temp>=120)
				{

					DcMotor_Rotate( CW, 100);
				}

	}
}
