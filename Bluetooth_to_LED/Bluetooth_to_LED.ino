#define led 3
int state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Serial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    state = Serial.read();
  }
  if (state = '0') {
    digitalWrite(led, LOW);
    Serial.println("LED: OFF");
    state = 0;
  }
  else if (state = '1') {
    digitalWrite(led, HIGH);
    Serial.println("LED: ON");
    state = 1;
  }
}
