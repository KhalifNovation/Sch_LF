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
	for (int i = 0; i < 7; i++) {
		AN[i].Pin = channel[i];
	}
}

void Sensor::calibration(int cycle = 30) {
	int _val[7];
	int	_pin[7];
	int	_highval[7];
	int	_lowval[7];
	for (int i = 0; i < 7; i++) {
		_val[i] = AN[i].Val;
		_pin[i] = AN[i].Pin;
	}

	for (int n = 0; n < cycle; n++) {
		for (int i = 0; i < 7; i++) {
			_val[i] = analogRead(_pin[i]);

			if (_val[i] < _highval[i]) {
				_highval[i] = _val[i];
			}

			if (_val[i] > _lowval[i]) {
				_lowval[i] = _val[i];
			}

		}
		delay(20);
	}



	for (int i = 0; i < 7; i++) {
		int thress = _highval[i] - _lowval[i];
		thress /= 2;

		AN[i].ThressHold = thress;
		AN[i].HighVal = _highval[i];
		AN[i].LowVal  = _lowval[i];
	}

}

bool Sensor::isBTN_press() {
	return !digitalRead(BTN);
}

bool Sensor::isJMP_connected() {
	return !digitalRead(JMP);
}

bool Sensor::isLS_detected(int ch) {
	return digitalRead(AN[ch].Pin);
}

int Sensor::getIntData(DataName dname, int ch) {
	int val;
	switch (dname) {
	case PIN:
		val = AN[ch].Pin;
		break;
	case VAL:
		val = AN[ch].State;
		break;
	case HIGH_VAL:
		val = AN[ch].Pin;
		break;
	case LOW_VAL:
		val = AN[ch].State;
		break;
	case THRESSHOLD:
		val = AN[ch].ThressHold;

	}

	return val;
}

bool Sensor::getBoolData(DataName dname, int ch) {
	
	bool val;

	switch (dname)
	{
	case STATE:
		val = AN[ch].State;
		break;
	case LAST_STATE:
		val = AN[ch].LastState;
		break;
	}

	return val;
}

int Sensor::LS_RAW(int ch)
{
	return analogRead(AN[ch].Pin);
}