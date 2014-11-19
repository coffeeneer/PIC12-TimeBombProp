#ifndef USER_H
#define USER_H

#define MINUTES 3
#define SECONDS 59
#define MILLISECONDS 999

#define DATA GPIObits.GPIO0
#define CLOCK GPIObits.GPIO1
#define STORAGE GPIObits.GPIO2

void InitApp(void);         /* I/O and Peripheral Initialization */
void ioInit(void);
void shiftData(unsigned int data);
void outputTime(void);

#endif