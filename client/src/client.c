#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <avr/sleep.h>

#include "client.h"
#include "rfm12.h"



void peripherie_init(void) {
	// port init
	DDRA	= 0x00;
	DDRB	= 0x00;
	DDRC	= 0x00;
	DDRD	= 0x00;
	PORTA	= 0x00;
	PORTB	= 0x00;
	PORTC	= 0x00;
	PORTD	= 0x00;

	DDRD	|= (1<<PD0) | (1<<PD1); // led ports
	PORTA	|= (1<<PA0) | (1<<PA1) | (1<<PA2) | (1<<PA3) | (1<<PA4) | (1<<PA5); // dip pullup
	PORTC	|= (1<<PC0) | (1<<PC1) | (1<<PC2); // dip pullup
	PORTD	|= (1<<PD0) | (1<<PD1) | (1<<PD5) | (1<<PD7); // dip and button pullup; leds off
}


int main(void) {

	peripherie_init();

	LED1_ON(); // power led

    uint8_t teststring[] = "teststring\r\n";
    uint8_t packettype = 0xEE;
    rfm12_init();  /* initialize the library */
    sei();

	while (1) {

        rfm12_tx (sizeof(teststring), packettype, teststring);
        rfm12_tick();

		if (BUTTON) {
			LED0_ON();
		}
		else {
			LED0_OFF();
		}

	}
	return 0;
}
