int state =0;
int initial= 1000;

void setup()
{
  
  pinMode(13, OUTPUT);
}

void loop()
{
  int a= millis();
  
  if (a> initial){
    initial = initial + 1000;
    if(state==0){
    state = 1;
    digitalWrite(13, 1);
  
  }else{
  state=0;
    digitalWrite(13, 0);
    
  }
  }
}