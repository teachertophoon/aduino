// p.178

const int led[6] = { 3, 5, 6, 9, 10, 11 };
const int analogPin = A0;

int randNum1;
int randNum2;
int randNum3;

int step = 1; //

void setup() {
  Serial.begin(9600);

//  1. 금고 비밀번호는 아두이노가 처음 실행될 때 랜덤한 숫자 3개가 결정된다.
//  첫 번째 숫자 범위: 683 ~ 1023
//  두 번째 숫자 범위: 1 ~ 341
//  세 번째 숫자 범위: 342 ~ 682
  int sensorInput = analogRead(analogPin);
  
  randomSeed(sensorInput); // 가변저항의 현재값을 이용해서 랜덤한 값을 얻는다.
  randNum1 = random(683, 1024);
  randNum2 = random(1, 342);
  randNum3 = random(342, 683);
  
  Serial.println(randNum1);
  Serial.println(randNum2);
  Serial.println(randNum3);
}

void loop() {

//  2. 가변저항을 돌려서 가변저항 값과 랜덤한 숫자 3개가 각각 일치할 경우
//   LED로 적절하게 표시한다.

  // 2.1 가변저항의 현재 값을 가져온다.
  int sensorInput = analogRead(analogPin);

  //   - 첫 번째 숫자를 맞췄을 경우: 첫 번째 LED 점등
  if (step == 1) {
    Serial.print(randNum1);
    Serial.print(" / ");
    Serial.println(sensorInput);
    if (randNum1 == sensorInput) {
      analogWrite(led[0], 255);
      step++;
    }
  }

  //   - 두 번째 숫자를 맞췄을 경우: 두 번째 LED 점등
  else if (step == 2) {
    if (randNum2 == sensorInput) {
      analogWrite(led[1], 255);
      step++;
    }
  }
  
  //   - 세 번째 숫자까지 다 맞췄을 경우: 모든 LED를 3회 정도 깜박인 후 소등
  else if (step == 3) {
    if (randNum3 == sensorInput) {
      for (int i = 1; i <= 3; i++) {
        for (int x = 0; x <= 5; x++) {
          analogWrite(led[x], 255);  
        }
        
        delay(2000);
        
        for (int x = 0; x <= 5; x++) {
          analogWrite(led[x], 0);  
        }
  
        delay(2000);
      }
      
      step = 0;
    }
  }
  else if (step == 0) {
    // IDLE (공회전)
  }
}
