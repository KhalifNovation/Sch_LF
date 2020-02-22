#include "Sensor.h"

Sensor::Sensor()
{
}

void Sensor::begin(PinLF mySchLF, SensorData *IR)
{
	// sensorSize = sizeof(IR) / sizeof(SensorData);
	pIR = IR;
	for (int i = 0; i < sensorSize; i++)
	{
		pIR[i].Pin = mySchLF.IR[i];
	}
}

void Sensor::calibration(int cycle = 30)
{
	int _val[sensorSize];
	int _pin[sensorSize];
	int _highval[sensorSize];
	int _lowval[sensorSize];

	for (int i = 0; i < sensorSize; i++)
	{
		_val[i] = pIR[i].Val;
		_pin[i] = pIR[i].Pin;
	}

	for (int n = 0; n < cycle; n++)
	{
		for (int i = 0; i < sensorSize; i++)
		{
			_val[i] = analogRead(_pin[i]);

			if (_val[i] < _highval[i])
			{
				_highval[i] = _val[i];
			}

			if (_val[i] > _lowval[i])
			{
				_lowval[i] = _val[i];
			}
		}
		delay(20);
	}

	for (int i = 0; i < sensorSize; i++)
	{
		int thress = _highval[i] - _lowval[i];
		thress /= 2;

		pIR[i].ThressHold = thress;
		pIR[i].HighVal = _highval[i];
		pIR[i].LowVal = _lowval[i];
	}
}

bool Sensor::scan(unsigned long period)
{
	unsigned long nMillis = millis();
	if (nMillis - pMillis > period)
	{

		for (int i = 0; i < sensorSize; i++)
		{
			pIR[i].Val = LS_RAW(i);
		}

		pMillis = nMillis;
		return 1;
	}
	return 0;
}

void Sensor::printScan()
{
	for (int i = 0; i < sensorSize; i++)
	{
		Serial.print(pIR[i].Val);
		if (i < sensorSize - 1)
			Serial.print(" : ");
		else
			Serial.println("\n");
	}
	
}

int Sensor::LS_RAW(int ch)
{
	return analogRead(pIR[ch].Pin);
}