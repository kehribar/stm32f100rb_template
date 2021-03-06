#include "stm32f10x.h"
#include "stm32f10x_misc.h"

/* Cortex M3 Delay functions */

static __IO uint32_t TimingDelay = 0;

void Delay(__IO uint32_t nTime)
{
    TimingDelay = nTime;

    while(TimingDelay != 0);
}

void TimingDelay_Decrement(void)
{
    if (TimingDelay != 0x00) {
        TimingDelay--;
    }
}
