#include <Servo.h>

const int analogPin = A0; // 가변저항
const int SERVO = 10; // 서보모터
Servo servo;

int step = 0; // 단계

void setup() {
  Serial.begin(115200); // 가변저항 값 확인을 위해 시리얼모니터 연결
}

void loop() {
  int analogValue = analogRead(analogPin);
  Serial.println(analogValue);

  if (step == 0) {
    servo.attach(SERVO);
    servo.write(0);
    delay(1000); // 0도로 돌아가기 위한 충분한 시간을 줌
    step++;
  }
  else if (step == 1) {
    // 와이퍼가 0도에서 180도까지 왕복 1초
    servo.write(180);
    delay(500);
    servo.write(0);
    delay(500);

    if (analogValue > 10) {
      if (analogValue > 10 && analogValue < 205) {
        delay(5000); 
      }
      else if (analogValue >= 205 && analogValue < 410) {
        delay(4000);
      }
      else if (analogValue >= 410 && analogValue < 615) {
        delay(3000);
      }
      else if (analogValue >= 615 && analogValue < 820) {
        delay(2000);
      }
      else if (analogValue >= 820 && analogValue < 1024) {
        delay(1000);
      }
    }
    else {
      step++;
    }
  }
  else if (step == 2) {
    servo.detach();
    step++;
  }
  else if (step == 3) {
    if (analogValue > 10) {
      step = 0;
    }
  }
}
