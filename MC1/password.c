/*
 * password.c
 *
 *  Created on: Nov 2, 2021
 *      Author: Mostafa
 */

#include "lcd.h"
#include "config.h"


char checkPass(uint8 eepromadrr,char* dialogue)
{
	_delay_ms(250);
	uint8 i;
	for(i=EEPROM_readByte(TRIES_FLAG_ADRR);i<NUM_OF_TRIES;i++)
	{
		EEPROM_writeByte(TRIES_FLAG_ADRR,i);
		uint8 pass1[PASSWORD_SIZE+1],pass2[PASSWORD_SIZE+1];
		pass1[PASSWORD_SIZE]='\0';
		EEPROM_readString(eepromadrr,pass2,PASSWORD_SIZE+1);
		passLcdDialoag(pass1,dialogue,PASSWORD_SIZE);
		if(!strcmp(pass1,pass2))
		{
			EEPROM_writeByte(TRIES_FLAG_ADRR,0);
			return 1;
		}
		else
		{
			LCD_sendCommand(CLR_SCREEN);
			LCD_displayString("wrong pass");
			LCD_goToRowColumn(1,0);
			LCD_displayCharacter('0'+NUM_OF_TRIES-i-1);
			LCD_displayString(" tries left");
			_delay_ms(500);



		}

	}
	return 0;
}

void changepass(char*dialoge1,char*dialoge2,uint8 eepromadrr)
{
	while(1)
	{
	uint8 adminpass1[PASSWORD_SIZE+1],adminpass2[PASSWORD_SIZE+1];
	adminpass1[PASSWORD_SIZE]='\0';
	adminpass2[PASSWORD_SIZE]='\0';
	 passLcdDialoag(adminpass1,dialoge1,PASSWORD_SIZE);
	 passLcdDialoag(adminpass2,dialoge2,PASSWORD_SIZE);
	 if(!strcmp(adminpass1,adminpass2))
	 {
		 EEPROM_writeString(eepromadrr,adminpass1);
		 LCD_sendCommand(CLR_SCREEN);
		 LCD_displayString("SUCCESS ....");
		 _delay_ms(400);
		 break;
	 }else
	 {
		 LCD_sendCommand(CLR_SCREEN);
		 LCD_displayString("Failed try again....");
		 _delay_ms(500);
	 }
	}
}

void passLcdDialoag(uint8 pass[],char*dialoge,uint8 size)
{
	LCD_sendCommand(CLR_SCREEN);
	LCD_displayString(dialoge);
	LCD_goToRowColumn(1,0);
	for(uint8 i=0;i<size;i++)
	{
		pass[i]=keypad_getPressedKey();
		LCD_displayCharacter(pass[i]);
		_delay_ms(250);
		LCD_sendCommand(MOVE_CURSOR_RIGHT);
		LCD_displayCharacter('*');

	}
}

void firstStart_func()
{
	LCD_sendCommand(CLR_SCREEN);
	LCD_displayString("start first time");
	LCD_goToRowColumn(1,0);
	LCD_displayString("Configuration");
	_delay_ms(500);
	/*------SET NEW PASSWORDS----------------*/
	changepass("New Admin pass","reEnt Admin pass",ADMINADRR);
	changepass("New guest pass","reEnt guest pass",GUESTADRR);
	/*------------------------------------------------*/
	/*-----------CLEAR EEPROM FLAGS ON FIRST START-----------*/
			EEPROM_writeByte(FIRSTSTARTADD,0);
			EEPROM_writeByte(TRIES_FLAG_ADRR,0);
			EEPROM_writeString(COMM_STR_ADDR,"0000000#");
			EEPROM_writeByte(COMM_STR_ADDR+COMM_STR_AIRCOND_VALUE_POS,AIR_COND_DEFUALT_VALUE+'0');
	/*-------------------------------------------------------------*/
}
