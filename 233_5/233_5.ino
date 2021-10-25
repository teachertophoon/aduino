// p.109

const unsigned int led[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };

void setup() {
  for (int x=0; x <= 7; x++) {
    pinMode(led[x], OUTPUT);
  }
}

void loop() {
  for (int x=0; x <= 7; x++) {
    for (int y=0; y <= 7; y++) {
      digitalWrite(led[y], LOW);
    }
  
    digitalWrite(led[x], HIGH);
  
    delay(500); // 0.25Hz

    digitalWrite(led[x], LOW);
  }
}
