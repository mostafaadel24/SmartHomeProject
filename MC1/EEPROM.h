/*
 * EEPROM.h
 *
 *  Created on: May 24, 2021
 *      Author: Mostafa
 */

#ifndef EEPROM_H_
#define EEPROM_H_
#include "macros.h"
void EEPROM_writeByte(uint16 addr ,uint8 data);
uint8 EEPROM_readByte(uint16 addr);
void EEPROM_writeString(uint16 addr,uint8*str);
void EEPROM_readString(uint16 addr,uint8*str,uint8 size);


#endif /* EEPROM_H_ */
