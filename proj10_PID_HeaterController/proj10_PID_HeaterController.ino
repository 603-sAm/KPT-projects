
#define AIN1 4
#define AIN2 5
double input, output, error, lastE;
double setpoint = 95;
double Kp = 50000;
double Ki = 1;
double Kd = 1;
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
  Serial.println(setpoint);
  
  currentT = millis();
//  Serial.print("currentT : "); Serial.println(currentT);
  elapsedT = currentT - previousT; 
//  Serial.print("previousT : "); Serial.println(previousT);
  elapsedT = (elapsedT); // 1000;//Second in unit
//  Serial.print("Correct T : "); Serial.println(elapsedT);
  input = map(analogRead(A2), 0, 1024, 0, 255);
  Serial.print("input value: "); Serial.println(input);
  
  error = -(setpoint - input);
//  Serial.print("error: "); Serial.println(error);
  
  integrateE += error * elapsedT;
//  Serial.print("integrate error: "); Serial.print(integrateE);
  
  differE = error - lastE;
  differE = differE / elapsedT;
//  Serial.print("differential error: "); Serial.println(differE);
  
  output = Kp * error + Ki * integrateE + Kd * differE;
  
  /*if (output < limMin) {
    output = limMin;
    }
  
  else if (output > limMax) {
    output = limMax;
    }*/
    Serial.print("output value:"); Serial.println(output);

    previousT = currentT;
    lastE = error;
    
    analogWrite(AIN2, output);//voltage supply to the heater
    delay(10);
}
