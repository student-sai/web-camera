#ifndef MotorDrive_h
#define MotorDrive_h

#include "Arduino.h"

class MotorDrive{
  private:
   int r1Pin;
   int r2Pin;
   int l1Pin;
   int l2Pin;
  public:
   void setRightPin(int r1, int r2);
   void setLeftPin(int l1, int l2);
   void drive(unsigned char state);
   void setDirection(unsigned char state);
};
#endif