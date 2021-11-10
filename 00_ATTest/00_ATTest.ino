#include "SoftwareSerial.h"

SoftwareSerial serial1(2, 3); // TX, RX (아두이노 기준 RX, TX)

void setup() {
  Serial.begin(9600);
  serial1.begin(9600);
}

void loop() {
  if (serial1.available()) {
    Serial.write(serial1.read()); // write 함수는 byte 출력, print 함수와 동일한 기능
  }

  if (Serial.available()) {
    serial1.write(Serial.read());
  }
}
