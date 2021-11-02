/*
 * spi.c
 *
 *  Created on: May 11, 2021
 *      Author: Mostafa
 */

#include"spi.h"
void SPI_initMaster()
{

DDRB|=0b10110000; //set sck and mosi and ss to output
CLR_BIT(DDRB,6);//set miso as input
SET_BIT(SPCR,MSTR); // set device as master
SET_BIT(SPCR,SPE); //spi enable
CLR_BIT(SPCR,CPOL);
CLR_BIT(SPCR,CPHA);
/*********** clock frequency fosc/4
 ***********SPI2X=0 SPR1=0 SPR0 =0
 */

}
void SPI_initSlave()
{

	SET_BIT(DDRB,6); //set miso to output
	DDRB&=~(0b10110000); //set sck and mosi and ss to input
	SET_BIT(SPCR,SPE); //spi enable
	CLR_BIT(SPCR,MSTR); // set device as slave
	/*********** clock frequency fosc/4
	 ***********SPI2X=0 SPR1=0 SPR0 =0
	 */
	CLR_BIT(SPCR,CPOL);
	CLR_BIT(SPCR,CPHA);
}
void SPI_sendByte(char data)
{
SPDR=data;
while(BIT_IS_CLR(SPSR,SPIF)){}
}
char SPI_receiveByte()
{
	while(BIT_IS_CLR(SPSR,SPIF)){}
	return SPDR;
}
void SPI_sendString(char* string)
{
uint8 i=0;
while(string[i]!='#')
{
	SPI_sendByte(string[i]);
	i++;
}
SPI_sendByte('#');
}
void SPI_receiveString(char* string)
{
	uint8 i =0;
	string[i]=SPI_receiveByte();
	while(string[i]!='#')
	{
		i++;
		string[i]=SPI_receiveByte();
	}
	string[i]='\0';
}
