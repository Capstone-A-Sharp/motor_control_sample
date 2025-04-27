
// 채널 A 제어 핀
const int motorA1 = 8;
const int motorA2 = 9;
const int motorPW_A = 3;  // 채널 A PWM

// 채널 B 제어 핀
const int motorB1 = 10;
const int motorB2 = 11;
const int motorPW_B = 5;  // 채널 B PWM

const int speed = 20;

void setup() {
  // 채널 A 핀 설정
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorPW_A, OUTPUT);

  // 채널 B 핀 설정
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorPW_B, OUTPUT);
}

void loop() {
  // ▶ 채널 A 정방향, 채널 B 역방향
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  analogWrite(motorPW_A, speed); // 채널 A 속도

  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(motorPW_B, speed); // 채널 B 속도

  // delay(3000);

  // // ▶ 둘 다 정지
  // digitalWrite(motorA1, LOW);
  // digitalWrite(motorA2, LOW);
  // analogWrite(motorPW_A, 0);

  // digitalWrite(motorB1, LOW);
  // digitalWrite(motorB2, LOW);
  // analogWrite(motorPW_B, 0);

  // delay(1000);

  // // ▶ 채널 A 역방향, 채널 B 정방향
  // digitalWrite(motorA1, LOW);
  // digitalWrite(motorA2, HIGH);
  // analogWrite(motorPW_A, speed);

  // digitalWrite(motorB1, HIGH);
  // digitalWrite(motorB2, LOW);
  // analogWrite(motorPW_B, speed);

  // delay(3000);

  // // ▶ 둘 다 정지
  // digitalWrite(motorA1, LOW);
  // digitalWrite(motorA2, LOW);
  // analogWrite(motorPW_A, 0);

  // digitalWrite(motorB1, LOW);
  // digitalWrite(motorB2, LOW);
  // analogWrite(motorPW_B, 0);

  // delay(1000);
}
