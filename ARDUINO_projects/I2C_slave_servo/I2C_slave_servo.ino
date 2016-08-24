#include <MotorDrive.h>
#include <Servo.h>
#include <Wire.h>
//繧ｵ繝ｼ繝懊�ｮ險ｭ螳�
Servo yaw_servo;
Servo pitch_servo;
MotorDrive md;
int pos = 0;
int yaw_pos = 65;
int pitch_pos = 50;
int one_motion = 5;

//譁�蟄励�ｮ險ｭ螳�
//nano縺ｯI2C縺ｧA4縺ｨA5繧剃ｽｿ縺�
int SLAVE_ADDRESS = 0x04;
int analogPin = A0;
int ledPin = 13;
int right1Pin = 12;
int right2Pin = 11;
int left1Pin = 8;
int left2Pin = 7;
boolean ledOn = false;
char ch;
void setup() 
{
  pinMode(ledPin, OUTPUT);
  //Serial.begin(9600);
  yaw_servo.attach(9);//蟾ｦ蜿ｳ縺ｮ蝗櫁ｻ｢
  pitch_servo.attach(10);//荳贋ｸ九�ｮ蝗櫁ｻ｢
  md.setRightPin(right1Pin, right2Pin);
  md.setLeftPin(left1Pin, left2Pin);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(processMessage);
  //Wire.onRequest(sendAnalogReading);
  yaw_servo.write(yaw_pos);
  pitch_servo.write(pitch_pos);
}
void loop()
{
  while(!Wire.available() > 0);
  ch = Wire.read();
  if (ch == 1) {
      digitalWrite(ledPin, ledOn);
  }
  cameraOperate(ch);
  md.setDirection(ch);
  delay(200);
  md.setDirection(B000);
}
void processMessage(int n)
{
}
void cameraOperate(char d)
{
  ledOn =! ledOn;
  digitalWrite(ledPin, ledOn);
  switch(d){
    case 64://right
      yaw_pos += one_motion;
      break;
    case 8://left
      yaw_pos -= one_motion;
      break;
    case 16://down
      pitch_pos += one_motion;
      break;
    case 32://up
      pitch_pos -= one_motion;
    default:break;
  }
  if(yaw_pos <= 0){
    yaw_pos = 0;
  }
  else if(yaw_pos >= 180){
    yaw_pos = 180;
  }
  
  if(pitch_pos <= 0){
    pitch_pos = 0;
  }
  else if(pitch_pos >= 180){
    pitch_pos = 180;
  }
  yaw_servo.write(yaw_pos);
  pitch_servo.write(pitch_pos);
  delay(15);
}
/*void sendAnalogReading()
{
  int reading = analogRead(analogPin);
  Wire.write(reading >> 0x02);
}*/

