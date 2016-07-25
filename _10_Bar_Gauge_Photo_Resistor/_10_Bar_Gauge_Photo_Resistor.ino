// Circuit for Photoresistor
// GND --- 10k --- A0 --- PhotoResistor --- 5V

// Circuit for each of the LEDs --- 10 LED Gauge
// GND --- 220k --- LED --- Pins(2-11)

// Initiate the LEDs on the gauge
int gauge[] = {10, 11, 9, 8, 3, 2, 4, 5, 6, 7};
// Count the number of LEDs, sizeof represents size in bytes
// int is 2 bytes
int bars = sizeof(gauge) / sizeof(int);

// Initiate the sensor pin
int sensor = A0;

void setup() {
  // Need to initiate in order for the serial monitor to work
  Serial.begin(9600);
  // Set all of the LEDs to OUTPUT
  for (int i; i < bars; i++) {
    pinMode(gauge[i], OUTPUT);
  }
  // Set the sensor to input
  pinMode(sensor, INPUT);
}

void loop() {
  // Use the serial monitor to monitor the output
  Serial.print("Sensor Reading: ");
  Serial.println(analogRead(sensor));
  // Mapping the sensor values
  int intensity = map(analogRead(sensor), 100, 1000, 0, 9);
  // Only light up when the bar is paste a certain threshold
  for (int i; i < bars; i++) {
    if (i <= intensity) {
      digitalWrite(gauge[i], HIGH);
    }
    else {
      digitalWrite(gauge[i], LOW);
    }
  }
}
