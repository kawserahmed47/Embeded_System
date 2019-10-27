#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>
Servo serv;

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

#define KEYPAD_ROW 4
#define KEYPAD_COLS 4

char* password ="1234"; //create a password
int pozisyon = 0; //keypad position

char keys[KEYPAD_ROW][KEYPAD_COLS]={

  {'1','2','3','A' },
     {'4','5','6','B' },
     {'7','8','9','C' },
     {'*','0','#','D' },

};

byte rowPins[]={5,4,3,2};
byte colPins[]={6,7,8,9};

Keypad kpd(
	makeKeymap(keys),
  	rowPins, colPins,
  	KEYPAD_ROW, KEYPAD_COLS
  	
);

void setup()
{
  lcd.begin(16,2);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  setLocked (true); //state of the password
  serv.attach(10);
}

void loop()
{
 /* char key = kpd.getKey();
  if(key){
    lcd.print(key);  
  }*/
  
  
  char whichKey = kpd.getKey(); //define which key is pressed with getKey

  lcd.setCursor(0, 0);
  lcd.print("    Welcome");
  lcd.setCursor(0, 1);
  lcd.print(" Enter Password");

  if(whichKey == '*' || whichKey == '#' || whichKey == 'A' ||       //define invalid keys
  whichKey == 'B' || whichKey == 'C' || whichKey == 'D'){

    pozisyon=0;
    setLocked (true);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Invalid Key!");
    delay(1000);
    lcd.clear();
  }
  if(whichKey == password [pozisyon]){

    pozisyon ++;
  }
  if(pozisyon == 4){
    setLocked (false);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("*** Verified ***");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Please Enter");
    lcd.setCursor(0, 1);
    lcd.print("Thanks");
    delay(7000);
    lcd.clear();
     setLocked (true);
    
   
  }
  delay(100);
  
  
  

}


void setLocked(int locked){
  if(locked){
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    serv.write(90);
    }
    else{
      digitalWrite(13, LOW);
      digitalWrite(12, HIGH);
       serv.write(0);
    }
  }

