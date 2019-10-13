void setup()
{
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
}

void loop()
{
  int var = analogRead(A0);
  int a = map(var,0,679,255,0);
  digitalWrite(13,a);
}