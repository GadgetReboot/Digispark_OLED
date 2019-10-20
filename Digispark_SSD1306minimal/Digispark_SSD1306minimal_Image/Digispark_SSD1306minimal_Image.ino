
// ATTiny85 OLED 128x64 Text Display Test
// Using Digispark hardware and the following libraries:
//
// https://github.com/kirknorthrop/SSD1306_minimal
// https://github.com/adafruit/TinyWireM
//
// Set board type to Digispark Default (16.5 MHz) in Arduino IDE
//
// Compile results in Arduino IDE 1.8.10
// Sketch uses 2568 bytes (42%) of program storage space. Maximum is 6012 bytes.
// Global variables use 31 bytes of dynamic memory.
//
// Gadget Reboot
//

#include "gadgetlogo.h"
#include "SSD1306_minimal.h"

SSD1306_Mini oled;   // oled object

void setup() {
  TinyWireM.begin(); // init I2C library
  oled.init(0x3c);   // init OLED at address 3C
}


void loop() {

  oled.drawImage(gadgetLogo, 0, 0, 128, 8);  // draw image from memory
  while (1) {};                              // loop forever, no more OLED interaction

}
