void setup() {
  Serial.begin(9600);
  randomSeed(100); // 0 ~ 1023 사이의 값

  int randNumber = random(300); // 0에서 299 사이 임의의 값 출력
  Serial.println(randNumber);

  int randNumber2 = random(10, 20); // 10에서 19 사이 임의의 값 출력
  Serial.println(randNumber2);
}

void loop() {
  
}
