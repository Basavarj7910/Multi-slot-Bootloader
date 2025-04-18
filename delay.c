#include "stm32f4xx.h"
#include "delay.h"
#include <stdint.h>
#include "uart.h"

#define DELAY_CYCLES  16000000
#define REQ_COUNT 1

#define enable_interrupt() do { __asm volatile("mov r0,#0"); __asm volatile("msr PRIMASK,r0");}while(0);
#define disable_interrupt() do { __asm volatile("mov r0,#1"); __asm volatile("msr PRIMASK,r0");}while(0);

volatile uint32_t curr_tick;
volatile uint32_t curr_tick_cp;

uint32_t get_ccount()
{
    disable_interrupt();
    curr_tick_cp = curr_tick;
    enable_interrupt();
    return curr_tick_cp;
}

void increment()
{
    curr_tick += REQ_COUNT;
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
    increment();
}

void delay(uint32_t delay) 
{
    uint32_t wait = get_ccount();
    if (delay < DELAY_CYCLES)
         delay++;
    while((get_ccount() - wait) < delay);
}
