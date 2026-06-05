#include <Arduino.h>
#include <Arduino.h>

#define IN1 4
#define IN2 5
#define IN3 13
#define IN4 14

const int stepSequence[4][4] = {
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1}
};

const int STEPS_PER_REV = 2048;
int stepDelay = 10; 

void rotateMotor(int steps, int direction) {
  int seqIndex = 0;
  int stepDir = (direction == 1) ? 1 : -1;

  for (int i = 0; i < abs(steps); i++) {
    digitalWrite(IN1, stepSequence[seqIndex][0]);
    digitalWrite(IN2, stepSequence[seqIndex][1]);
    digitalWrite(IN3, stepSequence[seqIndex][2]);
    digitalWrite(IN4, stepSequence[seqIndex][3]);

    delay(stepDelay);

    seqIndex += stepDir;
    if (seqIndex >= 4) seqIndex = 0;
    if (seqIndex < 0) seqIndex = 3;
  }

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(10);
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  Serial.begin(115200);
  Serial.println("Stepper motor ready");
}

void loop() {
  Serial.println("正转一圈");
  rotateMotor(STEPS_PER_REV, 1);
  delay(1000);

  Serial.println("反转一圈");
  rotateMotor(STEPS_PER_REV, -1);
  delay(1000);
}