/*
 *  COMP 50 Internet of Things
 *  Fall 2016
 *  Lab 3 I2C 
 *  by Thomas Li
 */



#include <Wire.h>

long zips[100];

void setup() {
  createZips();
  Wire.begin(1);                
  Wire.onRequest(requestEvent); 
}

void loop() {
  //delay(100);
}


void requestEvent() {
  int i = random(0,100);
  long zipCode = zips[i];
  byte longArray[4];
  longArray[0] = (zipCode >> 24) & 0xFF;
  longArray[1] = (zipCode >> 16) & 0xFF;
  longArray[2] = (zipCode >> 8) & 0xFF;
  longArray[3] = zipCode & 0xFF;
  Wire.write(longArray, 4);
}

void createZips() {
  for (int i = 0; i < 100; i++) 
    zips[i] = random(10000, 100000);
}

