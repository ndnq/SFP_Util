#ifndef RESPONDER_H
#define RESPONDER_H

#include "command.h"
#include "handler.h"

extern handler Handler;
bool handleMsg(command cmd);

#endif