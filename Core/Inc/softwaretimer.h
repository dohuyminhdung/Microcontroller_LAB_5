#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_
#include "main.h"
#define TICK 10

void setTimer0(int time);
void timerRun0();
uint8_t isTimerFlag0();

void setTimer1(int time);
void timerRun1();
uint8_t isTimerFlag1();

#endif /* INC_SOFTWARETIMER_H_ */
