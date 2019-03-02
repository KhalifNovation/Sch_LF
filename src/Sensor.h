// Sensor.h

#ifndef _SENSOR_h
#define _SENSOR_h

#include "Hardware.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif



class Sensor
{
public:
	void begin();

	bool isBTN_press();
	bool isJMP_connected();	
	bool isLS_detected(int ch);
	
	int LS_RAW(int ch);
	
private:

};



#endif

