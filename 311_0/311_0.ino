// p.141

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char userInput = Serial.read();
    Serial.print(userInput);
    Serial.print(".");
  }
}
