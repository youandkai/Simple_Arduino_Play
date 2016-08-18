
int green = 9;
int red = 10;
int blue = 11;

int knob = A0;
int lumen = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(green, INPUT);
  pinMode(red, INPUT);
  pinMode(blue, INPUT);
  pinMode(knob, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lumen = map(analogRead(knob), 0, 1023, 0, 255);
  
  analogWrite(green, lumen);
  analogWrite(red, lumen);
  analogWrite(blue, lumen);
}
