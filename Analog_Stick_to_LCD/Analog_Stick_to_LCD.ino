// connection reference
/*
RS - 7
E - 8
D4 - 9
D5 - 10
D6 - 11
D7 - 12
*/

// Library
#include <LiquidCrystal.h>

// LCD pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Previous time
unsigned long prev_ts = 0;

// switch
int sw = 6;

// axis
int xaxis = A1;
int yaxis = A2;

// test led
int led = 13;

void setup() {
  // Open serial port for testing
  Serial.begin(9600);
  // Initial stuff
  lcd.begin(16, 2);
  pinMode(sw, INPUT);
  pinMode(xaxis, INPUT);
  pinMode(yaxis, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the input on analog pin 0:
  int xval = analogRead(A1);
  int yval = analogRead(A2);
  int push = digitalRead(sw);

  // print out the value you read if past 100 milliseconds
  unsigned long ts = millis();
  // This prevents flickering of uncertain values
  if (ts - prev_ts > 100) {
    lcd.clear();
    // Print x-axis value
    lcd.setCursor(0, 0);
    lcd.print("x-axis: ");
    lcd.setCursor(8, 0);
    lcd.print(xval);
    // Print y-axis value
    lcd.setCursor(0, 1);
    lcd.print("y-axis: ");
    lcd.setCursor(8, 1);
    lcd.print(yval);
    prev_ts = ts;
  }
  // check button
  if (push == HIGH) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
}
