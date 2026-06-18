#include "uart.h"
#include "debug.h"

void uart_init(void)
{
    USART_Printf_Init(115200);
}

void uart_send_string(char *str)
{
    printf("%s", str);
}