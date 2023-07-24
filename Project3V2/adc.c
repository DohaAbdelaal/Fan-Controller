/*
 * adc.c
 *
 *  Created on: May 1, 2023
 *      Author: Doha
 */

#include "adc.h"


void ADC_init(const ADC_ConfigType *Config_Ptr)
{
	ADMUX = (ADMUX  & 0x3F )|(Config_Ptr->ref_volt<<REFS0);//insert voltage value in the last 2 digits
	SET_BIT(ADCSRA,ADEN);//enable the ADC
	ADCSRA |=(ADCSRA & 0xF8)|(Config_Ptr->prescaler);//insert pre-scaler value in the first 3 digits
}
uint16 ADC_readChannel(uint8 channel)
{
	ADMUX |=(ADMUX & 0xE0)| (channel & 0x07);	//insert channel value
	SET_BIT(ADCSRA,ADSC); //start conversion
	while(BIT_IS_CLEAR(ADCSRA,ADIF)){};//polling until conversion is Done and the flag is set
	SET_BIT(ADCSRA,ADIF);//clear the flag
	return ADC;
}

