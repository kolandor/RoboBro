/*
Command transfer protocol between IOT devices.
Work algorithm:
A command cannot be less than four bytes;
The first byte is responsible for the fact that it is a command;
The second byte is a long command (maximum 255 bytes);
All subsequent bytes (except the last) are responsible for the command;
The last byte is the XOR checksum of all previously sent bytes.
*/
#include <SoftwareSerial.h>

class CommandDescriptor 
{
  private:
    
    static const char COMMAND_BEGIN = 254;

    static const byte& GenerateHash(const byte* dataToCommand,const byte& dataSize)
    {
      byte hash = 0;

      for(int i = 0; i < dataSize - 1; i++)
      {
        hash ^= dataToCommand[i];
      }

      return hash;
    }

    static bool CheckHash(const byte* dataToCommand, const byte& dataSize)
    {
      return GenerateHash(dataToCommand, dataSize) == dataToCommand[dataSize - 1];
    }
  protected:
  
    CommandDescriptor(const byte& comand, const byte* commandData)
    {
      Command = comand;
      CommandData = commandData;
    };
    
  public:
    byte Command;
    byte* CommandData = NULL;

    static int SerialSendCommand(const byte& command, const byte* dataToCommand, const byte& dataToCommandLen,const SoftwareSerial& serial)
    {
      int ethalonLen = ((int)dataToCommandLen) + 4;
      byte* commandDataToSend = new byte[ethalonLen];
      memcpy(commandDataToSend + 2, dataToCommand, dataToCommandLen);
      commandDataToSend[0] = COMMAND_BEGIN;
      commandDataToSend[1] = dataToCommandLen;
      commandDataToSend[ethalonLen - 1] = GenerateHash(commandDataToSend + 2, dataToCommandLen + 1);

      serial.write(commandDataToSend, ethalonLen);

      delete[] commandDataToSend;
      
      return 1;
    }

    static CommandDescriptor* SerialReceiveCommand(const SoftwareSerial& serial)
    {
      CommandDescriptor* commandDescr = NULL;
      
      if (serial.available() > 0)
      {
        Serial.println("Serial avilible");//Debug
        byte isCommand = serial.read();
        if(isCommand == COMMAND_BEGIN)
        {
          Serial.println("Serial is COMMAND");//Debug
          byte commandLenght = serial.read();
          byte* commandData = new byte[commandLenght];
          serial.readBytes(commandData, commandLenght);
        
          if(CheckHash(commandData, commandLenght))
          {
            byte* commandDataEnd = new byte[commandLenght - 2];
            memcpy(commandDataEnd, commandData + 1, commandLenght -1);
            
            commandDescr = new CommandDescriptor(commandData[0], commandDataEnd);

            return commandDescr;
          }
            
          delete[] commandData;
         }
         else
         {
          Serial.print(isCommand);
          Serial.println("Flush buffer");
         }
        serial.flush();
      }
      
      return commandDescr;
    }
    
    virtual ~CommandDescriptor()
    {
      if(CommandData != NULL)
      {
        delete[] CommandData;
      }
    }
};
