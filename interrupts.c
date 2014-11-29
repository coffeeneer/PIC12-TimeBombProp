#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */
#include "interrupts.h"
#include "user.h"
extern unsigned short long time;
extern bit poof;

void initInterrupt(void) {
    PIR1 = 0;
    TMR1H = 0;
    TMR1L = 0;
    PIE1bits.TMR1IE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
}

void interrupt isr(void)
{
    if(PIR1bits.TMR1IF)
    {
        PIR1bits.TMR1IF = 0;
        if (!poof) {
            time--;
            TMR1H = 216;             // preset for timer1 MSB register
            TMR1L = 240;             // preset for timer1 LSB register
            if(time == 0) poof = true;
        }
    }
}


