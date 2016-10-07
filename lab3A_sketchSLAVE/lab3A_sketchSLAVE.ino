/*
 *  COMP 50 Internet of Things
 *  Fall 2016
 *  Lab 3 I2C 
 *  by Thomas Li and Tomer Shapira
 */



#include <Wire.h>


void blnk();

void setup() {
  Wire.begin(1);
  Wire.onReceive(receiveEvent);
  pinMode(13, OUTPUT);
}

void loop() {

}

void receiveEvent(int howMany) {
  while (Wire.available()) {
    char x = Wire.read();
    if (x == '1') {
      blnk();
    }
    if (x == '2') {
      blnk();
      blnk();
    }
    if (x == '3') {
      blnk();
      blnk();
      blnk();
    }
  }
}

void blnk() {
  digitalWrite(13, HIGH);
  delay(100000);
  digitalWrite(13, LOW);
  delay(100000);
}

