// p. 355
#include "NDelayFunc.h"

const int t1_LED = 13;
unsigned int on_off = 0;

const int t2_LED = 10;
unsigned int t_high = 0;

unsigned long t1_prev = 0;
const unsigned long t1_delay = 500;

unsigned long t2_prev = 0;
const unsigned long t2_delay = 4;

void fading() {
  t_high++;
  if (t_high > 255) t_high = 0;
  analogWrite(t2_LED, t_high);
}

void blink() {
  on_off++;
  if (on_off > 1) on_off = 0;
  digitalWrite(t1_LED, on_off);
}

NDelayFunc nDelayBlink(500, blink); // blink 함수를 500밀리초마다 실행한다고 선언
NDelayFunc nDelayFading(4, fading); // fading 함수를 4밀리초마다 실행한다고 선언

void setup() {
  pinMode(t1_LED, OUTPUT);
}

void loop() {
  nDelayBlink.run(); // blink 함수를 500밀리초마다 실행!
  nDelayFading.run(); // fading 함수를 4밀리초마다 실행!
}
