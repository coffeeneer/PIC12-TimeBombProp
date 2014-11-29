/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */
extern unsigned short long time;
extern bit poof;

void main(void) {
    ioInit();
    timerInit();
    initInterrupt();
    while(!poof){
        outputTime();
    }
    shiftData(0x80081);
    while(0);
}