#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>
#include "upd.h"

int pirPin = D7;
int val;
 
const char* ssid = "monu";
const char* password =  "1234567890";
const char* mqttServer = "soldier.cloudmqtt.com";
const int mqttPort = 18269;
const char* mqttUser = "nrfmmlmy";
const char* mqttPassword = "N9vGWSSTpTxp";
 
WiFiClient espClient;
PubSubClient client(espClient);
 
void setup() {
 
  Serial.begin(115200);
  
  pinMode(LED_BUILTIN, OUTPUT);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
 
  client.publish("/OTA", "Firmware Upgrade success!");
  client.subscribe("/OTA");
 
}
 
void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
 String Msg="";
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    //Serial.print((char)payload[i]);
    Msg+=(char)payload[i];
  }
  if(Msg=="Ota message to Esp8266"){
     client.publish("/OTA", "Firmware Upgrade Request Accepted!");
    Serial.print("Change the firmware");
    delay(1000);
     OTA();
    }
  
 
  Serial.println();
  Serial.println("-----------------------");
 
}
 
void loop() {
  val = digitalRead(pirPin);
//low = no motion, high = motion
if (val == HIGH)
{
  Serial.println("No motion");
}
else
{
  Serial.println("Motion detected  ALARM");
}
   digitalWrite(LED_BUILTIN, LOW);
  client.loop();
}
