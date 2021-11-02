/*
 * keypad.h
 *
 *  Created on: Dec 19, 2020
 *      Author: Mostafa
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "macros.h"
#include <avr/io.h>
/*
 * keyPad interface for 4x4 or 4x3 keypad
 * the connection is the rows is connected to the least significant bits of the port
 *  and the column to the most significant bit
 *  if you want to use 4x4 uncomment the following instruction else its default is 4x3
 */


/*
 * #define keypad4x4
 *
 */
#define keypad4x4

#define KEYPAD_IN_PORT PINA
#define KEYPAD_OUT_PORT PORTA
#define KEYPAD_DIRECTION_REG DDRA

uint8 keypad_getPressedKey();
uint8 keypad_4x3_adjSwitchNumber(uint8 key);
uint8 keyPad_4x4_adjSwitchNumber(uint8 key);


#endif /* KEYPAD_H_ */
