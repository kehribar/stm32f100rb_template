/*-----------------------------------------------------------------------------
/
/
/
/
/
/
/----------------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "stm32f10x_misc.h"
#include "stm32f10x_init.h"
#include "printf.h"

void __io_putchar(void* p, char ch)
{
    /* Write a character to the USART */
    USART_SendData(USART1, (uint8_t) ch);

    /* Loop until the end of transmission */
    while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET) {}
}

int main(void)
{
    /* Initialize system */
    STM32_Configuration();

    /* Wire putchar for printf */
    init_printf(0, __io_putchar);

    printf("Hello World!\r\n");    

    while (1)
    {
        GPIO_WriteBit(GPIOC, GPIO_Pin_8, Bit_SET);
        GPIO_WriteBit(GPIOC, GPIO_Pin_9, Bit_RESET);

        Delay(250);

        GPIO_WriteBit(GPIOC, GPIO_Pin_8, Bit_RESET);
        GPIO_WriteBit(GPIOC, GPIO_Pin_9, Bit_SET);

        Delay(250);
    }
}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t* file, uint32_t line)
{
    printf("Wrong parameters value: file %s on line %d\r\n", file, line);
    while (1) {}
}

#endif
