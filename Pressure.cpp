const int pressPin = A2;  // Analog input pin for pressure sensor
const int ledPin = 13;   // Digital output pin for LED indicator

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int pressReading = analogRead(pressPin);
  float pressure = (pressReading * 5.0 / 1024.0) * 100.0;
  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println("mbar");

  if (pressure > 1000.0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000);
}
