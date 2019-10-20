// ATTiny85 OLED 128x64 Text Display Test
// Using Digispark hardware and the following library:
// https://github.com/digistump/DigistumpArduino/tree/master/digistump-avr/libraries/DigisparkOLED
//
// Set board type to Digispark Default (16.5 MHz) in Arduino IDE
//
// Compile results in Arduino IDE 1.8.10
// Sketch uses 5996 bytes (99%) of program storage space. Maximum is 6012 bytes.
// Global variables use 70 bytes of dynamic memory.
//
// Gadget Reboot
//

#include <DigisparkOLED.h>
#include <Wire.h>

void setup() {
  analogReference(DEFAULT);  // make sure the analog reference is VCC (5 volts) so readings are 0v - 5v
  oled.begin();              // init OLED display
  oled.clear();              // clear screen
}

void loop() {

  //usage: oled.setCursor(X IN PIXELS, Y IN ROWS OF 8 PIXELS STARTING WITH 0);
  oled.setCursor(0, 0);      // top left
  oled.setFont(FONT8X16);
  oled.println("Read ADC:");

  oled.setFont(FONT6X8);
  oled.print(F("V0:  "));
  oled.print(((analogRead(0) / 1024.0) * 5.0)); //analogRead on pin P5
  oled.println(" V  ");

  /*
    oled.print(F("V1:  "));
    oled.print(((analogRead(1) / 1024.0) * 5.0)); //analogRead on pin P2
    oled.println(" V  ");

    oled.print(F("V2:  "));
    oled.print(((analogRead(2) / 1024.0) * 5.0)); //analogRead on pin P4
    oled.println(" V  ");

    oled.print(F("V3:  "));
    oled.print(((analogRead(3) / 1024.0) * 5.0)); //analogRead on pin P3
    oled.println(" V  ");
  */

}
