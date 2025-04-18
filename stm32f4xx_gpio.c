#include "stm32f4xx_gpio.h"
#include <stdint.h>

void gpio_clk_ctrl(GPIO_RegDef_t *gpiox, uint8_t val) {
    if (val == ENABLE) {
        if (gpiox == GPIOA) {
            GPIOA_PCLK_EN();
        } else if (gpiox == GPIOB) {
            GPIOB_PCLK_EN();
        } else if (gpiox == GPIOC) {
            GPIOC_PCLK_EN();
        } else if (gpiox == GPIOD) {
            GPIOD_PCLK_EN();
        } else if (gpiox == GPIOE) {
            GPIOE_PCLK_EN();
        } else if (gpiox == GPIOF) {
            GPIOF_PCLK_EN();
        } else if (gpiox == GPIOG) {
            GPIOG_PCLK_EN();
        } else if (gpiox == GPIOH) {
            GPIOH_PCLK_EN();
        } else if (gpiox == GPIOI) {
            GPIOI_PCLK_EN();
        }
    } else if (val == DISABLE) {
        if (gpiox == GPIOA) {
            GPIOA_PCLK_DIS();
        } else if (gpiox == GPIOB) {
            GPIOB_PCLK_DIS();
        } else if (gpiox == GPIOC) {
            GPIOC_PCLK_DIS();
        } else if (gpiox == GPIOD) {
            GPIOD_PCLK_DIS();
        } else if (gpiox == GPIOE) {
            GPIOE_PCLK_DIS();
        } else if (gpiox == GPIOF) {
            GPIOF_PCLK_DIS();
        } else if (gpiox == GPIOG) {
            GPIOG_PCLK_DIS();
        } else if (gpiox == GPIOH) {
            GPIOH_PCLK_DIS();
        } else if (gpiox == GPIOI) {
            GPIOI_PCLK_DIS();
        }
    }
}

void IRQ_en(uint8_t irq_num, uint8_t priority, uint8_t set_clear) {
 uint8_t ind = irq_num / 32;
 uint8_t rem = irq_num % 32;
 if (set_clear == INT_SET) {
    NVIC->NVIC_ISER[ind] |= (1 << rem);
 } else if( set_clear == INT_CLEAR) {
    NVIC->NVIC_ICER[ind] |= (1 << rem);
 }
 uint8_t int_ind = irq_num/4;
 uint8_t int_rem = irq_num %4;
 NVIC->NVIC_IPR[int_ind] &= ~(0xff <<(8 * int_rem));
 NVIC->NVIC_IPR[int_ind] |= (priority << (8 * int_rem));

}

