// Sensor.h

#ifndef _SENSOR_h
#define _SENSOR_h

#include "Hardware.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#define NUM_SENSORS				7
#define NUM_OF_SAMPLES			4
#define SAMPLES_TO_DELETE		2

enum DataName
{
	PIN,
	STATE,
	LAST_STATE,
	VAL,
	HIGH_VAL,
	LOW_VAL,
	LINE_VAL,
	ENV_VAL,
	THRESSHOLD
};

enum CalType
{
	TO_DETECT,
	TO_NOT_DETECT
};

enum CalStatus
{
	CAL_IN_PROGRESS,
	CAL_SUCCESS,
	CAL_FAILED
};

struct SensorData
{
	uint8_t Pin;
	bool State = false;
	bool LastState = false;
	uint16_t Val;
	uint16_t HighVal;
	uint16_t LowVal;
	uint16_t LineVal;
	uint16_t EnvVal;
	uint16_t ThressHold;
	
};

class Sensor
{
	public:
		SensorData AN[ NUM_SENSORS ];

		void begin();
		void calibration( int cycle );
		CalStatus calibrateSensor( CalType calType );

		bool isBTN_press();
		bool isJMP_connected();
		bool isLS_detected( uint8_t ch );
		
		uint16_t getIntData( DataName dname, uint8_t ch );
		bool getBoolData( DataName dname, uint8_t ch );
		
		uint16_t LS_RAW( uint8_t ch );
		uint16_t LS_ScanBinary( void );

	private:
		uint16_t analogSampleNX( uint8_t sensorCh );
		void sortTab( uint16_t tab[], uint8_t length );
	
};



#endif

