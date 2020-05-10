//https://youtu.be/71R3N1eqL1E
//Visit above link and support us on Youtube

int flamesensor =8;
int buzzer = 12;
int redled = 5;
int greenled = 6;
int flame = LOW;

void setup() {
Serial.begin(9600);
pinMode(flamesensor,INPUT);
pinMode(buzzer,OUTPUT);
pinMode(redled,OUTPUT);
pinMode(greenled,OUTPUT);
}

void loop() {
flame = digitalRead(flamesensor);
if (flame == LOW){
  Serial.println("Fire Occured Please Be Safe");
  digitalWrite(redled,HIGH);
  digitalWrite(greenled,LOW);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
}
else{
  digitalWrite(redled,LOW);
  digitalWrite(greenled,HIGH);
  digitalWrite(buzzer,LOW);
}
}
