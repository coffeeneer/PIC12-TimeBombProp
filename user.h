#ifndef USER_H
#define USER_H

#define TIME 0xFFFFF; //Time in 10ths of milliseconds

#define DATA GPIObits.GPIO0
#define CLOCK GPIObits.GPIO1
#define STORAGE GPIObits.GPIO4

void initApp(void);         /* I/O and Peripheral Initialization */
void ioInit(void);
void shiftData(unsigned short long data);
void outputTime(void);

#endif