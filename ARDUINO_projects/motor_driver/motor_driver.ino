class motorDrive{
  private:
   int r1Pin;
   int r2Pin;
   int l1Pin;
   int l2Pin;
  public:
   void setRightPin(int r1, int r2);
   void setLeftPin(int l1, int l2);
   void drive(unsigned char state);
   void operate(unsigned char state);
};
//サーボの設定
motorDrive mdrive;

//文字の設定
int right1Pin = 4;
int right2Pin = 5;
int left1Pin = 6;
int left2Pin = 8;

void setup() 
{
  mdrive.setRightPin(right1Pin, right2Pin);
  mdrive.setLeftPin(left1Pin, left2Pin);
}
void loop()
{
  //mdrive.operate(B0011);//forward
  //delay(20);
  //mdrive.operate(B0111);//backward
  //delay(20);
  //mdrive.operate(B0001);//rightward
  //delay(20);
  //mdrive.operate(B0010);//leftward
  //delay(20);
  mdrive.operate(B0000);//stop
  delay(20);
}
void motorDrive::setRightPin(int r1, int r2)
{
  r1Pin = r1;
  r2Pin = r2;
  pinMode(r1Pin, OUTPUT);
  pinMode(r2Pin, OUTPUT);
}
void motorDrive::setLeftPin(int l1, int l2)
{
  l1Pin = l1;
  l2Pin = l2;
  pinMode(l1Pin, OUTPUT);
  pinMode(l2Pin, OUTPUT);
}
 void motorDrive::drive(unsigned char state)
 {
   delay(1);
   digitalWrite(r1Pin, (state >> 0) & B0001);
   digitalWrite(r2Pin, (state >> 1) & B0001);
   digitalWrite(l1Pin, (state >> 2) & B0001);
   digitalWrite(l2Pin, (state >> 3) & B0001);
 }
 void motorDrive::operate(unsigned char state)
 {
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
