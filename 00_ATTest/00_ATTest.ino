#include "SoftwareSerial.h"

SoftwareSerial serial1(2, 3); // TX, RX (아두이노 기준 RX, TX)

void setup() {
  Serial.begin(9600);
  serial1.begin(9600);
}

void loop() {
  if (serial1.available()) {
    Serial.write(serial1.read());
  }

  if (Serial.available()) {
    serial1.write(Serial.read());
  }
}
