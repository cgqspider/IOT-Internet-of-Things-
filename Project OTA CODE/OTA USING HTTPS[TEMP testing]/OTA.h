ESP8266WiFiMulti WiFiMulti;
 //ONE TIME SETUP 
 void OneTimeSetup()
 {
 // initialize digital pin LED_BUILTIN as an output.
   USE_SERIAL.begin(115200);
   // USE_SERIAL.setDebugOutput(true);

    USE_SERIAL.println();
    USE_SERIAL.println();
    USE_SERIAL.println();

    for(uint8_t t = 4; t > 0; t--) {
        USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
        USE_SERIAL.flush();
        delay(1000);
    }

    WiFiMulti.addAP("monu", "1234567890");
 }
//MAIN OTA CODE


void OTA(String URL, String FingerPrint)
{
    if((WiFiMulti.run() == WL_CONNECTED)) {
    
    Serial.println("*** Updating firmware!");
//https://www.grc.com/fingerprints.htm GET FINGERPRINT OF HTTPS WEBSITE FROM HERE......
    t_httpUpdate_return ret = ESPhttpUpdate.update(URL, "", FingerPrint);
    
    Serial.println("*** Done updating!");

    switch(ret) {
        case HTTP_UPDATE_FAILED:
            USE_SERIAL.printf("Updated FAILED (%d): %s", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
           
            break;

        case HTTP_UPDATE_NO_UPDATES:
            USE_SERIAL.println("No update needed!");
            break;

        case HTTP_UPDATE_OK:
            USE_SERIAL.println("Update OK!");
            break;
    }

    delay(1000);
    ESP.restart();
    delay(1000);
  }
  
  
  }
  
