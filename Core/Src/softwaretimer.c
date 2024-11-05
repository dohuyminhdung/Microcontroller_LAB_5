#include "softwaretimer.h"

int timer0 = 0;
uint8_t timerFlag0 = 0;
void setTimer0(int time){
	timer0 = time / TICK;
	timerFlag0 = 0;
}
void timerRun0(){
	if(timer0 > 0){
		if(--timer0 <= 0) timerFlag0 = 1;
	}
}
uint8_t isTimerFlag0(){
	if(timerFlag0 == 1){
		timerFlag0 = 0;
		return 1;
	}
	return 0;
}

int timer1 = 0;
uint8_t timerFlag1 = 0;
void setTimer1(int time){
	timer1 = time / TICK;
	timerFlag1 = 0;
}
void timerRun1(){
	if(timer1 > 0){
		if(--timer1 <= 0) timerFlag1 = 1;
	}
}
uint8_t isTimerFlag1(){
	if(timerFlag1 == 1){
		timerFlag1 = 0;
		return 1;
	}
	return 0;
}
