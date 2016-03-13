
#define F_CPU 20000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define LEFT 0
#define RIGHT 1

#define TEXT_ON PORTD |= (1<<PORTD0)
#define TEXT_OFF PORTD &= ~(1<<PORTD0)

#define segA1_ON PORTC |= (1<<PORTC3)
#define segA1_OFF PORTC &= ~(1<<PORTC3)
#define segB1_ON PORTB |= (1<<PORTB0)
#define segB1_OFF PORTB &= ~(1<<PORTB0)
#define segC1_ON PORTD |= (1<<PORTD4)
#define segC1_OFF PORTD &= ~(1<<PORTD4)
#define segD1_ON PORTC |= (1<<PORTC2)
#define segD1_OFF PORTC &= ~(1<<PORTC2)
#define segE1_ON PORTC |= (1<<PORTC5)
#define segE1_OFF PORTC &= ~(1<<PORTC5)
#define segF1_ON PORTC |= (1<<PORTC4)
#define segF1_OFF PORTC &= ~(1<<PORTC4)
#define segG1_ON PORTD |= (1<<PORTD5)
#define segG1_OFF PORTD &= ~(1<<PORTD5)

#define segA2_ON PORTB |= (1<<PORTB2)
#define segA2_OFF PORTB &= ~(1<<PORTB2)
#define segB2_ON PORTB |= (1<<PORTB1)
#define segB2_OFF PORTB &= ~(1<<PORTB1)
#define segC2_ON PORTB |= (1<<PORTB3)
#define segC2_OFF PORTB &= ~(1<<PORTB3)
#define segD2_ON PORTB |= (1<<PORTB4)
#define segD2_OFF PORTB &= ~(1<<PORTB4)
#define segE2_ON PORTC |= (1<<PORTC1)
#define segE2_OFF PORTC &= ~(1<<PORTC1)
#define segF2_ON PORTB |= (1<<PORTB5)
#define segF2_OFF PORTB &= ~(1<<PORTB5)
#define segG2_ON PORTC |= (1<<PORTC0)
#define segG2_OFF PORTC &= ~(1<<PORTC0)

