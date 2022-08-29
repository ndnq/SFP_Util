#ifndef COMMAND_H
#define COMMAND_H
#include "Arduino.h"

struct command
{
  String cmd;
  int arg1, arg2;
};
#endif  