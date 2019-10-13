void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(A0,INPUT);
}

void loop()
{
  int a = analogRead(A0);
  int b= map(a,0,1023,0,255);
  digitalWrite(13,b);
  Serial.println(a);
}