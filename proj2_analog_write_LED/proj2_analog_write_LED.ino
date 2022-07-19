
int button = 3;
int led = 2;

void setup() {
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  
}

void loop() {


  if ( digitalRead(button) == HIGH) {
    //if button is pressed then turn the led on
    digitalWrite(led, HIGH);
  
  }

  else{   
    //else the button is not pressed, turn if off
    digitalWrite(led, LOW);
  }


}
