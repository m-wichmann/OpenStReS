#pragma once
#ifndef UART_H
#define UART_H

unsigned char ReceiveByte (void);
void TransmitByte (unsigned char data);
void InitUART ();

#endif // UART_H
