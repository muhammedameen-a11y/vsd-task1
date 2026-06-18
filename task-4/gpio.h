#ifndef GPIO_H
#define GPIO_H

#include "ch32v00x.h"

void gpio_input_init(void);
void gpio_output_init(void);

uint8_t gpio_read_input(void);

void gpio_toggle_output(void);

#endif