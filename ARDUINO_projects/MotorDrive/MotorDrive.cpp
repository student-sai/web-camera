#include "MotorDrive.h"
#include "Arduino.h"

void MotorDrive::setRightPin(int r1, int r2)
{
  r1Pin = r1;
  r2Pin = r2;
  pinMode(r1Pin, OUTPUT);
  pinMode(r2Pin, OUTPUT);
}
void MotorDrive::setLeftPin(int l1, int l2)
{
  l1Pin = l1;
  l2Pin = l2;
  pinMode(l1Pin, OUTPUT);
  pinMode(l2Pin, OUTPUT);
}
 void MotorDrive::drive(unsigned char state)
 {
   //delay(1);
   digitalWrite(r1Pin, (state >> 0) & B0001);
   digitalWrite(r2Pin, (state >> 1) & B0001);
   digitalWrite(l1Pin, (state >> 2) & B0001);
   digitalWrite(l2Pin, (state >> 3) & B0001);
 }
 void MotorDrive::setDirection(unsigned char state)
 {
   delayMicroseconds(100);
   if (state == B0011){
     drive(B0101);//forward
   }
   else if(state == B0111){
     drive(B1010);//backward
   }
   else if(state == B0001){
     drive(B1001);//rightward
   }
   else if(state == B0010){
     drive(B0110);//leftward
   }
   else {
     drive(B0000);//stop
   }
 }