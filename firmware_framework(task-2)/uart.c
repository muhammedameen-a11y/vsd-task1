#include <stdio.h>
#include "uart.h"

void uart_init()
{
    printf("UART Initialized\n");
}

void uart_write(char message[])
{
    printf("%s\n", message);
}

void uart_write_int(int value)
{
    printf("Counter: %d\n", value);
}