/*
 * EEPROM.c
 *
 *  Created on: May 24, 2021
 *      Author: Mostafa
 */

#include"EEPROM.h"
void EEPROM_writeByte(uint16 addr ,uint8 data)
{
	while(BIT_IS_SET(EECR,EEWE));//wait until EEWE is zero
	while(BIT_IS_SET(SPMCR,SPMEN)); //wait SPMEN to be zero
	EEAR=addr;
	EEDR=data;
	EECR=0b0100;//Write a logical one to the EEMWE bit while writing a zero to EEWE in EECR
	EECR=(1<<EEWE);


}
uint8 EEPROM_readByte(uint16 addr)
{
	while(BIT_IS_SET(EECR,EEWE));//wait until EEWE is zero
	EEAR=addr;
	EECR=(1<<EERE);
	return EEDR;

}
void EEPROM_writeString(uint16 addr,uint8*str)
{
	uint8 i =0;
	while(str[i]!='\0')
	{
	EEPROM_writeByte(addr+i,str[i]);
	i++;
	}
}

void EEPROM_readString(uint16 addr,uint8*str,uint8 size)
{
uint8 i;
for( i=0;i<size-1;i++)
{
	str[i]=EEPROM_readByte(addr+i);

}
str[i]='\0';
}
