// p.182

const int ledPin = 10;
const int analogPin = A0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int sensorInput = analogRead(analogPin);
  analogWrite(ledPin, sensorInput / 4);
}
