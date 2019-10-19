#include <Servo.h>
Servo serv;

void setup()
{
Serial.begin(9600);
pinMode(8, OUTPUT);
pinMode(7, INPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(10,INPUT);
serv.attach(2);
  
}
void loop(){
  digitalWrite(8,0);
  delay(10);
  digitalWrite(8,1);
  delay(10);
  digitalWrite(8,0);
  int b= digitalRead(10);
  float a= pulseIn(7,1);
  
  a= a/29/2;
  Serial.println(a);
  if(a<=20){ 
   // int b= digitalRead(10);
    Serial.println(b);
    if(b==1){
      serv.write(90);
    }else if(b==0){
      serv.write(0);
    }
    
    digitalWrite(12,1);
    digitalWrite(13,0);
    
  }else{
    serv.write(0);
    digitalWrite(13,1);
    digitalWrite(12,0);
    
  }
 
  
  
}