// Circuit for Photoresistor
// GND --- 10k --- A0 --- PhotoResistor --- 5V

// Initiate the sensor pin
int sensor1 = A0;
int sensor2 = A1;

unsigned long prev_ts = 0;

void setup() {
  // Need to initiate in order for the serial monitor to work
  Serial.begin(9600);
  // Set the sensor to input
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
}

void loop() {
  unsigned long ts = millis();
  if (ts - prev_ts > 100) {
    // Use the serial monitor to monitor the output
    Serial.print("Sensor Reading: ");
    Serial.print(analogRead(sensor1));
    Serial.print(", ");
    Serial.println(analogRead(sensor2));
    prev_ts = ts;
  }
}
