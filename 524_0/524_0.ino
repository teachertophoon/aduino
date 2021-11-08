// p.299 (공통 양극 4자리 7세그먼트)

const unsigned int led[7] = { 2, 3, 4, 5, 6, 7, 8 };
const unsigned int com[1+4] = { -1, 9, 10, 11, 12 };

const unsigned int num[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 }, /* 0 */
  { 0, 1, 1, 0, 0, 0, 0 }, /* 1 */
  { 1, 1, 0, 1, 1, 0, 1 }, /* 2 */
  { 1, 1, 1, 1, 0, 0, 1 }, /* 3 */
  { 0, 1, 1, 0, 0, 1, 1 }, /* 4 */
  { 1, 0, 1, 1, 0, 1, 1 }, /* 5 */
  { 1, 0, 1, 1, 1, 1, 1 }, /* 6 */
  { 1, 1, 1, 0, 0, 1, 0 }, /* 7 */
  { 1, 1, 1, 1, 1, 1, 1 }, /* 8 */
  { 1, 1, 1, 1, 0, 1, 1 }  /* 9 */
};

void display_init() {
  for (int x = 0; x < 7; x++) {
    pinMode(led[x], OUTPUT);
  }

  for (int y = 1; y <= 4; y++) {
    pinMode(com[y], OUTPUT);
  }
}

void display_clear() {
  for (int x = 0; x < 7; x++) {
    digitalWrite(led[x], HIGH); // 공통양극
  }
  for (int y = 1; y <= 4; y++) {
    digitalWrite(com[y], LOW); // 공통양극
  }
}

// 함수를 정의
void display_number(unsigned int n, unsigned int m) {
  display_clear();

  if (0 <= n && n <= 9 && 1 <= m && m <= 4) {
    for (int x = 0; x < 7; x++) {
      digitalWrite(led[x], num[n][x] == 1 ? LOW : HIGH); // 공통양극
    }
    digitalWrite(com[m], HIGH); // 공통양극
  }
}

void display_numbers(unsigned int num) {
  // 변수 num이 1일 경우, 변수 num이 5678일 경우
  unsigned int num_1000 = num / 1000; // 0, 5
  unsigned int num_100 = (num % 1000) / 100; // 0, 6
  unsigned int num_10 = (num % 100) / 10; // 0, 7
  unsigned int num_1 = num % 10; // 1, 8

  // 변수 num이 1일 경우는 0001
  // 변수 num이 5678일 경우는 5678

  display_number(num_1000, 1);
  delay(1);
  display_number(num_100, 2);
  delay(1);
  display_number(num_10, 3);
  delay(1);
  display_number(num_1, 4);
  delay(1);
}

void setup() {
  display_init();
}

void loop() {
  // p.300
  static unsigned int num = 0; // static 키워드가 붙으면 전역변수와 동일하게 동작합니다.
  num++;

  // p.301
  unsigned int cnt = 0;
  while(1) {
    display_numbers(num); // 한 번 호출하는데 0.004초 소요
    cnt++;
    if (cnt == 25) break;
  }
  // cnt: 250 while문 한 번 실행하는데 총 1초가 소요
  // cnt: 25 while문 한 번 실행하는데 총 0.1초가 소요
}
