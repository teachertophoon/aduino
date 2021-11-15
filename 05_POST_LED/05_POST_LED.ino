// WiFi 모듈 ESP-01 테스트 코드

#include "WiFiEsp.h"
#include "SoftwareSerial.h"
SoftwareSerial Serial1(2, 3); // TX, RX (아두이노는 RX, TX 순)

char ssid[] = "HYOSUNG-2G"; // 공유기 WiFi 이름
char pass[] = "hshs7001"; // 공유기 비밀번호

WiFiEspServer server(80); // 80번 포트 사용하는 서버 객체를 생성

void setup() {
  // debugging을 위한 시리얼 초기화
  Serial.begin(9600);

  // ESP-01 모듈을 위한 시리얼 초기화
  Serial1.begin(9600);

  // ESP 모듈 초기화
  WiFi.init(&Serial1);

  Serial.print("연결을 시도 중 입니다. WPA SSID: ");
  Serial.println(ssid);

  // WiFi 네트워크 연결
  WiFi.begin(ssid, pass);

  Serial.println("연결 되었습니다.");

  // 아두이노 웹 서버 시작
  server.begin();
}

void loop() {
  // 클라이언트 접속여부 확인 (Listen)
  WiFiEspClient client = server.available(); // (Listen)

  if (client) {
    Serial.println("새로운 클라이언트 접속");

    // Django 서버로부터 전달받은 요청처리
    char* buf = (char*)malloc(sizeof(char) * 512); // 요청받은 내용 저장공간 512Byte
    int index = 0;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        buf[index++] = c;
      }
      else {
        char* dataLength = (char*)malloc(sizeof(char) * 50); // 50Byte 메모리 할당
        getHeaderValue(buf, dataLength, "Content-Length: ");
        int length = atoi(dataLength); // 문자열을 정수로 변환

        // JSON 문자열을 요청받은 문자열로부터 끄집어 내기
        if (length > 0) {
          for (int i = 0; i < strlen(dataLength); i++) {
            dataLength[i] = '\0';
          }

          int cnt = 0;
          char* body = strstr(buf, "\r\n\r\n");
          int newLineLength = strlen("\r\n\r\n");
          for (int i = newLineLength; i < length + newLineLength; i++) {
            dataLength[cnt++] = body[i];
          }
          dataLength[cnt] = '\0';
          Serial.print("직렬화 된 JSON: ");
          Serial.println(dataLength);
        }
        free(dataLength);
        free(buf);
      }
    }

    // JSON 응답
    client.flush(); // 클라이언트에게 보내줄 정보를 누락없이 마무리하여 보내주도록 하는 함수
    client.stop(); // 서버와 클라이언트 간의 연결을 끊어주는 역할
    Serial.println("클라이언트 연결 끊김");
  }
}
