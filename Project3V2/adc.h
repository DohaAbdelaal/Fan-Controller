/*
 * adc.h
 *
 *  Created on: May 1, 2023
 *      Author: Doha
 */

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"
#include "common_macros.h"
#include<avr/io.h>
#define channel_num 2
#define ADC_MAX_VALUE 1023
#define ADC_MAX_VOLT 2.56
//ADC voltage
typedef enum
{
	AREF,
	AVCC,
	internal_voltage=3


}ADC_ReferenceVolatge;

typedef enum
{
	prescaler_2=1,prescaler_4,prescaler_8,prescaler_16,
	prescaler_32,prescaler_64,prescaler_128
}ADC_Prescaler;
typedef struct
{
	 ADC_ReferenceVolatge ref_volt;
	 ADC_Prescaler prescaler;
}ADC_ConfigType;

void ADC_init(const ADC_ConfigType *Config_Ptr);
uint16 ADC_readChannel(uint8 channel);


#endif /* ADC_H_ */
