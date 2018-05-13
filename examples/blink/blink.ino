//created by Jimmi Kardo Sitepu
//Founder of https://mikroavr.com
//make easy project seven segment with modul mikro7
//contact me any qustion to +6285207770631 --> whatsapp, SMS
#include <mikro7.h>
// Arduino pin configuration to modul mikro7
// D7 connected to Data Pin
// D8 connected to latch pin
// DS connected to clock pin
mikro7 mikro(7, 8, 9); // dis(data, latch, clock
void setup() {
  // put your setup code here, to run once:
}
void loop() {
  // put your main code here, to run repeatedly
    mikro.on();
    delay(500);
    mikro.off();
    delay(500);
  }
