// 채널 A 제어 핀
const int motorA1 = 8;
const int motorA2 = 9;
const int motorPW_A = 3;

// 채널 B 제어 핀
const int motorB1 = 10;
const int motorB2 = 11;
const int motorPW_B = 5;

// 스위치 입력 핀
const int switchPin = 2;

void setup() {
  Serial.begin(115200);

  // 모터 핀 설정
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorPW_A, OUTPUT);

  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorPW_B, OUTPUT);

  // 스위치 핀 설정 (내부 풀업 저항 사용)
  pinMode(switchPin, INPUT_PULLUP);
}

void loop() {
  if (Serial.available()) {
    int speed = Serial.parseInt(); // 시리얼로 속도 입력
    Serial.print("입력된 속도: ");
    Serial.println(speed);

    int switchState = digitalRead(switchPin); // 스위치 상태 읽기

    controlMotors(speed, switchState); // 함수 호출
  }
}

//  모터 제어 함수
void controlMotors(int speed, int switchState) {
  if (speed <= 10) {
    stopMotors();
    return;
  }

  if (switchState == LOW) {
    // 스위치 OFF → 전진
    Serial.println("전진");
    forwardMotors(speed);
  } else {
    // 스위치 ON → 후진
    Serial.println("후진");
    backwardMotors(speed);
  }
}

//  정지 함수
void stopMotors() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);

  analogWrite(motorPW_A, 0);
  analogWrite(motorPW_B, 0);
}

// 전진 함수
void forwardMotors(int speed) {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  analogWrite(motorPW_A, speed);

  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(motorPW_B, speed);
}

// 후진 함수
void backwardMotors(int speed) {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  analogWrite(motorPW_A, speed);

  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  analogWrite(motorPW_B, speed);
}
