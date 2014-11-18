#include <xc.h>         /* XC8 General Include File */

#include "timer.h"

void timerInit(void) {
    T1CONbits.TMR1GE = 1; // external gate enable
    T1CONbits.T1CKPS1 = 0;   // bits 5-4  Prescaler Rate Select bits
    T1CONbits.T1CKPS0 = 0;   // bit 4
    T1CONbits.T1OSCEN = 1;   // bit 3 Timer1 Oscillator Enable Control bit 1 = on
    T1CONbits.nT1SYNC = 1;  //
    T1CONbits.TMR1CS = 0;    // bit 1 Timer1 Clock Source Select bit...0 = Internal clock (FOSC/4)
    T1CONbits.TMR1ON = 1;    // bit 0 enables timer
    TMR1H = 252;             // preset for timer1 MSB register
    TMR1L = 24;             // preset for timer1 LSB register
}