/*
Name:        lightBot.ino
Created:     17/01/2018
Author:      Stefano Ledda <shurillu@tiscalinet.it>
Description: a simple example that do:
             1) parse incoming messages
             2) if "LIGHT ON" message is received, turn on the onboard LED
             3) if "LIGHT OFF" message is received, turn off the onboard LED
             4) otherwise, reply to sender with a welcome message

*/
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
const long utcOffsetInSeconds = 25200;

WiFiUDP ntpUDP;

uint8_t led = 2;            // the onboard ESP8266 LED.    
                            // If you have a NodeMCU you can use the BUILTIN_LED pin
                            // (replace 2 with BUILTIN_LED)							

NTPClient timeClient(ntpUDP, "id.pool.ntp.org", utcOffsetInSeconds);

void setup() {
	// initialize the Serial
	Serial.begin(115200);
	Serial.println("Starting TelegramBot...");

	// connect the ESP8266 to the desired access point
	myBot.wifiConnect(ssid, pass);

	// set the telegram bot token
	myBot.setTelegramToken(token);

	// check if all things are ok
	if (myBot.testConnection())
		Serial.println("\ntestConnection OK");
	else
		Serial.println("\ntestConnection NOK");

	// set the pin connected to the LED to act as output pin
	pinMode(led, OUTPUT);
	digitalWrite(led, HIGH); // turn off the led (inverted logic!)


  timeClient.begin();
}

void loop() {
	timeClient.update();
  // a variable to store telegram message data
	TBMessage msg;

	// if there is an incoming message...
	if (CTBotMessageText == myBot.getNewMessage(msg)) {

		if (msg.text.equalsIgnoreCase("LIGHT ON")) {              // if the received message is "LIGHT ON"...
			digitalWrite(led, LOW);                               // turn on the LED (inverted logic!)
			myBot.sendMessage(msg.sender.id, "Light is now ON pada pukul : "+timeClient.getFormattedTime());  // notify the sender
		}
		else if (msg.text.equalsIgnoreCase("LIGHT OFF")) {        // if the received message is "LIGHT OFF"...
			digitalWrite(led, HIGH);                              // turn off the led (inverted logic!)
			myBot.sendMessage(msg.sender.id, "Light is now OFF pada pukul : "+timeClient.getFormattedTime()); // notify the sender
		}
		else {                                                    // otherwise...
			// generate the message for the sender
			String reply;
			reply = (String)"Welcome " + msg.sender.username + (String)". Try LIGHT ON or LIGHT OFF.";
			myBot.sendMessage(msg.sender.id, reply);             // and send it
		}
	}
	// wait 500 milliseconds
	delay(500);
}
