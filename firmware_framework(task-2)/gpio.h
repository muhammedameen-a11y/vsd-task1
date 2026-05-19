#ifndef GPIO_H
#define GPIO_H

void gpio_init(int pin);
void gpio_set(int pin);
void gpio_clear(int pin);
void gpio_toggle(int pin);

int gpio_read(int pin);

#endif