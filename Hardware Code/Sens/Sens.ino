
/*
 * Created by K. Suwatchai (Mobizt)
 * 
 * Email: k_suwatchai@hotmail.com
 * 
 * Github: https://github.com/mobizt
 * 
 * Copyright (c) 2019 mobizt
 *
*/


//FirebaseESP8266.h must be included before ESP8266WiFi.h
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "spaid-54734.firebaseio.com"
#define FIREBASE_AUTH "Firebase Secret"
#define WIFI_SSID "theSSID"
#define WIFI_PASSWORD "thePassword"

//Define FirebaseESP8266 data object
FirebaseData firebaseData;


  const int trigPin = 5;  //D1
  const int echoPin = 4;  //D2 

  long duration;
  int distance;

void setup()
{

  Serial.begin(115200);


  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);



  if (Firebase.updateNode(firebaseData, "/Lake", "{\"Block1\":\"No\"")) {

  

} else {
  //Failed, then print out the error detail
  Serial.println(firebaseData.errorReason());
}

  String jsonStr = "";
 
  
}

void loop()
{

digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(200);


if(distance<15)
{
  if (Firebase.updateNode(firebaseData, "/Lake", "{\"Block1\":\"Yes\"}"))
  {}
  else {
  //Failed, then print out the error detail
  Serial.println(firebaseData.errorReason());
}
  
}
else
{
  if (Firebase.updateNode(firebaseData, "/Lake", "{\"Block1\":\"No\"}"))
  {}
  else {
  //Failed, then print out the error detail
  Serial.println(firebaseData.errorReason());
}

}
  
  
}
