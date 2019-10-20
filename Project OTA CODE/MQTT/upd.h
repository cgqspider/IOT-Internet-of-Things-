void OTA()
{
 Serial.println("*** Updating firmware!");
//https://www.grc.com/fingerprints.htm GET FINGERPRINT OF HTTPS WEBSITE FROM HERE......
    t_httpUpdate_return ret = ESPhttpUpdate.update("https://narayanjha.000webhostapp.com/upload/MQTT.ino.d1.bin", "", "5B:FB:D1:D4:49:D3:0F:A9:C6:40:03:34:BA:E0:24:05:AA:D2:E2:01");
    
    Serial.println("*** Done updating!");

    switch(ret) {
        case HTTP_UPDATE_FAILED:
            Serial.printf("Updated FAILED (%d): %s", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
            break;

        case HTTP_UPDATE_NO_UPDATES:
            Serial.println("No update needed!");
            break;

        case HTTP_UPDATE_OK:
            Serial.println("Update OK!");
            break;
    }

    delay(1000);
    ESP.restart();
    delay(1000);
}
