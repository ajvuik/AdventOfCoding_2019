#include <Arduino.h>
#include "OpCodes.hpp"

int IntCode[]{
  1,9,10,3,2,3,11,0,99,30,40,50
};
int IntCodeCounter=0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  switch(IntCode[IntCodeCounter]){
    case add:{
      IntCode[IntCode[IntCodeCounter+3]]=IntCode[IntCode[IntCodeCounter+1]]+IntCode[IntCode[IntCodeCounter+2]];
      IntCodeCounter+=4;
    }
    break;//add

    case mull:{
      IntCode[IntCode[IntCodeCounter+3]]=IntCode[IntCode[IntCodeCounter+1]]*IntCode[IntCode[IntCodeCounter+2]];
      IntCodeCounter+=4;
    }
    break;

    case halt:{
      Serial.println(IntCode[0]);
      Serial.println(IntCode[3]);
      while(1){
        delay(1);
      }
    }
    break;

  }
}