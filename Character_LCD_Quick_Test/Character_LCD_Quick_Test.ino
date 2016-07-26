// Liquid Crystal Display
// This is using the Arduino Mega 2560, so I have access to pins 47 through 52
// Otherwise use pins 7 through 12

/*
here is how to connect, it is so simple:
This is the white stuff
VSS --- GND
VDD --- 5V
GND --- Pot --- 5V
            |
            V0

This is read and write
RS --- pin 47
RW --- GND
EN --- pin 48
D4 --- pin 59
D5 --- pin 50
D6 --- pin 51
D7 --- pin 52

Back lighting
A - 5V
K - GND
*/

// Library
#include <LiquidCrystal.h>

// LCD pins
LiquidCrystal lcd(47, 48, 49, 50, 51, 52);

// Initiate the sensor pin
int sensor = 0;
int state = 1;
int laststate = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Set the sensor to input
  pinMode(sensor, INPUT);
}

void loop() {
  int intensity = analogRead(sensor);
  if (intensity < 200) {
    lcd.setCursor(0, 0);
    lcd.print("Light is off!");
    if (intensity < 10) {
      lcd.setCursor(0, 1);
      lcd.print("Dark");
      state = 1;
    } else {
      lcd.setCursor(0, 1);
      lcd.print("Dim");
      state = 2;
    }
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Light is on!");
    if (intensity < 500) {
      lcd.setCursor(0, 1);
      lcd.print("Light");
      state = 3;
    } else if (intensity < 800) {
      lcd.setCursor(0, 1);
      lcd.print("Bright");
      state = 4;
    } else {
      lcd.setCursor(0, 1);
      lcd.print("Very Bright");
      state = 5;
    }
  }
  if (state != laststate) {
    lcd.clear();
  }
  laststate = state;
}

