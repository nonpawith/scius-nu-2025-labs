#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "MAX30100_PulseOximeter.h"

#define REPORTING_PERIOD_MS 500

#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS  0x3c

PulseOximeter pox;
uint32_t tsLastReport = 0;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
float x1, x2;
unsigned char x3, x4;

void onBeatDetected() {
  Serial.println("Beat!");
}

void setup() {
  Serial.begin(115200);
  Serial.print("Initializing pulse oximeter..");
  pinMode(23, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)){
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.setTextColor(WHITE);

  if(!pox.begin()){
    Serial.println("FAILED");
    for(;;);
  } else {
    Serial.println("SUCCESS");
  }
  pox.setOnBeatDetectedCallback(beep001);

}

void loop() {
  pox.update();
  display.clearDisplay();
  yellow_display();
  if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
    Serial.print("Heart rate:");
    x1 = pox.getSpO2();
    x2 = pox.getHeartRate();
    x3 = x1;
    x4 = x2;
    Serial.print(x2);
    Serial.print("bpm / SpO2:");
    Serial.print(x1);
    Serial.println("%");
    display.setTextSize(2);
    display.setCursor(0, 22);
    display.print("SpO2: ");
    display.print(x3);
    display.setTextSize(1);
    display.setCursor(110, 27);
    display.print(" %");
    display.setTextSize(2);
    display.setCursor(0, 50);
    display.print("HR: ");
    display.print(x4);
    display.setTextSize(1);
    display.setCursor(100, 55);
    display.print("BPM");
    display.display();
    tsLastReport = millis();
  }
}

void yellow_display() {
  display.setTextSize(1);
  display.setCursor(15, 2);
  display.print(" BME KMUTNB 2025");
}

void beep001() {
  digitalWrite(23, LOW);
  digitalWrite(25, LOW);
  delay(2);
  digitalWrite(23, HIGH);
  digitalWrite(25, HIGH);
  delay(2);
  digitalWrite(23, LOW);
  digitalWrite(25, LOW);
  delay(2);
}
