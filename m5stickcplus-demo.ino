#include <M5StickCPlus.h>

volatile uint8_t stage = 0;

void drawText(const char* text) {
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextDatum(MC_DATUM);
  int16_t x = M5.Lcd.width() / 2;
  int16_t y = M5.Lcd.height() / 2;
  M5.Lcd.drawString(text, x, y);
}

void setup() {
  M5.begin();

  M5.Beep.beep();
}

void loop() {
  M5.update();

  if (M5.BtnA.wasReleased()) {
    stage++;
    switch (stage) {
      case 1:
        drawText("Hello world!");
        break;
      case 2:
        drawText(String("Screen w: " + String(M5.Lcd.width())).c_str());
        break;
      case 3:
        drawText(String("Screen h: " + String(M5.Lcd.height())).c_str());
        break;
      default:
        M5.Lcd.fillScreen(BLACK);
        stage = 0;
    }
  }
}