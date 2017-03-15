#include "refs-avr/bwl_adc.h"

#define ADC_ADJ ADC_ADJUST_RIGHT
#define ADC_REF ADC_REFS_INTERNAL_2_56
#define ADC_CLK ADC_PRESCALER_128

#define ADC1 ADC_MUX_ADC2
#define ADC2 ADC_MUX_ADC3
#define ADC3 ADC_MUX_ADC4
#define ADC4 ADC_MUX_ADC5

float adc_get_1()
{
	adc_init(ADC1,ADC_ADJ,ADC_REF,ADC_CLK);
	float result0=adc_read_average_float(64);
	float result=result0*1.1/1024.0*69.0;
	return result;
}

float adc_get_2()
{
	adc_init(ADC2,ADC_ADJ,ADC_REF,ADC_CLK);
	float result0=adc_read_average_float(64);
	float result=result0*1.1/1024.0*69.0;
	return result;
}

float adc_get_3()
{
	adc_init(ADC3,ADC_ADJ,ADC_REF,ADC_CLK);
	float result0=adc_read_average_float(64);
	float result=result0*1.1/1024.0*69.0;
	return result;
}

float adc_get_4()
{
	adc_init(ADC4,ADC_ADJ,ADC_REF,ADC_CLK);
	float result0=adc_read_average_float(64);
	float result=result0*1.1/1024.0*69.0;
	return result;
}
