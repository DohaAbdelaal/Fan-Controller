/*
 * Lm35_sensor.c
 *
 *  Created on: May 2, 2023
 *      Author: Doha
 */
#include "Lm35_sensor.h"
uint8 LM35_GetTemperature()
{
	uint16 ADC_value=ADC_readChannel(SENSOR_CHANNEL);
	uint8 temp=(uint32)(SENSOR_MAX_TEMP*ADC_MAX_VOLT*ADC_value)/(SENSOR_MAX_Volt*ADC_MAX_VALUE);
	return temp;
}

