void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  char var = Serial.read();
  if(var=='o'){
  digitalWrite(13,1);
  }else if(var== 'f'){
  digitalWrite(13,0);}
  
}