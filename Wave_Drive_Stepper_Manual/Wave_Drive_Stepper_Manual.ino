// manual wave motor
int drive[4] = {2, 3, 4, 5};
int drives = sizeof(drive) / sizeof(int);

// Clockwise Rotation
int cw[4][4] = {{HIGH, HIGH, LOW, LOW}, // Step 1
                {LOW, HIGH, HIGH, LOW}, // Step 2
                {LOW, LOW, HIGH, HIGH}, // Step 3
                {HIGH, LOW, LOW, HIGH}}; // Step 4

// Counter Clockwise Rotation      
int ccw[4][4] = {{HIGH, HIGH, LOW, LOW}, // Step 1
                 {HIGH, LOW, LOW, HIGH}, // Step 2
                 {LOW, HIGH, HIGH, LOW}, // Step 3
                 {LOW, LOW, HIGH, HIGH}}; // Step 4

// Wave Drive Clockwise
int wave_cw[4][4] = {{HIGH, LOW, LOW, LOW}, // Step 1
                  {LOW, HIGH, LOW, LOW}, // Step 2
                  {LOW, LOW, HIGH, LOW}, // Step 3
                  {LOW, LOW, LOW, HIGH}}; // Step 4

// Wave Drive Counter Clockwise
int wave_ccw[4][4] = {{LOW, LOW, LOW, HIGH}, // Step 1
                  {LOW, LOW, HIGH, LOW}, // Step 2
                  {LOW, HIGH, LOW, LOW}, // Step 3
                  {HIGH, LOW, LOW, LOW,}}; // Step 4

void setup() {
  for (int i = 0; i < drives; i++) {
    pinMode(drive[i], OUTPUT);
  }
}

void loop() {
  int count = 0;
  while (count < 256) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        digitalWrite(drive[j], wave_ccw[i][j]);
      }
      delay(3);
    }
    count++;
  }
  delay(1000);
  count = 0;
  while (count < 256) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        digitalWrite(drive[j], wave_cw[i][j]);
      }
      delay(3);
    }
    count++;
  }
  delay(1000);
}
