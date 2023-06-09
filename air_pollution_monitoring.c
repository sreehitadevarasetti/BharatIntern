const int MQ135Pin = A0; // Analog pin for MQ135 sensor
const int LEDPin = 13; // Digital pin for LED
const int BuzzerPin = 12; // Digital pin for buzzer

// Define variables
int MQ135Value = 0; // Value read from MQ135 sensor
float ppm = 0; // Parts per million of air pollutant
int warningThreshold = 100; // Warning threshold for air pollutant level

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize LED and buzzer pins
  pinMode(LEDPin, OUTPUT);
  pinMode(BuzzerPin, OUTPUT);
}

void loop() {
  // Read MQ135 sensor value
  MQ135Value = analogRead(MQ135Pin);

  // Calculate parts per million of air pollutant using the formula
  // ppm = (Rs/Ro)^((log10(Rs/Ro)-0.153)/0.47+1.34)
  float RsRoRatio = ((1023.0 / MQ135Value) - 1);
  ppm = pow(10, ((log10(RsRoRatio) - 0.153) / 0.47) + 1.34);

  // Print ppm value to serial monitor
  Serial.print("PPM: ");
  Serial.println(ppm);

  // Check if ppm value is above warning threshold
  if (ppm > warningThreshold) {
    // Turn on LED and buzzer
    digitalWrite(LEDPin, HIGH);
    digitalWrite(BuzzerPin, HIGH);

    // Print warning message to serial monitor
    Serial.println("Air pollutant level is above warning threshold!");
  }
   else {
    // Turn off LED and buzzer
    digitalWrite(LEDPin, LOW);
    digitalWrite(BuzzerPin, LOW);
  }

  // Delay for 1 second before reading sensor again
  delay(3000);
}