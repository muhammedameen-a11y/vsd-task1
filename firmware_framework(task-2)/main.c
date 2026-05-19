#include "gpio.h"
#include "uart.h"
#include "board.h"
#include "delay.h"

void delay()
{
    for(long int i = 0; i < 100000000; i++);
}

int main()
{
    int counter = 0;

    gpio_init(LED_PIN);
    gpio_init(STATUS_PIN);

    uart_init();

    uart_write(BOARD_NAME);
    uart_write(FIRMWARE_VERSION);

    while(1)
{
    gpio_toggle(LED_PIN);

    gpio_toggle(STATUS_PIN);

    if(gpio_read(LED_PIN))
        uart_write("LED_PIN State: HIGH");
    else
        uart_write("LED_PIN State: LOW");

    if(gpio_read(STATUS_PIN))
        uart_write("STATUS_PIN State: HIGH");
    else
        uart_write("STATUS_PIN State: LOW");

    uart_write("System Running...");

    uart_write_int(counter);

    counter++;

    delay_ms();
}

    return 0;
}