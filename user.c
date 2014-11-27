#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"
#include "timer.h"

short min = MINUTES;
short sec = SECONDS;
int ms = MILLISECONDS;
unsigned char poof = false;

void InitApp(void) {
    void initInterrupt();
    void timerInit();
    void ioInit();
}

void ioInit(void) {
    GPIO = 0;
    TRISIO = 0b00101000;
}

void outputTime(void){
    unsigned int data;
    unsigned int temp;
    temp = ms;
    data = ms/100;
    temp -= temp/100;
    data << 4;
    data |= temp/10;
    temp -= temp/10;
    temp = sec;
    data << 4;
    data |= temp/10;
    temp -= temp/10;
    data << 4;
    data |= temp;
    temp = min;
    data << 4;
    data |= min;
    shiftData(data);
}

void shiftData(unsigned int data){
    for(int i = 0; i < 20; i++) {
        DATA = data & 1;
        CLOCK = 1;
        CLOCK = 0;
        data = data >> 1;
    }
    STORAGE = 1;
    STORAGE = 0;
}