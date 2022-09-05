    #include <Wire.h>
    #include "Arduino.h"
    #include "src/handler.h"

   handler Handler;
   uint8_t insertAdd = 0xA0>>1; //Initial Device address

    void setup() {
      Wire.begin();
      Serial.begin(9600);                   // Start Serial at 9600baud
      Serial.setTimeout(500);               //Time between revieving data for it to be recognized as a command
      Handler = *new handler(micros());
      delay(5000);
      while(!Serial){};
      Serial.print(">");
    }

    void loop() {      
        Handler.checkForEvents();
      }
