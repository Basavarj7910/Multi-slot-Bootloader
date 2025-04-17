#ifndef __DELAY__
#define __DELAY__


void init_systick();
uint32_t get_ccount();
void delay(uint32_t delay);

#endif
