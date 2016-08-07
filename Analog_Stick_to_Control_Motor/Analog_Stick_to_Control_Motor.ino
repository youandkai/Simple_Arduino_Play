// Name: Kai Zhou
// Date: 2016-08-07

// This is using the analog stick to control the motor

// connection reference
/*
// LCD Screen
VSS - GND
VDD - 5V
V0 -----.
        |
5V --- Pot --- GND
RS - 7
E - 8
D4 - 9
D5 - 10
D6 - 11
D7 - 12
A - 5V
K - GND

// Analog Stick
SW - 6 // Unused
VRX - A1
VRY - A2
5V - 5V
GND - GND

// Motor Drive
5-12V - Vin (With external 12V power supply)
GND - Same GND as Vin
1N1 - 2
1N2 - 3
1N3 - 4
1N4 - 5
*/

// Library
#include <LiquidCrystal.h>

// define LCD pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// define analog controller axis
int xaxis = A1;
int yaxis = A2;
int sw = 6; // This is the unused Switch

// manual wave motor
int drive[4] = {2, 3, 4, 5};
int drives = sizeof(drive) / sizeof(int);

// Previous time - We want to be able run without the delay function
unsigned long prev_ts = 0;

// initialize values
bool scan = 0;
int dx = 0;
int dy = 0;
int xdir = 0;
int ydir = 0;

// Clockwise Rotation - Full - Full Stop
// To get more precision, use half stop motors
int cw[4][4] = {{HIGH, HIGH, LOW, LOW}, // Step 1
                {LOW, HIGH, HIGH, LOW}, // Step 2
                {LOW, LOW, HIGH, HIGH}, // Step 3
                {HIGH, LOW, LOW, HIGH}}; // Step 4

// Counter Clockwise Rotation  - Full Stop
int ccw[4][4] = {{HIGH, HIGH, LOW, LOW}, // Step 1
                 {HIGH, LOW, LOW, HIGH}, // Step 2
                 {LOW, LOW, HIGH, HIGH}, // Step 3
                 {LOW, HIGH, HIGH, LOW}}; // Step 4

// Wave Drive Clockwise
int wave_cw[4][4] = {{HIGH, LOW, LOW, LOW}, // Step 1
                  {LOW, HIGH, LOW, LOW}, // Step 2
                  {LOW, LOW, HIGH, LOW}, // Step 3
                  {LOW, LOW, LOW, HIGH}}; // Step 4

// Wave Drive Counter Clockwise
int wave_ccw[4][4] = {{LOW, LOW, LOW, HIGH}, // Step 1
                  {LOW, LOW, HIGH, LOW}, // Step 2
                  {LOW, HIGH, LOW, LOW}, // Step 3
                  {HIGH, LOW, LOW, LOW,}}; // Step 4

void setup() {
  // Open serial port for testing
  Serial.begin(9600);
  // Analog Stick
  lcd.begin(16, 2);
  pinMode(sw, INPUT);
  pinMode(xaxis, INPUT);
  pinMode(yaxis, INPUT);
  // Motor Drives
  for (int i = 0; i < drives; i++) {
    pinMode(drive[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the input on analog pin 0:
  int yval = analogRead(A1);
  int xval = analogRead(A2);
  int push = digitalRead(sw);
  
  // print out the value you read if past 100 milliseconds
  unsigned long ts = millis();

  // Scan Intital Values
  if (!scan) {
    dx = xval;
    dy = yval;
    scan = 1;
  }
  
  // read default value and determine a big average
  if (millis() < 2000) {
    if (ts - prev_ts > 100) {
      // Intitalize Output
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Intitializing...");
      lcd.setCursor(0, 1);
      lcd.print("Do Not Touch!");
      prev_ts = ts;
    }
    // Each time take then average - should do this around 15-20 times.
    dx = (dx + xval) / 2;
    dy = (dy + yval) / 2;
  }
  
  // determine direction - given a 20 point buffer zone
  if (xval < dx - 20) {
    xdir = 1;
  } else if (xval > dx + 20) {
    xdir = -1;
  } else {
    xdir = 0;
  }
  if (yval < dy - 20) {
    ydir = 1;
  } else if (yval > dy + 20) {
    ydir = -1;
  } else {
    ydir = 0;
  }

  // Turn the motor counter clockwise
  if (xdir == -1) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        digitalWrite(drive[j], ccw[i][j]); // This is full stop version for wave drive use wave_ccw
        // delay(10);
      }
      delay(3);
    }
  }
  // Turn the motor clockwise 
  else if (xdir == 1) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        digitalWrite(drive[j], cw[i][j]); // This is full stop version for wave drive use wave_cw
        // delay(10);
      }
      delay(3);
    }
  } 
  // Turn off all drives
  else {
    for (int j = 0; j < 4; j++) {
      digitalWrite(drive[j], LOW);
    }
  }
  
  // This prevents flickering of uncertain values
  // Print Direction of the Analog Stick - refreshes every 100 ms.
  if (ts - prev_ts > 100) {
    lcd.clear();
    // Print x-axis value
    lcd.setCursor(0, 0);
    if (xdir == -1 & ydir == -1) {
      lcd.print("Down Left");
    } else if (xdir == -1 & ydir == 0) {
      lcd.print("Left");
    } else if (xdir == -1 & ydir == 1) {
      lcd.print("Up Left");
    } else if (xdir == 0 & ydir == 1) {
      lcd.print("Up");
    } else if (xdir == 1 & ydir == 1) {
      lcd.print("Up Right");
    } else if (xdir == 1 & ydir == 0) {
      lcd.print("Right");
    } else if (xdir == 1 & ydir == -1) {
      lcd.print("Down Right");
    } else if (xdir == 0 & ydir == -1) {
      lcd.print("Down");
    } else {
      lcd.print("Middle");
    }
    prev_ts = ts;
  }
}
