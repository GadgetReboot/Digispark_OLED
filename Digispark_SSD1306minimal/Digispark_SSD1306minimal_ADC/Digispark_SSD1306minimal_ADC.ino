
// ATTiny85 OLED 128x64 Text Display Test
// Using Digispark hardware and the following libraries:
//
// https://github.com/kirknorthrop/SSD1306_minimal
// https://github.com/adafruit/TinyWireM
//
// Set board type to Digispark Default (16.5 MHz) in Arduino IDE
//
// Compile results in Arduino IDE 1.8.10
// Sketch uses 5350 bytes (88%) of program storage space. Maximum is 6012 bytes.
// Global variables use 61 bytes of dynamic memory.
//
// Gadget Reboot
//

#include "SSD1306_minimal.h"

SSD1306_Mini oled;   // oled object

char strValue[5];    // for converting float to string for text display

void setup() {
  TinyWireM.begin(); // init I2C library
  oled.init(0x3c);   // init OLED display
  oled.clear();
}


void loop() {

  //analogRead on pin P5
  oled.cursorTo(0, 0);
  oled.printString( "V0: ");
  oled.cursorTo(30, 0);
  printAnalog(0);
  oled.printString(" V");

  //analogRead on pin P2
  oled.cursorTo(0, 18);
  oled.printString( "V1: ");
  oled.cursorTo(30, 18);
  printAnalog(1);
  oled.printString(" V");

  //analogRead on pin P4
  oled.cursorTo(0, 36);
  oled.printString( "V2: ");
  oled.cursorTo(30, 36);
  printAnalog(2);
  oled.printString(" V");

  //analogRead on pin P3
  oled.cursorTo(0, 54);
  oled.printString( "V3: ");
  oled.cursorTo(30, 54);
  printAnalog(3);
  oled.printString(" V");

  delay(200);  // slow down jittery screen updates from ADC readings

}

// read the requested ADC input and calculate the voltage with 2 decimals
// print as text on OLED display
void printAnalog(byte i) {
  dtostrf(((analogRead(i) / 1024.0) * 5.0), 4, 2, strValue);
  oled.printString(strValue);
}
