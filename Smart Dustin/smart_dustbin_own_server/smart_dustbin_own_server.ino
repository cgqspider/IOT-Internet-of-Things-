#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const int trigPin = 4;  //D4
const int echoPin = 5;  //D3

long duration;
int distance,percentage;

 int  total_len;
const char* ssid = "monu";
const char* password = "";
 
void setup () {
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
total_len=19;
  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
    Serial.print("Connecting..");
 
  }
 
}
 
void loop() {


digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);
 
  percentage=(distance*100)/total_len; 


 
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
    HTTPClient http;  //Declare an object of class HTTPClient

   


 
    http.begin("http://reverenced-depositi.000webhostapp.com/insert.php?temp=3&hum="+String(percentage));  //Specify request destination
    int httpCode = http.GET();                                                                  //Send the request
 
    if (httpCode > 0) { //Check the returning code
 
      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);                     //Print the response payload
 
    }
 
    http.end();   //Close connection
 
  }


  delay(10000);    //Send a request every 30 seconds
 
}
