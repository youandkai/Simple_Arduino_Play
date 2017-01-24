// Circuit for Photoresistor
// GND --- 10k --- A0 --- PhotoResistor --- 5V

// Initiate the sensor pin
int pr1 = A0;
int pr2 = A1;
int pr3 = A2;

void setup() {
  // Need to initiate in order for the serial monitor to work
  Serial.begin(9600);
  // Set all of the LEDs to OUTPUT
  // Set the sensor to input
  pinMode(pr1, INPUT);
  pinMode(pr2, INPUT);
  pinMode(pr3, INPUT);
}

void loop() {
  // Use the serial monitor to monitor the output
  Serial.print("Sensor 1: ");
  Serial.print(analogRead(pr1));
  Serial.print(", Sensor 2: ");
  Serial.print(analogRead(pr2));
  Serial.print(", Sensor 3: ");
  Serial.println(analogRead(pr3));
  delay(1);
}
