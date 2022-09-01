#include "responder.h"
#include "handler.h"
#include "cmds/cmds.h"
extern handler Handler;

bool handleMsg(command message){
    
    if (message.cmd.equals(F("tryWriting")))
    {
        tryWriting();
        return;
    }
    
    if (message.cmd.equals(F("setDeviceAddress"))&& (message.arg1 != -1))
    {
        Serial.println(insertAdd);
        insertAdd = message.arg1>>1;        //162 for A2 160 for A0
        Serial.println(insertAdd);
        return;
    }

    if(message.cmd.equals(F("getRaw")) && message.arg1 != -1 && message.arg2 != -1)
    {
        printRawData(message.arg1, message.arg2);
        return;
    }

    if(message.cmd.equals(F("getInfo")))
    {
        getIdentifier();
        getExtIdentifier();
        getConnector();
        getEncoding();
        getSignalingRate();
        getRateIdentifier();
        getVendorName();
        getVendorPartNumber();
        getVendorRevision();
        getVendorSerialNumber();
        getVendorDate();
        getLinkLength();

        getVendorSpecificInformation();
        return;
    }
    if(message.cmd.equals(F("getDiagnostics")))
    {
        readTemp();
        readVoltage();
        readTxBias();
        readTxOUT();
        readRxIn();
        readLasTemp();
        readTECCurrent();
        return;
    } 

    if (message.cmd.equals(F("getEncoding")))
    {
        getEncoding();
        return;
    }

    if(message.cmd.equals(F("read8")) && (message.arg1 != -1))
    {
        Serial.println(read8B(message.arg1),HEX);
        return;
    }

    if(message.cmd.equals(F("read16")) && (message.arg1 != -1))
    {
        Serial.println(read16B(message.arg1),HEX);
        return;
    }

    if(message.cmd.equals(F("write8")) && (message.arg1 != -1))
    {
        write8B((uint8_t)message.arg1,(uint8_t)message.arg2);
        Serial.println("Wrote to target, now reading");
        //Serial.println(message.arg1);
        //Serial.println(message.arg2);
        Serial.println(read8B(message.arg1),HEX);
        return;
    }

    if(message.cmd.equals(F("write16")) && (message.arg1 != -1))
    {
        write16B(message.arg1,message.arg2);
        Serial.print("Wrote to target, now reading :");
        Serial.println(read16B(message.arg1));
        return;
    }

    if(message.cmd.equals(F("getIdentifier")))
    {
        getIdentifier();
        return;
    }

    if(message.cmd.equals(F("getExtIdentifier")))
    {
        getExtIdentifier();
        return;
    }

    if(message.cmd.equals(F("getConnector")))
    {    
        getConnector();
        return;
    }

    if(message.cmd.equals(F("help"))){
        Serial.println(F("List of available commands: "));
        Serial.println(F("help, read16() read8(add),write8(add,dat), getRaw"));
        Serial.println(F("getInfo, getConnector, getIdentifier, getExtIdentifier, tryWriting"));
        Serial.println(F("setDeviceAddress(add), getEncoding, getSignalingRate"));
        Serial.println(F("getVendorName, getVendorPartNumber, getVendorRevision, getVendorSerialNumber"));
        Serial.println(F("readASCII(startADD,endADD), getVendorSpecificInformation, getVendorDate"));
        Serial.println(F("tryAddressChange, readTemperature, readVoltage, readTxBias"));
        Serial.println(F("readTxOut, readRxIn, readLasTemp, readTECCurent, getDiagnostics"));
        Serial.println(F("escape , monitor(mode)"));

        Serial.println(F("More on: https://github.com/ndnq/SFP_Util"));

        return;
    }

    if (message.cmd.equals(F("getSignalingRate")))
    {
        getSignalingRate();
        return;
    }
    
    if (message.cmd.equals(F("getRateIdentifier")))
    {
        getRateIdentifier();
        return;
    }
    
    if (message.cmd.equals(F("readASCII"))&&message.arg1 != -1 && message.arg2 != -1)
    {
        readASCII(message.arg1,message.arg2);
        return;
    }
    
    if (message.cmd.equals(F("getVendorName")))
    {
        getVendorName();
        return;
    }

    if (message.cmd.equals(F("getVendorPartNumber")))
    {
        getVendorPartNumber();
        return;
    }

    if (message.cmd.equals(F("getVendorRevision")))
    {
        getVendorRevision();
        return;
    }

    if (message.cmd.equals(F("getVendorSerialNumber")))
    {
        getVendorSerialNumber();
        return;
    }

    if (message.cmd.equals(F("getVendorSpecificInformation")))
    {
        getVendorSpecificInformation();
        return;
    }

    if (message.cmd.equals(F("getLinkLength")))
    {
        getLinkLength();
        return;
    }

    if(message.cmd.equals("cls")){
        clearScreen();
        return;
    }

    if (message.cmd.equals(F("getVendorDate")))
    {
        getVendorDate();
        return;
    }

    if (message.cmd.equals(F("tryAddressChange")) && message.arg1 != -1)
    {
        tryAddressChange(message.arg1);
        return;
    }

    if (message.cmd.equals(F("readTemperature")))
    {
        readTemp();
        return;
    }

    if(message.cmd.equals(F("readVoltage")))
    {
        readVoltage();
        return;
    }
    
    if(message.cmd.equals(F("readTxBias")))
    {
        readTxBias();
        return;
    }
    
    if(message.cmd.equals(F("readTxOut")))
    {
        readTxOUT();
        return;
    }    
    
    if(message.cmd.equals(F("readRxIn")))
    {
        readRxIn();
        return;
    }

    if(message.cmd.equals(F("readLasTemp")))
    {
        readLasTemp();
        return;
    }
    if(message.cmd.equals(F("readTECCurrent")))
    {
        readTECCurrent();
        return;
    }

    if(message.cmd.equals(F("escape")))
    {
        Handler.escape = true;
        Handler.Tb = false;
        Handler.Vb = false;
        Handler.TxBb = false;
        Handler.TxPb = false;
        Handler.RxPb = false;
        Handler.LsTb = false;
        Handler.TECb = false;
        return;
    }

    if(message.cmd.equals(F("monitor")))
    {
        monitorData(message.arg1);
        return;
    }

    

    Serial.println(F("Unknown command. Type \"help\" for a list of commands"));

}