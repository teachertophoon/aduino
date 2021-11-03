// p. 226

#include <TimerOne.h>

const int LED = 10;

void setup() {
  Timer1.initialize();
  Timer1.pwm(LED, 0); // 0 ~ 1023

  // Timer1.setPeriod(1000000); // 마이크로초 = 1초 1Hz
  // Timer1.setPeriod(1000000/10); // 10Hz
  //Timer1.setPeriod(1000000/100); // 100Hz
  Timer1.setPeriod(1000000/1000); // 1000Hz
  //Timer1.setPwmDuty(LED, 511); // 0 ~ 1023
  //Timer1.setPwmDuty(LED, 100); // 0 ~ 1023
  Timer1.setPwmDuty(LED, 900); // 0 ~ 1023
}

void loop() {

}
