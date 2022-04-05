/*
* timer.c
*
* Created: 10/6/2021 4:54:59 PM
*  Author: Wynn
*/
#define F_CPU 2000000UL
#include "timer.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdio.h>
#include <util/delay.h>


//for PART 3. Added ISR function, enable timer0 interrupt in init

// this ISR function is called when timer0 reaches
//compare value, compare flag is automatically cleared
volatile uint8_t countDs1 = 0;
volatile uint8_t countDs2 = 0;
volatile uint8_t count;
volatile uint8_t timeCounter = 0;
volatile uint8_t digit = 2;

//initializing array for segment display
volatile uint8_t segDisplay[10] = {0x3F,0x6,0x5B,0x4F,0x66,0x6D,0x7D,0x7,0x7F,0x67};

ISR(TIMER0_COMPA_vect){
	
	//choose which digit to update using a flag 
	//if last displayed digit 1, display digit 2 and vice versa
	if(digit == 2){
		count = countDs1;
		digit = 1;
	}
	else{
		count = countDs2;
		digit = 2;
	}
	
	//determine which segments to turn on depending on the number and turns off both digits off(disable them)
	if(count == 2 || count == 8 || count == 3 || count == 5 || count == 6 || count == 9 || count == 4){
		PORTB = 0x13; //10011
		PORTC = segDisplay[count];
	}
	else{
		PORTB = 0x3; //00011
		PORTC = segDisplay[count];
	}
	

	//set I/O pins connected to the segments to display the chosen digits

	if(digit == 2){ //display second digit
		PORTB &= ~(1<<PINB1);
		//countDs2++;
	}
	else{ //display first digit
		PORTB &= ~(1<<PINB0);
 	}
	
	//resetting counts
	if((countDs2 == 10) && (countDs1 == 10)){
		countDs1 = 0;
		countDs2 = 0;
	}
	
	if(countDs2 == 10){
		countDs2 = 0; 
	}	//flag gets updated
	
}

//initialize and configure timer0 to count to 10 ms
void timer_init(){
	TCCR0A = 0b00000010;
	TCCR0B = 0b00000100;
	OCR0A = 78; //set OCR0A so an interrupt occurs every 10 ms
	TIMSK0 = 0b00000010; // enable output compare match A interrupt
}
