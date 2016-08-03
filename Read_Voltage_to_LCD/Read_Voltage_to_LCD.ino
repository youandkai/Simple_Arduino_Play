// Read and Print Out Voltage to the LCD

// Library
#include <LiquidCrystal.h>
#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 100

// LCD pins
LiquidCrystal lcd(47, 48, 49, 50, 51, 52);

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
