// 드라이버 1 핀 설정
const int pwmPin1 = 9;    // 드라이버 1 PWM 핀
const int a1Pin1 = 8;     // 드라이버 1 A1 핀
const int a2Pin1 = 7;     // 드라이버 1 A2 핀

// 드라이버 2 핀 설정
const int pwmPin2 = 6;    // 드라이버 2 PWM 핀
const int a1Pin2 = 5;     // 드라이버 2 A1 핀
const int a2Pin2 = 4;     // 드라이버 2 A2 핀

void setup() {
  Serial.begin(115200); // 시리얼 통신 초기화

  // 드라이버 1 핀 설정
  pinMode(pwmPin1, OUTPUT);
  pinMode(a1Pin1, OUTPUT);
  pinMode(a2Pin1, OUTPUT);

  // 드라이버 2 핀 설정
  pinMode(pwmPin2, OUTPUT);
  pinMode(a1Pin2, OUTPUT);
  pinMode(a2Pin2, OUTPUT);
}

void loop() {
  if (Serial.available()) { // 시리얼 데이터가 있으면
    int speed = Serial.parseInt(); // 입력된 속도값을 읽음
    Serial.print("받은 속도: ");
    Serial.println(speed);

    if (speed <= 10) {
      // 속도가 0일 때 모터 정지 (신호 끊기)
      digitalWrite(a1Pin1, LOW);
      digitalWrite(a2Pin1, LOW);
      digitalWrite(a1Pin2, LOW);
      digitalWrite(a2Pin2, LOW);

      analogWrite(pwmPin1, 0); // PWM 신호 OFF
      analogWrite(pwmPin2, 0); // PWM 신호 OFF
    } else {
      // 드라이버 1: 정회전
      digitalWrite(a1Pin1, HIGH);  // 드라이버 1 A1 HIGH
      digitalWrite(a2Pin1, LOW);   // 드라이버 1 A2 LOW
      analogWrite(pwmPin1, speed); // 속도 설정

      // 드라이버 2: 정회전
      digitalWrite(a1Pin2, HIGH);  // 드라이버 2 A1 HIGH
      digitalWrite(a2Pin2, LOW);   // 드라이버 2 A2 LOW
      analogWrite(pwmPin2, speed); // 속도 설정
    }
  }

  delay(100); // 0.1초 대기 (입력 처리 시간)
}
