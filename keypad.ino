#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>
Servo myservo;
int pos=0; 
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

const byte rows=4;
const byte cols=4;
 
char key[rows][cols]=
{
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9', 'C'},
{'*','0','#', 'D'},
};
byte rowPins[rows]={1,2,3,4};
byte colPins[cols]={5,6,7,8};
Keypad keypad= Keypad(makeKeymap(key),rowPins,colPins,rows,cols);
char* password="6949";
int currentposition=0;

int buzz=12;
//int invalidcount=12;
int invalidcount = 0;
int maxattempts = 3;
 
 
 
void setup()
{
lcd.begin(16,2);
displayscreen();
Serial.begin(9600);

pinMode(buzz, OUTPUT);
myservo.attach(9);
}
 
void loop()
{
if( currentposition==0)
{
displayscreen();
 
}
int l ;
char code=keypad.getKey();
if(code!=NO_KEY)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Enter password");
lcd.setCursor(7,1);
lcd.print(" ");
lcd.setCursor(7,1);
for(l=0;l<=currentposition;++l)
{
 
lcd.print("*");
keypress();
}
if (code==password[currentposition])
{
++currentposition;

if(currentposition==4)
{
invalidcount = 0;   // reset wrong attempts
unlockdoor();
currentposition=0;
}
}
  
//if (code==password[currentposition])
//{
//++currentposition;
//if(currentposition==4)
//{
 
//unlockdoor();
//currentposition=0;
 
//}
 
//}
 
//**else
//{
  
//++invalidcount;
//incorrect();
//currentposition=0;
//}
else
{
invalidcount++;

if(invalidcount >= maxattempts)
{
alarmLock();
invalidcount = 0;
}

else
{
incorrect();
}

currentposition = 0;
}  

}

}
void alarmLock()
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("SYSTEM LOCKED");

for(int i=0;i<10;i++)
{
digitalWrite(buzz,HIGH);
delay(300);
digitalWrite(buzz,LOW);
delay(300);
}

lcd.clear();
lcd.print("Try Again");
delay(3000);

displayscreen();
}



 
void unlockdoor()
{
delay(900);
 

lcd.setCursor(0,0);
lcd.print("Acess granted");
lcd.setCursor(0,1);
lcd.println("door unlocked!!!");

unlockbuzz();
 
for(pos = 180; pos>=0; pos-=5) 
{
myservo.write(pos); 
delay(5); 
}
delay(2000);
 
 
 
delay(1000);
counterbeep();
 
delay(1000);
 
for(pos = 0; pos <= 180; pos +=5)
{
myservo.write(pos); 
delay(50);
myservo.write(180);   
delay(300);  
 
 
currentposition=0;
 
lcd.clear();
displayscreen();
 
}
}
 

 
void incorrect()
{
delay(500);
lcd.clear();
lcd.setCursor(1,0);
lcd.print("NOPE");
lcd.setCursor(6,0);
lcd.print("INCORRECT");
lcd.setCursor(15,1);
lcd.println(" ");
lcd.setCursor(4,1);
lcd.println("WRONG!!!");
 
lcd.setCursor(13,1);
lcd.println(" ");
Serial.println("INCORRECT PASSWORD");

digitalWrite(buzz, HIGH);
delay(3000);
lcd.clear();

digitalWrite(buzz,LOW);
displayscreen();
}

void clearscreen()
{
lcd.setCursor(0,0);
lcd.println(" ");
lcd.setCursor(0,1);
lcd.println(" ");

}

void keypress()
{
digitalWrite(buzz, HIGH);
delay(50);
digitalWrite(buzz, LOW);
}

void displayscreen()
{
 
lcd.setCursor(0,0);
lcd.println("ENTER PASSWORD");
lcd.setCursor(1 ,1);
 
lcd.println("its of 4 digit!!");
}

void armservo()
{
 
for (pos=0;pos<=180;pos+=70)
{
myservo.write(pos);
delay(5);
}
delay(5000);
 
for(pos=180;pos>=0;pos-=70)
{
myservo.write(pos);
delay(25);  
myservo.write(185); 
delay(300);
}
 
}

void unlockbuzz()
{
 
digitalWrite(buzz, HIGH);//4 times called
delay(80);
digitalWrite(buzz, LOW);
delay(80);
digitalWrite(buzz, HIGH);
delay(80);
digitalWrite(buzz, LOW);
delay(200);
digitalWrite(buzz, HIGH);
delay(80);
digitalWrite(buzz, LOW);
delay(80);
digitalWrite(buzz, HIGH);
delay(80);
digitalWrite(buzz, LOW);
delay(80);
}
 

void counterbeep()
{
delay(1200);
 
 
lcd.clear();
digitalWrite(buzz, HIGH);
 
lcd.setCursor(2,15);
lcd.println(" ");
lcd.setCursor(2,14);
lcd.println(" ");
lcd.setCursor(2,0);
delay(200);
lcd.println("GET IN WITHIN:::");
 
lcd.setCursor(4,1);
lcd.print("5");
delay(200);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
digitalWrite(buzz,LOW);
delay(1000);

digitalWrite(buzz, HIGH);
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
lcd.setCursor(4,1); 
lcd.print("4");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
digitalWrite(buzz,LOW);
delay(1000);

digitalWrite(buzz, HIGH);
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
lcd.setCursor(4,1);
lcd.print("3");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
digitalWrite(buzz,LOW);
delay(1000);

digitalWrite(buzz, HIGH);
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
lcd.setCursor(4,1);
lcd.print("2");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
digitalWrite(buzz,LOW);
delay(1000);

digitalWrite(buzz, HIGH);
lcd.setCursor(4,1);
lcd.print("1");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN::");
digitalWrite(buzz,LOW);
delay(1000);

digitalWrite(buzz, HIGH);
delay(40);
digitalWrite(buzz,LOW);
delay(40);
digitalWrite(buzz, HIGH);
delay(40);
digitalWrite(buzz,LOW);
delay(40);
digitalWrite(buzz, HIGH);
delay(40);
digitalWrite(buzz,LOW);
delay(40);
digitalWrite(buzz, HIGH);
delay(40);
digitalWrite(buzz,LOW);
lcd.clear();
lcd.setCursor(2,0);
lcd.print("CLOSING");
delay(500);
lcd.setCursor(12,0);
lcd.print(".");
delay(500);
lcd.setCursor(13,0);
lcd.print(".");
delay(500);
lcd.setCursor(14,0);
lcd.print(".");
delay(400);
lcd.clear();
lcd.setCursor(4,0);
lcd.print("CLOSING!!");
delay(440);
armservo();  
}