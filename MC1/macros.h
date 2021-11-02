/*
 * macros.h
 *
 *  Created on: Dec 19, 2020
 *      Author: Mostafa
 */
#include <avr/io.h>
#include <util/delay.h>

#ifndef MACROS_H_
#define MACROS_H_


#define SET_BIT(reg,bit) (reg)|=(1<<(bit));
#define CLR_BIT(reg,bit) (reg)&=~(1<<(bit));
#define BIT_IS_SET(reg,bit) (reg)&(1<<(bit))
#define BIT_IS_CLR(reg,bit) !((reg)&(1<<(bit)))
typedef unsigned char uint8;
typedef unsigned short uint16;
#endif /* MACROS_H_ */
