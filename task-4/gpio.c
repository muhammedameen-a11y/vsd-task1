#include "gpio.h"

void gpio_input_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
}

void gpio_output_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOD, &GPIO_InitStructure);
}

uint8_t gpio_read_input(void)
{
    return GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_3);
}

void gpio_toggle_output(void)
{
    static uint8_t state = 0;

    state = !state;

    if(state)
        GPIO_SetBits(GPIOD, GPIO_Pin_4);
    else
        GPIO_ResetBits(GPIOD, GPIO_Pin_4);
}