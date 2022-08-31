#ifndef RESPONDER_H
#define RESPONDER_H

#include "command.h"
bool handleMsg(command cmd);
void getIdentifier();
void getExtIdentifier();
void getConnector();
void getEncoding();
void getSignalingRate();
void getRateIdentifier();
void readASCII(uint8_t start, uint8_t end);
void tryWriting();
void getVendorName();
void getVendorPartNumber();
void getVendorRevision();
void getVendorSerialNumber();
void getVendorSpecificInformation();
void getLinkLength();
void clearScreen();
void getVendorDate();
void tryAddressChange(uint8_t mem);
void readTemp();
void readVoltage();
void readTxBias();
void readTxOUT();
void readRxIn();
void readLasTemp();
#endif