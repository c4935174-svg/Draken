#include <Arduino.h>
int ledPins[] = {2, 4, 5, 18};        // 按顺序排列
int ledCount = 4;                     // LED 数量

void setup() {
  // 将所有 LED 引脚设置为输出模式
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
    // 初始状态全部熄灭
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  // 阶段 1：依次点亮所有 LED（每个点亮后保持）
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);   // 点亮当前 LED
    delay(200);                       // 等待 200 毫秒
  }

  // 阶段 2：依次熄灭所有 LED（每个熄灭后保持）
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], LOW);    // 熄灭当前 LED
    delay(200);                       // 等待 200 毫秒
  }
}