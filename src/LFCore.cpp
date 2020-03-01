#include "LFCore.h"
SchLF::SchLF(){

}
SchLF::SchLF(int *motorPin, int *irSensorPin, int buzzerPin, int jumperPin, int buttonPin)
{
    motorPinSize = sizeof(_motorPin) / sizeof(int);
    irPinSize = sizeof(_sensorIRPin) / sizeof(int);
    
    for (int i = 0; i < motorPinSize; i++)
        _motorPin[i] = motorPin[i];

    for (int i = 0; i < irPinSize; i++)
        _sensorIRPin[i] = irSensorPin[i];

    _buzzerPin = buzzerPin;
    _jumperPin = jumperPin;
    _buttonPin = buttonPin;
}

void SchLF::begin(PinLF mySchLF, SensorData *IR, bool invertL, bool invertR)
{
    int myMotorPin[6] = {
        mySchLF.L_In1,
        mySchLF.L_In2,
        mySchLF.L_Speed,
        mySchLF.R_In1,
        mySchLF.R_In2,
        mySchLF.R_Speed
    };

    motorPinSize = sizeof(myMotorPin) / sizeof(int);
    irPinSize = sizeof(_sensorIRPin) / sizeof(int);
    for (int i = 0; i < motorPinSize; i++){
        _motorPin[i] = myMotorPin[i];
    }

    for (int i = 0; i < irPinSize; i++){
        _sensorIRPin[i] = mySchLF.IR[0];
    }
    
    _buzzerPin = mySchLF.Buzzer;
    _buttonPin = mySchLF.Button;
    _jumperPin = mySchLF.Jumper;

    LFsensor.begin(mySchLF,IR);
    begin(invertL, invertR);
}

void SchLF::begin(bool invertL, bool invertR)
{
    for (int i = 0; i < motorPinSize; i++)
    {
        if (i == 2 || i == 5)
            pinMode(_motorPin[i], OUTPUT);
    }

    pinMode(_buzzerPin, OUTPUT);
    pinMode(_buttonPin, INPUT_PULLUP);
    pinMode(_jumperPin, OUTPUT);
    LFmotor.begin(_motorPin,invertL,invertR);
    
}

void SchLF::buzzer(String mode)
{
    if (mode.equals("ON"))
    {
        digitalWrite(_buzzerPin, HIGH);
    }
    else if (mode.equals("OFF"))
    {
        digitalWrite(_buzzerPin, LOW);
    }
}


void SchLF::forward(int speed)
{
    LFmotor.forward(speed);
}

void SchLF::forward(int speedL,int speedR)
{
    LFmotor.forward(speedL,speedR);
}

void SchLF::backward(int speed)
{
    LFmotor.backward(speed);
}

void SchLF::turnLeft(int speed)
{
    LFmotor.turnLeft(speed);
}

void SchLF::turnRight(int speed)
{
    LFmotor.turnRight(speed);
}

void SchLF::calibration(){
    LFsensor.calibration();
}

bool SchLF::scan(unsigned long period){
    return LFsensor.scan(period);
}

void SchLF::printRaw(){
    LFsensor.printRaw();;
}

void SchLF::printBool(){
    LFsensor.printBool();;
}


void SchLF::stop()
{
    LFmotor.stop();
}

void SchLF::taskFinish()
{
    LFmotor.stop();
    buzzer("ON");
    delay(1000);
    buzzer("OFF");
    while (1)
        ;
}