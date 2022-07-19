int led = 11;

void setup() {
  pinMode(led, OUTPUT);  //LED
}

void loop() {

digitalWrite(led, HIGH);
delay(2000);
analogWrite(led,128);
delay(2000);
digitalWrite(led, LOW);
delay(2000);
  }
