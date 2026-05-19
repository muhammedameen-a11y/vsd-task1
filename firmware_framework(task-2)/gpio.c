#include <stdio.h>
#include "gpio.h"

static int pin_states[100] = {0};

void gpio_init(int pin)
{
    printf("GPIO %d initialized\n", pin);
}

void gpio_set(int pin)
{
    pin_states[pin] = 1;
    printf("GPIO %d HIGH\n", pin);
}

void gpio_clear(int pin)
{
   pin_states[pin] = 0;
    printf("GPIO %d LOW\n", pin);
}

void gpio_toggle(int pin)
{
    pin_states[pin] = !pin_states[pin];

    if(pin_states[pin])
        printf("GPIO %d TOGGLED HIGH\n", pin);
    else
        printf("GPIO %d TOGGLED LOW\n", pin);
}

int gpio_read(int pin)
{
    return pin_states[pin];
}