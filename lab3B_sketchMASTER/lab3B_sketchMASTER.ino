/*
 *  COMP 50 Internet of Things
 *  Fall 2016
 *  Lab 3 I2C 
 *  by Thomas Li
 */



#include <Wire.h>

void setup() {
  Wire.begin();       
  Serial.begin(9600); 
}

void loop() {
  while (Serial.available()) {
    int number = Serial.parseInt();
    for (int i = 0; i < number; i++) {
      Wire.requestFrom(1, 4);   
      if (Wire.available()) { 
        byte b1 = Wire.read();
        byte b2 = Wire.read();
        byte b3 = Wire.read();
        byte b4 = Wire.read();

        long zipCode = b1;
        zipCode = (zipCode << 8) | b2;
        zipCode = (zipCode << 8) | b3;
        zipCode = (zipCode << 8) | b4;
        
        Serial.println(zipCode);        
      }
    }

    //delay(500);
  }
}
