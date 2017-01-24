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

int pan = 0;    // variable to store the servo position
int tilt = 0;
int knob1 = A0;
int knob2 = A1;
unsigned long last_ts = 0;


void setup() {
  panservo.attach(9);  // attaches the servo on pin 9 to the servo object
  tiltservo.attach(10);
  pinMode(knob1, INPUT);
  pinMode(knob2, INPUT);
  Serial.begin(9600);
}

void loop() {
    pan = map(analogRead(knob1), 1023, 0, 0, 179);
    tilt = map(analogRead(knob2), 1023, 0, 30, 179);
      Serial.print("Pan: ");
      Serial.print(pan);
      Serial.print(" - Tilt: ");
      Serial.println(tilt);
      panservo.write(pan);
      tiltservo.write(tilt);
      last_ts = millis();
}

