#include <SchLF.h>

void setup()
{
    Serial.begin(9600);
    robot.begin(myPin, &mySensorData, true, false);
    robot.calibration();
}

void loop()
{
    robot.forward(80);
	delay(1000);
	robot.turnLeft(80);
	delay(1000);
	robot.forward(80);
	delay(1000);
	robot.turnLeft(80);
	delay(1000);
	robot.forward(80);
	delay(1000);
	robot.turnLeft(80);
	delay(1000);
	robot.forward(80);
	delay(1000);
	robot.turnLeft(80);
	delay(1000);

}