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

int pan = 90;    // variable to store the servo position
int tilt = 0;
int knob1 = A0;
int knob2 = A1;
unsigned long last_ts = 0;
int cmd1 = 0;
int cmd2 = 0;
int center1 = 0;
int center2 = 0;
int pan_add = 0;
int tilt_add = 0;

void setup() {
  panservo.attach(9);  // attaches the servo on pin 9 to the servo object
  tiltservo.attach(10);
  panservo.write(pan);
  tiltservo.write(tilt);
  pinMode(knob1, INPUT);
  pinMode(knob2, INPUT);
  Serial.begin(9600);
  center1 = analogRead(knob1);
  center2 = analogRead(knob2);
}

void loop() {
  cmd1 = analogRead(knob1);
  cmd2 = analogRead(knob2);
  int ts = millis();
  pan_add = (abs(cmd1 - center1) / center1) * 90 - 1;
  tilt_add = (abs(cmd2 - center2) / center2) * 90 - 1;
  pan = constrain(pan + pan_add, 0, 179);
  tilt = constrain(tilt + tilt_add, 30, 110);
  Serial.print("Pan: ");
  Serial.print(pan);
  Serial.print(" - Tilt: ");
  Serial.println(tilt);
  panservo.write(pan);
  tiltservo.write(tilt);
  last_ts = ts;
  delay(1);
}