void drawDigit(bool part, int digit){
	if(part == 0){
		switch(digit){
			case 0: segA1_ON;
				    segB1_ON;
				    segC1_ON;
				    segD1_ON;
				    segE1_ON;
				    segF1_ON;
				    segG1_OFF;
				    break;
			case 1: segA1_OFF;
				    segB1_OFF;
				    segC1_ON;
			        segD1_ON;
				    segE1_OFF;
				    segF1_OFF;
				    segG1_OFF;
				    break;
			case 2: segA1_OFF;
					segB1_ON;
					segC1_ON;
					segD1_OFF;
					segE1_ON;
					segF1_ON;
					segG1_ON;
					break;
			case 3: segA1_OFF;
					segB1_ON;
					segC1_ON;
					segD1_ON;
					segE1_ON;
					segF1_OFF;
					segG1_ON;
					break;
			case 4: segA1_ON;
					segB1_OFF;
					segC1_ON;
					segD1_ON;
					segE1_OFF;
					segF1_OFF;
					segG1_ON;
					break;
			case 5: segA1_ON;
					segB1_ON;
					segC1_OFF;
					segD1_ON;
					segE1_ON;
					segF1_OFF;
					segG1_ON;
					break;
			case 6: segA1_ON;
					segB1_ON;
					segC1_OFF;
					segD1_ON;
					segE1_ON;
					segF1_ON;
					segG1_ON;
					break;
			case 7: segA1_OFF;
					segB1_ON;
					segC1_ON;
					segD1_ON;
					segE1_OFF;
					segF1_OFF;
					segG1_OFF;
					break;
			case 8: segA1_ON;
					segB1_ON;
					segC1_ON;
					segD1_ON;
					segE1_ON;
					segF1_ON;
					segG1_ON;
					break;
			case 9: segA1_ON;
					segB1_ON;
					segC1_ON;
					segD1_ON;
					segE1_ON;
					segF1_OFF;
					segG1_ON;
					break;
		}
	}
	else{
		switch(digit){
			case 0: segA2_ON;
					segB2_ON;
					segC2_ON;
					segD2_ON;
					segE2_ON;
					segF2_ON;
					segG2_OFF;
					break;
			case 1: segA2_OFF;
					segB2_OFF;
					segC2_ON;
					segD2_ON;
					segE2_OFF;
					segF2_OFF;
					segG2_OFF;
					break;
			case 2: segA2_OFF;
					segB2_ON;
					segC2_ON;
					segD2_OFF;
					segE2_ON;
					segF2_ON;
					segG2_ON;
					break;
			case 3: segA2_OFF;
					segB2_ON;
					segC2_ON;
					segD2_ON;
					segE2_ON;
					segF2_OFF;
					segG2_ON;
					break;
			case 4: segA2_ON;
					segB2_OFF;
					segC2_ON;
					segD2_ON;
					segE2_OFF;
					segF2_OFF;
					segG2_ON;
					break;
			case 5: segA2_ON;
					segB2_ON;
					segC2_OFF;
					segD2_ON;
					segE2_ON;
					segF2_OFF;
					segG2_ON;
					break;
			case 6: segA2_ON;
					segB2_ON;
					segC2_OFF;
					segD2_ON;
					segE2_ON;
					segF2_ON;
					segG2_ON;
					break;
			case 7: segA2_OFF;
					segB2_ON;
					segC2_ON;
					segD2_ON;
					segE2_OFF;
					segF2_OFF;
					segG2_OFF;
					break;
			case 8: segA2_ON;
					segB2_ON;
					segC2_ON;
					segD2_ON;
					segE2_ON;
					segF2_ON;
					segG2_ON;
					break;
			case 9: segA2_ON;
					segB2_ON;
					segC2_ON;
					segD2_ON;
					segE2_ON;
					segF2_OFF;
					segG2_ON;
					break;
		}
	}
}

void drawChar(char c){
	switch(c){
		case 'd':segA1_OFF;
				 segB1_OFF;
				 segC1_ON;
				 segD1_OFF;
				 segE1_OFF;
				 segF1_ON;
				 segG1_ON;
				 segA2_ON;
				 segB2_OFF;
				 segC2_OFF;
				 segD2_ON;
				 segE2_OFF;
				 segF2_OFF;
				 segG2_ON;
				 break;	
		case 'f':segA1_ON;
				 segB1_ON;
				 segC1_ON;
				 segD1_ON;
				 segE1_OFF;
				 segF1_OFF;
				 segG1_ON;
				 segA2_ON;
				 segB2_ON;
				 segC2_ON;
				 segD2_OFF;
				 segE2_OFF;
				 segF2_ON;
				 segG2_ON;
				 break;
		case 'm':segA1_ON;
				 segB1_ON;
				 segC1_ON;
				 segD1_OFF;
				 segE1_OFF;
				 segF1_ON;
				 segG1_OFF;
				 segA2_ON;
				 segB2_ON;
				 segC2_ON;
				 segD2_ON;
				 segE2_OFF;
				 segF2_OFF;
				 segG2_OFF;
				 break;
	}
}

int second,minute,hour,day,type;

ISR(TIMER2_OVF_vect)
{
	second++;
	if (second==60)
	{
		second=0;
		minute++;
		if (minute==60)
		{
			minute=0;
			hour++;
			if (hour==24)
			{
				hour=0;
				day--;
				if(day<=0)day=0;
			}
		}
	}
}


