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
  float data;
  for (int i = 0; i< 2; i++){
    mikro.on();
    delay(500);
    mikro.off();
    delay(500);
  }
  for ( int i = 0; i < 10000; i++){
    //use NOT if we want to display point for float data tipe, 
    //and data*10, must be to multiple 10 like next line code below
    mikro.display(i,NOT);
    delay(500);
  }
}
