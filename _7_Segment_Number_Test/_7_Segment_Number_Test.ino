int pin[8] = {6, 7, 8, 9, 10, 11, 12, 13};
int two[5] = {0, 1, 3, 4, 6};

int mat[11][8] = {{HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW}, // 0
                  {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW}, // 1
                  {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH, LOW}, // 2
                  {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH, LOW}, // 3
                  {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW}, // 4
                  {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH, LOW}, // 5
                  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, LOW}, // 6
                  {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW}, // 7
                  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW}, // 8
                  {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, LOW}, // 9
                  {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW}}; // Nothing

int knob = A0;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(pin[i], OUTPUT);
  }
  pinMode(knob, INPUT);
}

void loop() {
  int val = map(analogRead(knob), 0, 1023, 10, 0); // 0 - 1023
  if (val > 9) {
    val = 9;
  }
  number(val);
}

void number(int dig) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(pin[i], mat[dig][i]);
  }
}

