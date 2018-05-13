# mikro7,LIBRARY SEVEN SEGMENT  FOR ARDUINO
Seven Segment arduino library, drive with ic 74hc595 and ULN2803, we create modul seven segment 3" Commond Anode. This module easy to use, low price and high quality. 
This libray have four function, perhaps we will update function. 

first function:

void mikro7::on();
this function to on all of your segment, this we use for check does all seven segment good?
void mikro7::off();
this function to off all of your segment, perhaps for one condition that we want to decrease power uses

you can get code blink segment for example, or code like this:

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
    mikro.on(); // on segment
    delay(500);
    mikro.off(); // off segment
    delay(500);
  }
  

