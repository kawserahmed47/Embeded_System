void setup()
{
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(A0,INPUT);
}

void loop()
{
  
  float temp =analogRead(A0);
  temp = temp * 0.48828125;
 
  Serial.println(temp);
 
  if(temp>60){
    int num_of_students= Serial.read();
    if(num_of_students>15){
    digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
    }else if(num_of_students==0){
    digitalWrite(11, LOW);
   digitalWrite(12, LOW);
  
    }
  
  
  
  }else{
    digitalWrite(11, LOW);
   digitalWrite(12, LOW);
  
  }
}