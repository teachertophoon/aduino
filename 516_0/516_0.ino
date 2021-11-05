// p. 271

const unsigned int led[7] = { 2, 3, 4, 5, 6, 7, 8 };

// p.274
void display_init() {
  for (int x = 0; x < 7; x++) {
    pinMode(led[x], OUTPUT); 
  }
}

void display_clear() {
  // led 모두 끄기
  for (int x = 0; x < 7; x++) {
    digitalWrite(led[x], LOW);
  }
}

void setup() {
  display_init();
}

void loop() {
  for (int x = 0; x < 7; x++) {
    
    display_clear();

    digitalWrite(led[x], HIGH);
    
    //delay(500); // 1/3.5 = 0.286Hz (50Hz 이하이기 때문에 명확하게 하나씩 불이 들어오는걸 확인가능)
    delay(1); // 1/0.007 = 143Hz
  }
}

// p.271
