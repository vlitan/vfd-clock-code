#include "display.h"
#include <Arduino.h>
#include "sysConfig.h"


char chars[charConfig::knownCharacters];

//sets the pins as output, shuts the display off
void setupDisplay(){
  for (int i = 0; i < 4; i++){
    pinMode(pinConfig::selectPins[i], OUTPUT);
  }
   for (int i = 0; i < 10; i++){
    pinMode(pinConfig::segmentPins[i], OUTPUT);
  }
  close();
}

//shuts the display off
void close(){
   for (int i = 0; i < 4; i++){
    digitalWrite(pinConfig::selectPins[i], HIGH);
  }
   for (int i = 0; i < 10; i++){
    digitalWrite(pinConfig::segmentPins[i], HIGH);
  }
}

//turns on a speficied tube, closing the rest
void turnOnSingle(int index){
   for (int i = 0; i < 4; i++){
    if (i == index){
       digitalWrite(pinConfig::selectPins[i], LOW);
    }
    else{
      digitalWrite(pinConfig::selectPins[i], HIGH);
    }
  }
}

//updates the pins according to the values from the digits array
void update(int index){
  for (int i = 0; i < 10; i++){
    digitalWrite(pinConfig::segmentPins[i], charConfig::lut[chars[index]][i]);
  }
}

//sets a digit in the digit array
void setCharacter(int index, int value){
  chars[index] = value;
}

//enables the next tube and shuts off all the rest
void iterate(){
  static char i = 0;
  update(i);
  turnOnSingle(i);
  i = (i + 1) % 4;
}

