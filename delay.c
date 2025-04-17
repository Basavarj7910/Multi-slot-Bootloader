#include "stm32f4xx.h"
#include "delay.h"
#include <stdint.h>
#include "uart.h"

#define DELAY_CYCLES  16000000
#define REQ_COUNT 1
static uint32_t curr_tick = 0;

uint32_t get_ccount()
{
    return curr_tick;
}

void init_systick()
{
  /* initializing max count valu to the counter */
  SYST->RVR = (DELAY_CYCLES - 1);
  /* initializing zero to the current value register*/
  SYST->CVR = 0x00;
  /* enable the internal clock source */
  SYST->CSR |= ( 1 << 2);
  /* enable the interrupt */
  SYST->CSR |= ( 1 << 1);
  /* enable the systick timer */
  SYST->CSR |= ( 1 << 0);
}

void SysTick_Handler() 
{
    curr_tick++;
//    printf("hello every one \r\n");
}

void delay(uint32_t delay) 
{
    uint32_t wait = get_ccount();
    while((get_ccount() - wait) < delay);
}
