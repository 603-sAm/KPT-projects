
                        
const int AIN1 = 5;
const int AIN2 = 4;
                        
const int BIN1 = 2;
const int BIN2 = 1;

void setup()
{
                        // Motor A : set all pins as output
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);


                        // Motor B : set all pins as output
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

}

void loop()
{
                        //drive forward at full speed by pulling AIN1/BIN1 High
                        //and AIN2/BIN2 low, while writing a full 255 to PWMA/PWMB to
                        //control speed
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);


  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);


                        //wait 1 second
  delay(1000);

                        //Brake the motorS by pulling both direction pins to
                        //the same state (in this case LOW). PWMA/PWMB doesn't matter
                        //in a brake situation, but set as 0.
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);


                        //wait 1 second
  delay(1000);

                        //change direction to reverse by flipping the states
                        //of the direction pins from their forward state at lower speed
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);


                        //wait 1 second
  delay(1000);

                        //Brake again
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);


                        //wait 1 second
  delay(1000);
}
