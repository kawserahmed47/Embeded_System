#include <IRremote.h>

int RECV_PIN =2;
IRrecv irrecv(RECV_PIN);
decode_results results;

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
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      
    }
    else if(results.value==0xFD8877){digitalWrite(7,LOW);
                                    digitalWrite(3,HIGH);
                                    digitalWrite(5,LOW);}
    else if(results.value==0xFD48B7){digitalWrite(7,LOW);
                                    digitalWrite(6,LOW);
                                    digitalWrite(4,HIGH);}
  else{
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
   	digitalWrite(5,LOW);
  
  }
  }
}