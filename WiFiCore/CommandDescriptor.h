/*
Command transfer protocol between IOT devices.
Work algorithm:
A command cannot be less than four bytes;
The first byte is responsible for the fact that it is a command;
The second byte is a long command (maximum 255 bytes);
All subsequent bytes (except the last) are responsible for the command;
The last byte is the XOR checksum of all previously sent bytes.
*/

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
  
    CommandDescriptor(const byte& comand, byte* commandData)
    {
      Command = comand;
      CommandData = commandData;
    };
    
  public:
    byte Command;
    byte* CommandData = NULL;

    static int SerialSendCommand(const byte& command, const byte* dataToCommand, const byte& dataToCommandLen)
    {
      Serial.println("Start method send");//Debug
      int ethalonLen = ((int)dataToCommandLen) + 4;
      byte* commandDataToSend = new byte[ethalonLen];
      memcpy(commandDataToSend + 2, dataToCommand, dataToCommandLen);
      commandDataToSend[0] = COMMAND_BEGIN;
      commandDataToSend[1] = dataToCommandLen;
      commandDataToSend[ethalonLen - 1] = GenerateHash(commandDataToSend + 2, dataToCommandLen + 1);

      Serial.println("Data send");//Debug
      Serial2.write(commandDataToSend, ethalonLen);

      delete[] commandDataToSend;
      
      return 1;
    }

    static CommandDescriptor* SerialReceiveCommand()
    {
      CommandDescriptor* commandDescr = NULL;
      
      if (Serial2.available() > 0)
      {
        Serial.println("Serial avilible");//Debug
        byte isCommand = Serial2.read();
        if(isCommand == COMMAND_BEGIN)
        {
          Serial.println("Serial is COMMAND");//Debug
          byte commandLenght = Serial2.read();
          byte* commandData = new byte[commandLenght];
          Serial2.readBytes(commandData, commandLenght);
        
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
        Serial2.flush();
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
