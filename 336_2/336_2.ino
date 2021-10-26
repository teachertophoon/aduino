// p.178

const int led[6] = { 3, 5, 6, 9, 10, 11 };
const int analogPin = A0;

void setup() {

}

void loop() {
  int sensorInput = analogRead(analogPin);

  // 예: 가변저항 400
  for (int n = 0; n <= 5; n++) {
    if (sensorInput / 171 >= 1+n)
      analogWrite(led[n], 255);
    else if (sensorInput / 171 >= 0+n)
      analogWrite(led[n], int(sensorInput % 171 / 171.0 * 255));
  }
}
