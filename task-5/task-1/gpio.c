#include <stdio.h>
#include "gpio.h"

void gpio_write(int pin, int state)
{
    printf("GPIO Pin %d set to %d\n", pin, state);
}
