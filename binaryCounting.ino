int arr[16][4]={
  {0,0,0,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,1,1},
  {0,1,0,0},
  {0,1,0,1},
  {0,1,1,0},
  {0,1,1,1},
  {1,0,0,0},
  {1,0,0,1},
  {1,0,1,0},
  {1,0,1,1},
  {1,1,0,0},
  {1,1,0,1},
  {1,1,1,0},
  {1,1,1,1},
              };

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  
}

void loop()
{
  for(int i=0; i<16; i++){
    for(int j=0; j<4; j++){
      digitalWrite(13-j, arr[i][j]);
    }delay(2000);
  }
  
 
}