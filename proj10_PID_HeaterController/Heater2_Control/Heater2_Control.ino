/*#define AIN1 4
#define AIN2 5

double input;
double vol;
double setpoint;
double Kp=0, Ki=0, Kd=0;

PID myPID(&input, &vol, &setpoint,Kp, Ki, Kd, DIRECT); 

void setup() {
  Serial.begin(9600);
  setpoint = 2.05;
  myPID.SetMode(AUTOMATIC);
  myPID.SetTunings(Kp, Ki, Kd)
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {

  
  
  input = map(analogRead(A0), 0, 1024, 0, 255);
  vol = (input * 5.0 )/1024.0 ;
  myPID.Compute();
  /*i f (vol < 2.05){
    digitalWrite(AIN2,LOW);
  }
  else{
      digitalWrite(AIN2,HIGH);
  }
  Serial.print("Voltage :");
  Serial.println(vol);
}*/

#define AIN1 4
#define AIN2 5
double input, output, error, lastE;
double setpoint = 127;
double Kp = 5;
double Ki = 50;
double Kd = 14000;
int limMax = 255;
int limMin = 0;
double currentT, previousT;
double differE, integrateE, elapsedT;

void setup() {
  Serial.begin(9600);
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(A2, INPUT);
}

void loop() {
  currentT = millis();
  //Serial.print("currentT : "); Serial.println(currentT);
  elapsedT = currentT - previousT; 
  //Serial.print("previousT : "); Serial.println(previousT);
  elapsedT = (elapsedT); // 1000;//Second in unit
//  Serial.print("Correct T : "); Serial.println(elapsedT);
  input = map(analogRead(A2), 0, 1024, 0, 255);
  Serial.print("input value: "); Serial.println(input);
  
  error = -(setpoint - input);
  //Serial.print("error: "); Serial.println(error);
  
  integrateE += error * elapsedT;
  //Serial.print("integrate error: "); Serial.print(integrateE,);
  
  differE = error - lastE;
  differE = differE / elapsedT;
  //Serial.print("differential error: "); Serial.println(differE);
  
  output = Kp * error + Ki * integrateE + Kd * differE;
  if (output < limMin) {
    output = limMin;
    }
  
  else if (output > limMax) {
    output = limMax;
    }
    Serial.print("output value:"); Serial.println(output);

    previousT = currentT;
    lastE = error;
    
    analogWrite(AIN2, output);//voltage supply to the heater
    delay(10);
}
