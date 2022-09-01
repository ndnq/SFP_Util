#include "cmds.h"


void readTemp()
{
    bool revert = false;
    if (insertAdd == 80)
    {
        insertAdd = 81;
        revert = true;
    }
    Serial.print(F("Temperature [C]: "));
    Serial.println(readFixedPointNumberS(96,97)/256.0,3);
    if(revert)
    {
        insertAdd = 80;
    }
}

void readVoltage(){

    bool revert = false;
    if (insertAdd == 80)
    {
        insertAdd = 81;
        revert = true;
    }
    Serial.print(F("Supply Voltage [mV]: "));
    Serial.println(readFixedPointNumberUS(98,99)/10.0f,1);
    if(revert)
    {
        insertAdd = 80;
    }
}

//Read TX bias Current
void readTxBias()
{
    bool revert = false;
    if (insertAdd == 80)
    {
        insertAdd = 81;
        revert = true;
    }
    Serial.print(F("TX bias Current [mA]: "));
    Serial.println(readFixedPointNumberUS(100,101)/500.0f,2);
    if(revert)
    {
        insertAdd = 80;
    }

}
//Read TX output Power
void readTxOUT()
{
    bool revert = false;
    if (insertAdd == 80)
    {
        insertAdd = 81;
        revert = true;
    }
    Serial.print(F("TX output power [mW]: "));
    Serial.println(readFixedPointNumberUS(102,103)/10000.0f,4);
    if(revert)
    {
        insertAdd = 80;
    }
}
//Read RX recieved optical Power
void readRxIn()
{
    bool revert = false;
    if (insertAdd == 80)
    {
        insertAdd = 81;
        revert = true;
    }
    Serial.print(F("RX input power [mW]: "));
    Serial.println(readFixedPointNumberUS(104,105)/10000.0f,4);
    if(revert)
    {
        insertAdd = 80;
    }
}
//Laser Temperature
void readLasTemp()
{
    bool revert = false;
    if (insertAdd == 80)
    {
        insertAdd = 81;
        revert = true;
    }
    Serial.print(F("Laser Temperature [C]: "));
    Serial.println(readFixedPointNumberS(106,107)/256.0f,3);
    if(revert)
    {
        insertAdd = 80;
    }

}

void readTECCurrent()
{
    bool revert = false;
    if (insertAdd == 80)
    {
        insertAdd = 81;
        revert = true;
    }
    Serial.print(F("TEC Current [mA]: "));
    Serial.println(readFixedPointNumberS(108,109)/10.0f,3);
    if(revert)
    {
        insertAdd = 80;
    }

}

void monitorData(int arg1)
{
    if (arg1 == -1)
    {
        Handler.escape = false;
        while (!Handler.escape)
        {
         diagReadout(arg1);
         Handler.checkForEvents();
        }
    }
    switch (arg1)
    {
    case 0:
        Handler.Tb = true;
        break;
    case 1:
        Handler.Vb = true;
        break;
    case 2:
        Handler.TxBb = true;
        break;
    case 3:
        Handler.TxPb = true;
        break;
    case 4:
        Handler.RxPb = true;
        break;
    case 5:
        Handler.LsTb = true;
        break;
    case 6:
        Handler.TECb = true;
        break;
    default:
        break;
    }
    
    
}

void diagReadout(uint8_t arg1)
{
    bool notfirst = false;
    bool revert = false;
    if (insertAdd == 80)
    {
        insertAdd = 81;
        revert = true;
    }

    if (Handler.Tb)
    {
    Serial.print(readFixedPointNumberS(96,97)/256.0f,3); //Temp
    notfirst=true;
    }
    if (Handler.Vb)
    {
    if(notfirst){Serial.print(", ");}
    notfirst=true;
    Serial.print(readFixedPointNumberUS(98,99)/10.0f,1);
    }
    if (Handler.TxBb)
    {
    if(notfirst){Serial.print(", ");}
    notfirst=true;
    Serial.print(readFixedPointNumberUS(100,101)/500.0f,2);
    }
    if (Handler.TxPb)
    {
    if(notfirst){Serial.print(", ");}
    notfirst=true;
    Serial.print(readFixedPointNumberUS(102,103)/10000.0f,4);
    }
    if (Handler.RxPb)
    {
    if(notfirst){Serial.print(", ");}
    notfirst=true;
    Serial.print(readFixedPointNumberUS(104,105)/10000.0f,4);
    }
    if (Handler.LsTb)
    {
    if(notfirst){Serial.print(", ");}
    notfirst=true;
    Serial.print(readFixedPointNumberS(106,107)/256.0f,3);
    }
    if (Handler.TECb)
    {
    if(notfirst){Serial.print(", ");}
    notfirst=true;
    Serial.print(readFixedPointNumberS(108,109)/10.0f,3);
    }
    Serial.print("\n");
    if(revert)
    {
        insertAdd = 80;
    }
        return;
    }