
#include "readWriteUtils.h"


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
   delay(1);
    return value;
    }

    uint8_t read8B(int addr)
    {
    Wire.beginTransmission(insertAdd);
    Wire.write(addr);   
    Wire.endTransmission();
    Wire.requestFrom(insertAdd, 1, 1); 
    unsigned int value = Wire.read();
    delay(1);
    return value;
    }


void printRawData(uint8_t startAdd,uint8_t stopADD)
{
    Serial.println("Addres, Value");
    for (size_t i = startAdd; i <= stopADD; i=i+1)
        {
        Serial.print(i,DEC);
        Serial.print(", ");
        Serial.println(read8B(i),HEX);
        }
}

String readText(int start, int end)
{
    String text="";

    for (int i = start; i < end+1; i++)
    {
         text+=(char)read8B(i);
    }
    return text;
}

void preformAddressChange(bool mem)
{
Wire.beginTransmission(0b00000000);
Wire.write(0b00000100);
if (mem == true)
{
    Wire.write(0b00000000);
}else{
    Wire.write(0b00000010);
}
Wire.endTransmission();


}

int16_t readFixedPointNumberS(uint8_t addRes1,uint8_t addRes2)
{
    int16_t value = read8B(addRes1);
    value = value<<8;
    value = value | read8B(addRes2);
    return value;

}

uint16_t readFixedPointNumberUS(uint8_t addRes1,uint8_t addRes2)
{
    uint16_t value = read8B(addRes1);
    value = value<<8;
    value = value | read8B(addRes2);
    return value;

}