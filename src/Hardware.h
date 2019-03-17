#ifndef _HARDWARE_h
#define _HARDWARE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

//Serial setup

#define debugMode false
#define serialMode true
#define baudrate 9600

//Sensor Hardware Setting (Pin's number)

#define BTN		3
#define JMP		4

#define LS_0	A0
#define LS_1	A1
#define LS_2	A2
#define LS_3	A3
#define LS_4	A4
#define LS_5	A5
#define LS_6	A6

#define init_BTN()	pinMode(BTN,INPUT_PULLUP)
#define init_JMP()	pinMode(JMP,INPUT_PULLUP)
#define init_LS_0()	pinMode(LS_0,INPUT)
#define init_LS_1()	pinMode(LS_1,INPUT)
#define init_LS_2()	pinMode(LS_2,INPUT)
#define init_LS_3()	pinMode(LS_3,INPUT)
#define init_LS_4()	pinMode(LS_4,INPUT)
#define init_LS_5()	pinMode(LS_5,INPUT)
#define init_LS_6()	pinMode(LS_6,INPUT)

#define init_LS()	init_BTN(); init_JMP(); init_LS_0(); init_LS_1(); init_LS_2(); init_LS_3(); init_LS_4(); init_LS_5(); init_LS_6()

//Motor Driver Hardware Setting (Pin's number)

#define DIR_A1		7
#define DIR_A2		8
#define PWM_A		9

#define DIR_B1		12
#define DIR_B2		13
#define PWM_B		11

#define BUZZ		6

#define init_DIR_A1()	pinMode(DIR_A1,OUTPUT)
#define init_DIR_A2()	pinMode(DIR_A2,OUTPUT)
#define init_DIR_B1()	pinMode(DIR_B1,OUTPUT)
#define init_DIR_B2()	pinMode(DIR_B2,OUTPUT)

#define init_BUZZ()		pinMode(BUZZ,OUTPUT)

#define BUZZ_ON()		digitalWrite(BUZZ,HIGH)
#define BUZZ_OFF()		digitalWrite(BUZZ,LOW)

#define init_MOTOR()	init_DIR_A1(); init_DIR_A2(); init_DIR_B1(); init_DIR_B2()



#endif
