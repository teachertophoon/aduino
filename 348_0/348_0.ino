// p.197

const int BUZZER = 10;
const int button[2] = { 3, 2 };

const int note[2] = { 262, 294 };

void setup() {
  for (int n = 0; n <= 1; n++) {
    pinMode(button[n], INPUT);
  }
}

void loop() {
  if (digitalRead(button[0]) == HIGH) {
    tone(BUZZER, note[0]);
  }
  else if (digitalRead(button[1]) == HIGH) {
    tone(BUZZER, note[1]);
  }
  else {
    noTone(BUZZER);
  }
}
