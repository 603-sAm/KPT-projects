int IR = A5;
int led = 4;
int IRvalue = 0;
//boolean LEDStatus = false;

void setup() 
{

 pinMode(led,OUTPUT);
 pinMode(IR, INPUT);
 Serial.begin(9600);

}

void loop() {
  
//    int IRstatus = digitalRead(IR);
//   should use analog read because there are not only 0/1 
//    if (IRstatus == 1) 
//    {
//
//      if(LEDStatus==false){
//        LEDStatus=true;
//        digitalWrite(led, HIGH);
//    }
//    else {
//      LEDStatus=false;
//    digitalWrite(led, LOW);
//    }
//    }
//
int IRvalue = analogRead(IR);

  if (IRvalue > 1000)
 {
  digitalWrite (led, HIGH);
 }

 else
 {
  digitalWrite (led, LOW);
 }
 Serial.println(IRvalue);
  }

 
