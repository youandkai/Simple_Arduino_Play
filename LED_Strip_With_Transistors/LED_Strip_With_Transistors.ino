
int green = 9;
int red = 10;
int blue = 11;


const int trig = 13;
const int echo = 12;

long dur;
int dist;

int lumen = 255;
int display_lumen = 255;

unsigned long prev_ts = 0;

void setup() {
  // Ultrasound
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  // put your setup code here, to run once:
  pinMode(green, INPUT);
  pinMode(red, INPUT);
  pinMode(blue, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
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
  lumen = map(constrain(dist, 0, 50), 0, 50, 0, 255);

  if (lumen < display_lumen - 25) {
    display_lumen--;
  } else if (lumen > display_lumen - 25) {
    display_lumen++;
  }
  if (ts - prev_ts > 10) {
    analogWrite(green, display_lumen);
    analogWrite(red, display_lumen);
    analogWrite(blue, display_lumen);
    prev_ts = ts;
  }
}
