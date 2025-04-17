#include "float_point.h"
#include "stm32f4xx.h"


void enable_fpu()
{
    *CPACR |= ( 1<< 20);
    *CPACR |= ( 1<< 21);
    *CPACR |= ( 1<< 22);
    *CPACR |= ( 1<< 23);
}
    
