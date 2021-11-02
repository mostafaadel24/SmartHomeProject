/*
 * LCD.h
 *
 *  Created on: Dec 23, 2020
 *      Author: Mostafa
 */

#ifndef LCD_H_
#define LCD_H_
#include<avr/io.h>
#include<util/delay.h>
#include"macros.h"

#define LCD_DATA_DDR DDRC
#define LCD_CONTROL_DDR DDRD
#define LCD_OUT_PORT PORTC
#define LCD_CONTROL_PORT PORTD
#define LCD_ENABLE PD6
#define LCD_RW PD5
#define LCD_RS PD4
#define CLR_SCREEN 0X01
#define CURSOR_BLINK 0X0F
#define MOVE_CURSOR_RIGHT 0x10
void LCD_init();
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 c);
void LCD_displayString(uint8* c);
void LCD_goToRowColumn(uint8 row,uint8 col);
void LCD_displayStringRowColumn(uint8 *c,uint8 row,uint8 col);
void LCD_clearScreen();
void LCD_intgerToString(long num);


#endif /* LCD_H_ */
