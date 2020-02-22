
#include "MOTOR.h"

MOTOR::MOTOR(int *pin, bool DirL, bool DirR)
{
	int i = 0;
	P_LeftA = pin[i];
	P_LeftB = pin[++i];
	P_LeftSpeed = pin[++i];
	P_RightA = pin[++i];
	P_RightB = pin[++i];
	P_RightSpeed = pin[++i];
	ArraySize = ++i;

	for (int n = 0; n < ArraySize; n++)
		pinList[n] = pin[n];

	DirL_C = DirL;
	DirR_C = DirR;
}

MOTOR::MOTOR(bool DirL, bool DirR)
{
	DirL_C = DirL;
	DirR_C = DirR;
}

void MOTOR::begin()
{
	for (int i = 0; i < ArraySize; i++)
	{
		pinMode(pinList[i], OUTPUT);
	}
}

void MOTOR::begin(int *pin)
{
	int i = 0;
	P_LeftA = pin[i];
	i++;
	P_LeftB = pin[i];
	i++;
	P_LeftSpeed = pin[i];
	i++;
	P_RightA = pin[i];
	i++;
	P_RightB = pin[i];
	i++;
	P_RightSpeed = pin[i];
	i++;
	ArraySize = i;
}

void MOTOR::forward(int speed)
{
	
	motor_left(speed);
	motor_right(speed);
	run();
}

void MOTOR::backward(int speed)
{
	motor_left(-speed);
	motor_right(-speed);
	run();
}

void MOTOR::turnLeft(int speed)
{
	motor_left(speed);
	motor_right(-speed);
	run();
}

void MOTOR::turnRight(int speed)
{
	motor_left(-speed);
	motor_right(speed);
	run();
}

void MOTOR::stop()
{
	motor_left(0);
	motor_right(0);
	run();
}

void MOTOR::drive(double heading, int speed, int gain)
{
	int Lspeed;
	int Rspeed;
	Lspeed = speed + (heading);
	Rspeed = speed - (heading);

	motor_left(Lspeed);
	motor_right(Rspeed);
	run();
}

void MOTOR::motor_left(int speed)
{
	speed = constrain(speed, -255, 255);

	if (speed > 0)
	{
		DirL_A = false;
		DirL_B = true;
	}

	else
	{
		DirL_A = true;
		DirL_B = false;
	}

	DirL_A = (DirL_C != true ? DirL_A : !DirL_A);
	DirL_B = (DirL_C != true ? DirL_B : !DirL_B);

	SpeedL = abs(speed);
}

void MOTOR::motor_right(int speed)
{
	speed = constrain(speed, -255, 255);

	if (speed > 0)
	{
		DirR_A = true;
		DirR_B = false;
	}

	else
	{
		DirR_A = false;
		DirR_B = true;
	}

	DirR_A = (DirR_C != true ? DirR_A : !DirR_A);
	DirR_B = (DirR_C != true ? DirR_B : !DirR_B);

	SpeedR = abs(speed);
}

void MOTOR::run(int duration, bool debug = false)
{
	unsigned long now = millis();
	if (now - prev > duration)
	{
		if (!debug)
		{
			digitalWrite(P_LeftA, DirL_A);
			digitalWrite(P_LeftB, DirL_B);
			analogWrite(P_LeftSpeed, SpeedL);
			digitalWrite(P_RightA, DirR_A);
			digitalWrite(P_RightB, DirR_B);
			analogWrite(P_RightSpeed, SpeedR);
		}
		else
		{
			Serial.print(SpeedL);
			Serial.print("  ");
			Serial.println(SpeedR);
		}
		prev = now;
	}
}

void MOTOR::run()
{
	digitalWrite(P_LeftA, DirL_A);
	digitalWrite(P_LeftB, DirL_B);
	analogWrite(P_LeftSpeed, SpeedL);
	digitalWrite(P_RightA, DirR_A);
	digitalWrite(P_RightB, DirR_B);
	analogWrite(P_RightSpeed, SpeedR);
}