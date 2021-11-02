/*
 * main.c
 *
 *  Created on: Oct 30, 2021
 *      Author: Mostafa
 */
#include"spi.h"
#include"EEPROM.h"
#include "ADC.h"
#include<avr/interrupt.h>

void timer0_init()
{
	cli();
	CLR_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	TCNT0=0x00;
	SET_BIT(TIMSK,TOIE0);
	sei();
}

volatile char commString[10]="0000000000";

int main(void)
{
/*INITIALIZATIONS-------------------*/
DDRC=0xFF;
SPI_initSlave();
ADC_init();
timer0_init();
/*--------------------------------*/
	while(1)
	{

		SPI_receiveString(commString);//recive comm String commands from MC1 to control rooms

		/*------------  commString= room1,
		 * 							room2,
		 * 							room3,
		 * 							room4,
		 * 							tv,
		 * 							aircond,
		 * 							airCondSetValue,
		 * 							Null,
		 */

		/*control rooms and tv as we recived from comm string---------*/
		for(char i=0;i<5;i++)
		{
		if(commString[i]-'0')
		{
		SET_BIT(PORTC,i);
		}
		else
		{
		CLR_BIT(PORTC,i);

		}
		}
		/*--------------------------------------------------------*/

	}
}

ISR(TIMER0_OVF_vect)
{
	long temp;
	if(commString[5]-'0')
			{
				temp = ADC_readChannel();
				temp = (temp*150*5)/(1023*1.5);
				if((commString[6]-'0')<temp)
				{
					SET_BIT(PORTC,5);
				}
				else
				{
					CLR_BIT(PORTC,5);
				}
			}
	else
	{
		CLR_BIT(PORTC,5);

	}
}
