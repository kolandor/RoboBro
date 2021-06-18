#include <Arduino.h>
#include <analogWrite.h>

/////////////////////////ENGINE CONTROL/////////////////////////
#define COMMAND_ENGINE 1
#define ENGINE_FORWARD 1
#define ENGINE_BACKWARD 0

//---- you can change the values ​​of these pins for the convenience of connecting your motor driver ----

//contacts responsible for the direction of rotation of the wheel.
#define LEFT_FORWARD 12
#define LEFT_BACKWARD 14
#define RIGHT_FORWARD 27
#define RIGHT_BACKWARD 26

//PWM Arduino contacts responsible for motor power
#define POWER_RIGHT 25
#define POWER_LEFT 13

//Driver control function
void Move(const byte &leftState, const byte &leftPower, const byte &rightState, const byte &rightPower)
{
  analogWrite(POWER_LEFT, leftPower);
  digitalWrite(LEFT_FORWARD, leftState);
  digitalWrite(LEFT_BACKWARD, !leftState);

  analogWrite(POWER_RIGHT, rightPower);
  digitalWrite(RIGHT_FORWARD, rightState);
  digitalWrite(RIGHT_BACKWARD, !rightState);
}

void InitialDriver()
{
  //initialize the pins that control the driver
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(LEFT_BACKWARD, OUTPUT);
  pinMode(RIGHT_BACKWARD, OUTPUT);
  Move(0, 0, 0, 0);
}