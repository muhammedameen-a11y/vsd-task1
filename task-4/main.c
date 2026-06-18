#include "gpio.h"
#include "uart.h"
#include "timer.h"

#include <stdio.h>

#define SAMPLE_RATE_MS 100

int main(void)
{
    char buffer[64];
    uint8_t sample;

    uart_init();
    timer_init();

    gpio_output_init();
    gpio_input_init();

    uart_send_string("Time_ms,Input\r\n");

    while(1)
    {
        gpio_toggle_output();

        sample = gpio_read_input();

        sprintf(buffer,
                "%lu,%d\r\n",
                timer_get_tick(),
                sample);

        uart_send_string(buffer);

        timer_delay_ms(SAMPLE_RATE_MS);
    }
}