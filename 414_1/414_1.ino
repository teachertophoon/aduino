// p. 238

#include <TimerOne.h>

const int SERVO = 10;

const int SERVO_PERIOD = 20000; // us = 20ms(밀리초)
const int SERVO_MINDUTY = (1024 / 20) * 0.7; // 35, (1024 / 20)는 1ms(밀리초), 0.7밀리초
const int SERVO_MAXDUTY = (1024 / 20) * 2.3; // 117, 2.3밀리초

void setup() {
  Timer1.initialize();
  Timer1.pwm(SERVO, 0);

  Timer1.setPeriod(SERVO_PERIOD);
  Timer1.setPwmDuty(SERVO, SERVO_MINDUTY); // 한 주기 당 0.7밀리초 동안 HIGH 값을 줌

  delay(1000);

  for (int cnt = 0; cnt <= 2; cnt++) {
    Timer1.setPwmDuty(SERVO, SERVO_MINDUTY); // 0도로 회전
    delay(1000);
    Timer1.setPwmDuty(SERVO, SERVO_MAXDUTY); // 180도로 회전
    delay(1000);
  }

  Timer1.disablePwm(SERVO);
}

void loop() {

}
