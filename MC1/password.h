/*
 * password.h
 *
 *  Created on: Nov 2, 2021
 *      Author: Mostafa
 */

#ifndef PASSWORD_H_
#define PASSWORD_H_

char checkPass(uint8 eepromadrr,char* dialogue);
void changepass(char*dialoge1,char*dialoge2,uint8 eepromadrr);
void passLcdDialoag(uint8 pass[],char*dialoge,uint8 size);
void firstStart_func();

#endif /* PASSWORD_H_ */
