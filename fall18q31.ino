#include <Servo.h>
Servo serv;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  serv.attach(11);
}

void loop()
{
  digitalWrite(13,0);
  delay(10);
  digitalWrite(13,1);
  delay(10);
  digitalWrite(13,0);
  
  float a=pulseIn(12,1);
  a=a/29/2;
 Serial.println(a);
  
  if(a<50){
    serv.write(90);
  
  }else{
  serv.write(0);
  }
  
  
}