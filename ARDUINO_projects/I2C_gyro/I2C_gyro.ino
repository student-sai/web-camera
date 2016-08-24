#include <Wire.h>

const int L3GD20_ADDR = B1101011;

#define WHO_AM_I 0x0F
#define CTRL_REG1 0x20 
#define OUT_X_L 0x28
#define OUT_X_H 0x29
#define OUT_Y_L 0x2A
#define OUT_Y_H 0x2B
#define OUT_Z_L 0x2C
#define OUT_Z_H 0x2D

unsigned int readRegister(byte reg){
  Wire.beginTransmission(L3GD20_ADDR);
  Wire.write(reg);
  Wire.endTransmission();
  
  Wire.requestFrom(L3GD20_ADDR, 1);
  return Wire.read();
}
void writeRegister(byte reg,byte data){
  Wire.beginTransmission(L3GD20_ADDR);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission();
}
int readGyro( byte H, byte L){
  int gyro, l, h;
  l = readRegister(L);
  h = readRegister(H);
  gyro = h << 8 | l;
  gyro = gyro*0.00875;
  return gyro;
}
void setup() {
  Wire.begin();
  Serial.begin(9600);
  int res = readRegister(WHO_AM_I);
  Serial.println(res, HEX);
  writeRegister(CTRL_REG1,0x0F);
}

void loop() {
  
  int x,y,z,h,l;

  l = readRegister(OUT_X_L);
  h = readRegister(OUT_X_H);
  x = h << 8 | l;
  x = x*0.00875;

  l = readRegister(OUT_Y_L);
  h = readRegister(OUT_Y_H);
  y = h << 8 | l;
  y = y*0.00875;
  
  l = readRegister(OUT_Z_L);
  h = readRegister(OUT_Z_H);
  z = h << 8 | l;
  z = z*0.00875;
  
  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print(",");
  Serial.println(z);
  
  delay(500);
  
}
