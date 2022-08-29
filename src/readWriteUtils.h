#ifndef RWUTILS_H
#define RWUTILS_H

void write16B(int addr, int value);
void write8B(uint8_t addr, uint8_t value);
void printRawData(uint8_t startAdd, uint8_t stopAdd);
unsigned int  read16B(int addr);
uint8_t  read8B(int addr);
String readText(int start, int end);
#endif