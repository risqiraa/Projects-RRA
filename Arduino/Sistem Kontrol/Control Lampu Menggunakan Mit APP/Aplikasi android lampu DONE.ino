#include <ThingSpeak.h>               // add librery
#include <ESP8266WiFi.h>

WiFiClient  client;
unsigned long counterChannelNumber =  1781052;                // Channel ID
const char * myCounterReadAPIKey = "QU44OWJD65LJGF2N";     // Read API Key
const int FieldNumber1 = 1;                                 // The field you wish to read
const int FieldNumber2 = 2;                                 // The field you wish to read
const int FieldNumber3 = 3; 
const int FieldNumber4 = 4; 
void setup()
{
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  Serial.begin(115200);
  Serial.println();

  WiFi.begin("ZTE_2.4G_NXqSPx", "12345678");                     // write wifi name & password           

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop() 
{
 int A = ThingSpeak.readLongField(counterChannelNumber, FieldNumber1, myCounterReadAPIKey);
 Serial.println(A);
 digitalWrite(D2,A);
 int B = ThingSpeak.readLongField(counterChannelNumber, FieldNumber2, myCounterReadAPIKey);
 Serial.println(B);
 digitalWrite(D3,B);
 int C = ThingSpeak.readLongField(counterChannelNumber, FieldNumber3, myCounterReadAPIKey);
 Serial.println(C);
 digitalWrite(D5,C);
 int D = ThingSpeak.readLongField(counterChannelNumber, FieldNumber4, myCounterReadAPIKey);
 Serial.println(D);
 digitalWrite(D6,D);
}
