#include "./functions.h"
#include "mbed.h"
#include "stm32746g_discovery_lcd.h"
#include <iostream>
#include <random>

Mutex stdio_mutex;

Thread thread1;
Thread thread2;
Thread thread3;

void displayOnDisplay(int xPosition, int yPosition, int number) {
    stdio_mutex.lock();
    BSP_LCD_DisplayStringAt(xPosition, yPosition, (uint8_t *)"ADAM JAKUB" + number, CENTER_MODE);
    stdio_mutex.unlock();
    ThisThread::sleep_for(THREAD_DURATION);
    stdio_mutex.lock();
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    stdio_mutex.unlock();
}

void startThread1() {
    while (true) {
        displayOnDisplay(0, 50, 5);
    }
}

void startThread2() {
    while (true) {
        displayOnDisplay(0, 100, 1);
    }
}

void startThread3() {
    while (true) {
        displayOnDisplay(0, 150, 7);
    }
}

int main() {
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);

    BSP_LCD_Clear(LCD_COLOR_BLACK);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
    BSP_LCD_SetTextColor(LCD_COLOR_MAGENTA);

    thread1.start(startThread1);
    thread2.start(startThread2);
    thread3.start(startThread3);
    while (true) {}
}
