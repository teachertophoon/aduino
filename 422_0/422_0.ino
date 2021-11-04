// p.244

const int ledPin = 13;
const int buttonPin = 2;

int led_state = LOW;
bool led_state_changed = false;

void buttonPressed() {
  led_state = (led_state == LOW) ? HIGH : LOW; // 삼항연산자
  led_state_changed = true;
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressed, RISING);
}

void loop() {
  if (led_state_changed) {
    led_state_changed = false;
    digitalWrite(ledPin, led_state);
  }
}
