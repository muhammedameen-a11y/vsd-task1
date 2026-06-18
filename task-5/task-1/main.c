#include "gpio.h"

int main()
{
    gpio_write(13, 1);
    gpio_write(13, 0);

    return 0;
}