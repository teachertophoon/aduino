// p. 355

class NDelayFunc {
  // 멤버변수
  unsigned long t_prev; // 이전 수행 시간
  const unsigned long t_delay; // 반복시간 설정(딜레이 설정)
  void (* func)(); // 함수포인터 (함수의 주소를 저장하는 변수)

  public: // 클래스를 객체화 한 뒤, 외부에서 호출 가능한 부분 (접근제한자)
    // 생성자
    NDelayFunc(
      const unsigned long t_delay,
      void (* func)()
      ) : t_prev(0), t_delay(t_delay), func(func) // 멤버 초기화 리스트
      {} 

  void run() {
    unsigned long t_now = millis();
    if (t_now - t_prev >= t_delay) {
      t_prev = t_now;

      func();
    }
  }
};

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
