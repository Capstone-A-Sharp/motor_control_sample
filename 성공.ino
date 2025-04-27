// 핀 설정
const int pwmPin = 9;    // PWM 신호 핀 (속도 제어)
const int a1Pin = 8;     // A1 방향 제어 핀
const int a2Pin = 7;     // A2 방향 제어 핀

void setup() {
  pinMode(pwmPin, OUTPUT);
  pinMode(a1Pin, OUTPUT);
  pinMode(a2Pin, OUTPUT);
}

void loop() {
  // 정회전
  digitalWrite(a1Pin, HIGH);  // A1 핀 HIGH
  digitalWrite(a2Pin, LOW);   // A2 핀 LOW
  analogWrite(pwmPin, 16);   // 속도 제어 (0~255, 50% 듀티)
  delay(2000);                // 2초 유지

  // 역회전
  digitalWrite(a1Pin, LOW);   // A1 핀 LOW
  digitalWrite(a2Pin, HIGH);  // A2 핀 HIGH
  analogWrite(pwmPin, 16);   // 속도 유지
  delay(2000);                // 2초 유지

  // // 정지
  // digitalWrite(a1Pin, LOW);
  // digitalWrite(a2Pin, LOW);
  // analogWrite(pwmPin, 0);     // 속도 0
  // delay(2000);                // 2초 유지
}
