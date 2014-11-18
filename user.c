#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"
#include "timer.h"

int min = MINUTES;
int sec = SECONDS;
int ms = MILLISECONDS;
unsigned char poof = false;

void InitApp(void)
{
    void initInterrupt();
    void timerInit();
    void ioInit();
}

void ioInit(void) {
    GPIO = 0;
    TRISIO = 0b00101000;
}

void shiftData(unsigned int data){
    for(int i = 0; i < 20; i++) {
        DATA = data & 1;
        CLOCK = 1;
        CLOCK = 0;
        data >> 1;
    }
    STORAGE = 1;
    STORAGE = 0;
}