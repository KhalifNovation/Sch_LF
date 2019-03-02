// MOTOR.h

#ifndef _MOTOR_h
#define _MOTOR_h

#include "Hardware.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Motor
{
public:
	void begin();
	void forward(int speed);
	void backward(int speed);
	void left(int speed);
	void right(int speed);
	
	void motor_left(int speed);
	void motor_right(int speed);

private:


};



#endif
