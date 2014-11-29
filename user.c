#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"
#include "timer.h"

volatile unsigned long time = TIME;
bit poof = false;

void ioInit(void) {
    CMCON = 0x7;
    GPIO = 0;
    TRISIO = 0b00101100;
}

void outputTime(void){
    /*Hier de vertaling van de time variabele die de tijd in tienden msec
     bijhoudt naar een variabele met de data in BCD format als volgt:
     0xTIENTALMILLISECONDEN;HONDERDTALMILLISECONDEN;SECONDEN;TIENTALSECONDEN;MINUTEN*/
    shiftData((unsigned short long)time); //uitshiften van de data
}

void shiftData(unsigned short long data){
    for(int i = 0; i < 20; i++) {
        if(data & (0x80000)) DATA = 1;
        else DATA = 0;
        CLOCK = 1;
        CLOCK = 0;
        data = data << 1;
    }
    STORAGE = 1;
    STORAGE = 0;
}