
#include <Servo.h>

//LED For Signal
int red = 2;
int yellow = 3;
int green = 4;

//Servo Motors For Hit
Servo servFront, servBack;

//DC Motors For Wheel
int motor_1_Front= 7;
int motor_1_Back= 8;
int motor_2_Front= 9;
int motor_2_Back= 10;
int ena = 13;
//Ultrasonic Distance Sensor
int trig = 11;
int echo = 12;

//Some necessary Variable
float distance;
char input;

void setup() {
Serial.begin(9600);
//LED pin Setup
 pinMode(red,OUTPUT);
 pinMode(yellow,OUTPUT);
 pinMode(green,OUTPUT);

 //Servo Motors pin Setup
 servFront.attach(5);
 servBack.attach(6);
 
 //Dc Motors pin Setup
 pinMode(motor_1_Front,OUTPUT);
 pinMode(motor_1_Back,OUTPUT);
 pinMode(motor_2_Front,OUTPUT);
 pinMode(motor_2_Back,OUTPUT);
 pinMode(ena,OUTPUT);

 //Ultrasonic Distance Sensor pin Setup
 pinMode(trig,OUTPUT);
 pinMode(echo,INPUT);
     

}

void loop() {
    //IF get code Signal Light Red Will be on
  digitalWrite(red,HIGH);
  
  //Distance Measurement Using Ultrasonic Distance Sensore Control
  digitalWrite(trig,LOW);
  delay(10);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  distance=pulseIn(echo,HIGH);
  distance= distance/29/2;
  Serial.println(distance);//For Serial Print the value of distance


//input from bluetooth or serial
  if(Serial.available() > 0){
    input =Serial.read();
}

//For Driving with Dc motors
switch(input){

  case 'F':
  digitalWrite(motor_1_Front, HIGH);
  digitalWrite(motor_1_Back, LOW);
  digitalWrite(ena,HIGH);
  digitalWrite(motor_2_Front, HIGH);
  digitalWrite(motor_2_Back, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(yellow, LOW);
  break;
  
  case 'B':
  digitalWrite(motor_1_Front, LOW);
  digitalWrite(motor_1_Back, HIGH);
  digitalWrite(ena,HIGH);
  digitalWrite(motor_2_Front, LOW);
  digitalWrite(motor_2_Back, HIGH);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  break;
  
  case 'S':
  digitalWrite(motor_1_Front, LOW);
  digitalWrite(motor_1_Back, LOW);
  digitalWrite(ena,LOW);
  digitalWrite(motor_2_Front, LOW);
  digitalWrite(motor_2_Back, LOW);
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  
  }

  


  //For Fighting Hit with Servo Motors
    if(distance < 50){
      	servFront.write(0);
        servBack.write(0);
      switch(input){
        case '1':
        servFront.write(90);
        servBack.write(0);
        digitalWrite(yellow,HIGH);
        break;
        case '2':
        servFront.write(0);
        servBack.write(0);
        digitalWrite(yellow,LOW);
        break;
        case '3':
        servFront.write(0);
        servBack.write(90);
        digitalWrite(yellow,HIGH);
        break;
        
        }

        if(distance < 20){
          
          digitalWrite(yellow,HIGH);
          digitalWrite(red,LOW);
          servFront.write(90);
          delay(200);
          digitalWrite(yellow,LOW);
          digitalWrite(red,LOW);
          servFront.write(0);
          delay(200);
         
          
          }
      
      
      }else if(distance>30){
        servFront.write(0);
        servBack.write(0);
        
        }

}