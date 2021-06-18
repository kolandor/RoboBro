#include "RobotMove.h"
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
String comd;

void setup()
{
  InitialDriver();
  SerialBT.begin("RoboBro"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop()
{
  String tcomd = SerialBT.readString();
  if ('0' <= tcomd.c_str()[0] && '8' >= tcomd.c_str()[0] && tcomd.c_str()[0] != comd.c_str()[0])
  {
    comd = tcomd;
    Move(0, 0, 0, 0);
    delay(50);
  }

  if (!(millis() % 100l))
  {
    byte leftState = 0;
    byte leftPower = 0;
    byte rightState = 0;
    byte rightPower = 0;


    if (comd == "1") //FORWARD
    {
      leftState = FORWARD;
      leftPower = DANCE_PWR;
      rightState = FORWARD;
      rightPower = DANCE_PWR;
    }
    else if (comd == "3") //BACKWARD
    {
      leftState = BACKWARD;
      leftPower = DANCE_PWR;
      rightState = BACKWARD;
      rightPower = DANCE_PWR;
    }
    else if (comd == "2") //RIGHT
    {
      leftState = FORWARD;
      leftPower = DANCE_PWR;
      rightState = BACKWARD;
      rightPower = DANCE_PWR;
    }
    else if (comd == "4") //LEFT
    {
      leftState = BACKWARD;
      leftPower = DANCE_PWR;
      rightState = FORWARD;
      rightPower = DANCE_PWR;
    }
    else if (comd == "5") //FORWARD_RIGTH
    {
      leftState = FORWARD;
      leftPower = DANCE_PWR;
      rightState = FORWARD;
      rightPower = DANCE_PWR / 2;
    }
    else if (comd == "8") //FORWARD_LEFT
    {
      leftState = FORWARD;
      leftPower = DANCE_PWR / 2;
      rightState = FORWARD;
      rightPower = DANCE_PWR;
    }
    else if (comd == "6") //BACKWARD_RIGHT
    {
      leftState = BACKWARD;
      leftPower = DANCE_PWR;
      rightState = BACKWARD;
      rightPower = DANCE_PWR / 2;
    }
    else if (comd == "7") //BACKWARD_RIGHT
    {
      leftState = BACKWARD;
      leftPower = DANCE_PWR / 2;
      rightState = BACKWARD;
      rightPower = DANCE_PWR;
    }


    Move(leftState, leftPower, rightState, rightPower);
  }
}