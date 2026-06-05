#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);  

  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("SSD1306 初始化失败！");
    for(;;);
  }
  Serial.println("OLED 已连接");

  display.clearDisplay();             
  display.setTextSize(1);  
  display.setTextColor(SSD1306_WHITE); 
  display.setCursor(0, 0);  
  display.println("Hello, World!");
  display.println("ESP32 + OLED");
  display.display();
}

void loop() {

}