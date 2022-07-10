#include <NTPClient.h>
// change next line to use with another board/shield
#include <ESP8266WiFi.h>
//#include <WiFi.h> // for WiFi shield
//#include <WiFi101.h> // for WiFi 101 shield or MKR1000
#include <WiFiUdp.h>
#include "CTBot.h"
CTBot myBot;

String ssid = "HARIINNN";     // REPLACE mySSID WITH YOUR WIFI SSID
String pass = "00000000"; // REPLACE myPassword YOUR WIFI PASSWORD, IF ANY
String token = "5424171815:AAGYT8if_KMlM0KrPWr1yDG64oL227IT6D0";   // REPLACE myToken WITH YOUR TELEGRAM BOT TOKEN


WiFiUDP ntpUDP;

// You can specify the time server pool and the offset (in seconds, can be
// changed later with setTimeOffset() ). Additionally you can specify the
// update interval (in milliseconds, can be changed using setUpdateInterval() ).
NTPClient timeClient(ntpUDP, "id.pool.ntp.org", 3600, 60000);

void setup(){
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() {
  timeClient.update();
  // a variable to store telegram message data
	TBMessage msg;
  
  Serial.println(timeClient.getFormattedTime());

  delay(1000);
}
