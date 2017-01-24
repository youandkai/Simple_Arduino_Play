// Circuit for Photoresistor
// GND --- 10k --- A0 --- PhotoResistor --- 5V

//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int gauge[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int bars = sizeof(gauge) / sizeof(int);
int sensor = A0;
int pot = A1;

void setup() {
  // Need to initiate
  Serial.begin(9600);
  // put your setup code here, to run once:
  for (int i; i < bars; i++) {
    pinMode(gauge[i], OUTPUT);
  }
  pinMode(sensor, INPUT);
  pinMode(pot, INPUT);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Welcome to ");
  lcd.setCursor(0,1);
  lcd.print("Light Logger V0.10!");
  lcd.setCursor(0,2);
  lcd.print("Created by:");
  lcd.setCursor(0,3);
  lcd.print("Kai Zhou");
  delay(5000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Sensor Reading: ");
  Serial.println(analogRead(sensor));
  int intensity = map(analogRead(sensor), 100, 1000, 0, 9);
  for (int i; i < bars; i++) {
    if (i <= intensity) {
      digitalWrite(gauge[i], HIGH);
    }
    else {
      digitalWrite(gauge[i], LOW);
    }
  }
  int sensor_read = map(analogRead(sensor), 0, 1023, 0, 999);
  int pot_read = map(analogRead(pot), 0, 1023, 0, 999);
  // Write to the LCD
  lcd.setCursor(0,0);
  lcd.print("Light:");
  lcd.setCursor(6,0);
  lcd.print(sensor_read);
  lcd.setCursor(0,1);
  lcd.print("Sensitivity:");
  lcd.setCursor(12,1);
  lcd.print(pot_read);
  lcd.setCursor(0,2);
  if (sensor_read > pot_read) {
     lcd.print("Light is on!");
  }
  else {
    lcd.print("Light is off!");
  }
  delay(100);
}
