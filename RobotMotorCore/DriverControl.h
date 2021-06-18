/////////////////////////ENGINE CONTROL/////////////////////////
#define COMMAND_ENGINE 1
#define ENGINE_FORWARD 1
#define ENGINE_BACKWARD 0

//---- you can change the values ​​of these pins for the convenience of connecting your motor driver ----

//contacts responsible for the direction of rotation of the wheel.
#define LEFT_FORWARD 8
#define LEFT_BACKWARD 7
#define RIGHT_FORWARD 5
#define RIGHT_BACKWARD 4

//PWM Arduino contacts responsible for motor power
#define POWER_RIGHT 3
#define POWER_LEFT 9

void Move(byte &leftState, byte &leftPower, byte &rightState, byte &rightPower);

void InitialDriver()
{
  //initialize the pins that control the driver
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(LEFT_BACKWARD, OUTPUT);
  pinMode(RIGHT_BACKWARD, OUTPUT);
  //Move(0,0,0,0);
}

//Driver control function
void Move(const byte &leftState,const byte &leftPower,const byte &rightState,const byte &rightPower)
{
    analogWrite(POWER_LEFT, leftPower);
    digitalWrite(LEFT_FORWARD, leftState);   
    digitalWrite(LEFT_BACKWARD, !leftState); 

    analogWrite(POWER_RIGHT, rightPower);
    digitalWrite(RIGHT_FORWARD, rightState);
    digitalWrite(RIGHT_BACKWARD, !rightState);
}
