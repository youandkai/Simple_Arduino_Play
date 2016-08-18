// Must be one of those pins with a squiggly line

int x = A0;
int y = A1;
int led1 = 5;
int led2 = 3;
int button = 2;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(button, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int lumen1 = map(analogRead(x), 0, 1023, 10, 245);
  int lumen2 = map(analogRead(y), 0, 1023, 10, 245);
  analogWrite(led1, lumen1);
  analogWrite(led2, lumen2);
  Serial.print("x-value: ");
  Serial.println(lumen1);
  Serial.print("y-value: ");
  Serial.println(lumen2);
  delay(1); // delay in between reads for stability
}
