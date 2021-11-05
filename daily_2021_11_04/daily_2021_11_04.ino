#include "PinChangeInterrupt.h"

const int BUZZER = 10;
const int ACTIVE_BUZZER = 11;
const int button[4] = { 5, 4, 3, 2 };

int step = 1;
int currentQuestion = 1;
int buzzerMode = 0; // 0: 대기중, 1: 정답, 2: 오답

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
const int answers[2] = { 1, 1 };

void setup() {
  Serial.begin(115200);

  delay(1000);

  for (int n = 0; n < 4; n++) {
    pinMode(button[n], INPUT);
  }

  pinMode(ACTIVE_BUZZER, OUTPUT);

  // 인터럽트 추가
  attachPCINT(digitalPinToPCINT(button[0]), buttonPressed1, RISING); // 5번핀
  attachPCINT(digitalPinToPCINT(button[1]), buttonPressed2, RISING); // 4번핀
  attachInterrupt(digitalPinToInterrupt(button[2]), buttonPressed3, RISING); // 3번핀
  attachInterrupt(digitalPinToInterrupt(button[3]), buttonPressed4, RISING); // 2번핀
}

void buttonPressed1() {
  int num = 1;
  int answer = answers[currentQuestion - 1];
  // 정답일 경우
  if (num == answer) {
      buzzerMode = 1;
      step++;
  }
  // 정답이 아닐 경우
  else {
    buzzerMode = 2;
  }
}

void buttonPressed2() {
  int num = 2;
  int answer = answers[currentQuestion - 1];
  // 정답일 경우
  if (num == answer) {
      buzzerMode = 1;
      step++;
  }
  // 정답이 아닐 경우
  else {
    buzzerMode = 2;
  }
}

void buttonPressed3() {
  int num = 3;
  int answer = answers[currentQuestion - 1];
  // 정답일 경우
  if (num == answer) {
      buzzerMode = 1;
      step++;
  }
  // 정답이 아닐 경우
  else {
    buzzerMode = 2;
  }
}

void buttonPressed4() {
  int num = 4;
  int answer = answers[currentQuestion - 1];
  // 정답일 경우
  if (num == answer) {
      buzzerMode = 1;
      step++;
  }
  // 정답이 아닐 경우
  else {
    buzzerMode = 2;
  }
}

void loop() {
  if (step == 1) {
    int totalQuestionCount = sizeof(answers) / sizeof(answers[0]);
    if (currentQuestion <= totalQuestionCount) {
      Serial.print(questions[currentQuestion - 1]);
      Serial.print(options[currentQuestion - 1]);
      step++;
    }
    else {
      // IDLE
      step = 0;
    }
  }
  else if (step == 2) {
    // IDLE
    // 스위치의 인터럽트 발생을 기다리고 있는 중

    if (buzzerMode == 1) {
      // 440, 554, 659, 880 (딩동댕동!!)
      tone(BUZZER, 440); delay(300); noTone(BUZZER);
      tone(BUZZER, 554); delay(300); noTone(BUZZER);
      tone(BUZZER, 659); delay(300); noTone(BUZZER);
      tone(BUZZER, 880); delay(300); noTone(BUZZER);
      buzzerMode = 0;
    }
    else if (buzzerMode == 2) {
      // 능동 부저 (땡!)
      digitalWrite(ACTIVE_BUZZER, HIGH);
      delay(1000);
      digitalWrite(ACTIVE_BUZZER, LOW);
      buzzerMode = 0;
    }
  }
  else if (step == 3) {
    step = 1;
    currentQuestion++;
  }
}
