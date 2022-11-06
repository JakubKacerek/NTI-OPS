#include "mbed.h"
#include "stm32746g_discovery_lcd.h"

Thread t1, t2;



void neco(int x, int y, int time){
        BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
        BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);
        BSP_LCD_DisplayStringAt(x, y, (uint8_t *)"Já jsem 1", CENTER_MODE);
        ThisThread::sleep_for(time);
}
void runThread1(){
    while(true){
        neco(2, 0, 1000);
    }
}

void runThread2(){
    while(true){
        neco(4, 4, 2000);
    }
}
int main()
{
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    t1.start(runThread1);
    t2.start(runThread2);
    while (true) {
        neco(3, -3, 500);
    }
}