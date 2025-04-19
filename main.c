#include <stdint.h>
#include "uart.h"
#include "delay.h"
#include "float_point.h"
#include "bsp.h"
#define APPL1 0x08008000U
typedef void(*appl)(void);

void shift_default_appl()
{
    printf("bootloader started \r\n");
    uint32_t defaul_addr;
    uint32_t msp_value;
    defaul_addr = *((uint32_t *)(APPL1 + 4));
    appl appl1 = (appl) defaul_addr;
    msp_value = *((uint32_t *)APPL1);
    if (msp_value != 0xffffffff) {
        printf("started to load the application1\r\n");
        __asm volatile("msr msp,%0"::"r"(msp_value));
        appl1();
    } else {
        printf("there is no any application\r\n");
    }
}

int main()
{
    enable_fpu();
    uart_init();
    init_systick();
    //init_led();
    //buttton_init();
   shift_default_appl(); 
    while(1) {
        printf("hello world \r\n");
        delay(3); 
        printf("hi every one\r\n");
        delay(1); 
    }
    return 0;
}
