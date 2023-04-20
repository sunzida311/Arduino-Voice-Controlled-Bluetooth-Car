#include<SoftwareSerial.h>
#include <Wire.h> 
int LF = 8;
int LB = 9;
int RF = 10;
int RB = 11;
void setup()
{
  Serial.begin(9600);
  pinMode(LF, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(RB, OUTPUT);
 
}
 
void loop()
{
  if (Serial.available())
  {
    String a = Serial.readString();
    Serial.print("The command is ");
    Serial.println(a);
    if (a == "go forward")
      Forward();
    if (a == "go back")
      Backward();
    if (a == "right" || a == "turn right")
      Right();
    if (a == "left" || a == "turn left")
      Left();
    if (a == "stop")
      Stop();
  }
}
void Forward()
{
  digitalWrite(LF, HIGH);
  digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(LB, LOW);
}
void Backward()
{
  digitalWrite(LB, HIGH);
  digitalWrite(RB, HIGH);
  digitalWrite(RF, LOW);
  digitalWrite(LF, LOW);
}
void Right()
{
  digitalWrite(LF, HIGH);
  digitalWrite(RF, LOW);
  digitalWrite(RB, HIGH);
  digitalWrite(LB, LOW);
}
void Left()
{
  digitalWrite(LF, LOW);
  digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(LB, HIGH);
}
void Stop()
{
  digitalWrite(LF, LOW);
  digitalWrite(RF, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LB, LOW);
}
