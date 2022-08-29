#ifndef HANDLER_H
#define HANDLER_H
#include <Arduino.h>
#include "readWriteUtils.h"
#include "command.h"

extern int insertAdd;

class handler {
  private:
    String handler::extractArg(String dataIn);
    String handler::extractCmd(String dataIn);
    command handler::parseCommand(String dataIn);
    String handler::trimStringOut(String strIn,char f, char t);
    unsigned long timeStamp;
  public:
    handler(unsigned long currentTime);
    handler();
    void checkForEvents();
};

#endif