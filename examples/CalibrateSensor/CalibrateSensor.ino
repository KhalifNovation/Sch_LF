/**
 * This is an example code to perform sensor calibration.
 * 
 * How to use this example?
 * Step 1:
 *      ** Place line sensors to White/Environment area
 *      ** Press button to start calibrate White/Environment value
 * Step 2:
 *      ** Place line sensors to Black/Line area
 *      ** Press button to start calibrate Black/Line value
 * Step 3:
 *      ** Press button to exit calibration process and to view
 *         value that been captured.
*/

#include "Motor.h"
#include "Sensor.h"
#include "Hardware.h"

// Serial configuration 
#define debugMode false
#define serialMode true
#define baudrate 9600

// Create instances
Motor robot;
Sensor input;

// Declare variables
int buttonPressed = 0;
bool calibrationDone = false;
int totalSensors = 7;

void setup()
{
    init_Serial();      //initialize serial
    init_Hardware();    //initialize robot hardware
}

void loop()
{
    while( calibrationDone != true )
    {
        // Check pressed button
        if( input.isBTN_press() )
        {            
            // Wait for button debounce
            while( input.isBTN_press() ){};
            
            if( buttonPressed == 0 )
            {
                Serial.println("Button pressed: Calibrating ENVIRONMENT value");
                
                // Calibrate HIGH value (black area)
                input.calibrateSensor( TO_NOT_DETECT );
            }
            else if( buttonPressed == 1 )
            {
                Serial.println("Button pressed: Calibrating LINE value");
                
                // Calibrate LOW value (white area)
                input.calibrateSensor( TO_DETECT );
            }
            else
            {
                // Print LOW and HIGH sensor reading
                Serial.println("NX calibration");
                for( int i = 0; i < totalSensors; i++ )
                {
                    Serial.print( " LINE:" );
                    Serial.print( input.getIntData( LINE_VAL, i ) );
                    Serial.print( " ENV:" );
                    Serial.print( input.getIntData( ENV_VAL, i ) );
                    Serial.print( "\t" );
                }
                Serial.println();
                
                // Close calibration process
                calibrationDone = true;
            }

            // Increase number of button pressed
            buttonPressed += 1;
        }
    }

    // Do robot work here..
}

// initialize Serial
void init_Serial()
{
  // check if user serial or debug mode
  if(debugMode || serialMode)
  {
    // Additional serial setup can be add here
    Serial.begin(baudrate);
  }
}

// initialize Robot Hardware
void init_Hardware()
{
  robot.begin();		//initialize output (Motor)
  input.begin();		//initialize input (Button,Jumper,IR Sensor)
  init_BUZZ();		//initialize buzzer
}