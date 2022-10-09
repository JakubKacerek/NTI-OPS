#include "mbed.h"


Serial pc(USBTX, USBRX);
DigitalOut myled(LED1);

void blinkLed(float one, float two, float three, float four, float five) {
    if (one > 0){
        myled = 1;wait(one);
    }
    if (two > 0){
        myled = 0; wait(0.2);
        myled = 1; wait(two);
    }
    if (three > 0){
        myled = 0; wait(0.2);
        myled = 1; wait (three);
    }
    if (four > 0){
        myled = 0; wait(0.2);
        myled = 1; wait(four);
    }
    if (five > 0){
        myled = 0; wait(0.2);
        myled = 1; wait(five);
    }
    myled = 0; wait(2);
}

void blinkLed(char morse) {
    switch (morse) {
        case 'A' : blinkLed(0.2, 0.6,0,0,0); break;
        case 'D' : blinkLed(0.6, 0.2,0.2,0,0); break;
        case 'M' : blinkLed(0.6, 0.6,0,0,0); break;
        case 'J' : blinkLed(0.2, 0.6,0.6,0.6,0); break;
        case 'K' : blinkLed(0.6, 0.2,0.6,0,0); break;
        case 'U' : blinkLed(0.2, 0.2,0.6,0,0); break;
        case 'B' : blinkLed(0.6, 0.2,0.2,0.2,0); break;
        default : blinkLed(0,0,0,0,0); break;
    }
}

int main() {  
    char myMessage[] = "JAKUB ADAM";
        while (1){      int size = sizeof (myMessage);
        for (int i=0; i<size; i++){
            blinkLed (myMessage[i]);
        }
    }
}

