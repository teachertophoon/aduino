// p. 270

const unsigned int led[7] = { 2, 3, 4, 5, 6, 7, 8 };

void setup() {
  for (int x = 0; x < 7; x++) {
    pinMode(led[x], OUTPUT); 
  }
}

void loop() {
  // led 켜기
  for (int x = 0; x < 7; x++) {
    digitalWrite(led[x], HIGH);
  }
  delay(500);

  // led 끄기
  for (int x = 0; x < 7; x++) {
    digitalWrite(led[x], LOW);
  }
  delay(500);
}

// p.270
