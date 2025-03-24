const int humidPin = A1;  // Analog input pin for humidity sensor
const int ledPin = 13;   // Digital output pin for LED indicator

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int humidReading = analogRead(humidPin);
  float humidity = (humidReading * 5.0 / 1024.0) * 100.0;
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  if (humidity > 60.0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000);
}