int main(void)
{	
	DDRC = 0b00111111;

	DDRD = 0b11110001;
	PORTD = 0b00001110;
	
	DDRB = 0b00111111;
	
	TEXT_ON;
	
	TIMSK &= ~(1 << OCIE2)|(1 << TOIE2); // Запрещаем прерывания по T2
	ASSR |= (1 << AS2); // Включаем асинхронный режим T2
	TCNT2 = 0; // Сбрасываем регистр счета
	TCCR2 |= (1 << CS22)|(1 << CS20); // Предделитель на 128(32768/128 = 256 тиков/c)

	//прерывания
	sei();
	TIMSK |= (1 << TOIE2); // Разрешаем прерывание по переполнению Т2
	
	second = 14;
	minute = 01;
	hour = 22;
	day = 88;
	type = 0;
	
	int pass1 = 0, pass2 = 0, pass3 = 0, power = true;
	
	while(1)
	{	
		//доступ
		if(!(PIND & (1<<PIND1))){
			pass3++;
			if(pass3>30000)pass3=30001;
		}
		if(!(PIND & (1<<PIND2))){
			pass1++;
			if(pass1>30000)pass1=30001;
		}
		if(!(PIND & (1<<PIND3))){
			pass2++;
			if(pass2>30000)pass2=30001;
		}
		
		//включение-выключение 
		if(power == false){
			if((hour==7 && minute==30) || pass3>30000){
				power=true;
				TEXT_ON;
				pass3=0;
			}
		}
		else{
			if((hour==21 && minute==30) || pass3>30000){
				power=false;
				pass3 = 0;
			}
		}
		
		if(power){
			//отображение
			if(type==0){
				drawDigit(LEFT,day/10);
				drawDigit(RIGHT,day%10);
			}
			else if(type==1){
				drawDigit(LEFT,hour/10);
				drawDigit(RIGHT,hour%10);
			}
			else if(type==2){
				drawDigit(LEFT,minute/10);
				drawDigit(RIGHT,minute%10);
			}
			else if(type==3){
				sei();
				drawDigit(LEFT,second/10);
				drawDigit(RIGHT,second%10);
			}	
		}else{
			segA1_OFF;
			segA2_OFF;
			segB1_OFF;
			segB2_OFF;
			segC1_OFF;
			segC2_OFF;
			segD1_OFF;
			segD2_OFF;
			segE1_OFF;
			segE2_OFF;
			segF1_OFF;
			segF2_OFF;
			segG1_OFF;
			segG2_OFF;
			TEXT_OFF;
		}
		
		if(pass1<30000 || pass2<30000)continue;
		
		if(!(PIND & (1<<PIND1))){
			while(!(PIND & (1<<PIND1)));
			_delay_ms(50);
			
			type++;
			if(type==1)cli();
			if(type>3){
				pass1=0;
				pass2=0;
				type = 0;
			}
		}
		
		if(type==0){
			if(!(PIND & (1<<PIND2))){
				while(!(PIND & (1<<PIND2)));
				_delay_ms(50);
				day++;
				if(day>50)day=0;
			}
			if(!(PIND & (1<<PIND3))){
				while(!(PIND & (1<<PIND3)));
				_delay_ms(50);
				day--;
				if(day<0)day=50;
			}
		}
		else if(type==1){
			if(!(PIND & (1<<PIND2))){
				while(!(PIND & (1<<PIND2)));
				_delay_ms(50);
				hour++;
				if(hour>23)hour=0;
			}
			if(!(PIND & (1<<PIND3))){
				while(!(PIND & (1<<PIND3)));
				_delay_ms(50);
				hour--;
				if(hour<0)hour=23;
			}
		}
		else if(type==2){
			if(!(PIND & (1<<PIND2))){
				while(!(PIND & (1<<PIND2)));
				_delay_ms(50);
				minute++;
				if(minute>59)minute=0;
			}
			if(!(PIND & (1<<PIND3))){
				while(!(PIND & (1<<PIND3)));
				_delay_ms(50);
				minute--;
				if(minute<0)minute=59;
			}
		}
	}
}
