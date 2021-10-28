const int BUZZER = 10;
const int ACTIVE_BUZZER = 11;
const int button[4] = { 5, 4, 3, 2 };

int step = 1;
int currentQuestion = 1;

// 문제
const char *questions[2] = {
  "문제 1) 다음 중 컴퓨터의 기능이 아닌 것은?\n",
  "문제 2) 기록되어 있는 자료를 읽기만 가능한 기억 장치는?\n"
};

// 보기
const char *options[2] = {
  "1. 출력기능\t2. 입력기능\n3. 연산기능\t4. 판단기능\n",
  "1. 롬(ROM\t2. 램(RAM)\n3. 하드디스크\t4. 모니터\n"
};

// 답
const int answers[2] = { 4, 1 };

void setup() {
  Serial.begin(115200);

  delay(1000);

  for (int n = 0; n < 4; n++) {
    pinMode(button[n], INPUT);
  }

  pinMode(ACTIVE_BUZZER, OUTPUT);
}

void loop() {
  if (step == 1) {
    Serial.print(questions[currentQuestion - 1]);
    Serial.print(options[currentQuestion - 1]);
    step++;
  }
  else if (step == 2) {
    int answer = answers[currentQuestion - 1];

    // 정답일 경우
    if (digitalRead(button[answer - 1]) == HIGH) {
      // 440, 554, 659, 880 (딩동댕동!!)
      tone(BUZZER, 440); delay(300); noTone(BUZZER);
      tone(BUZZER, 554); delay(300); noTone(BUZZER);
      tone(BUZZER, 659); delay(300); noTone(BUZZER);
      tone(BUZZER, 880); delay(300); noTone(BUZZER);
    }
  }
}
