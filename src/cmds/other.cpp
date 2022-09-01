#include "cmds.h"

void tryWriting(){
    int valueB4=0;
    for (size_t i = 0; i < 256; i++)
        {
            valueB4=read8B(i);
            write8B(i,(uint8_t)252);
            if (valueB4==read8B(i))
            {
            //Serial.print("Failed writing at ");
            //Serial.println(i);
            }else{
                Serial.print(F("Succes writing at "));
                Serial.println(i);
                write8B(i,valueB4);
            }
            
        }
        Serial.println("Done Trying");
}



void clearScreen(){
    Serial.print("\033[2J");
    Serial.print("\033[H");
}

void tryAddressChange(int mem){
    if (mem == 1 || mem == 0)
    {
        preformAddressChange((bool)mem);
        if (mem==1)
        {
            Serial.println(F("Addres now 0xA2"));
            insertAdd = 0xA2 >> 1;
        }else{
            Serial.println(F("Addres now 0xA0"));
            insertAdd = 0xA0 >> 1;
        }
        
    }else{
        Serial.println(F("Incorrent Argument"));
    }
}