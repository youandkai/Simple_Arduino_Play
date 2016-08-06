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

// Read and Print Out Voltage to the LCD

// Library
#include <LiquidCrystal.h>

// LCD pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Previous time
unsigned long prev_ts = 0;
float prev_volt = 0;

// the setup routine runs once when you press reset:
void setup() {
  lcd.begin(16, 2);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensor = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensor * (5.0 / 1023.0);
  
  // print out the value you read if past 100 milliseconds
  unsigned long ts = millis();
  // This prevents flickering of uncertain values
  if (ts - prev_ts > 100 & abs(prev_volt - voltage) > 0.01 ) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Voltage: ");
    lcd.setCursor(9, 0);
    lcd.print(voltage);
    prev_ts = ts;
    prev_volt = voltage;
  }
  
}
