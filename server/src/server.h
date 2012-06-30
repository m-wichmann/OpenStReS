#pragma once
#ifndef MAIN_H
#define MAIN_H

void peripherie_init(void);
int main(void);



#define LED0_ON() PORTD &= ~(1<<PD4)
#define LED0_OFF() PORTD |= (1<<PD4)
#define LED0_TOGGLE() PORTD ^= (1<<PD4)
#define LED1_ON() PORTD &= ~(1<<PD5)
#define LED1_OFF() PORTD |= (1<<PD5)
#define LED1_TOGGLE() PORTD ^= (1<<PD5)



#endif // MAIN_H
