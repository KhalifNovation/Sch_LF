#ifndef SENDATA
#define SENDATA

struct _SensorData
{
	int Pin;
	bool State = false;
	bool LastState = false;
	int Val;
	int HighVal;
	int LowVal;
	int ThressHold;
};

struct SensorData{
	_SensorData IR[7];
	uint8_t state;
	uint8_t prevState;
	uint8_t pos;
};

#endif