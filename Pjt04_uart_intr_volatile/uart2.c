#include <avr/io.h>
#include <compat/deprecated.h>
#include <util/delay.h>
#include <avr/interrupt.h>
//int uart_putchar_2(char ch, FILE *stream);

//FILE = Mystdout = FDEV_SETUP_STREAM (uart_putchar_2, NULL, _FDEV_SETUP_WRITE);
void uart_init()
{
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
char buf[64];
int volatile bufi, txend = 1;
int uart_putstart(char str[])
{
	char ch;
	int n = strlen(str);
	while(sizeof(buf) - strlen(buf +bufi) + -1 < n);
	cli();
	strcpy(buf, buf + bufi);
	strcat(buf, str);
	bufi = 0;
	if(txend) {
		txend = 0;
		ch = buf[bufi++];
		UDR0 = ch;
	}
	sei();
}
ISR(USART0_TX_vect)
{
	char ch = buf[bufi];

	if(!ch) {
			bufi = 0, txend = 1;
			return;
			}
			if(ch == '\n')
			buf[bufi] = '\r';
			else
			bufi++;
			UDR0 =ch;
	}


