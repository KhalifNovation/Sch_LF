/*
	KhalifNovation
	Sensor CPP File

	Created :	12/02/2019 21:46:35
	Author :     Syed Uthman
	Hardware Target : KhalifTech Sch_LF (Arduino Nano Compatible Board)

*/

#include "Sensor.h"



int channel[] = {
		LS_0,
		LS_1,
		LS_2,
		LS_3,
		LS_4,
		LS_5,
		LS_6
};

void Sensor::begin(){
	init_LS();
}

void Sensor::calibration() {

}

bool Sensor::isBTN_press() {
	return !digitalRead(BTN);
}

bool Sensor::isJMP_connected() {
	return !digitalRead(JMP);
}

bool Sensor::isLS_detected(int ch) {
	return digitalRead(channel[ch]);
}

int Sensor::LS_RAW(int ch)
{
	return analogRead(channel[ch]);
}