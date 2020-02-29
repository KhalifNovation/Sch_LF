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
		pIR->IR[i].Pin = mySchLF.IR[i];
	}
}

void Sensor::calibration(int cycle)
{
	int _val[sensorSize];
	int _pin[sensorSize];
	int _highval[sensorSize];
	int _lowval[sensorSize];

	for (int i = 0; i < sensorSize; i++)
	{
		_val[i] = pIR->IR[i].Val;
		_pin[i] = pIR->IR[i].Pin;
	}

	for (int n = 0; n < cycle; n++)
	{
		for (int i = 0; i < sensorSize; i++)
		{
			_val[i] = analogRead(_pin[i]);

			if (_val[i] > _highval[i])
			{
				_highval[i] = _val[i];
			}

			if (_val[i] < _lowval[i])
			{
				_lowval[i] = _val[i];
			}
		}
		delay(20);
	}
	Serial.println("Calibration Done");

	for (int i = 0; i < sensorSize; i++)
	{
		int thress = _highval[i] - _lowval[i];
		thress = 750;

		pIR->IR[i].ThressHold = thress;
		pIR->IR[i].HighVal = _highval[i];
		pIR->IR[i].LowVal = _lowval[i];
	}

	Serial.println("ThressHold");
	for(int i = 0; i < sensorSize; i++){
		Serial.print(pIR->IR[i].ThressHold);
		if (i < sensorSize - 1)
			Serial.print(" : ");
		else
			Serial.println("\n");
	}

	Serial.println("HighVal");
	for(int i = 0; i < sensorSize; i++){
		Serial.print(pIR->IR[i].HighVal);
		if (i < sensorSize - 1)
			Serial.print(" : ");
		else
			Serial.println("\n");
	}

	Serial.println("LowVal");
	for(int i = 0; i < sensorSize; i++){
		Serial.print(pIR->IR[i].LowVal);
		if (i < sensorSize - 1)
			Serial.print(" : ");
		else
			Serial.println("\n");
	}

}

bool Sensor::scan(unsigned long period)
{
	unsigned long nMillis = millis();
	if (nMillis - pMillis > period)
	{
		pIR->state = 0;
		for (int i = 0; i < sensorSize; i++)
		{
			pIR->IR[i].Val = LS_RAW(i);
			pIR->IR[i].State = pIR->IR[i].Val > pIR->IR[i].ThressHold ? true : false;
			pIR->state |=  (uint8_t)pIR->IR[i].State << (6 - i);
		}
		pMillis = nMillis;
		return 1;
	}
	return 0;
}

void Sensor::printRaw()
{
	for (int i = 0; i < sensorSize; i++)
	{
		Serial.print(pIR->IR[i].Val);
		if (i < sensorSize - 1)
			Serial.print(" : ");
		else
			Serial.println("\n");
	}
}

void Sensor::printBool(){
	for (int i = 0; i < sensorSize; i++)
	{
		Serial.print(pIR->IR[i].State);
		if (i < sensorSize - 1)
			Serial.print(" : ");
		else
			Serial.println("\n");
	}
}

int Sensor::LS_RAW(int ch)
{
	return analogRead(pIR->IR[ch].Pin);
}