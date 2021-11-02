/*
 * menu.c
 *
 *  Created on: Oct 31, 2021
 *      Author: Mostafa
 */
#include"menus.h"
#include"screens.h"
/*global variables ---------------*/
char airCondOnDialogue[16];
const char *Screens[9][2]={{MAIN_MENU_SCREEN},
		{ADMIN1_SCREEN},
		{ADMIN2_SCREEN},
		{GUEST_SCREEN},
		{ROOM_ON_SCREEN},
		{ROOM_OFF_SCREEN},
		{BLOCK_MODE_SCREEN},
		{AIR_COND_OFF_SCREEN},
		{airCondOnDialogue,AIR_COND_ON_SCREEN_2ND_ROW}};

char currentScreen=0;
char roomsStatus[5];
char airCond=0;
char airCondSetValue=AIR_COND_DEFUALT_VALUE;
char airCondStringValue[3];
char currentRoom;
char statusFlag=4;
/*-----------------------------------------------*/

void mainscreen_f()
{
char x =keypad_getPressedKey();
switch(x)
{
case '0':if(checkPass(ADMINADRR,"enter admin pass"))
		{
		currentScreen=admin1;
		statusFlag=adminS;
		}
		else
		{
			currentScreen=blockScreen;
			statusFlag=blockS;
		}

	break;
case '1':if(checkPass(GUESTADRR,"enter guest pass"))
		{
		currentScreen=guest;
		statusFlag=guestS;
		}
		else
		{
		currentScreen=blockScreen;
		statusFlag=blockS;
		}
	break;
case '2':
	break;
case '3':
	break;
case '4':
	break;

}
}
void admin1_f()
{
	char x =keypad_getPressedKey();
	switch(x)
	{
	case '0':currentScreen=mainscreen;
		break;
	case '1':currentRoom=0;
	if(roomsStatus[currentRoom])
		currentScreen=roomON;
	else
		currentScreen=roomOFF;
		break;
	case '2':currentRoom=1;
	if(roomsStatus[currentRoom])
		currentScreen=roomON;
	else
		currentScreen=roomOFF;
		break;
		break;
	case '3':currentRoom=2;
	if(roomsStatus[currentRoom])
		currentScreen=roomON;
	else
		currentScreen=roomOFF;
		break;
		break;
	case '4':currentScreen=admin2;
		break;

	}
}
void admin2_f()
{
	char x =keypad_getPressedKey();

	switch(x)
	{
	case '0':currentScreen=admin1;
		break;
	case '1':currentRoom=3;
	if(roomsStatus[currentRoom])
		currentScreen=roomON;
	else
		currentScreen=roomOFF;
		break;
	case '2':currentRoom=4;
	if(roomsStatus[currentRoom])
		currentScreen=roomON;
	else
		currentScreen=roomOFF;
		break;
	case '3':
		airCondStringValue[0]='0'+airCondSetValue/10;
		airCondStringValue[1]='0'+airCondSetValue%10;
		airCondStringValue[2]='\0';
		strcpy(airCondOnDialogue,AIR_COND_ON_SCREEN_1ST_ROW);
		strcat(airCondOnDialogue,airCondStringValue);
		if(airCond)
		currentScreen=airON;
	else
		currentScreen=airOFF;
		break;
	case '4':if(checkPass(ADMINADRR,"enter admin pass"))
			{
			firstStart_func();
			currentScreen=mainscreen;
			}
			else
			{
				currentScreen=blockScreen;
				statusFlag=blockS;
			}

		break;

	}
}
void guest_f(){
	char x =keypad_getPressedKey();
	switch(x)
	{
	case '0':currentScreen=mainscreen;
		break;
	case '1':currentRoom=0;
	if(roomsStatus[currentRoom])
		currentScreen=roomON;
	else
		currentScreen=roomOFF;
		break;
	case '2':currentRoom=1;
	if(roomsStatus[currentRoom])
		currentScreen=roomON;
	else
		currentScreen=roomOFF;
		break;
	case '3':currentRoom=2;
	if(roomsStatus[currentRoom])
		currentScreen=roomON;
	else
		currentScreen=roomOFF;
		break;
	case '4':currentRoom=3;
	if(roomsStatus[currentRoom])
		currentScreen=roomON;
	else
		currentScreen=roomOFF;
		break;

	}
}
void roomON_f(){
	char x =keypad_getPressedKey();
	switch(x)
	{
	case '0':if(statusFlag==adminS)
		currentScreen=admin1;
	else
		currentScreen=guest;
		break;
	case '1':roomsStatus[currentRoom]=0;
	EEPROM_writeByte(COMM_STR_ADDR+currentRoom,roomsStatus[currentRoom]+'0');
	if(statusFlag==adminS)
		currentScreen=admin1;
	else
		currentScreen=guest;
		break;
	case '2':
		break;
	case '3':
		break;
	case '4':
		break;

	}
}
void roomOFF_f(){
	char x =keypad_getPressedKey();
	switch(x)
	{
	case '0':if(statusFlag==adminS)
		currentScreen=admin1;
	else
		currentScreen=guest;
		break;
	case '1':roomsStatus[currentRoom]=1;
	EEPROM_writeByte(COMM_STR_ADDR+currentRoom,roomsStatus[currentRoom]+'0');
	if(statusFlag==adminS)
		currentScreen=admin1;
	else
		currentScreen=guest;
		break;
	case '2':
		break;
	case '3':
		break;
	case '4':
		break;

	}
}
void blockMode()
{
	EEPROM_writeByte(BLOCK_FLAG_ADRR,0);
	for(int i=BLOCK_MODE_WAIT;i>0;i--)
	{
		LCD_goToRowColumn(1,0);
		LCD_displayString("   ");
		LCD_goToRowColumn(1,0);
		LCD_intgerToString(i);
		_delay_ms(1000);
	}
	currentScreen=mainscreen;
	statusFlag=4;
	EEPROM_writeByte(BLOCK_FLAG_ADRR,1);
	EEPROM_writeByte(TRIES_FLAG_ADRR,0);


}
void airCondChangeValue()
{
	char value=0,x=0;
	LCD_sendCommand(CLR_SCREEN);
	LCD_displayString("set value 2digit");
	LCD_goToRowColumn(1,0);
	LCD_displayString("   C");
	LCD_goToRowColumn(1,0);
	for(char i=10;i>=1;i=i/10)
	{
		_delay_ms(250);
		x=keypad_getPressedKey();
		LCD_displayCharacter(x);
		value=value+(i*(x-'0'));
	}
	airCondSetValue=value;
	EEPROM_writeByte(COMM_STR_ADDR+COMM_STR_AIRCOND_VALUE_POS,airCondSetValue+'0');




}
void airOFF_f(){
	char x =keypad_getPressedKey();
	switch(x)
	{
	case '0':if(statusFlag==adminS)
		currentScreen=admin2;
		break;
	case '2':airCond=1;
	EEPROM_writeByte(COMM_STR_ADDR+COMM_STR_AIRCOND_POS,airCond+'0');

	if(statusFlag==adminS)
		currentScreen=admin2;
		break;
	case '1':
		airCondChangeValue();
		currentScreen=admin2;
		break;

	}
}
void airON_f(){
	char x =keypad_getPressedKey();
	switch(x)
	{
	case '0':if(statusFlag==adminS)
		currentScreen=admin2;
		break;
	case '2':airCond=0;
	EEPROM_writeByte(COMM_STR_ADDR+COMM_STR_AIRCOND_POS,airCond+'0');
	if(statusFlag==adminS)
		currentScreen=admin2;
		break;
	case '1':
		airCondChangeValue();
		currentScreen=admin2;
		break;

	}
}
void(*navigateScreens[9])()={mainscreen_f,
		admin1_f,
		admin2_f,
		guest_f,
		roomON_f,
		roomOFF_f,
		blockMode,
		airOFF_f,
		airON_f};
void displayScreen()
{
	LCD_sendCommand(CLR_SCREEN);
	LCD_displayString(Screens[currentScreen][0]);
	LCD_goToRowColumn(1,0);
	LCD_displayString(Screens[currentScreen][1]);


}

