#include <Arduino.h>

#include <ThingerESP8266.h>

#define USERNAME "purnimasinha"
#define DEVICE_ID "IPCS"
#define DEVICE_CREDENTIAL "TmOJQrO1$#CL"

#define SSID "puru"
#define SSID_PASSWORD "1234567890puru"

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  thing.add_wifi(SSID, SSID_PASSWORD);

  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  thing["led"] << digitalPin(LED_BUILTIN);

  // resource output example (i.e. reading a sensor value)
  thing["millis"] >> outputValue(millis());

  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  thing.handle();
}