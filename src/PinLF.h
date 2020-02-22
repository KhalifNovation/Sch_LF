#ifndef PLF
#define PLF
#include <Arduino.h>

typedef struct _Pin
{
    int L_In1 = 12;
    int L_In2 = 13;
    int L_Speed = 11;
    int R_In1 = 7;
    int R_In2 = 8;
    int R_Speed = 9;

    int Buzzer = 6;

    int Button = 3;

    int Jumper = 4;

    int IR[7] = {A0, A1, A2,
                 A3, A4, A5, A6};

    void setLeftMotor(int LEFT_IN1, int LEFT_IN2, int LEFT_SPEED)
    {
        L_In1 = LEFT_IN1;
        L_In2 = LEFT_IN2;
        L_Speed = LEFT_SPEED;
    };

    void setRightMotor(int RIGHT_IN1, int RIGHT_IN2, int RIGHT_SPEED)
    {
        R_In1 = RIGHT_IN1;
        R_In2 = RIGHT_IN2;
        R_Speed = RIGHT_SPEED;
    };

    void setBuzzer(int BUZZER)
    {
        Buzzer = BUZZER;
    };

    void setButton(int BUTTON)
    {
        Button = BUTTON;
    };

    void setJumper(int JUMPER)
    {
        Jumper = JUMPER;
    };

} PinLF;

#endif