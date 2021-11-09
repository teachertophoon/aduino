// NDelay 라이브러리 적용하여 1초마다 온습도 측정값을 출력시켜보세요.
// 1. NDelayFunc.h 파일을 include 한다.
#include "NDelayFunc.h"

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE); // DHT 객체를 생성, dht(2, 11)

float h; // 습도
float t; // 온도

// 2. 반복 실행할 코드를 함수로 만든다.
void readDHT() {
  h = dht.readHumidity(); // 현재 측정된 습도 값 가져오는 함수 호출
  t = dht.readTemperature(); // 현재 측정된 온도 값 가져오는 함수 호출

  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("Temperature: ");
  Serial.println(t);
}

// 3-1. 전역변수로 NDelayFunc 객체를 생성한다.
// 3-2. 객체 생성 시, 첫 번째 파라메터는 몇초마다 반복할지 설정
// 3-3. 객체 생성 시, 두 번째 파라메터는 반복 실행할 함수명(2번에서 작성한 함수명)을 작성
NDelayFunc nDelayReadDHT(1000, readDHT);

void setup() {
  Serial.begin(9600);
  dht.begin(); // 1. DHT 클래스에 정의된 begin 함수 호출
}

void loop() {
  // 4. loop 함수에 3번에서 생성한 nDelayReadDHT 객체를 이용하여 run() 함수를 실행한다.
  nDelayReadDHT.run();
}
