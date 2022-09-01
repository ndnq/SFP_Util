#include "handler.h"    
#include "responder.h"

#define transmiTtime 2000000UL
void printRawData();

bool CursorState;

handler::handler(unsigned long currentTime)
{
    timeStamp = currentTime;
    
}

handler::handler()
{
}

void handler::checkForEvents()
{
    //Do something periodically
    if (micros()-timeStamp > transmiTtime)
    {
        //Here goes the code that executes once per transmitTime clock cycles
        timeStamp = micros();
        
    }
    //Recieve serial data
    if (Serial.available() > 0)
    {
        
        String dataIn = Serial.readStringUntil('\n\r');            //Reads incoming data as ASCII characters
        for (size_t i = 0; i < dataIn.length(); i++)    //Strip them of nl or rc if there are any
         {
            if (dataIn.charAt(i)=='\n'||dataIn.charAt(i)=='\r')
            {
            dataIn.remove(i,1);
            }
         }
        handleMsg(parseCommand(dataIn));
    }
}

//Extracts arguments from input command ex. write8(8,25) -> 8,25

String handler::extractArg(String dataIn)
{
    int argStart=0;
    int argEnd=0;
    for(int i=0; i<(int)dataIn.length(); i++)
    {
        if (dataIn.charAt(i)=='(')
        {
            argStart = i;
        }

    }
    dataIn.remove(0,argStart+1);
    for (int i=0; i<(int)dataIn.length(); i++)
    {
        if (dataIn.charAt(i)==')')
        {
            argEnd = i;
        }
    }

    if (argStart == 0 && argEnd == 0)
    {
        return "";
    }
    dataIn.remove(argEnd,1);
    return dataIn;
}

//Extracts command from input command ex write8(25,6) -> write8

String handler::extractCmd(String dataIn)
{
    int argStart=0;
    int argEnd=0;
    for(int i=0; i<(int)dataIn.length(); i++)
    {
        if (dataIn.charAt(i)=='(')
        {
            argStart = i;
        }
    }
    for (int i=0; i<(int)dataIn.length(); i++)
    {
        if (dataIn.charAt(i)==')')
        {
            argEnd = i;
        }
    }
    if (argStart == 0 && argEnd == 0)
    {
        return dataIn;
    }
    dataIn.remove(argStart,argEnd-argStart+1);    

    return dataIn;
}
//Parse given command. Accepts templates of cmd | cmd(arg1) | cmd(arg1,arg2)
command handler::parseCommand(String dataIn)
{
    command returnCmd;
    returnCmd.cmd ="";
    returnCmd.arg1 = -1;
    returnCmd.arg2 = -1;
    String rawArgs,rawArgs1,rawArgs2;
    
    returnCmd.cmd = extractCmd(dataIn);
    rawArgs = extractArg(dataIn);
    
    for (int i = 0; i < rawArgs.length(); i++)
    {   
        
        if(rawArgs.length()==0)
        {
            returnCmd.arg1 = -1;
            returnCmd.arg2 = -1;
            return returnCmd;
        }
        if(rawArgs.indexOf(',')==-1)
        {
            returnCmd.arg1 = rawArgs.toInt();
            returnCmd.arg2 = -1;
            return returnCmd;
        }
        if(rawArgs.charAt(i)==',')
        {
            rawArgs2 = rawArgs;
            rawArgs2.remove(0,i+1);
            returnCmd.arg2 = rawArgs2.toInt();
            rawArgs1 = rawArgs;
            rawArgs1.remove(i,rawArgs1.length()-i+1);
            returnCmd.arg1 = rawArgs1.toInt();
        }

    }
    
    return returnCmd;

}