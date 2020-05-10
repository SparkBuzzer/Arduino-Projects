//https://www.youtube.com/watch?v=qIHbL_xOWgY
//Visit above link and support us on Youtube

const int trigPin = 10;
const int echoPin = 9;
const int buzzer = 8;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

float duration, distance;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("  cm ");    
  lcd.setCursor(0,0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm ");
  delay(200);


  if(distance<=20){
    digitalWrite(buzzer,HIGH);
    delay(500);
  }else{
    digitalWrite(buzzer,LOW);
  }
}
