/*ROBO BLG 5key*/

#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11); //TX, RX respectively
String readdata;
void setup()
{
BT.begin(9600);
Serial.begin(9600);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
}

void loop()
{
while (BT.available())
{ 
char c = BT.read();
readdata += c; 
}
if (readdata.length() > 0) 
{
Serial.println(readdata);
if(readdata == "FORWARD")
{ 
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
delay(50);
}
else if (readdata == "BACK")
{
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
digitalWrite(9,HIGH);
delay(50);
}
else if(readdata =="RIGHT")
{
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,HIGH);
delay(50);
}
else if(readdata =="LEFT")
{
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
delay(50);
}
else if(readdata =="STOP")
{
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
delay(50);
}
readdata="";
}
}
