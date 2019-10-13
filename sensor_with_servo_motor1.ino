#include <Servo.h>
Servo serv;

void setup()
{
Serial.begin(9600);
pinMode(8, OUTPUT);
pinMode(7, INPUT);
serv.attach(2);
  
}
void loop(){
  digitalWrite(8,0);
  delay(10);
  digitalWrite(8,1);
  delay(10);
  digitalWrite(8,0);
  
  float a= pulseIn(7,1);
  
  a= a/29/2;
  Serial.println(a);
  if(a<=20){ 
    serv.write(90);
  }else{
    serv.write(0);
  }
 
  
  
}