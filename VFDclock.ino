
//#include <TaskScheduler.h>
#include <Wire.h>
#include "clock.h"
#include "sysConfig.h"
#include "display.h"
//
//
//Scheduler scheduler;
//
//void printDate();
//Task printDateTask(1000, TASK_FOREVER, &printDate);

void setup(){
//  Wire.begin();
//  Serial.begin(9600);
// // setDateTime(); //MUST CONFIGURE IN FUNCTION
//
//  scheduler.init();
//  scheduler.addTask(printDateTask);
//  printDateTask.enable();
  setupDisplay();
//    turnOnSingle(0);
//   for (int i = 0; i < 10; i++){
//    digitalWrite(pinConfig::segmentPins[i], LOW);
//    delay(2000);
//  }
  for (int i = 0; i < 4; i++){
    setCharacter(i, i);
  }
}

void loop(){
  iterate();
  delayMicroseconds(500);
}
