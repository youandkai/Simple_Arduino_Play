
// set LED pins
int led[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int leds = sizeof(led) / sizeof(int);

int rate = 10;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < leds; i++) {
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < leds; i++) {
    digitalWrite(led[i], HIGH);
  }
}
