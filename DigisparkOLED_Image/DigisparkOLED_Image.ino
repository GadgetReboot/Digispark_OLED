// ATTiny85 OLED 128x64 Image Display Test
// Using Digispark hardware and the following library:
// https://github.com/digistump/DigistumpArduino/tree/master/digistump-avr/libraries/DigisparkOLED
//
// Set board type to Digispark Default (16.5 MHz) in Arduino IDE
//
// Compile results in Arduino IDE 1.8.10
// Sketch uses 5004 bytes (83%) of program storage space. Maximum is 6012 bytes.
// Global variables use 51 bytes of dynamic memory.
//
// Gadget Reboot
//

#include <DigisparkOLED.h>
#include <Wire.h>

#include "gadgetlogo.h"

void setup() {
  oled.begin();                             // init OLED display
}

void loop() {
  oled.bitmap(0, 0, 128, 8, gadgetLogo);    // draw image from memory
  while (1) {};                             // loop forever, no more OLED communication
}
