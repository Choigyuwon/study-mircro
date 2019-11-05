//main.c
#include <avr/io.h>
#include <util/delay.h>
#include "led.h"
#include "UARTO.h"

void led();	//함수원형 waring이 나올 수 있다.
//static uint8_t i;
int main()

{
	char c;
	uart_init();
	while(1) {
		for(c='A'; c<='Z'; c++)
			uart_putchar(c);
			uart_putchar('\n');
			}
}



/*
{
	led_init();
//	led_off_all();
//	uint8_t i;
	int i;
	while(1){
	for(i=0; i<8; i++)
	{
	led_on(i);
	_delay_ms(100);
	}
	for(i=7;i>=0;i--)
	{
	led_off(i);
	_delay_ms(100);
	}
	_delay_ms(100);
}
	return 0;
	
}
*/




