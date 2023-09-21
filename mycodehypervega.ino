#include <Servo.h>
char t;
Servo myservo;  
#define servoPin 3 
#define pushButtonPin 2 

int angle =0;    

int buttonPushed =0;

void setup() {
  Serial.begin(9600);         
  myservo.attach(servoPin); 
  pinMode(pushButtonPin,INPUT_PULLUP);
   myservo.write(0);
}

void loop() {
  if(digitalRead(pushButtonPin) == LOW){
    buttonPushed = 1;
  }
  
  if( buttonPushed == 1){
    if((angle == 180))
  {
    myservo.write(0);
    angle=0;
    Serial.println(angle);
    delay(1000);
 
  }
  else if(angle == 0)
  {
    myservo.write(180);
    angle=180;
    Serial.println(angle);
    delay(1000);
    
  }
  else
  {
    myservo.write(0);
    angle=0;
    Serial.println(angle);
    delay(1000);
  }
      buttonPushed=0;
  }


  if(Serial.available())
  { 
    t = Serial.read();
    Serial.println(t);
    if(t=='U')
      { 
        myservo.write(180); 
      }
     if(t=='O')
     {
      myservo.write(0);
     }
  }
  
   
  
   delay(100);
} 
