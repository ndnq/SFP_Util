    #include <Wire.h>
    #include "readWriteUtils.h"
    #include"Arduino.h"
    #include "handler.h"



void write16B(int addr, int value)
    {
    Wire.beginTransmission(insertAdd);
    Wire.write(addr); 

    Wire.write(0xff & (value>>8));
    Wire.write(0xff & value);
    Wire.endTransmission();
    delay(10);
    }

    void write8B(uint8_t addr, uint8_t value)
    {
    Wire.beginTransmission(insertAdd);
    Wire.write(addr); 

    Wire.write(value);
    Wire.endTransmission();
    delay(10);
    }
    
   unsigned int  read16B(int addr)
    {

    Wire.beginTransmission(insertAdd);
    Wire.write(addr);   
    Wire.endTransmission();
    Wire.requestFrom(insertAdd, 2, 1); 
    unsigned int value = Wire.read()<<8;
    value |= Wire.read();
   delay(10);
    return value;
    }

       uint8_t read8B(int addr)
    {

    Wire.beginTransmission(insertAdd);
    Wire.write(addr);   
    Wire.endTransmission();
    Wire.requestFrom(insertAdd, 1, 1); 
    unsigned int value = Wire.read();
   delay(10);
    return value;
    }


    void printRawData(uint8_t startAdd,uint8_t stopADD){
        Serial.println("Addres, Value");
for (size_t i = startAdd; i <= stopADD; i=i+1)
        {
        Serial.print(i,DEC);
        Serial.print(", ");
        Serial.println(read8B(i),HEX);
        }
    }

    String readText(int start, int end){
        String text=" ";

        for (int i = start; i < end+1; i++)
        {
            text+=(char)read8B(i);
        }
        return text;
    }