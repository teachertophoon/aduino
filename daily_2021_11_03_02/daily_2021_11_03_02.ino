const int BUZZER = 10;
const int trig_pin = 11;
const int echo_pin = 12;

int step = 1;

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  Serial.begin(115200);
}

void loop() {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  long duration = pulseIn(echo_pin, HIGH);
  long distance = (duration / 2) / 29.1;

  Serial.print(distance);
  Serial.println(" cm");

  if (step == 1) {
    if (distance <= 10) {
      step++;
    }
  }
  else if (step == 2) {
    if (distance > 10) {
      tone(BUZZER, 262);
      delay(3000);
      noTone(BUZZER);
      step = 1;
    }
  }
}
