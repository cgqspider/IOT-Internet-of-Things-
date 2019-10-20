#include "IncludeAll.h"
#include "OTA.h"

int i=0;
// the setup function runs once when you press reset or power the board
void setup() {
   pinMode(LED_BUILTIN, OUTPUT);
  OneTimeSetup();
  
}

// the loop function runs over and over again forever
void loop() {

  i++;
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);// wait for a second
  Serial.println(i);
  if(i==10){
    OTA("https://narayanjha.000webhostapp.com/upload/Blink.ino.d1.bin", "5B:FB:D1:D4:49:D3:0F:A9:C6:40:03:34:BA:E0:24:05:AA:D2:E2:01");    
    }
}


