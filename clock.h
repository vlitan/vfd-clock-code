#pragma once



typedef struct time_s{ 
  byte second;  //0-59
  byte minute;  //0-59
  byte hour;    //0-23
  byte weekDay; //1-7
  byte monthDay;//1-31
  byte month;   //1-12
  byte year;    //0-99
} time_t;


void setDateTime(const time_t now);

time_t getDateTime(void);
byte decToBcd(byte val);

byte bcdToDec(byte val);

void printDate();
