int randNumber = random(300); // 0에서 299 사이 임의의 값 출력
int randNumber2 = random(10, 20); // 10에서 19 사이 임의의 값 출력

void setup() {
  Serial.begin(9600);
  Serial.println(sizeof(long)); // 아두이노에서는 32비트의 크기를 long 타입에 저장가능

  // long, int - 시드를 만들기 위해 숫자를 전달.
  // 첫 번째 파라미터 숫자는 long 타입에 저장할 수 있는 숫자 범위만큼 입력가능
  randomSeed(100); 
  
  Serial.println(randNumber);
  Serial.println(randNumber2);
}

void loop() {
  
}
