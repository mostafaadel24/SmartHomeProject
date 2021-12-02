# SmartHomeProject
this project intended to simulate a smart home enviroment using 2 AVRs, LCD, keypad,  some LEDs, and a temperature sensor
## Overview
We Control 4 rooms, TV, and air conditioning (AC) it has 2 modes -each are password protected- admin mode and guest mode
Admin has more privilege which he can control TV and AC but guest can control the rooms only.
If you enter password wrong multiple time you enter a block mode where you must wait a few seconds then try again, this state is saved in the non-volatile memory (EEPROM) so restarting the system will not allow you to bypass this step.
The user can set the temperature of the air conditioner which switches on and off according to comparing target and ambient temperatures using a temp sensor.
All states of rooms and air condititoning are saved in EEPROM so after restart every room state will stay same

## Functionality 
### Start for first time
***
when you start the Micro-controller for the first time you are asked to enter the password for admin and guest
you can reset the system later within admin privilege to change the passwords you enterd
### main menu
***
this is the first menu you can choose between [admin](#admin-menu) mode by pressing on key "0" on the keypad or [guest](#guest-menu) mode by pressing key "1" from keypad
when you choose you are asked to enter the password for the selected mode
```

    select mode:
    0-admin 1-guest

```

### admin menu
***
when you enter the correct password for admin you will be greeted with the following menu
```

    1-room1     2-room2
    3-room3     4-more

```
by pressing the keypad keys "1" , "2", or "3" you will enter the correspondig [room menu](#room-menu) so you can turn on or off the room
by pressing "4" you will enter the following menu
```

    1-room4     2-tv
    3-aircond     4-rest

```
then by pressing the following keys
"1" will allow you to enter [room menu](#room-menu) for room number 4 so you can turn it on or off
"2" to turn the TV on or off TV menu is similer to [room menu](#room-menu)
"3" to control AC you will be entering the [AC control menu](#AC-menu)
"4" to reset the system so you can change the password you will be asked to confirm you identity by entring the admin password

**you can always go back one menu back by pressing the "0" key in the keypad**

### guest menu
***
when you enter the correct password for admin you will be greeted with the following menu
```

    1-room1     2-room2
    3-room3     3-room4

```
by pressing the keypad keys "1" , "2", "3", or "4" you will enter the corresponding [room menu](#room-menu) so you can turn on or off the room

**you can always go back one menu back by pressing the "0" key in the keypad**

### room menu
***
the room menu will show you the status of the room then you can take action to turn on or off the room
in case the room status is off the following menu will show
```

    Status OFF
    1-ON

```
press "1" to turn on the corresponding room press "0" to go back and do nothing

in case the room is on
```

    Status ON
    1-OFF

```
press "1" to turn off the corresponding room press "0" to go back and do nothing

### AC menu
***
In this menu you can turn on or off the AC and change it's value
when the AC is off
```

    air cond    S:OFF
    1-setVal    2-ON

```
press "2" to turn the AC on
or press "1" to set a new value the following menu will show to enter a new value contain of 2 digits number
```

    set value 2digit
      C

```
in case the AC was on
```

    air con S:ON V:30
    1-setVal    2-ON

```
the "S:ON" represend the status of the AC ON and the "V:30" represent that the current value is 30 °c

**you can always go back one menu back by pressing the "0" key in the keypad**