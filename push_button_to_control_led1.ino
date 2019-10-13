int state =0;
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
}

void loop()
{
 int a= digitalRead(7);
  Serial.println(a);
  
  if(a==0){
  digitalWrite(13,LOW);

  
  }else if(a==1){
  	digitalWrite(13,HIGH);
    delay(5000);

  }
  
}