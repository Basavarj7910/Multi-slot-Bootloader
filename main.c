#include <stdint.h>
#include <stdbool.h>
#include "uart.h"
#include "delay.h"
#include "float_point.h"
#include "bsp.h"
#include "stm32f4xx.h"
#define DEFAULT_APP 0x08020000U
#define APP1_BASE   0x08060000U
#define APP2_BASE   0x080a0000U

typedef void(*appl)(void);
extern volatile bool button_press;
extern volatile uint8_t key_value;

#define enable_interrupt() do { __asm volatile("mov r0,#0"); __asm volatile("msr PRIMASK,r0");}while(0);
#define disable_interrupt() do { __asm volatile("mov r0,#1"); __asm volatile("msr PRIMASK,r0");}while(0);


void disable_interrupts()
{
    USART2->USART_CR1 = 0;              // Disable USART2 completely
    USART2_PCLK_DIS();            // Turn off clock
    GPIOA_PCLK_DIS();            // Optional if GPIOA not needed
    EXTI->EXTI_IMR = 0;
    EXTI->EXTI_PR = 0xffffffff;
    NVIC->NVIC_ICER[1] = (1 << (38 % 32));  // Disable interrupt
    NVIC->NVIC_IPR[1] = (1 << (38 % 32));  // Clear any pending USART2 interrupt
    NVIC->NVIC_ICER[0] = (1 << (6 % 32));  // Disable interrupt
    NVIC->NVIC_IPR[0] = (1 << (6 % 32));  // Clear any pending EXTI0 interrupt
}

void shift_to_appl(uint32_t addr)
{
    uint32_t defaul_addr;
    uint32_t msp_value;
    defaul_addr = *((uint32_t *)(addr + 4));
    appl appl1 = (appl) defaul_addr;
    msp_value = *((uint32_t *)addr);
    if (msp_value != 0xffffffff) {
        printf("started to load application\r\n");
        __asm volatile("msr msp,%0"::"r"(msp_value));
        // Disable USART2 and GPIOA
        disable_interrupts();
        appl1();
    } else {
        printf("there is no application in flash \r\n");
    }
}


int main()
{
    enable_fpu();
    uart_init();
    init_systick();
    init_led();
    buttton_init();
    printf("bootloader started \r\n");
    printf("Press user button to load application 1& 2\r\n");
    delay(5);
    if (button_press) {
        /*Button pressed*/
        printf("DBG: Button Pressed \r\n");

        /*Button pressed*/
        printf("===============================================\r\n");
        printf("===============================================\r\n");
        printf("===============================================\r\n");
        printf("\r\n");
        printf("Bootloader Menu\r\n");
        printf("\r\n");
        printf("===============================================\r\n");
        printf("===============================================\r\n");
        printf("===============================================\r\n");

        printf("Available Commands:\r\n");
        printf("1       ==> Run App 1\r\n");
        printf("2       ==> Factory App 2\r\n");
        while(1) {
            if (key_value == 1) {
                printf("App 1 Selected\r\n");
                shift_to_appl((uint32_t)APP1_BASE);
            } else if (key_value == 2) {
                printf("App 2 Selected\r\n");
                shift_to_appl((uint32_t)APP2_BASE);
            }
        }
    } else {
        printf("button not pressed loading default Application\r\n");
        shift_to_appl((uint32_t)DEFAULT_APP);
    }
    while(1) {
        printf("Application not found\r\n");
    }
    return 0;
}
