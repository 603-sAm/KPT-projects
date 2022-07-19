#include <PID_v1.h>
#define AIN1 4
#define AIN2 5

double vol;
double input;
double output;
double setpoint;
double Kp=5, Ki=2, Kd=0.1;

PID myPID(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT); 

void setup() {
  Serial.begin(9600);
  setpoint = 419;
  myPID.SetMode(AUTOMATIC);
  myPID.SetTunings(Kp, Ki, Kd);
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  
  input = analogRead(A0);
  //vol = (input * 5.0 )/1024.0 ;
  myPID.Compute();
  //analogWrite(AIN2 ,output);
  if (input < 419){
    digitalWrite(AIN2,LOW);
  }
  else{
      digitalWrite(AIN2,HIGH);
  }
  //Serial.print("input ");
  //thermister
  Serial.print(input);
  Serial.print(',');
  //Serial.print(" "); 
  //Serial.print("output ");
  //voltage analog
  Serial.println(output);
  //Serial.print(" "); 
  //Serial.print("setpoint ");
 // Serial.println(setpoint);

}

/*#define AIN1 4
#define AIN2 5
int i;

void setup() {
  Serial.begin(9600);
  
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);  
}
 
void loop() {
  for(int i=0; i<255; i++){
    analogWrite(AIN1, i);
    delay(10);
    Serial.println(i);
  }
  for(int i=255; i>0; i--){
    analogWrite(AIN1, i);
    delay(10);
    Serial.println(i);

  }
}*/
