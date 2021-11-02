/*
 * main.c
 *
 *  Created on: Oct 16, 2021
 *      Author: Mostafa
 */



#include "EEPROM.h"
#include "keypad.h"
#include "spi.h"
#include "LCD.h"
#include <string.h>
#include "menus.h"


setCommStringFlags(char commString[]){
	for(uint8 i=0;i<5;i++)
	{
		roomsStatus[i]=commString[i]-'0';

	}
	airCond=commString[COMM_STR_AIRCOND_POS]-'0';
	airCondSetValue=commString[COMM_STR_AIRCOND_VALUE_POS]-'0';
}

int main(void)
{
	/*INTIALIZATIONS------------------------*/
	LCD_init();
	SPI_initMaster();
	/*-------------------------------------------*/

	/*CHECK FOR BLOCK MODE---------------------*/
	uint8 blockFlag=EEPROM_readByte(BLOCK_FLAG_ADRR);
	if(!blockFlag)
	{
		currentScreen=blockScreen;
		statusFlag=blockS;
	}
	/*------------------------------------------*/
	/*CHECK FOR FIRST START-------------------------*/
		uint8 firstStartFlag=EEPROM_readByte(FIRSTSTARTADD);
		if (firstStartFlag)
		{
			firstStart_func();
		}
	/*------------------------------------------------*/

	char commString[9]; /*room1,
						room2,
						room3,
						room4,
						tv,
						aircond,
						aircondvalue,
						endOFstring,
						null
						*/

	EEPROM_readString(COMM_STR_ADDR,commString,9); // read comm string from EEPROM after restart
	setCommStringFlags(commString); //set flags variables in MC after reading the stored string from EEPROM
	SPI_sendString(commString); // send comm string to 2nd MC after reboot

	/*LCD WELCOME DISPLAY AFTER REBOOT-------------------*/
	LCD_sendCommand(CLR_SCREEN);
	LCD_displayString("   Welcome to ");
	LCD_goToRowColumn(1,0);
	LCD_displayString("   SMART Home");
	_delay_ms(500);
	/*---------------------------------------------------*/

while(1)
{

	displayScreen();
	EEPROM_readString(COMM_STR_ADDR,commString,9);
	SPI_sendString(commString);
	navigateScreens[currentScreen]();
	_delay_ms(250);
}
}


