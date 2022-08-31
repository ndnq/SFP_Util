#ifndef RWUTILS_H
#define RWUTILS_H
#include <Wire.h>
#include"Arduino.h"
#include "handler.h"

void write16B(int addr, int value);
void write8B(uint8_t addr, uint8_t value);
void printRawData(uint8_t startAdd, uint8_t stopAdd);
void preformAddressChange(bool mem);
uint16_t readFixedPointNumberUS(uint8_t addRes1,uint8_t addRes2);
int16_t readFixedPointNumberS(uint8_t addRes1,uint8_t addRes2);
unsigned int  read16B(int addr);
uint8_t  read8B(int addr);
String readText(int start, int end);
#endif