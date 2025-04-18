#include <stdint.h>
#include "uart.h"
#include "delay.h"
#include "float_point.h"
#include "bsp.h"


int main()
{
    enable_fpu();
    uart_init();
    init_systick();
    init_led();
    buttton_init();
    while(1) {
        printf("hello world \r\n");
        delay(3); 
        printf("hi every one\r\n");
        delay(1); 
    }
    return 0;
}
