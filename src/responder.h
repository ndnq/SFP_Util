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

#endif