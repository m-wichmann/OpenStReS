#include <avr/io.h>

#include "server.h"
#include "uart.h"


void peripherie_init(void) {
	DDRA	= 0x00;
	DDRB	= 0x00;
	DDRD	= 0x00;
	PORTA	= 0x00;
	PORTB	= 0x00;
	PORTD	= 0x00;

	DDRB	|= (1<<PB0) | (1<<PB1); // led ports
    PORTD	|= (1<<PB0) | (1<<PB1); // leds off
}


int main(void) {

    peripherie_init();
    InitUART();

    volatile int i = 0;

	while (1) {

        TransmitByte (ReceiveByte() + 1);
        LED1_TOGGLE();
//        for (i = 0; i < 10000; i++) {

//        }
	}
	return 0;
}
