#include <stdint.h>
#include "uart.h"
#include "delay.h"
#include "float_point.h"


int main()
{
    enable_fpu();
    uart_init();
    init_systick();
    while(1) {
        printf("hello world \r\n");
        delay(3); 
    }
    return 0;
}
