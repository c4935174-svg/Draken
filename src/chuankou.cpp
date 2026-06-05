#include <Arduino.h>

// 改用 GPIO4 和 GPIO5
#define LED1 4
#define LED2 5

const String CMD_LED1 = "1";
const String CMD_LED2 = "2";

bool led1State = false;
bool led2State = false;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);

  Serial.begin(115200);
  Serial.println("System ready. Send '1' or '2' to toggle LED.");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readString();
    input.trim();

    if (input == CMD_LED1) {
      led1State = !led1State;
      digitalWrite(LED1, led1State ? HIGH : LOW);
      Serial.print("LED1 is ");
      Serial.println(led1State ? "ON" : "OFF");
    }
    else if (input == CMD_LED2) {
      led2State = !led2State;
      digitalWrite(LED2, led2State ? HIGH : LOW);
      Serial.print("LED2 is ");
      Serial.println(led2State ? "ON" : "OFF");
    }
    else {
      Serial.print("Unknown command: ");
      Serial.println(input);
    }
  }
}