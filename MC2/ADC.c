/*
 * ADC.c
 *
 *  Created on: Dec 29, 2020
 *      Author: Mostafa
 */


#include"ADC.h"

void ADC_init()
{
	ADMUX=0;
	SET_BIT(ADCSRA,ADEN);/*enable adc*/
	SET_BIT(ADCSRA,ADIF);/*clear interrupt flag*/
	SET_BIT(ADCSRA,ADPS1);/*---- prescaler 8----*/
	SET_BIT(ADCSRA,ADPS0);


}
uint16 ADC_readChannel()
{
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLR(ADCSRA,ADIF))
	{

	}
	SET_BIT(ADCSRA,ADIF);/*clear interrupt flag*/
	return (ADC&0x3ff);

}
