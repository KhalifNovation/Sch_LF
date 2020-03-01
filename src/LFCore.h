#ifndef LFLIB
#define LFLIB

#include <Arduino.h>
#include "MOTOR.h"
#include "PinLF.h"
#include "SensorData.h"
#include "Sensor.h"

class SchLF
{
private:
    int motorPinSize;
    int irPinSize;
    int _motorPin[6];
    int _sensorIRPin[7];
    int _buzzerPin;
    int _buttonPin;
    int _jumperPin;
    MOTOR LFmotor;
    Sensor LFsensor;

    bool sBeeper;

public:
    SchLF();
    SchLF(int *motorPin, int *irSensorPin, int buzzerPin, int jumperPin, int buttonPin);
    void begin(PinLF mySchLF, SensorData *IR, bool invertL, bool invertR);
    void begin(bool invertL, bool invertR);

    void buzzer(String mode);

    bool isButtonPress() {return !digitalRead(_buttonPin);};

    bool jumper() {return digitalRead(_jumperPin);};

    void forward(int speed);
    void forward(int speedL, int speedR);
    void backward(int speed);
    void turnLeft(int speed);
    void turnRight(int speed);

    // void drive(double heading, int speed, int gain);

    bool scan(unsigned long period = 30);
    void calibration();
    void printRaw();
    void printBool();

    void stop();

    void taskFinish(void);
};

#endif