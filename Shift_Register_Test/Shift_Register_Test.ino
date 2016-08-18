// Here is the basic structure of the shift register that I have
/*
    --U-- - Shaped Indent Here
D1 |     | 5V - Power
D2 |     | D0 - Pin 1
D3 |     | Data - Input Data Pin
D4 |     | On/Off - Put on 5V - Always on
D5 |     | Latch - Execute
D6 |     | Clock - Push to Shift
D7 |     | Master Clear - Reset Everything to 0 - Put as GND
GND|_____| Connect to the next shift

 */

// Define pins
int latch = 2;
int data = 3;
int cp = 4;
int leds = 8;

unsigned int pattern[] = {
  B10000000,
  B11000000,
  B11100000,
  B11110000,
  B01111000,
  B00111100,
  B00011110,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
};

int count = sizeof(pattern) / sizeof(int);

void setup() {
  pinMode(latch, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(cp, OUTPUT);
}

void loop() {
  for (int i = 0; i < count; i++) {
    digitalWrite(latch, LOW);
    shiftOut(data, cp, MSBFIRST, pattern[i]);
    digitalWrite(latch, HIGH);
    delay(50);
  }
  for (int i = count - 1; i > 0; i--) {
    digitalWrite(latch, LOW);
    shiftOut(data, cp, MSBFIRST, pattern[i]);
    digitalWrite(latch, HIGH);
    delay(50);
  }
}

