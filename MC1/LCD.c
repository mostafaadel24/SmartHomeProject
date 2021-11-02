/*
 * LCD.c
 *
 *  Created on: Dec 23, 2020
 *      Author: Mostafa
 */

#include "LCD.h"

void LCD_init()
{
	LCD_DATA_DDR=0xFF;
	SET_BIT(LCD_CONTROL_DDR,LCD_ENABLE);
	SET_BIT(LCD_CONTROL_DDR,LCD_RW);
	SET_BIT(LCD_CONTROL_DDR,LCD_RS);
	LCD_sendCommand(1);
	LCD_sendCommand(0b00001100);
	LCD_sendCommand(0b00111000);

}
void LCD_sendCommand(uint8 command)
{
	CLR_BIT(LCD_CONTROL_PORT,LCD_RS);
	CLR_BIT(LCD_CONTROL_PORT,LCD_RW);
	LCD_OUT_PORT=command;
	SET_BIT(LCD_CONTROL_PORT,LCD_ENABLE);
	_delay_ms(1);
	CLR_BIT(LCD_CONTROL_PORT,LCD_ENABLE);


}
void LCD_displayCharacter(uint8 c)
{
	SET_BIT(LCD_CONTROL_PORT,LCD_RS);
	CLR_BIT(LCD_CONTROL_PORT,LCD_RW);
	LCD_OUT_PORT=c;
	SET_BIT(LCD_CONTROL_PORT,LCD_ENABLE);
	_delay_ms(1);
	CLR_BIT(LCD_CONTROL_PORT,LCD_ENABLE);

}
void LCD_displayString(uint8* c)
{
	while((*c)!='\0')
	{
		LCD_displayCharacter(*c);
		c++;
	}
}
void LCD_goToRowColumn(uint8 row,uint8 col)
{
	uint8 address=col;
	switch(row)
	{
	case(0):
			address=col;
	break;
	case(1):
			address=col+0x40;
	break;
	}
	LCD_sendCommand(address|0b10000000);
}
void LCD_displayStringRowColumn(uint8 *c,uint8 row,uint8 col)
{
	LCD_goToRowColumn(row,col);
	LCD_displayString(c);
}
void LCD_clearScreen()
{
	LCD_sendCommand(1);
}
void LCD_intgerToString(long num)
{
	char str[11];
	uint8 i=0;
	if(num<0)
		{
		LCD_displayCharacter('-');
		num=-num;
		}
	while(num)
	{
		str[i]=(num%10)+48;
		num=num/10;
		i++;
	}
	while(i>0)
	{
		LCD_displayCharacter(str[i-1]);
		i--;
	}
}

