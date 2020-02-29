#ifndef _MOTOR_h
#define _MOTOR_h
#include <Arduino.h>
class MOTOR
{
public:

private:
	unsigned long prev;

	int P_LeftA;
	int P_LeftB;
	int P_LeftSpeed;
	int P_RightA;
	int P_RightB;
	int P_RightSpeed;
	int ArraySize;

	int pinList[6];

	bool DirL_A;
	bool DirL_B;
	bool DirR_A;
	bool DirR_B;
	int SpeedL;
	int SpeedR;
	bool DirL_C;
	bool DirR_C;

public:
	MOTOR(int *pin, bool DirL=true, bool DirR=true);
	MOTOR(bool DirL=true, bool DirR=true);
	void begin(void);
	void begin(int *pin,bool DirL=true, bool DirR=true);

	void forward(int speed);
	void forward(int speedL, int speedR);
	void backward(int speed);
	void turnLeft(int speed);
	void turnRight(int speed);
	void stop();

	void drive(double heading, int speed, int gain);

	void motor_left(int speed);
	void motor_right(int speed);

	void run();
	void run(int duration,bool debug=false);
private:


};


#endif

