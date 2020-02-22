#ifndef SENDATA
#define SENDATA

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

#endif