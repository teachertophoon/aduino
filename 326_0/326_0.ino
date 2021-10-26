// p.161

const int led[6] = { 3, 5, 6, 9, 10, 11 };
const int buttonPin = 2;

void setup() {
  for (int x = 0; x <= 5; x++) {
    pinMode(led[x], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonInput = digitalRead(buttonPin);
  if (buttonInput == HIGH) {
    for (int x = 0; x <= 5; x++) {
      // led 모두 끄기
      for (int y = 0; y <= 5; y++) {
        digitalWrite(led[y], LOW);
      }

      digitalWrite(led[x], HIGH);

      buttonInput = digitalRead(buttonPin);
      if (buttonInput == LOW) break;

      delay(50);
    }
  }
}
