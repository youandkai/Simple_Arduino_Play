// Ultrasonic Sonar Test
/*
10 LED's on pins 2-11
220k Resistors
VCC - 5V
trig - 13
echo - 12
GND - GND
*/

const int trig = 13;
const int echo = 12;

long dur;
int dist;

// leds
int led[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int gauge = 0;

// previous ts
unsigned long prev_ts = 0;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  for (int i = 0; i < 10; i++) {
    pinMode(led[i], OUTPUT);
  }
  Serial.begin(9600);
}
 
void loop() {
  // Obtain timestamp
  unsigned long ts = millis();
  
  digitalWrite(trig, LOW);
  delayMicroseconds(5);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  dur = pulseIn(echo, HIGH, 30000); // 30000 is timeout value
  dist = dur * 0.034 / 2; // sound travels at 340 m/s, distance is doubled.
  if (dur == 0 | dist > 50) {
    pinMode(echo, OUTPUT);
    digitalWrite(echo, LOW);
    delay(1);
    pinMode(echo, INPUT);
  }

  if (dist > 0 & dist < 50) {
    gauge = map(dist, 2, 20, 10, 1);
  } else {
    gauge = 0;
  }
  for (int i = 0; i < 10; i++) {
    if (i < gauge) {
      digitalWrite(led[i], HIGH);
    }
    else {
      digitalWrite(led[i], LOW);
    }
  }
  prev_ts = ts;
  Serial.print("Distance: ");
  Serial.println(dist);

}
