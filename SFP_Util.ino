    #include <Wire.h>
    #include"Arduino.h"
    #include "src/handler.h"

    handler Handler1;
    
   int insertAdd = 0xA0>>1; //Device addres has to be shifted one bit right

    void setup() {
      Wire.begin();
      Serial.begin(9600);                 // Start Serial at 9600baud
      Serial.setTimeout(1000);               //Maximim number of ms between revieving data to it to be considered continuous
      Handler1 = *new handler(micros());
      delay(5000);
    }

    void loop() {
      Handler1.checkForEvents();
      }
