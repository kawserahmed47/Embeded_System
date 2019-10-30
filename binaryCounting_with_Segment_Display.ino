int arr[10][4]={
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

              };

int a=9;
int b=8;
int c=7;
int d=6;
int e=5;
int f=4;
int g=3;
//int dp=2;


void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  
  
  
}

void loop()
{
  
  for(int i=0; i<10; i++){
    for(int j=0; j<4; j++){
      digitalWrite(13-j, arr[i][j]);
    }if(i==0){
      digitalWrite(a,1); 
 digitalWrite(b,1);  
 digitalWrite(c,1);  
 digitalWrite(d,1);  
 digitalWrite(e,1);  
 digitalWrite(f,1);  
 digitalWrite(g,0);
    
    }else if(i==1){
       digitalWrite(a,0); 
 digitalWrite(b,1);  
 digitalWrite(c,1);  
 digitalWrite(d,0);  
 digitalWrite(e,0);  
 digitalWrite(f,0);  
 digitalWrite(g,0);
    
    }else if(i==2){
       digitalWrite(a,1); 
 digitalWrite(b,1);  
 digitalWrite(c,0);  
 digitalWrite(d,1);  
 digitalWrite(e,1);  
 digitalWrite(f,0);  
 digitalWrite(g,1); 
    
    }
    
    else if(i==3){
     digitalWrite(a,1); 
 digitalWrite(b,1);  
 digitalWrite(c,1);  
 digitalWrite(d,1);  
 digitalWrite(e,0);  
 digitalWrite(f,0);  
 digitalWrite(g,1);
    
    }else if(i==4){
       digitalWrite(a,0); 
 digitalWrite(b,1);  
 digitalWrite(c,1);  
 digitalWrite(d,0);  
 digitalWrite(e,0);  
 digitalWrite(f,1);  
 digitalWrite(g,1); 
    
    }else if(i==5){
    digitalWrite(a,1); 
 digitalWrite(b,0);  
 digitalWrite(c,1);  
 digitalWrite(d,1);  
 digitalWrite(e,0);  
 digitalWrite(f,1);  
 digitalWrite(g,1); 
    }else if(i==6){
    digitalWrite(a,1); 
 digitalWrite(b,0);  
 digitalWrite(c,1);  
 digitalWrite(d,1);  
 digitalWrite(e,1);  
 digitalWrite(f,1);  
 digitalWrite(g,1);
    }else if(i==7){
      digitalWrite(a,1); 
 digitalWrite(b,1);  
 digitalWrite(c,1);  
 digitalWrite(d,0);  
 digitalWrite(e,0);  
 digitalWrite(f,0);  
 digitalWrite(g,0); 
    
    }else if(i==8){
       digitalWrite(a,1); 
 digitalWrite(b,1);  
 digitalWrite(c,1);  
 digitalWrite(d,1);  
 digitalWrite(e,1);  
 digitalWrite(f,1);  
 digitalWrite(g,1); 
    
    }else if(i==9){
      digitalWrite(a,1); 
 digitalWrite(b,1);  
 digitalWrite(c,1);  
 digitalWrite(d,1);  
 digitalWrite(e,0);  
 digitalWrite(f,1);  
 digitalWrite(g,1);
    
    }
    
    delay(2000);
  }
  
 
  
 
}