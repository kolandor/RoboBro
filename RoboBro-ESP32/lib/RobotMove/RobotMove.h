#include "DriveControl.h"

#define FORWARD 1
#define BACKWARD 0
#define DANCE_PWR 255

//Robot stop
void Zer(int delayTime)
{
  byte leftState = 0;
  byte leftPower = 0;
  byte rightState = 0;
  byte rightPower = 0;
  Move(leftState, leftPower, rightState, rightPower);
  delay(delayTime);
}

void Zer()
{
  byte leftState = 0;
  byte leftPower = 0;
  byte rightState = 0;
  byte rightPower = 0;
  Move(leftState, leftPower, rightState, rightPower);
}

//Robot turn right
void Ri(int delayTime)
{
  byte leftState = FORWARD;
  byte leftPower = DANCE_PWR;
  byte rightState = BACKWARD;
  byte rightPower = DANCE_PWR;
  Move(leftState, leftPower, rightState, rightPower);
  delay(delayTime);
}

void Ri()
{
  byte leftState = FORWARD;
  byte leftPower = DANCE_PWR;
  byte rightState = BACKWARD;
  byte rightPower = DANCE_PWR;
  Move(leftState, leftPower, rightState, rightPower);
}


//Robot turn left
void Le(int delayTime)
{
  byte leftState = BACKWARD;
  byte leftPower = DANCE_PWR;
  byte rightState = FORWARD;
  byte rightPower = DANCE_PWR;
  Move(leftState, leftPower, rightState, rightPower);
  delay(delayTime);
}

void Le()
{
  byte leftState = BACKWARD;
  byte leftPower = DANCE_PWR;
  byte rightState = FORWARD;
  byte rightPower = DANCE_PWR;
  Move(leftState, leftPower, rightState, rightPower);
}

//Robot move forward
void Fo(int delayTime)
{
  byte leftState = FORWARD;
  byte leftPower = DANCE_PWR;
  byte rightState = FORWARD;
  byte rightPower = DANCE_PWR;
  Move(leftState, leftPower, rightState, rightPower);
  delay(delayTime);
}

void Fo()
{
  byte leftState = FORWARD;
  byte leftPower = DANCE_PWR;
  byte rightState = FORWARD;
  byte rightPower = DANCE_PWR;
  Move(leftState, leftPower, rightState, rightPower);
}

//Robot move backward
void Ba(int delayTime)
{
  byte leftState = BACKWARD;
  byte leftPower = DANCE_PWR;
  byte rightState = BACKWARD;
  byte rightPower = DANCE_PWR;
  Move(leftState, leftPower, rightState, rightPower);
  delay(delayTime);
}

void Ba()
{
  byte leftState = BACKWARD;
  byte leftPower = DANCE_PWR;
  byte rightState = BACKWARD;
  byte rightPower = DANCE_PWR;
  Move(leftState, leftPower, rightState, rightPower);
}