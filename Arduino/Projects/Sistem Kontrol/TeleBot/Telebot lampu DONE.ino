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
//ssidwifi,passwod,dan token bot tele
String ssid = "HARIINNN";     // REPLACE mySSID WITH YOUR WIFI SSID
String pass = "00000000"; // REPLACE myPassword YOUR WIFI PASSWORD, IF ANY
String token = "5424171815:AAGYT8if_KMlM0KrPWr1yDG64oL227IT6D0";   // REPLACE myToken WITH YOUR TELEGRAM BOT TOKEN

//definisi variabel
uint8_t led1 = D2; //invert
uint8_t led2 = D3;
uint8_t led3 = D5;
uint8_t led4  = D6;             
                            
//inisial variabel global
String sttsled1 = "OFF";
String sttsled2 = "OFF";
String sttsled3 = "OFF";
String sttsled4 = "OFF";




void setup() {
	// Mengaktifkan Serial Monitor
	Serial.begin(115200);
	Serial.println("\n\n\n\n\nStarting TelegramBot...");

	// mengkoneksikan esp8266 ke wifi
	myBot.wifiConnect(ssid, pass);

	// set the telegram bot token
	myBot.setTelegramToken(token);

	// check koneksi wifi
	if (myBot.testConnection())
		Serial.println("\ntestConnection OK : "+ssid);
	else
		Serial.println("\ntestConnection NOK"+ssid);

	// set the pin connected to the LED to act as output pin
	pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
	digitalWrite(led1, LOW); // turn off the led (inverted logic!) karena D2 inverted logic!

}

