/*
 * IncFile1.h
 *
 * Created: 10/6/2021 4:55:06 PM
 *  Author: Wynn
 */ 

#ifndef TIMERH
#define TIMERH

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

//initialize timer0 as per part 1
void timer_init();
extern volatile uint8_t countDs1;
extern volatile uint8_t countDs2;
extern volatile uint8_t segDisplay[10];
extern volatile uint8_t timeCounter;

#endif / TIMER0H */
