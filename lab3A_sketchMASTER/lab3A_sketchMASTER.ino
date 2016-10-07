/*
 *  COMP 50 Internet of Things
 *  Fall 2016
 *  Lab 3 I2C 
 *  by Thomas Li and Tomer Shapira
 */



#include <Wire.h>


void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  
  while (Serial.available()) {
    char x = Serial.read();
    if (x == '1') {
      Wire.beginTransmission(1);
      Wire.write('1');
    }
    if (x == '2') {
      Wire.beginTransmission(1);
      Wire.write('2');      
    }
    if (x == '3') {
      Wire.beginTransmission(1);
      Wire.write('3');
    }
    Wire.endTransmission();
    
    //delay(2000);
  }
}
