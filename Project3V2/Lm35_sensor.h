/*
 * Lm35_sensor.h
 *
 *  Created on: May 2, 2023
 *      Author: Doha
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_
#include "ADC.h"

#define SENSOR_CHANNEL 2
#define SENSOR_MAX_TEMP 150
#define SENSOR_MAX_Volt 1.5

uint8 LM35_GetTemperature();

#endif /* LM35_SENSOR_H_ */
