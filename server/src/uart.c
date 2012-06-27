#include "uart.h"
#include <avr/io.h>

unsigned char ReceiveByte (void) {
    while (!(UCSRA & (1 << RXC)));
    return UDR;
}

void TransmitByte (unsigned char data) {
    while (!(UCSRA & (1 << UDRE)));
    UDR = data;
}

void InitUART (void) {

    // init regs
    UCSRA = 0x00;
    UCSRB = 0x00;
    UCSRC = 0x00;

    // enable receiver and transmitter
    UCSRB = (1 << RXEN) | (1 << TXEN);
    // set parity odd; 8 bit frames; 1 stop bit
    UCSRC = (1 << UPM1) | (1 << UPM0) | (1 << UCSZ1) | (1 << UCSZ0);
    // set baud rate; at 8 MHz this should yield 2400 baud
    UBRRL = 25;

}
