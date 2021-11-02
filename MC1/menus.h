/*
 * menus.h
 *
 *  Created on: Oct 31, 2021
 *      Author: Mostafa
 */
#include "config.h"
#include"macros.h"
#include"lcd.h"
#include "password.h"

/* global define----*/
#ifndef MENUS_H_
#define MENUS_H_
extern char airCondDialogue[16];
extern const char *Screens[9][2];
extern char currentScreen;
extern char roomsStatus[5];
extern char airCond;
extern char airCondSetValue;
extern char airCondStringValue[3];
extern char currentRoom;
extern char statusFlag;
extern enum status{adminS,guestS,blockS};
extern enum Escreens{mainscreen,admin1,admin2,guest,roomON,roomOFF,blockScreen,airOFF,airON};
/*-------------------------*/

/*functions declaration -------------*/
void displayScreen();
extern void(*navigateScreens[9])();


#endif /* MENUS_H_ */
