#include "CommandDescriptor.h"
#include "BluetoothSerial.h"
#include <string>

#define RXD2 16
#define TXD2 17

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() 
{
  //Serial.begin(115200);
  Serial2.begin(38400, SERIAL_8N1, RXD2, TXD2);
  SerialBT.begin("ESP32test"); //Bluetooth device name
}

void loop()
{
  if (Serial2.available())
    SerialBT.write(Serial2.read());
  if (SerialBT.available())
  {
    SerialBT.read();
    byte driveComd[] = {'a', 'b', 'c'};
    CommandDescriptor::SerialSendCommand(1, driveComd, 3);
  }
  /*if (Serial.available()) 
  {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    char symb = SerialBT.read();

    if(symb == 'A')
    {
      char driveComd[] = {COMMAND_BEGIN, 4, COMMAND_ENGINE};
      Serial.write(driveComd, 3);
    }
    else
    {
      SerialBT.println("ERROR");
      SerialBT.write(symb);
      char bf[10] = {0};
      int value = symb;
      snprintf(bf, 10, "%d", value);
      SerialBT.println(bf);
    }
  }
  delay(20);*/
}
