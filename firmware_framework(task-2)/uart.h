#ifndef UART_H
#define UART_H

void uart_init();
void uart_write(char message[]);
void uart_write_int(int value);

#endif