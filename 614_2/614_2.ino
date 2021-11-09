// p. 349

const int LED = 13;
const int LED2 = 12;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  for (int on_off = 0; on_off <= 1; on_off++) {
    digitalWrite(LED, on_off);
    delay(500);
  }

  for (int on_off = 0; on_off <= 1; on_off++) {
    digitalWrite(LED2, on_off);
    delay(250);
  }
}
