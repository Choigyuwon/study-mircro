#include <stdio.h>
#include <avr/io.h>
#include <compat/deprecated.h>
#include <util/delay.h>

int uart_putchar_2(char ch, FILE *stream);

FILE Mystdout = FDEV_SETUP_STREAM(uart_putchar_2, NULL, _FDEV_SETUP_WRITE);

void uart_init()
{	
	stdout = &Mystdout;
	UBRR0H = 0x00;
	UBRR0L = 0x07;
	sbi(UCSR0A,U2X0);
	sbi(UCSR0B, TXEN0);
}

int uart_putchar(char ch)
{
	if(ch=='\n')
	uart_putchar('\r');
	_delay_ms(200);
	UDR0 = ch;
	return(1);
	}
int uart_putstr(char *sp)
{
	for( ; *sp; sp++)
		uart_putchar(*sp);
		return(1);
}
int uart_putchar_1(char ch, FILE *stream)
{
	if(ch=='\n')
	uart_putchar_1('\r',stream);
	_delay_ms(1);
	UDR0 = ch;
	return(1);
}
int uart_putchar_2(char ch, FILE *stream)
{
	if(ch=='\n')
	uart_putchar_2('\r',stream);
	while( !(UCSR0A & (1 << UDRE0)) )
		;
		_delay_ms(1);
		UDR0 = ch;
		return(1);
	

}
