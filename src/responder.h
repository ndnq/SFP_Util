#ifndef RESPONDER_H
#define RESPONDER_H

#include "command.h"
#include "handler.h"

void monitorData(int arg1);
extern handler Handler;
bool handleMsg(command cmd);
void diagReadout(uint8_t arg1);
void getIdentifier();
void getExtIdentifier();
void getConnector();
void getEncoding();
void getSignalingRate();
void getRateIdentifier();
void readASCII(int start, int end);
void tryWriting();
void getVendorName();
void getVendorPartNumber();
void getVendorRevision();
void getVendorSerialNumber();
void getVendorSpecificInformation();
void getLinkLength();
void clearScreen();
void getVendorDate();
void tryAddressChange(int mem);
void readTemp();
void readVoltage();
void readTxBias();
void readTxOUT();
void readRxIn();
void readLasTemp();
void readTECCurrent();

#endif