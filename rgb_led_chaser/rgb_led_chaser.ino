int ledpin;
int pot = A0;

void setup() {
for(ledpin=2;ledpin<=8;ledpin++){
  pinMode(ledpin,OUTPUT);
 }
}
void loop() {
  for(ledpin=2;ledpin<=8;ledpin++){
  int value = analogRead(pot);
  digitalWrite(ledpin,HIGH);
  delay(value);
  }
    for(ledpin=2;ledpin<=8;ledpin++){
      int value = analogRead(pot);
  digitalWrite(ledpin,LOW);
  delay(value);
  }
}
