#include <Servo.h>
#include <SoftwareSerial.h>


   int motorA1  = 5;
   int motorA2  = 6;
   int Servopin = 3;
   int state;
   int vSpeed;
   char ch;
   Servo Servo1;

void setup() {

    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    Servo1.attach(Servopin);
    Serial.begin(9600);
    Servo1.write(60);
}

void loop() {

  //Save income data to variable 'state'
    if(Serial.available() > 0)
    {     
      state = Serial.read();
      ch = state;
      Serial.print("state:");Serial.print(state);
      Serial.print(" ch:");Serial.print(ch);
    }
     


    if(state == '0')
     vSpeed = 0;
    if(state == '1')
     vSpeed = 120;
    if(state == '2')
     vSpeed = 140;
    if(state == '3')
     vSpeed = 160;
    if(state == '4')
     vSpeed = 180;
    if(state == '5')
     vSpeed = 200;
    if(state == '6')
     vSpeed = 210;
    if(state == '7')
     vSpeed = 220;
    if(state == '8')
     vSpeed = 230;
    if(state == '9')
     vSpeed = 240;
    if(state == 'q')
     vSpeed = 255;
     

  /***********************Forward****************************/
  //If state is equal with number 'F', car will go forward!
    if (state == 'F') {
      analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0);
      Servo1.write(60);      

    }  
  
  /***********************Backward****************************/
  //If state is equal with number 'B', car will go backward
    else if (state == 'B') {
      analogWrite(motorA1, 0); analogWrite(motorA2, vSpeed); 
      Servo1.write(60); 

    }

  /***************************Right*****************************/
  //If state is equal with number 'R', wheels will turn right
    else if (state == 'R') {
      analogWrite(motorA1, 0); analogWrite(motorA2, 0); 
      Servo1.write(105);    

    }
    
  /***************************Left*****************************/
  //If state is equal with number 'L', wheels will turn left
    else if (state == 'L') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, 0); 
      Servo1.write(15);    

    }

  /**********************Forward Right************************/
  //If state is equal with number 'I', car will go forward right
    else if (state == 'I') {
      analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0); 
      Servo1.write(105);        

    }
    
  /**********************Forward Left************************/
  //If state is equal with number 'G', car will go forward left
    else if (state == 'G') {
      analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0);  
      Servo1.write(15);      

    }
    
  /**********************Backward Right************************/
  //If state is equal with number 'J', car will go backward right
    else if (state == 'J') {
      analogWrite(motorA1, 0); analogWrite(motorA2, vSpeed); 
      Servo1.write(105);   

    }
    
  /**********************Backward Left************************/
  //If state is equal with number 'H', car will go backward left
    else if (state == 'H') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed); 
      Servo1.write(15);   

    }
    
  /***************************Stop*****************************/
  //If state is equal with number 'S', stop the car
    else if (state == 'S') {
      analogWrite(motorA1, 0); analogWrite(motorA2, 0);  
      Servo1.write(60); 
      
    }
    
  
    }
