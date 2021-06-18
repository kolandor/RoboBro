//Sample bot control
void moveBot() 
{
  Ri(500);
  Zer(100);
  
  Le(500);
  Zer(100);
  
  Fo(100);
  Zer(100);
  
  Ba(100);
  Zer(100);

  Ri(500);
  Zer(100);
  
  Le(500);
  Zer(100);

  Ri(500);
  Zer(100);
  
  Le(500);
  Zer(100);
}

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