void gpio_init(GPIO_handle_t gpiox) {
    // enable mode of the gpio
    if (gpiox.gpio_conf.mode <= GPIO_MODE_ANALOG) {
        gpiox.pGPIOX->MODER &= ~(0x3 << (gpiox.gpio_conf.pin_num * 2));
        gpiox.pGPIOX->MODER |= (gpiox.gpio_conf.mode << (gpiox.gpio_conf.pin_num * 2));
    } else {
        // interrupt mode
        if (gpiox.gpio_conf.mode == GPIO_MODE_IR) {
            EXTI->EXTI_RTSR |= (1 << (gpiox.gpio_conf.pin_num));
            EXTI->EXTI_FTSR &= ~(1 << (gpiox.gpio_conf.pin_num));
        } else if (gpiox.gpio_conf.mode == GPIO_MODE_IF) {
            EXTI->EXTI_RTSR &= ~(1 << (gpiox.gpio_conf.pin_num));
            EXTI->EXTI_FTSR |= (1 << (gpiox.gpio_conf.pin_num));
        } else if (gpiox.gpio_conf.mode == GPIO_MODE_IFR) {
            EXTI->EXTI_FTSR |= (1 << (gpiox.gpio_conf.pin_num));
            EXTI->EXTI_RTSR |= (1 << (gpiox.gpio_conf.pin_num));
        }

        SYSCFG_PCLK_EN();
        //enabling exti gpio pin
        uint8_t pin_num = gpiox.gpio_conf.pin_num / 4;
        uint8_t pin_ind = gpiox.gpio_conf.pin_num % 4;
        if (gpiox.pGPIOX == GPIOA) {
        SYSCFG->SYSCFG_EXTICR[pin_num] &= ~(0xff << (4 * pin_ind));
        } else if (gpiox.pGPIOX == GPIOB) {
        SYSCFG->SYSCFG_EXTICR[pin_num] &= ~(0xff << (4 * pin_ind));
        SYSCFG->SYSCFG_EXTICR[pin_num] |= (0x01 << (4 * pin_ind));
        } else if (gpiox.pGPIOX == GPIOC) {
        SYSCFG->SYSCFG_EXTICR[pin_num] &= ~(0xff << (4 * pin_ind));
        SYSCFG->SYSCFG_EXTICR[pin_num] |= (0x02 << (4 * pin_ind));
        } else if (gpiox.pGPIOX == GPIOD) {
        SYSCFG->SYSCFG_EXTICR[pin_num] &= ~(0xff << (4 * pin_ind));
        SYSCFG->SYSCFG_EXTICR[pin_num] |= (0x03 << (4 * pin_ind));
        } else if (gpiox.pGPIOX == GPIOE) {
        SYSCFG->SYSCFG_EXTICR[pin_num] &= ~(0xff << (4 * pin_ind));
        SYSCFG->SYSCFG_EXTICR[pin_num] |= (0x04 << (4 * pin_ind));
        } else if (gpiox.pGPIOX == GPIOF) {
        SYSCFG->SYSCFG_EXTICR[pin_num] &= ~(0xff << (4 * pin_ind));
        SYSCFG->SYSCFG_EXTICR[pin_num] |= (0x05 << (4 * pin_ind));
        } else if (gpiox.pGPIOX == GPIOG) {
        SYSCFG->SYSCFG_EXTICR[pin_num] &= ~(0xff << (4 * pin_ind));
        SYSCFG->SYSCFG_EXTICR[pin_num] |= (0x06 << (4 * pin_ind));
        } else if (gpiox.pGPIOX == GPIOH) {
        SYSCFG->SYSCFG_EXTICR[pin_num] &= ~(0xff << (4 * pin_ind));
        SYSCFG->SYSCFG_EXTICR[pin_num] |= (0x07 << (4 * pin_ind));
        } else if (gpiox.pGPIOX == GPIOI) {
        SYSCFG->SYSCFG_EXTICR[pin_num] &= ~(0xff << (4 * pin_ind));
        SYSCFG->SYSCFG_EXTICR[pin_num] |= (0x08 << (4 * pin_ind));
        }
        //enablibg interuupt  mask register for the pin
         EXTI->EXTI_IMR |= (1 << (gpiox.gpio_conf.pin_num));
    }
    // setting the output type
    gpiox.pGPIOX->OTYPER &= ~(0x1 << gpiox.gpio_conf.pin_num);
    gpiox.pGPIOX->OTYPER |= (gpiox.gpio_conf.out_type << gpiox.gpio_conf.pin_num);
    // setting the ouput speed
    gpiox.pGPIOX->OSPEEDR &= ~(0x3 << (gpiox.gpio_conf.pin_num * 2));
    gpiox.pGPIOX->OSPEEDR |= (gpiox.gpio_conf.out_speed << (gpiox.gpio_conf.pin_num * 2));
    // setting pull_up or pull_down
    gpiox.pGPIOX->PUPDR &= ~(0x3 << (gpiox.gpio_conf.pin_num * 2));
    gpiox.pGPIOX->PUPDR |=(gpiox.gpio_conf.pull_up_down << (gpiox.gpio_conf.pin_num * 2));
    if (gpiox.gpio_conf.mode <= GPIO_MODE_ALT) {
        if (gpiox.gpio_conf.pin_num <= 7) {
            gpiox.pGPIOX->AFR[0] &= ~(0xf << (gpiox.gpio_conf.pin_num * 4));
            gpiox.pGPIOX->AFR[0] |= (gpiox.gpio_conf.alt_fun << (gpiox.gpio_conf.pin_num * 4));
        } else {
            gpiox.pGPIOX->AFR[1] &= ~(0xf << ((gpiox.gpio_conf.pin_num - 8) * 4));
            gpiox.pGPIOX->AFR[1] |= (gpiox.gpio_conf.alt_fun << ((gpiox.gpio_conf.pin_num - 8) * 4));
        }
    }
}

void gpio_dinit(GPIO_RegDef_t * gpiox)
{

        if (gpiox == GPIOA) {
            RCC->AHB1RSTR |= (1 << 0);
        } else if (gpiox == GPIOB) {
            RCC->AHB1RSTR |= (1 << 1);
        } else if (gpiox == GPIOC) {
            RCC->AHB1RSTR |= (1 << 2);
        } else if (gpiox == GPIOD) {
            RCC->AHB1RSTR |= (1 << 3);
        } else if (gpiox == GPIOE) {
            RCC->AHB1RSTR |= (1 << 4);
        } else if (gpiox == GPIOF) {
            RCC->AHB1RSTR |= (1 << 5);
        } else if (gpiox == GPIOG) {
            RCC->AHB1RSTR |= (1 << 6);
        } else if (gpiox == GPIOH) {
            RCC->AHB1RSTR |= (1 << 7);
        } else if (gpiox == GPIOI) {
            RCC->AHB1RSTR |= (1 << 8);
        }
   
}

uint8_t gpio_read_pin(GPIO_RegDef_t * gpiox, uint8_t pin) {
    return (gpiox->IDR & (0x01 << pin));
}

uint16_t gpio_read_port(GPIO_RegDef_t * gpiox);

void gpio_write_pin(GPIO_RegDef_t * gpiox, uint8_t pin, uint8_t value) {
    if (value == ENABLE) {
        gpiox->ODR |= (1 << pin);
    } else if (value == DISABLE) {
        gpiox->ODR &= ~(1 << pin);
    }
}

void gpio_toggle_pin(GPIO_RegDef_t * gpiox, uint8_t pin) {
    gpiox->ODR ^= (1 << pin);
}
