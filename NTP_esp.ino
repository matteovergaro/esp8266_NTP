// Written by Matteo Vergaro and Nicolò Vergaro

#include <ESP8266WiFi.h>
#include "time.h"
#include "TZ.h"

#define BAUDRATE 9600

// "SSID of your wifi"
const char* ssid       = "";
// "pwd of your wifi"
const char* password   = "";

// "ntp server", this is an italian ntp, you can change it
const char* ntpServer = "ntp1.inrim.it";

const long  gmtOffset_sec = 0;
const int   daylightOffset_sec = 0;

void setup() {
  Serial.begin(BAUDRATE);
  int i=0;
  while (WiFi.status() != WL_CONNECTED && i < 15) {
    Serial.print(".");
    i++;
    delay(500);
  }
  delay(2000);
  if(WiFi.status() == 6){
    //Serial.println("Trying again...");
    //Serial.printf("Connecting to %s ", ssid);
    WiFi.begin(ssid,password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
      }
  }
  
  Serial.print("CONNECTED with IP: ");
  Serial.println(WiFi.localIP());
  
  // to change the timezone https://github.com/esp8266/Arduino/blob/master/cores/esp8266/TZ.h
  configTime(TZ_Europe_Rome, ntpServer);

}

void loop() {
  time_t tnow = time(nullptr);
  Serial.print(String(ctime(&tnow)));
  delay(60000);
}