void setup() {
  analogWrite (3, 255);

}

void loop() {
  for (int k=0 ; k<255;k+=10)
  {
    analogWrite (3,k);
    delay(100);
  }

  for (int k=255 ; k>=0; k-=10)
  {
    analogWrite (3,k);
    delay(100);
  }
}
