#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */
#include "interrupts.h"
extern short min;
extern short sec;
extern int ms;
extern unsigned char poof;

void initInterrupt(void) {
    PIE1bits.T1IE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
}

void interrupt isr(void)
{
    if(PIR1bits.TMR1IF)
    {
        PIR1bits.TMR1IF = 0;
        if(!poof){
            ms--;
            if(ms < 0) {
                sec--;
                ms = 999;
            }
            if(sec < 0) {
                min--;
                sec = 59;
            }
            if (min < 0) {
                poof = true;
            }
        }
    }
}


