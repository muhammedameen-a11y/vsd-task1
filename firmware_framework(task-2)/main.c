#include "ch32v00x.h"
#include "debug.h"

int main(void) {
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    SystemCoreClockUpdate();
    Delay_Init();
    USART_Printf_Init(115200); // <-- add this for serial

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    while (1) {
        GPIO_WriteBit(GPIOD, GPIO_Pin_4, Bit_SET);
        printf("LED ON\r\n");   // <-- prints to serial
        Delay_Ms(500);
        GPIO_WriteBit(GPIOD, GPIO_Pin_4, Bit_RESET);
        printf("LED OFF\r\n");  // <-- prints to serial
        Delay_Ms(500);
    }
}
