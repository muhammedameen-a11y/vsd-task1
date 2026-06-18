#include "ch32v00x.h"
#include "debug.h"
#include "timer.h"

int main(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    SystemCoreClockUpdate();
    USART_Printf_Init(115200);

    timer_init();

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    while(1)
    {
        GPIO_WriteBit(GPIOD, GPIO_Pin_4, Bit_SET);
        printf("Tick: %lu | LED ON\r\n", timer_get_tick());
        timer_delay_ms(500);

        GPIO_WriteBit(GPIOD, GPIO_Pin_4, Bit_RESET);
        printf("Tick: %lu | LED OFF\r\n", timer_get_tick());
        timer_delay_ms(500);
    }
}