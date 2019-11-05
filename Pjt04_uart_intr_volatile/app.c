#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "led.h"
#include "uart.h"


int is_prime(int n)
{
	int i;
	for(i=2;i<=n/2;i++)
		if((n%i) ==0) return(0);
		return(1);
}
