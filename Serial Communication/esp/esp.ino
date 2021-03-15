//#include <SoftwareSerial.h>
//SoftwareSerial s(12,14); //(D6,D5);
#include <ArduinoJson.h>
//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
{
  Serial.begin(9600);
// 
//  lcd.begin();
//  lcd.home();
//  lcd.print("Hello, Hydroponics");
//  delay(1000);
 
}
int i =100 ;
void loop(void)
{
 DynamicJsonBuffer jsonS;
 DynamicJsonBuffer jsonR;

 JsonObject& doc = jsonS.createObject();
doc["type"] = "request";

doc.printTo(Serial);

 
 if(Serial.available()>0)
{
  JsonObject& roc = jsonR.parseObject(Serial);
if (roc == JsonObject::invalid())
  {
    return;
  }
  int data1=roc["data"];
    Serial.print("data1=");
    Serial.println(data1);


}
Serial.flush();
doc["r1"] = 1;

doc.printTo(Serial);

Serial.flush();
doc["r1"] = 0;

doc.printTo(Serial);
  
delay(1000);

}