void loop() {
	// a variable to store telegram message data
	TBMessage msg;

	// jika ada pesan masuk
	if (CTBotMessageText == myBot.getNewMessage(msg)) {

		if (msg.text.equalsIgnoreCase("L1 ON")) {                 // ketika pesan L1 ON
			digitalWrite(led1, HIGH);                               // Menyalakan lampu 1
      sttsled1 = "ON";     
      myBot.sendMessage(msg.sender.id, "Light 1 is now ON");  // notify the sender
      myBot.sendMessage(msg.sender.id, "STATUS LAMPU\n=================\nL1 = "+sttsled1+"\nL2 = "+sttsled2+"\nL3 = "+sttsled3+"\nL4 = "+sttsled4+"\n=================");        
		}
		else if (msg.text.equalsIgnoreCase("L1 OFF")) {           // ketika pesan L1 OFF
			digitalWrite(led1, LOW);                                // Mematikan lampu 1
      sttsled1 = "OFF";
			myBot.sendMessage(msg.sender.id, "Light 1 is now OFF"); // notify the sender
      myBot.sendMessage(msg.sender.id, "STATUS LAMPU\n=================\nL1 = "+sttsled1+"\nL2 = "+sttsled2+"\nL3 = "+sttsled3+"\nL4 = "+sttsled4+"\n=================");        
		}
    else if (msg.text.equalsIgnoreCase("L2 ON")) {            // ketika pesan L2 ON
			digitalWrite(led2, HIGH);                               // Meyalakan lampu 2
      sttsled2 = "ON";  
			myBot.sendMessage(msg.sender.id, "Light 2 is now ON");  // notify the sender
      myBot.sendMessage(msg.sender.id, "STATUS LAMPU\n=================\nL1 = "+sttsled1+"\nL2 = "+sttsled2+"\nL3 = "+sttsled3+"\nL4 = "+sttsled4+"\n=================");        
		}
    else if (msg.text.equalsIgnoreCase("L2 OFF")) {           // ketika pesan L2 ON
			digitalWrite(led2, LOW);                                // Mematikan lampu 2
      sttsled2 = "OFF";  
			myBot.sendMessage(msg.sender.id, "Light 2 is now OFF"); // notify the sender
      myBot.sendMessage(msg.sender.id, "STATUS LAMPU\n=================\nL1 = "+sttsled1+"\nL2 = "+sttsled2+"\nL3 = "+sttsled3+"\nL4 = "+sttsled4+"\n=================");        
		}
    else if (msg.text.equalsIgnoreCase("L3 ON")) {        
			digitalWrite(led3, HIGH);    
      sttsled3 = "ON";                            
			myBot.sendMessage(msg.sender.id, "Light 3 is now ON"); // notify the sender
      myBot.sendMessage(msg.sender.id, "STATUS LAMPU\n=================\nL1 = "+sttsled1+"\nL2 = "+sttsled2+"\nL3 = "+sttsled3+"\nL4 = "+sttsled4+"\n=================");        
		}
    else if (msg.text.equalsIgnoreCase("L3 OFF")) {        
			digitalWrite(led3, LOW);                              
      sttsled3 = "OFF";  
			myBot.sendMessage(msg.sender.id, "Light 3 is now OFF"); // notify the sender
      myBot.sendMessage(msg.sender.id, "STATUS LAMPU\n=================\nL1 = "+sttsled1+"\nL2 = "+sttsled2+"\nL3 = "+sttsled3+"\nL4 = "+sttsled4+"\n=================");        
		}
    else if (msg.text.equalsIgnoreCase("L4 ON")) {        
			digitalWrite(led4, HIGH);                              
      sttsled4 = "ON";
			myBot.sendMessage(msg.sender.id, "Light 4 is now ON"); // notify the sender
      myBot.sendMessage(msg.sender.id, "STATUS LAMPU\n=================\nL1 = "+sttsled1+"\nL2 = "+sttsled2+"\nL3 = "+sttsled3+"\nL4 = "+sttsled4+"\n=================");        
		}
    else if (msg.text.equalsIgnoreCase("L4 OFF")) {        
			digitalWrite(led4, LOW);                              
      sttsled4 = "OFF";
			myBot.sendMessage(msg.sender.id, "Light 4 is now OFF"); // notify the sender
      myBot.sendMessage(msg.sender.id, "STATUS LAMPU\n=================\nL1 = "+sttsled1+"\nL2 = "+sttsled2+"\nL3 = "+sttsled3+"\nL4 = "+sttsled4+"\n=================");        
		}
    else if (msg.text.equalsIgnoreCase("ALL OFF")) {        
			digitalWrite(led1, LOW);        
      digitalWrite(led2, LOW);            
      digitalWrite(led3, LOW);            
      digitalWrite(led4, LOW);                                  
      sttsled1 = "OFF";
      sttsled2 = "OFF";
      sttsled3 = "OFF";
      sttsled4 = "OFF";
			myBot.sendMessage(msg.sender.id, "ALL Light is now OFF"); // notify the sender
      myBot.sendMessage(msg.sender.id, "STATUS LAMPU\n=================\nL1 = "+sttsled1+"\nL2 = "+sttsled2+"\nL3 = "+sttsled3+"\nL4 = "+sttsled4+"\n=================");        
		}
    else if (msg.text.equalsIgnoreCase("ALL ON")) {        
			digitalWrite(led1, HIGH);                              
      digitalWrite(led2, HIGH);                              
      digitalWrite(led3, HIGH);                              
      digitalWrite(led4, HIGH);                              
      sttsled1 = "ON";
      sttsled2 = "ON";
      sttsled3 = "ON";
      sttsled4 = "ON";
			myBot.sendMessage(msg.sender.id, "ALL Light is now ON"); // notify the sender
      myBot.sendMessage(msg.sender.id, "STATUS LAMPU\n=================\nL1 = "+sttsled1+"\nL2 = "+sttsled2+"\nL3 = "+sttsled3+"\nL4 = "+sttsled4+"\n=================");        
		}
		else {                                                    // otherwise...
			// generate the message for the sender
			String reply;
			reply = (String)"Welcome " + msg.sender.username + (String)"\n===================\nL1 = Lampu 1\nL2 = Lampu 2\nL3 = Lampu 3\nL4 = Lampu 4\nALL = Semua Lampu\n===================";
			myBot.sendMessage(msg.sender.id, reply);             // and send it
		}
	}
  
	// wait 500 milliseconds
	delay(100);
}
