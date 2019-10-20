#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "fauxmoESP.h"

#define WIFI_SSID "JioFi2_C7398C"//change your Wifi name
#define WIFI_PASS "zrf9b6ug47"//Change your Wifi Password
#define SERIAL_BAUDRATE                 115200

fauxmoESP fauxmo;
//declare switching pins
//Change pins according to your NodeMCU pinouts
#define bulb D4
#define fan D3
#define television D2
#define cooler D1

// -----------------------------------------------------------------------------
// Wifi Setup
// -----------------------------------------------------------------------------

void wifiSetup() {

    // Set WIFI module to STA mode
    WiFi.mode(WIFI_STA);

    // Connect
    Serial.printf("[WIFI] Connecting to %s ", WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    // Wait
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(100);
    }
    Serial.println();

    // Connected!
    Serial.printf("[WIFI] STATION Mode, SSID: %s, IP address: %s\n", WiFi.SSID().c_str(), WiFi.localIP().toString().c_str());
}
// -----------------------------------------------------------------------------
// Device Callback
// -----------------------------------------------------------------------------
void callback(uint8_t device_id, const char * device_name, bool state) {
  Serial.print("Device "); Serial.print(device_name); 
  Serial.print(" state: ");
  if (state) {
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }
  //Switching action on detection of device name
  if ( (strcmp(device_name, "bulb") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      digitalWrite(bulb, LOW);
    } else {
      digitalWrite(bulb, HIGH);
    }
  }



if ( (strcmp(device_name, "fan") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      digitalWrite(fan, LOW);
    } else {
      digitalWrite(fan, HIGH);
    }
  }



  if ( (strcmp(device_name, "television") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      digitalWrite(television, LOW);
    } else {
      digitalWrite(television, HIGH);
    }
  }

if ( (strcmp(device_name, "cooler") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      digitalWrite(cooler, LOW);
    } else {
      digitalWrite(cooler, HIGH);
    }
  }



  
}

void setup() {
    //Initialize pins to Low on device start
    pinMode(bulb, OUTPUT);
    digitalWrite(bulb, LOW);


    pinMode(fan, OUTPUT);
    digitalWrite(fan, LOW);



      pinMode(television, OUTPUT);
    digitalWrite(television, LOW);



      pinMode(cooler, OUTPUT);
    digitalWrite(cooler, LOW);
    
    // Init serial port and clean garbage
    Serial.begin(SERIAL_BAUDRATE);
    Serial.println("FauxMo demo sketch");
    Serial.println("After connection, ask Alexa/Echo to 'turn <devicename> on' or 'off'");

    // Wifi
    wifiSetup();

    // Device Names for Simulated Wemo switches
    fauxmo.addDevice("bulb");
     fauxmo.addDevice("fan");
    fauxmo.addDevice("television");
    fauxmo.addDevice("cooler");
   
    fauxmo.onMessage(callback);
}

void loop() {
  fauxmo.handle();
}

