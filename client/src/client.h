#pragma once
#ifndef MAIN_H
#define MAIN_H

int main(void);
void peripherie_init(void);



#define LED0_ON() PORTD &= ~(1<<PD0)
#define LED0_OFF() PORTD |= (1<<PD0)
#define LED0_TOGGLE() PORTD ^= (1<<PD0)
#define LED1_ON() PORTD &= ~(1<<PD1)
#define LED1_OFF() PORTD |= (1<<PD1)
#define LED1_TOGGLE() PORTD ^= (1<<PD1)

#define BUTTON (~((PIND & (1<<PIND5))>>PIND5) & 0x01)
#define DIP4 (~(((PIND & (1<<PIND7))>>PIND7) | ((PINC & ((1<<PINC0) | (1<<PINC1) | (1<<PINC2)))<<1)) & 0x0f)
#define DIP6 (~(((PINA & (1<<5))>>5) | ((PINA & (1<<4))>>3) | ((PINA & (1<<3))>>1) | ((PINA & (1<<2))<<1) | ((PINA & (1<<1))<<3) | ((PINA & (1<<0))<<5)) & 0x3f)





#endif // MAIN_H
