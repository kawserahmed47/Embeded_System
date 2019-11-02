void setup()
{
Serial.begin(9600);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(2,OUTPUT);
pinMode(A0,INPUT);
  
}

void loop()
{
  
  
  int a =analogRead(A0);
  Serial.println(a);
  
  if(a<20){
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  delay(500);
  
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  delay(500);
  
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  delay(500);
  
  }else{
    digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  
  }
  
 
    
 
}