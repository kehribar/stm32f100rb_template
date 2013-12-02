#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "stm32f10x_misc.h"

void NMI_Handler(void)
{

}

void HardFault_Handler(void)
{
    while (1) {}
}

void MemManage_Handler(void)
{
    while (1) {}
}

void BusFault_Handler(void)
{
    while (1) {}
}

void UsageFault_Handler(void)
{
    while (1) {}
}

void DebugMon_Handler(void)
{

}

void SVC_Handler(void)
{

}

void PendSV_Handler(void)
{

}

void SysTick_Handler(void)
{
    TimingDelay_Decrement();
}

void TIM2_IRQHandler(void)
{

}

void EXTI0_IRQHandler(void)
{

}
