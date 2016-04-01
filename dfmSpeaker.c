#define F_CPU 1000000L
#include <avr/io.h>

void USART_Init(unsigned int baud){
	UBRRH = (unsigned char)(baud>>8);
	UBRRL = (unsigned char)baud;
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<USBS)|(3<<UCSZ0);
}

void USART_Transmit(unsigned char data){
	while(!(UCSRA & (1<<UDRE)));
	UDR = data;
}

int main(void)
{
	int i;
	USART_Init(12);
	DDRB = 0b00000000;
	PORTB = 0b00000001;
    while(1)
    {
		if(!(PINB & (1<<PINB0))){
			while(!(PINB & (1<<PINB0)));	
			for(i=0;i<10000;i++); 
			USART_Transmit('a');
		}   
    }
}
