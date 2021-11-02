/*
 * ADC.h
 *
 *  Created on: Dec 29, 2020
 *      Author: Mostafa
 */

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include <util/delay.h>
#include "macros.h"


void ADC_init();
uint16 ADC_readChannel();


#endif /* ADC_H_ */
