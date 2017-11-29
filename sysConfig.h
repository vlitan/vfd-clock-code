#pragma once 
#include <Arduino.h>
namespace pinConfig{
  const int selectPins[4] = {
    A3,  //select1
    A2, //select2
    A1, //select3
    A0  //select4
    };
  const int segmentPins[10] = {
    8,  //a
    5, //b
    4,  //c
    11,  //d
    12,  //e
    10,  //f
    13,  //g
    7, //h
    9,  //q
    6, //dp
  };
  enum segs{
    a,
    b,
    c,
    d,
    e,
    f,
    g,
    q,
    dp
  };
}

namespace charConfig{
  using namespace pinConfig;
  const int knownCharacters = 10;
  const bool lut[knownCharacters][10] = {
 //a b c d e f g h q dp
  {0,0,0,0,0,0,1,1,1,1},//0
  {1,0,0,1,1,1,1,1,1,1},//1
  {0,0,1,0,0,1,0,1,1,1},//2
  {0,0,0,0,1,1,0,1,1,1},//3
  {1,0,0,1,1,0,0,1,1,1},//4
  {0,1,0,0,1,0,0,1,1,1},//5
  {0,1,0,0,0,0,0,1,1,1},//6
  {0,0,0,1,1,1,1,1,1,1},//7
  {0,0,0,0,0,0,0,1,1,1},//8
  {0,0,0,0,1,0,0,1,1,1}//9
  };
}
/*        avr   arduino  vfd
 * seg1   pd4   4         
 * seg2   pd5   5         
 * seg3   pd6   6         
 * seg4   pd7   7         
 * seg5   pb0   8         
 * seg6   pb1   9         
 * seg7   pb2   10        
 * seg8   pb3   11        
 * seg9   pb4   12        
 * seg10  pb5   13        
*/
