#include <Arduino.h>
#include <Wire.h>
#include "clock.h"
#define DS1307_ADDRESS 0x68

const byte zero = 0x00; //workaround for issue #527

void setDateTime(const time_t now){

Wire.beginTransmission(DS1307_ADDRESS);
Wire.write(zero);

Wire.write(decToBcd(now.second));
Wire.write(decToBcd(now.minute));
Wire.write(decToBcd(now.hour));
Wire.write(decToBcd(now.weekDay));
Wire.write(decToBcd(now.monthDay));
Wire.write(decToBcd(now.month));
Wire.write(decToBcd(now.year));

Wire.write(zero); //start

Wire.endTransmission();
}

time_t getDateTime(void){
  time_t now;

  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_ADDRESS, 7);
  
  now.second = Wire.read();
  now.minute = Wire.read();
  now.hour = Wire.read() & 0b111111; //24 hour time
  now.weekDay = Wire.read(); //0-6 -> sunday – Saturday
  now.monthDay = Wire.read();
  now.month = Wire.read();
  now.year = Wire.read();
  return (now);
}

byte decToBcd(byte val){
// Convert normal decimal numbers to binary coded decimal
return ( (val/10*16) + (val%10) );
}

byte bcdToDec(byte val) {
// Convert binary coded decimal to normal decimal numbers
return ( (val/16*10) + (val%16) );
}


void printDate(){
  time_t now = getDateTime();
  
  int second = bcdToDec(now.second);
  int minute = bcdToDec(now.minute);
  int hour = bcdToDec(now.hour); //24 hour time
  int weekDay = bcdToDec(now.weekDay); //0-6 -> sunday – Saturday
  int monthDay = bcdToDec(now.monthDay);
  int month = bcdToDec(now.month);
  int year = bcdToDec(now.year);
  
  //print the date EG 3/1/11 23:59:59
  Serial.print(month);
  Serial.print("|");
  Serial.print(monthDay);
  Serial.print("|");
  Serial.print(year);
  Serial.print("|");
  Serial.print(hour);
  Serial.print("|");
  Serial.print(minute);
  Serial.print(":");
  Serial.println(second);
}
