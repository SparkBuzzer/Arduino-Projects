//#include <SoftwareSerial.h>
#include <ArduinoJson.h>   // json 5.3 library
#include "DHT.h"
//SoftwareSerial esp8266(0,1);

//
#define DHTPIN 9     // 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int i=0;
int r1= 5,r2= 6,r3= 7,r4= 8 ;      //relay



void setup(void) {
  Serial.begin(9600);
pinMode(r1,OUTPUT);
pinMode(r2,OUTPUT);
pinMode(r3,OUTPUT);
pinMode(r4,OUTPUT);
  dht.begin();      // dht11
}


void loop(void) {

DynamicJsonBuffer jsonS;  //jsonS for sending  to esp8266
JsonObject& soc = jsonS.createObject();



//******************************************
if(Serial.available()){
     DynamicJsonBuffer jsonR;    //jsonR for Receiving from esp8266
 JsonObject& doc = jsonR.parseObject(Serial);
if (doc == JsonObject::invalid())
  {
//    Serial.print("ERROR");
//    return;
  }

    // data received from esp8266
    int data2=doc["data2"];
   
   Serial.print("data2=");
    Serial.print(data2);
//    Serial.println("good format");


    // data received from esp8266 is compared to turn On/Off Relay


    if(doc["r1"] == "0") {
     digitalWrite(r1,LOW);
    }
    if(doc["r1"] == "1") {
     digitalWrite(r1,HIGH);     
    }
    if(doc["r2"] == "0") {
     digitalWrite(r2,LOW);
    }
    if(doc["r2"] == "1") {
     digitalWrite(r2,HIGH);
    }
    if(doc["r3"] == "0") {
     digitalWrite(r3,LOW);
    }
    if(doc["r3"] == "1") {
     digitalWrite(r3,HIGH);
    }
    if(doc["r4"] == "0") {
     digitalWrite(r4,LOW);
    }
    if(doc["r4"] == "1") {
     digitalWrite(r4,HIGH);
    }
    if(doc["type"] == "request") {

     soc["data1"] = i;
     soc.printTo(Serial); //data sent to esp8266
     i++;
     delay(1000);
    }

}

delay(1000);
}
  
