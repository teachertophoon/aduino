#include "WiFiEsp.h"
#include "SoftwareSerial.h"

SoftwareSerial Serial1(2, 3); // TX, RX

char ssid[] = "HYOSUNG-2G"; // 공유기 WiFi 이름
char pass[] = "hshs7001"; // 공유기 비밀번호
char server[] = "192.168.0.81"; // 여러분의 장고 서버IP주소

WiFiEspClient client;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  WiFi.init(&Serial1);
  Serial.print("연결을 시도 중 입니다. WPA SSID: ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  Serial.println("연결 되었습니다.");
}

void loop() {
  client.stop();

  if (client.connect(server, 8000)) {
    /* 
     * 1. GET 요청하기 
     */
    client.print("GET /api/test/ HTTP/1.1\r\n"); // 웹브라우저 주소창에 http://192.168.0.81:8000/api/test/
    client.print("Host: ");
    client.print(server);
    client.print(":8000\r\n"); // "Host: 192.168.0.81:8000"
    client.print("\r\n");
    // 요청 헤더정보 (Request Header)
    // GET /api/test/ HTTP/1.1
    // Host: 192.168.0.81:8000

    /*
     * 장고 서버로부터 전달받은 응답(Response)
     */
    // 응답 내용을 저장할 메모리 할당
    char* buf = (char*)malloc(sizeof(char) * 512); // 512Byte 크기 할당 (동적배열할당 / C언어 내용)
    int index = 0;

    while(client.connected()) {
      if (client.available()) { // 서버로부터 전달받은 응답 중 아두이노가 처리하지 않은 내용이 존재하는지 여부
        char c = client.read();
        buf[index++] = c;
      }
      else {
        client.stop();
      }
    }

    // 응답 내용을 출력
    for (int i = 0; i < index; i++) {
      Serial.print(buf[i]);
    }
    free(buf); // 할당 받았던 메모리를 해제
  }
}
