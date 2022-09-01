#include "cmds.h"

void readASCII(int start, int end){
    Serial.println(readText(start,end));
    return;
}

void getVendorName(){
    Serial.print(F("Vendor Name: "));
    Serial.println(readText(20,35));

}

void getVendorPartNumber(){
    Serial.print(F("Vendor Part Number: "));
    Serial.println(readText(40,55));
}

void getVendorRevision(){
    Serial.print(F("Vendor Revision Number: "));
    Serial.println(readText(56,59));
}

void getVendorSerialNumber(){
    Serial.print(F("Vendor Serial Nubmer: "));
    Serial.println(readText(68,83));
}

void getVendorSpecificInformation(){
    Serial.print("Vendor reserved: ");
    Serial.println(readText(128,255));
    return;
}

void getVendorDate(){
    Serial.print(F("Vendor Date: "));
    Serial.print(readText(84,85));
    Serial.write('.');
    Serial.print(readText(86,87));
    Serial.write('.');
    Serial.println(readText(88,89));
}