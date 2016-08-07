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

// initialize values
bool scan = 0;
int dx = 0;
int dy = 0;
int xdir = 0;
int ydir = 0;
    
void setup() {
  // Open serial port for testing
  Serial.begin(9600);
  // Initial stuff
  lcd.begin(16, 2);
  pinMode(sw, INPUT);
  pinMode(xaxis, INPUT);
  pinMode(yaxis, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the input on analog pin 0:
  int yval = analogRead(A1);
  int xval = analogRead(A2);
  int push = digitalRead(sw);
  
  // print out the value you read if past 100 milliseconds
  unsigned long ts = millis();
  
  if (!scan) {
    dx = xval;
    dy = yval;
    scan = 1;
  }
  // read default value and determine a big average
  if (millis() < 2000) {
    if (ts - prev_ts > 100) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Intitializing...");
      lcd.setCursor(0, 1);
      lcd.print("Do Not Touch!");
      prev_ts = ts;
    }
    dx = (dx + xval) / 2;
    dy = (dy + yval) / 2;
  }
  
  // determine direction
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


  // This prevents flickering of uncertain values
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
