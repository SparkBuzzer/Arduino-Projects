int pwmled = 11;


void setup() {
  Serial.begin(9600);
  pinMode(pwmled,OUTPUT);
  pinMode(pot,INPUT);
}

void loop() {
   potvalue = analogRead(pot);
  analogWrite(pwmled,potvalue/4);
  delay(50);
  Serial.print("Value=");
  Serial.println(potvalue);
  }
