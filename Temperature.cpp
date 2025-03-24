const int tempPin = A0;  // Analog input pin for temperature sensor
const int ledPin = 13;   // Digital output pin for LED indicator

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int tempReading = analogRead(tempPin);
  float temperature = (tempReading * 5.0 / 1024.0) * 100.0;
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  if (temperature > 30.0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000);
}
