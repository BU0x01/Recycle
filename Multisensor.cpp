const int tempPin = A0;  // Analog input pin for temperature sensor
const int humidPin = A1;  // Analog input pin for humidity sensor
const int pressPin = A2;  // Analog input pin for pressure sensor
const int ledPin = 13;   // Digital output pin for LED indicator

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int tempReading = analogRead(tempPin);
  float temperature = (tempReading * 5.0 / 1024.0) * 100.0;

  int humidReading = analogRead(humidPin);
  float humidity = (humidReading * 5.0 / 1024.0) * 100.0;

  int pressReading = analogRead(pressPin);
  float pressure = (pressReading * 5.0 / 1024.0) * 100.0;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println("mbar");

  if (temperature > 30.0 || humidity > 60.0 || pressure > 1000.0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000);
}
