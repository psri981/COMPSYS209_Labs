/*
 * Task1Lab6.c
 *
 * Created: 10/6/2021 4:51:42 PM
 * Author : Wynn
 */ 


#define F_CPU 2000000UL

#include "timer.h"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdio.h>


int main(void)
{
	/* Replace with your application code */

	DDRB &= ~(1 << PINB7); // setting push button as an input
	DDRB |= 1 << PINB0; //setting Ds1 to output
	DDRB |= 1 << PINB1;    //setting DS2 to output
	DDRB |= 1 << PINB4; //setting segment 'g' as output

	DDRC = 0xFF; //setting pins in LED segments as outputs

	PORTB = 0x1; //configure Ds2 to only be used (the second digit)

	timer_init();
	sei();

	while (1)
	{					
				_delay_ms(1000);
				cli();
				countDs2++;
				if(countDs2 == 10){
					countDs1++;
				}
				sei();

	}
}
