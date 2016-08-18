// Kai Zhou
// Modified 2016-07-25

// So after plugging everything in using analog pins 16-19 as digital
// digital write every pin and combinations of pins and define them in rows and columns

// Pontentiometers
/*
GND --- Meter 1 --- 5V
           |
           A0

GND --- Meter 2 --- 5V
           |
           A1
*/
// 8x8 Matrix Display
// pins --- pins(2-13,16-19), resistors not necessary, probably should have them, but works without them

// Testing phase, I plug stuff in randomly so I need to test what each pin does
/*
void loop {
  // digitalWrite(2, HIGH); // line 2
  // digitalWrite(3, HIGH); // column 7
  // digitalWrite(4, HIGH); // column 6
  // digitalWrite(5, HIGH); // line 1
  // digitalWrite(6, HIGH); // column 4
  // digitalWrite(7, HIGH); // line 3
  // digitalWrite(8, HIGH); // line 6
  // digitalWrite(9, HIGH); // line 4
  // digitalWrite(10, HIGH); // column 1
  // digitalWrite(11, HIGH); // column 2
  // digitalWrite(12, HIGH); // line 7
  // digitalWrite(13, HIGH); // column 8
  // digitalWrite(16, HIGH); // line 5
  // digitalWrite(17, HIGH); // column 3
  // digitalWrite(18, HIGH); // column 5
  // digitalWrite(19, HIGH); // line 8
}
*/

// these are rows and columns
int row[] = {5, 2, 7, 9, 16, 8, 12, 19};
int col[] = {10, 11, 17, 6, 18, 4, 3, 13};
int rows = sizeof(row) / sizeof(int);
int cols = sizeof(col) / sizeof(int);

// these are the knobs
const int knob1 = A0;
const int knob2 = A1;

void setup() {
  // I guess I need to monitor this something is not working
  Serial.begin(9600);
  // initialize all pins on rows and columns
  for (int i = 0; i < rows; i++) {
    pinMode(row[i], OUTPUT); 
  }
  for (int i = 0; i < cols; i++) {
    pinMode(col[i], OUTPUT);
  }
}

void loop() {
  digitalWrite(2, HIGH); // line 6
  digitalWrite(3, HIGH); // line 3
  // digitalWrite(4, HIGH); // column 4
  digitalWrite(5, HIGH); // line 1
  // digitalWrite(6, HIGH); // column 6
  // digitalWrite(7, HIGH); // column 7
  // digitalWrite(8, HIGH); // column 3
  digitalWrite(9, HIGH); // line 2
  // digitalWrite(10, HIGH); // column 1
  // digitalWrite(11, HIGH); // column 2
  digitalWrite(12, HIGH); // line 4
  // digitalWrite(13, HIGH); // column 8
  digitalWrite(16, HIGH); // line 7
  digitalWrite(17, HIGH); // line 5
  // digitalWrite(18, HIGH); // column 5
  digitalWrite(19, HIGH); // line 8
}

/*

// Ok, so I first need to star out stuff so I know how the hell I can get LED 1-1 to light up
// Don't forget to select COM4 --- Arduino Uno, swtiching boards here.
void loop() {
  int col_sel = map(analogRead(knob1), 0, 600, 9, 0);
  int row_sel = map(analogRead(knob2), 0, 600, 9, 0);
  Serial.println(analogRead(knob1));
  for (int i = 0; i < cols; i++) {
    if (i == col_sel) {
      digitalWrite(col[i], LOW);
    } else {
      digitalWrite(col[i], HIGH);
    }
  }
  digitalWrite(row[row_sel], HIGH);
}

/*
void lightCol(int sel) {
  for (int i = 0; i < rows; i++) {
    digitalWrite(row[i], HIGH);
    for (int j = 0; j < cols; j++) {
      if (j != sel) {
        digitalWrite(col[j], HIGH);
      }
      else {
        digitalWrite(col[j], LOW);
      }
    }
  }
}

void loop() {
  // int rate = map(analogRead(knob1), 1023, 0, 10, 1000);
  int rate = 100;
  for (int i = 0; i < rows; i++) {
    digitalWrite(row[i], HIGH);
    delay(rate); 
    digitalWrite(row[i], LOW);
  }
  for (int i = rows - 2; i > 0; i--) {
    digitalWrite(row[i], HIGH);
    delay(rate); 
    digitalWrite(row[i], LOW);
  }
}
*/

