int ledpin;
int pot = A0;
int value;
void setup() {
for(ledpin=2;ledpin<=13;ledpin++){
  pinMode(ledpin,OUTPUT);
 }
}
void loop() {
  for(ledpin=2;ledpin<=13;ledpin++){
    value = analogRead(pot);
  digitalWrite(ledpin,HIGH);
  delay(value);
  }
    for(ledpin=2;ledpin<=13;ledpin++){
       value = analogRead(pot);
  digitalWrite(ledpin,LOW);
  delay(value);
  }
}
