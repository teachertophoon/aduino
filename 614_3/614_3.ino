// p. 349 아래 코드

const int LED = 13;
int on_off = 0;

unsigned long t_prev = 0;
const unsigned long t_delay = 500;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  // 첫 번째 작업
  unsigned long t_now = millis();
  if (t_now - t_prev >= t_delay) {
    t_prev = t_now;
  ////////////////////////////////

    // 실제 작업하는 내용
    on_off++;
    if (on_off > 1) on_off = 0;
    digitalWrite(LED, on_off);
  ////////////////////////////////
  }
  ////////////////////////////////

  // LED 1개를 회로에 추가
  // 위 예제를 참고하셔서 250밀리초 단위로 껐다켰다를 반복하세요.
  
  // P. 347 코드에서
  // Serial.println("t1"); 부분과 Serial.println("\tt2"); 부분을 각각
  // 13번 핀에 연결된 LED 점멸 코드와 다른핀에 연결된 LED 점멸코드로 바꿔주시면 됩니다.
}
