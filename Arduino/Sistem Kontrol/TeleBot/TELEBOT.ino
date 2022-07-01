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
#include "CTBot.h"
CTBot myBot;

String ssid = "HARIINNN";     // REPLACE mySSID WITH YOUR WIFI SSID
String pass = "00000000"; // REPLACE myPassword YOUR WIFI PASSWORD, IF ANY
String token = "5424171815:AAGYT8if_KMlM0KrPWr1yDG64oL227IT6D0";   // REPLACE myToken WITH YOUR TELEGRAM BOT TOKEN

String sttsled1 = "OFF";
int jmlonled1;


uint8_t led1 = D2;            // the onboard ESP8266 LED.    
                            // If you have a NodeMCU you can use the BUILTIN_LED pin
                            // (replace 2 with BUILTIN_LED)							

void setup() {
	// initialize the Serial
	Serial.begin(115200);
	Serial.println("\n\n\nStarting RRABot...");

	// connect the ESP8266 to the desired access point
	myBot.wifiConnect(ssid, pass);

	// set the telegram bot token
	myBot.setTelegramToken(token);

	// check if all things are ok
	if (myBot.testConnection())
		Serial.println("\nCONNECTED");
	else
		Serial.println("\nDISCONNECTED");

	// set the pin connected to the LED to act as output pin
	pinMode(led1, OUTPUT);
	digitalWrite(led1, LOW); // turn off the led (inverted logic!)
  
}

void loop() {
	// a variable to store telegram message data
	TBMessage msg;

	// if there is an incoming message...
	
		if (sttsled1 == "OFF"){
      if (CTBotMessageText == myBot.getNewMessage(msg)) {
        if (msg.text.equalsIgnoreCase("L1 ON")) {              // if the received message is "LIGHT ON"...
          digitalWrite(led1, HIGH);                              // turn off the led (inverted logic!)
          sttsled1 = "ON";
          jmlonled1 = jmlonled1+1;
          myBot.sendMessage(msg.sender.id, "Lampu 1 - NYALA\nTelah Menyala "+(String)jmlonled1+" Kali"); // notify the sender  
        }else if(msg.text.equalsIgnoreCase("L1 OFF")) {              // if the received message is "LIGHT ON"...
          digitalWrite(led1, LOW);                              // turn off the led (inverted logic!)
          sttsled1 = "OFF";
          jmlonled1 = jmlonled1;
          myBot.sendMessage(msg.sender.id, "Lampu 1 - MATI\nTelah Menyala "+(String)jmlonled1+" Kali"); // notify the sender  
        }
      }   
    }else if (sttsled1 == "ON"){
      if (CTBotMessageText == myBot.getNewMessage(msg)) {
        if (msg.text.equalsIgnoreCase("L1 ON")) {              // if the received message is "LIGHT ON"...
          digitalWrite(led1, HIGH);                              // turn off the led (inverted logic!)
          sttsled1 = "ON";
          jmlonled1 = jmlonled1;
          myBot.sendMessage(msg.sender.id, "Lampu 1 - NYALA\nTelah Menyala "+(String)jmlonled1+" Kali"); // notify the sender  
        }else if(msg.text.equalsIgnoreCase("L1 OFF")) {              // if the received message is "LIGHT ON"...
          digitalWrite(led1, LOW);                              // turn off the led (inverted logic!)
          sttsled1 = "OFF";
          jmlonled1 = jmlonled1;
          myBot.sendMessage(msg.sender.id, "Lampu 1 - MATI\nTelah Menyala "+(String)jmlonled1+" Kali"); // notify the sender  
        }
      }   
    }else {                                                    // otherwise...
         
      }
	
	// wait 500 milliseconds
	delay(500);
}
