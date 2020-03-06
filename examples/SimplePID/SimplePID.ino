#include <SchLF.h>
#include <PID_v1.h>

double Setpoint = 6;
double Input, Output;
int speedNorm = 60;
int speedL;
int speedR;

double Kp = 2, Kd = 0;
PID myPID(&Input, &Output, &Setpoint, Kp, 0, Kd, DIRECT);


void setup()
{
    Serial.begin(9600);
    robot.begin(myPin, &mySensorData, true, false);
    robot.calibration();
}

void loop()
{
    if(robot.scan()){
        
        Input = mySensorData.pos;
        myPID.Compute();

        speedL = speedNorm - OUTPUT;
        speedR = speedNorm + OUTPUT;

        Serial.print(speedL);
        Serial.print("\t");
        Serial.println(speedR);
    }
}