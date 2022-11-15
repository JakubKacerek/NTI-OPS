#include "mbed.h"
#include "stm32746g_discovery_lcd.h"

#define TIME 1000

Thread t1;
Thread t2;

void display(int xPosition, int yPosition, int number) {
  BSP_LCD_DisplayStringAt(xPosition, yPosition,
                          (uint8_t *)"Adam Jakub" + number, CENTER_MODE);
}

void startThread1() {
  display(0, 50, 3);
  HAL_Delay(DISPLAY_TIME);
}

void startThread2() {
  display(0, 100, 5);
  HAL_Delay(DISPLAY_TIME);
}

int main() {
  BSP_LCD_Init();
  BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
  BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);

  BSP_LCD_Clear(LCD_COLOR_BLACK);
  BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
  BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
  BSP_LCD_SetTextColor(LCD_COLOR_MAGENTA);

  t1.start(startThread1);
  t1.join();
  BSP_LCD_Clear(LCD_COLOR_BLACK);
  ThisThread::sleep_for(DISPLAY_TIME);

  t2.start(startThread2);
  t2.join();
  BSP_LCD_Clear(LCD_COLOR_BLACK);
  ThisThread::sleep_for(DISPLAY_TIME * 2);

  while (true) {
  }
}
