#include "timer.h"
#include "debug.h"

static uint32_t tick = 0;

void timer_init(void)
{
    Delay_Init();
}

void timer_delay_ms(uint32_t ms)
{
    Delay_Ms(ms);
    tick += ms;
}

uint32_t timer_get_tick(void)
{
    return tick;
}