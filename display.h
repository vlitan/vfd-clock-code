#pragma once

//sets the pins as output, shuts the display off
void setupDisplay();

//shuts the display off
void close();

//turns on a speficied tube, closing the rest
void turnOnSingle(int index);

//updates the pins according to the values from the digits array
void update(int);

//sets a digit in the digit array
void setCharacter(int index, int value);

//enables the next tube and shuts off all the rest
void iterate();
