#pragma once
#ifndef MAIN_H
#define MAIN_H

void peripherie_init(void);
int main(void);



#define LED0_ON() PORTB &= ~(1<<PB0)
#define LED0_OFF() PORTB |= (1<<PB0)
#define LED0_TOGGLE() PORTB ^= (1<<PB0)
#define LED1_ON() PORTB &= ~(1<<PB1)
#define LED1_OFF() PORTB |= (1<<PB1)
#define LED1_TOGGLE() PORTB ^= (1<<PB1)



#endif // MAIN_H
