#include <SchLF.h>

void setup()
{
    Serial.begin(9600);
    robot.begin(myPin, &mySensorData, true, false);
    robot.calibration();
}

void loop()
{
    
    if (robot.scan())
    {
        int error =mySensorData.pos - 6;
        Serial.println(error);
    }
}