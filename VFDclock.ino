#include <TaskScheduler.h>
#include <Wire.h>
#include "clock.h"
#define DS1307_ADDRESS 0x68

Scheduler scheduler;

void printDate();
Task printDateTask(1000, TASK_FOREVER, &printDate);

void setup(){
  Wire.begin();
  Serial.begin(9600);
 // setDateTime(); //MUST CONFIGURE IN FUNCTION

  scheduler.init();
  scheduler.addTask(printDateTask);
  printDateTask.enable();
}

void loop(){
  scheduler.execute();
}
