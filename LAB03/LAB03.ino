#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH    128
#define SCREEN_HEIGHT   64
#define OLED_RESET      -1
#define SCREEN_ADDRESS  0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
unsigned char x1=24, x2=63;

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)){
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
}

void loop() {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(15, 2);
  display.print(" BME KMUTNB 2025");
  display.setTextSize(2);
  display.setCursor(1, 22);
  display.print("SpO2 = ");
  display.print(x1);
  display.setCursor(1, 50);
  display.print("HR = ");
  display.print(x2);
  display.display();
  delay(500);
  display.clearDisplay();
  display.display();
  delay(500);
}
