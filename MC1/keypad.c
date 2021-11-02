/*
 * keypad.c
 *
 *  Created on: Dec 23, 2020
 *      Author: Mostafa
 */

#include"keypad.h"

uint8 keypad_getPressedKey()
{
	KEYPAD_DIRECTION_REG=0x00;
#ifdef keypad4x4
	KEYPAD_OUT_PORT=0xf0;
#else
	KEYPAD_OUT_PORT=0x80;
#endif
	uint8 i,j=0;
	while(1)
	{
	for(i=0;i<4;i++)
	{
		KEYPAD_DIRECTION_REG=(1<<i);
		#ifdef keypad4x4
			for(j=0;j<4;j++)
		#else
			for(j=0;j<3;j++)
		#endif
			{
				if(BIT_IS_CLR(KEYPAD_IN_PORT,j+4))
				{
			#ifdef keypad4x4
					return keyPad_4x4_adjSwitchNumber(i*4+j+1);
			#else
					return keypad_4x3_adjSwitchNumber(i*4+j+1);
			#endif
				}
			}
	}
	}
	return -1;
}

uint8 keypad_4x3_adjSwitchNumber(uint8 key)
{
	switch(key)
	{
	case(10):
			return '*';
			break;
	case(11):
			return '0';
			break;
	case(12):
			return'#';
			break;
	default:
		return key;
		break;
	}
return -1;
}
uint8 keyPad_4x4_adjSwitchNumber(uint8 key)
{
switch(key)
{
case(1):
		return '7';
		break;
case(2):
		return '8';
		break;
case(3):
		return '9';
		break;
case(4):
		return'/';
		break;
case(5):
		return '4';
		break;
case(6):
		return '5';
		break;
case(7):
		return '6';
		break;
case(8):
		return 'x';
		break;
case(9):
		return '1';
		break;
case(10):
		return '2';
		break;
case(11):
		return '3';
		break;
case(12):
		return '-';
		break;
case(13):
		return 'c';
		break;
case(14):
		return '0';
		break;
case(15):
		return '=';
		break;
case(16):
		return'+';
		break;
default:
	return key;
	break;
}
return -1;
}
