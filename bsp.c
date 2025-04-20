#include <stdint.h>
#include <stdbool.h>
#include "bsp.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"

GPIO_handle_t led;
GPIO_handle_t button;
volatile bool button_press = false;
void init_led()
{

    gpio_clk_ctrl(GPIOD, ENABLE);
    led.pGPIOX = GPIOD;
    led.gpio_conf.pin_num = 12;
    led.gpio_conf.out_speed = LOW_SPEED;
    led.gpio_conf.out_speed = LOW_SPEED;
    led.gpio_conf.out_type = PUSH_PULL;
    led.gpio_conf.mode = GPIO_MODE_OUT;
    led.gpio_conf.pull_up_down = NO_PULL_DOWN;
    gpio_init(led);
}

void led_on()
{
    gpio_write_pin(GPIOD, 12, 1);
}

void led_off()
{
    gpio_write_pin(GPIOD, 12, 0);
}

void buttton_init() {
    gpio_clk_ctrl(GPIOA, ENABLE);
    button.pGPIOX = GPIOA;
    button.gpio_conf.pin_num = 0;
    button.gpio_conf.mode = GPIO_MODE_IR;
    gpio_init(button);
    IRQ_en(6, 10, INT_SET);
}

void EXTI0_IRQHandler()
{
    button_press = true;
    EXTI->EXTI_PR |= (1 << 0);
}



