// Sensor.h

#ifndef _SENSOR_h
#define _SENSOR_h

#include "Hardware.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define NUM_SENSORS		7

enum DataName {
	PIN,
	STATE,
	LAST_STATE,
	VAL,
	HIGH_VAL,
	LOW_VAL,
	THRESSHOLD
};

struct SensorData
{
	int Pin;
	bool State = false;
	bool LastState = false;
	int Val;
	int HighVal;
	int LowVal;
	int ThressHold;
	
};

class Sensor
{
public:
	SensorData AN[ NUM_SENSORS ];

private:


public:
	void begin();
	void calibration(int cycle = 30);

	bool isBTN_press();
	bool isJMP_connected();	
	bool isLS_detected(int ch);
	
	int getIntData(DataName dname,int ch);
	bool getBoolData(DataName dname, int ch);
	
	int LS_RAW(int ch);

	
private:
	
};



#endif

