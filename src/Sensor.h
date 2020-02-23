#ifndef _SENSOR_h
#define _SENSOR_h

#include <Arduino.h>
#include "PinLF.h"
#include "SensorData.h"

class Sensor
{
public:
	
private:
	SensorData *pIR;
	int sensorSize = 7;

	unsigned pMillis;

public:
	Sensor();

	void begin(PinLF mySchLF, SensorData *IR);
	void calibration(int cycle = 100);
	
	bool scan(unsigned long period);
	void printRaw();
	void printBool();
		
	int LS_RAW(int ch);

private:
	
};



#endif

