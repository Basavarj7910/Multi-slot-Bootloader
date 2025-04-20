#ifndef __STM32F4xx_GPIO__
#define __STM32F4xx_GPIO__

#include "stm32f4xx.h"
#include <stdint.h>

typedef struct
{
    uint8_t pin_num;           /* <pin number of port posible value from @GPIO pin numbers*/
    uint8_t mode;              /* mode of gpio pin posible value from @MODE OF GPIO   */
    uint8_t out_speed;        /* speed of gpio pin posible value from @SPEED OF GPIO */
    uint8_t out_type;         /* output type of gpio pin posible value from @Different output types */
    uint8_t pull_up_down;        /* pull_up or pull down conifigeration for gpio posible value from @push pull of gpio */
    uint8_t alt_fun;          /* alternate function of pin posible alternate functions @ALT_FUNCTIONS OF GPIO*/
}gpio_conf_t;

/*
 *GPIO HANDLER
 */

typedef struct 
{
    GPIO_RegDef_t *pGPIOX;      /* base adress of port */
    gpio_conf_t  gpio_conf;     /* configeration values for pin */
}GPIO_handle_t;

/*
 *Different mode of the gpio
 */

typedef enum
{
    GPIO_MODE_IN = 0,
    GPIO_MODE_OUT = 1,
    GPIO_MODE_ALT = 2,
    GPIO_MODE_ANALOG = 3,
    GPIO_MODE_IR = 4,
    GPIO_MODE_IF = 5,
    GPIO_MODE_IFR = 6,
}GPIO_MODE_t;

/* 
 *PUSH PULL Configuartion 
 */

typedef enum
{
    NO_PULL_DOWN = 0x00,
    PULL_UP      = 0x01,
    PULL_DOWN    = 0x02,
    RESERVE      = 0x03
} push_pull_t;

/* 
 *Output types of gpio
 */

typedef enum
{
    PUSH_PULL = 0x00,
    OPEN_DRAIN = 0x01,
} output_type_t;

/*
 *Different Speed of GPIO
 */

typedef enum
{
    LOW_SPEED = 0x00,
    MEDIUM_SPEED = 0x01,
    HIGH_SPEED = 0x02,
    VHIGH_SPEED = 0x03,
} out_type_t;

/*
 *pin numbers of gpio
 */
typedef enum
{
    GPIO_NUM0 = 0,
    GPIO_NUM1 = 1,
    GPIO_NUM2 = 2,
    GPIO_NUM3 = 3,
    GPIO_NUM4 = 4,
    GPIO_NUM5 = 5,
    GPIO_NUM6 = 6,
    GPIO_NUM7 = 7,
    GPIO_NUM8 = 8,
    GPIO_NUM9 = 9,
    GPIO_NUM10 = 10,
    GPIO_NUM11 = 11,
    GPIO_NUM12 = 12,
    GPIO_NUM13 = 13,
    GPIO_NUM14 = 14,
    GPIO_NUM15 = 15,
}GPIO_NUM_t;

typedef enum 
{
    AF0 = 0,
    AF1 = 1,
    AF2 = 2,
    AF3 = 3,
    AF4 = 4,
    AF5 = 5,
    AF6 = 6,
    AF7 = 7,
    AF8 = 8,
    AF9 = 9,
    AF10 = 10,
    AF11 = 11,
    AF12 = 12,
    AF13 = 13,
    AF14 = 14,
    AF15 = 15
}alt_fun_t;
typedef enum {
    INT_SET = 0,
    INT_CLEAR = 1,
    INT_PEND_SET = 2,
    INT_PEND_CLEAR = 3,
    INT_ACT_BIT = 4,
}INT_CONFIG_t;


/* *************************************************************
 * @fn            - gpio_clk_ctrl
 *
 * @brief         - Function to enable or  disable clock
 * 
 * @param[in]     - Base Address of GPIO PORT
 * @param[in]     - ENABLE or DISABLE 
 * 
 * @return        - null
 * note           - null
 */

void gpio_clk_ctrl(GPIO_RegDef_t *gpiox, uint8_t val);

/* *************************************************************
 * @fn            - gpio_init
 *
 * @brief         - Function to initialse pin
 * 
 * @param[in]     - Congigeartion of pin
 * 
 * @return        - null
 * note           - null
 */

void gpio_init(GPIO_handle_t gpiox);         

/* *************************************************************
 * @fn            - gpio_deinit
 *
 * @brief         - Function to deinitialize the port
 * 
 * @param[in]     - Base Address of GPIO PORT
 * 
 * @return        - null
 * note           - null
 */

void gpio_dinit(GPIO_RegDef_t *gpiox);       // deinitializing gpio


/* *************************************************************
 * @fn            - gpio_read_pin
 *
 * @brief         - Function to read the value of pin
 * 
 * @param[in]     - Base Address of GPIO PORT
 * @param[in]     - pin number
 * 
 * @return        - value of pin
 * note           - null
 */

uint8_t gpio_read_pin(GPIO_RegDef_t *gpiox, uint8_t pin);

/* *************************************************************
 * @fn            - gpio_read_port
 *
 * @brief         - Function to read the value of port
 * 
 * @param[in]     - Base Address of GPIO PORT
 * 
 * @return        - value of port
 * note           - null
 */

uint16_t gpio_read_port(GPIO_RegDef_t *gpiox);

/* *************************************************************
 * @fn            - gpio_write_pin
 *
 * @brief         - Function to write the value to pin of the port
 * 
 * @param[in]     - Base Address of GPIO PORT
 * @param[in]     - pin number
 * @param[in]     - value of pin
 * 
 * @return        - null
 * note           - null
 */

void gpio_write_pin(GPIO_RegDef_t *gpiox, uint8_t pin, uint8_t value);

/* *************************************************************
 * @fn            - gpio_toggle_pin
 *
 * @brief         - Function to toggle the value of pin
 * 
 * @param[in]     - Base Address of GPIO PORT
 * 
 * @return        - null
 * note           - null
 */
void gpio_toggle_pin(GPIO_RegDef_t *gpiox, uint8_t pin);

/* *************************************************************
 * @fn            - IRQ_en
 *
 * @brief         - Function to enbale the irq of nvic
 * 
 * @param[in]     - IRQ NUM
 * @param[in]     - priority of interrupt
 * @param[in]     - enable/disable
 * 
 * @return        - null
 * note           - null
 */
void IRQ_en(uint8_t irq_num, uint8_t priority, uint8_t set_clear);
#endif
