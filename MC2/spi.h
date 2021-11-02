/*
 * spi.h
 *
 *  Created on: May 11, 2021
 *      Author: Mostafa
 */

#ifndef SPI_H_
#define SPI_H_
#include "macros.h"

void SPI_initMaster();
void SPI_initSlave();
void SPI_sendByte(char data);
char SPI_receiveByte();
void SPI_sendString(char* string);
void SPI_receiveString(char* string);


#endif /* SPI_H_ */
