/**
 * @file	Sensor.cpp
 * @author	Syed Uthman
 * @date	12 Feb 2019
 * 
 * @brief	This is HAL for sensors and other inputs such as Button and Jumper.
 * 			This library is developed to be used with KhalifTech Sch_LF 
 * 			or Arduino Nano board.
 * 
*/

#include "Sensor.h"

int channel[] = {
		LS_0,
		LS_1,
		LS_2,
		LS_3,
		LS_4,
		LS_5,
		LS_6
};

void Sensor::begin()
{
	// Init pinmode for all inputs
	init_LS();

	// Assign Pin to sensor channel number
	for (int i = 0; i < NUM_SENSORS; i++) {
		AN[i].Pin = channel[i];
	}
}

void Sensor::calibration(int cycle = 30) {
	int _val[ NUM_SENSORS ];
	int	_pin[ NUM_SENSORS ];
	int	_highval[ NUM_SENSORS ];
	int	_lowval[ NUM_SENSORS ];

	for (int i = 0; i < NUM_SENSORS; i++) {
		_val[i] = AN[i].Val;
		_pin[i] = AN[i].Pin;
	}

	for (int n = 0; n < cycle; n++) {
		for (int i = 0; i < NUM_SENSORS; i++) {
			_val[i] = analogRead(_pin[i]);

			if (_val[i] < _highval[i]) {
				_highval[i] = _val[i];
			}

			if (_val[i] > _lowval[i]) {
				_lowval[i] = _val[i];
			}

		}
		delay(20);
	}



	for (int i = 0; i < NUM_SENSORS; i++) {
		int thress = _highval[i] - _lowval[i];
		thress /= 2;

		AN[i].ThressHold = thress;
		AN[i].HighVal = _highval[i];
		AN[i].LowVal  = _lowval[i];
	}
}

/*
* @brief	Get the average of N-X ADC samples
*
* @param	calType, environment/line calibration type
* @return	calibration status
**/
CalStatus Sensor::calibrateSensor( CalType calType )
{
	CalStatus calStatus = CAL_IN_PROGRESS;

	for( uint8_t sensorCh = 0; sensorCh < NUM_SENSORS; sensorCh++ )
	{
		if( calType == TO_NOT_DETECT )
		{
			AN[sensorCh].EnvVal = analogSampleNX( channel[sensorCh] );
		}
		else if( calType == TO_DETECT )
		{
			AN[sensorCh].LineVal = analogSampleNX( channel[sensorCh] );
		}
	}

	// Check if every sensor has HighVal and LowVal
	return CAL_SUCCESS;
}

/*
* @brief	Get the average of N-X ADC samples
*
* @param	sensorCh, sensor channel number
* @return	avg_sample, sensor channel average value
**/
uint16_t Sensor::analogSampleNX( uint8_t sensorCh )
{
	uint32_t avg_sample = 0x00;
	uint16_t adc_sample[8] = {0};
	uint8_t index = 0x00;

	for( index = 0x00; index < NUM_OF_SAMPLES; index++ )
	{
		adc_sample[index] = analogRead( sensorCh );
	}

	// Sort the N-X ADC samples
	sortTab( adc_sample, NUM_OF_SAMPLES );

	// Add the N ADC samples
	for( index = SAMPLES_TO_DELETE/2; index < NUM_OF_SAMPLES - (SAMPLES_TO_DELETE/2); index++ )
	{
		avg_sample += adc_sample[index];
	}

	// Compute the average of N-X ADC sample
	avg_sample /= NUM_OF_SAMPLES - SAMPLES_TO_DELETE;

	// Return average value
	return avg_sample;
}

/*
* @brief	Sort the N ADC samples in ascending order
*
* @param	tab[], ADC samples to be sorted
* @param	length, number of ADC samples
* @return	None
**/
void Sensor::sortTab( uint16_t tab[], uint8_t length )
{
	uint8_t i = 0x00;
	uint8_t exchange = 0x01;
	uint16_t tmp = 0x00;

	// Sort tab
	while( exchange == 1 )
	{
		exchange = 0;
		for( i = 0; i < length; i++ )
		{
			if( tab[i] > tab[i+1] )
			{
				tmp = tab[i];
				tab[i] = tab[i+1];
				tab[i+1] = tmp;
				exchange = 1;
			}
		}
	}
}

bool Sensor::isBTN_press()
{
	return (!digitalRead( BTN ) == 0 ? true : false );
}

bool Sensor::isJMP_connected()
{
	return (!digitalRead( JMP ) == 0 ? true : false );
}

bool Sensor::isLS_detected(int ch)
{
	return digitalRead(AN[ch].Pin);
}

uint16_t Sensor::getIntData( DataName dname, uint8_t ch )
{
	uint16_t val = 0u;
	switch( dname )
	{
		case PIN:
			val = AN[ch].Pin;
			break;
		case ENV_VAL:
			val = AN[ch].EnvVal;
			break;
		case LINE_VAL:
			val = AN[ch].LineVal;
			break;
		case HIGH_VAL:
			val = AN[ch].HighVal;
			break;
		case LOW_VAL:
			val = AN[ch].LowVal;
			break;
		case THRESSHOLD:
			val = AN[ch].ThressHold;
			break;
		default:
		break;
	}

	return val;
}

bool Sensor::getBoolData( DataName dname, uint8_t ch )
{
	bool val = false;
	switch( dname )
	{
		case STATE:
			val = AN[ch].State;
			break;
		case LAST_STATE:
			val = AN[ch].LastState;
			break;
		default:
		break;
	}

	return val;
}

/**
 * @brief	Read raw sensor value from ADC
 * 
 * @param	ch, sensor channel
 * @return	sensor raw value
*/
uint16_t Sensor::LS_RAW( uint8_t ch )
{
	return analogRead(AN[ch].Pin);
}