#include <Servo.h> 
Servo serv1, serv2;
char g;
void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
   pinMode(8, INPUT);
  serv1.attach(9);
  serv2.attach(10);
 
  pinMode(11, OUTPUT);
   pinMode(12, INPUT);
  //pinMode(13, INPUT);
   
}

void loop()
{
   if(Serial.available()>0){
    
    
   g = Serial.read();}
   
	int a = digitalRead(12);
  Serial.println(a);
  if(a== 1){
  	digitalWrite(2,1);
    if(g=='f'){
      Serial.print(g);
   
     digitalWrite(6,HIGH);
      delay(1000);
    }else if(g=='l'){
    
      digitalWrite(6,LOW);
      Serial.print(g);
      delay(1000);
    }
    
    
    
    
    digitalWrite(7,0);
    delay(10);
    digitalWrite(7,1);
    delay(10);
    digitalWrite(7,0);
    float b= pulseIn(8,1);
    b= b/29/2;
    if (b<30 ){
      digitalWrite(3,1);
    	char c = Serial.read();
      switch (c) {
   
    case '2':    
      Serial.println("Hit From Front");
        digitalWrite(4,HIGH);
        serv1.write(90);
        
        
      break;
    case '3':    
      Serial.println("Hit Back From Front");
        digitalWrite(4,LOW);
        serv1.write(0);
      break;
    case '4':    
      Serial.println("Hit From Back");
        digitalWrite(5,HIGH);
        serv2.write(90);
        
      break;
     case '5':    
      Serial.println("Hit From Back");
        digitalWrite(5,LOW);
        serv2.write(0);
      break;
  }//switch c
      
      if(b<15){
      
      serv1.write(90);
        digitalWrite(4, HIGH);
        delay(500);
        serv1.write(0);
        digitalWrite(4, LOW);
        delay(500);
        
      }
      
      
    }// if b<30
    else if(b>30){
    digitalWrite(3,0);
    }//else if b>30
    
  }//if a==1 
  else if(a==0){
  
  
  } //elseif a==0
    
}//loop