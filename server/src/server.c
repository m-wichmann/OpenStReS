#include <avr/io.h>
#include <avr/interrupt.h>

#include "server.h"
#include "uart.h"
#include "rfm12.h"

void peripherie_init(void) {
	DDRA	= 0x00;
	DDRB	= 0x00;
	DDRC	= 0x00;
	DDRD	= 0x00;
	PORTA	= 0x00;
	PORTB	= 0x00;
	PORTC	= 0x00;
	PORTD	= 0x00;

	DDRD	|= (1<<PD4) | (1<<PD5); // led ports
    PORTD	|= (1<<PD4) | (1<<PD5); // leds off
}


int main(void) {

    peripherie_init();
    InitUART();

    LED0_ON();

    uint8_t teststring[] = "teststring\r\n";
    uint8_t packettype = 0xEE;
    rfm12_init();  /* initialize the library */
    sei();

    volatile int i = 0;

	while (1) {

//        TransmitByte (ReceiveByte() + 1);
        TransmitByte ('a');

//        if (i++ >= 10000) {
            LED1_TOGGLE();
//            i = 0;
//        }



        rfm12_tx (sizeof(teststring), packettype, teststring);
        rfm12_tick();

        

//        for (i = 0; i < 10000; i++) {
//
//        }

	}
	return 0;
}






