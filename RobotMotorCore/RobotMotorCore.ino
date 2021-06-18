#include "DriverControl.h"
#include "CommandDescriptor.h"
#include <SoftwareSerial.h>

//direction of rotation of the wheel
#define FORWARD 1
#define BACKWARD 0

//possibility of engines during the dance (test drive)
#define DANCE_PWR 150

SoftwareSerial SoftSerial(2, 3); // RX, TX

void setup()
{
  InitialDriver();
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  SoftSerial.begin(38400);
}

void loop()
{
  if (SoftSerial.available())
    Serial.write(SoftSerial.read());
  if (Serial.available())
    SoftSerial.write(Serial.read());
  /*if(comand == COMMAND_ENGINE)
  {
    Serial.println("Serial is COMMAND_ENGINE");//Debug
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  }*/
}
