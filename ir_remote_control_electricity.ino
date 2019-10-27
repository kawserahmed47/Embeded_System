#include <IRremote.h>

int RECV_PIN =2;
IRrecv irrecv(RECV_PIN);
decode_results results;
boolean s = false;
boolean t = false;
boolean u = false;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  	pinMode(7,OUTPUT);
   	pinMode(6,OUTPUT);
   	pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  
}

void loop()
{
  if (irrecv.decode(&results))
    {
     Serial.println(results.value, HEX);
     irrecv.resume(); // Receive the next value
    
    if(results.value==0xFD08F7){
      if(s== false){
        digitalWrite(3,HIGH);
    
        s= true;
      
      }else if(s==true){
         digitalWrite(3,LOW);
  
        s= false;
      
      }
    
      
    }
    else if(results.value==0xFD8877){
     if(t== false){
       
    digitalWrite(4,HIGH);
    
        t= true;
      
      }else if(t==true){
        
    digitalWrite(4,LOW);
    
        t= false;
      
      }
    
    }
    else if(results.value==0xFD48B7){
    
       if(u== false){
       
      digitalWrite(5,HIGH);
        u= true;
      
      }else if(u==true){
         
      digitalWrite(5,LOW);
        u= false;
      
      }
    
    }
  else{
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
   	digitalWrite(5,LOW);
  
  }
  }
}