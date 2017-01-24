/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo panservo;  // create servo object to control a servo
Servo tiltservo;
// twelve servo objects can be created on most boards

void setup() {
  panservo.attach(9);  // attaches the servo on pin 9 to the servo object
  tiltservo.attach(10);
  tiltservo.write(40);
  Serial.begin(9600);
}

void loop() {
  panservo.write(80);
  delay(200);
  panservo.write(100);
  delay(200);
}

