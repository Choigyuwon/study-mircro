//main.c
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.h"
#include "timer2.h"

int main() 
{
/*
	uint8_t h,m,s;
	uart_init();
	timer2_init(); sei();
	for(h=0,m=0,s=0; ;s++) {
		time_flag=0;
		while(time_flag ==0);
		if(s==60) 
		{
			m++;
			s=0;
		}
		else if(m==60) 
		{
			h++;
			m=0;
		}
		pr_time(60);
	}
	return(0);
	*/
	int sec = 0;
	uart_init();
	timer2_init();
	sei();
	while(1){
		while(!time_flag);
		time_flag = 0;
		sec++;
		pr_time(sec);
		}
}
