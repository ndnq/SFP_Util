#ifndef CMDS_H
#define CMDS_H
#include "../command.h"
#include "../handler.h"
extern handler Handler;
//Command Definitions

    //Identification
void getIdentifier();
void getExtIdentifier();
void getConnector();
void getEncoding();
void getSignalingRate();
void getRateIdentifier();
void getLinkLength();
    //ASCIIidentification
void readASCII(int start, int end);
void getVendorName();
void getVendorPartNumber();
void getVendorRevision();
void getVendorSerialNumber();
void getVendorSpecificInformation();
void getVendorDate();
    //Monitoring
void readTemp();
void readVoltage();
void readTxBias();
void readTxOUT();
void readRxIn();
void readLasTemp();
void readTECCurrent();
void monitorData(int arg1);
void diagReadout(uint8_t arg1);
    //Other
void tryWriting();
void clearScreen();
void tryAddressChange(int mem);

#endif