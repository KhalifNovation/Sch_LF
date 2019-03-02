/*
	KhalifNovation
	Motor CPP File

	Created :	12/02/2019 21:46:35
	Author :     Syed Uthman
	Hardware Target : KhalifTech Sch_LF (Arduino Nano Compatible Board)

*/
#include "Motor.h"

void Motor::begin() {
	init_MOTOR();
}

void Motor::forward(int speed) {
	motor_left(speed);
	motor_right(speed);
}

void Motor::backward(int speed) {
	motor_left(-speed);
	motor_right(-speed);
}

void Motor::left(int speed) {
	motor_left(-speed);
	motor_right(speed);
}

void Motor::right(int speed) {
	motor_left(speed);
	motor_right(-speed);
}

void Motor::motor_left(int speed) {
	speed = constrain(speed, -255, 255);

	if (speed > 0) {
		digitalWrite(DIR_B1, LOW);
		digitalWrite(DIR_B2, HIGH);
	}

	else {
		digitalWrite(DIR_B1, HIGH);
		digitalWrite(DIR_B2, LOW);
	}

	analogWrite(PWM_B,abs(speed));
}

void Motor::motor_right(int speed) {
	speed = constrain(speed, -255, 255);

	if (speed > 0) {
		digitalWrite(DIR_A1, HIGH);
		digitalWrite(DIR_A2, LOW);
	}

	else {
		digitalWrite(DIR_A1, LOW);
		digitalWrite(DIR_A2, HIGH);
	}

	analogWrite(PWM_A,abs(speed));
}
