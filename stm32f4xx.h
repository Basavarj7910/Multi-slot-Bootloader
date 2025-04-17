#ifndef __STM32F4XX__
#define __STM32F4XX__
#include <stdint.h>
/*
  *base adress of SRAM and Flash
*/

 #define HAL_FLASH_BASEADDR  0x08000000U     /* flash base address */
 #define HAL_SRAM1_BASEADDR  0x20000000U     /* SRAM1 base address */
 #define HAL_SRAM_BASEADDR   SRAM1_BASE      /* SRMA base address */
 #define HAL_SRAM2_BASEADDR  (SRAM + (112 * 1024))U  /* SRAM2 base adress */
 #define HAL_ROM_BASEADDR    0x1FFF0000U     /* ROM base address */
 #define HAL_OTP_BASEADDR    0x1FFF7800U     /* OTP base address*/
 #define HAL_RCC_BASEADDR    0x40023800U
 #define HAL_NIVIC_BASEADDR  0xE000E100U    /* NVIC base address */

/*
   *Peripheral base adress
*/

 #define HAL_PERIPH_BASE    0x40000000U
 #define HAL_APB1_BASEADDR  PERIPH_BASE
 #define HAL_APB2_BASEADDR  0x40010000U
 #define HAL_AHB1_BASEADDR  0x40020000U
 #define HAL_AHB2_BASEADDR  0x50000000U
 #define HAL_AHB3_BASEADDR  0xA0000000U


/*
 *system peripherals
*/

#define CPACR ((uint32_t *)0xE000ED88U)
#define SYST_BASE 0xE000E010U



/*
  *Base adress of peripherals hanging on AHB1 BUS
*/
 #define HAL_GPIOADDR_SIZE  0x400U
 #define HAL_GPIOA_BASEADDR 0x40020000U
 #define HAL_GPIOB_BASEADDR 0x40020400U
 #define HAL_GPIOC_BASEADDR 0x40020800U
 #define HAL_GPIOD_BASEADDR 0x40020c00U
 #define HAL_GPIOE_BASEADDR 0x40021000U
 #define HAL_GPIOF_BASEADDR 0x40021400U
 #define HAL_GPIOG_BASEADDR 0x40021800U
 #define HAL_GPIOH_BASEADDR 0x40021c00U
 #define HAL_GPIOI_BASEADDR 0x40022000U
 #define HAL_GPIOJ_BASEADDR 0x40022400U
 #define HAL_GPIOK_BASEADDR 0x40022800U


/* 
  *Definining base adress of peripherals hanginh on APB1 BUS
*/

 #define HAL_I2C1_BASEADDR 0x40005400
 #define HAL_I2C2_BASEADDR 0x40005800U

 #define HAL_I2C3_BASEADDR 0x40005c00U
 #define HAL_SPI2_BASEADDR 0x40003800U
 #define HAL_SPI3_BASEADDR 0x40003c00U

 #define HAL_USART2_BASEADDR 0x40004400U
 #define HAL_USART3_BASEADDR 0x40004800U
 #define HAL_USART4_BASEADDR 0x40004c00U
 #define HAL_USART5_BASEADDR 0x40005000U
 #define HAL_USART7_BASEADDR 0x40007800U
 #define HAL_USART8_BASEADDR 0x40007c00U

/* 
  *Defining base address of peripherals hanging on APB2 BUS
*/

 #define HAL_USART1_BASEADDR 0x40011000U
 #define HAL_USART6_BASEADDR 0x40011400U

 #define HAL_SPI1_BASEADDR  0x40013000U
 #define HAL_SPI4_BASEADDR  0x40013400U
 #define HAL_SPI5_BASEADDR 0x40015000U
 #define HAL_SPI6_BASEADDR 0x40015400U

 #define HAL_SYSCFG_BASEADDR 0x40013800U
 #define HAL_EXTI_BASEADDR 0x40013c00U
/*
 * defining register structure of systick timer
*/

typedef struct {
    volatile uint32_t CSR;
    volatile uint32_t RVR;
    volatile uint32_t CVR;
    volatile uint32_t CALIB;
}SYS_RegDef_t;

#define SYST ((SYS_RegDef_t*)SYST_BASE)

/*
  *Defining GPIOS register structure
*/

typedef struct
{
    volatile uint32_t MODER;           /* GPIO port mode registe Address offset: 0x00 */
    volatile uint32_t OTYPER;          /* GPIO port output type register Address offset: 0x04 */
    volatile uint32_t OSPEEDR;         /* GPIO port output speed register Address offset: 0x08 */
    volatile uint32_t PUPDR;           /* GPIO port pull-up/pull-down registe Address offset: 0x0C */
    volatile uint32_t IDR;             /* GPIO port input data register Address offset: 0x10 */
    volatile uint32_t ODR;             /* GPIO port output data registe Address offset: 0x14 */
    volatile uint32_t BSRR;            /* GPIO port bit set/reset registe Address offset: 0x18 */
    volatile uint32_t LCKR;            /* GPIO port configuration lock register Address offset: 0x1C */
    volatile uint32_t AFR[2];         /*  AFRL[0] GPIO alternate function lower register and AFRL[1] is higher register adress offset: 0x20 */
}GPIO_RegDef_t;

/*
  *defining strcure of RCC registers
*/

typedef struct
{
  volatile uint32_t CR;           /* RCC clock control register (RCC_CR) Address offset: 0x00 */
  volatile uint32_t PLLCFGR;      /* RCC PLL configuration register (RCC_PLLCFGR)Address offset: 0x04  */
  volatile uint32_t CFGR;         /* RCC clock configuration register (RCC_CFGR) Address offset: 0x08 */
  volatile uint32_t  CIR ;         /* RCC clock interrupt register (RCC_CIR) Address offset: 0x0C */
  volatile uint32_t AHB1RSTR;     /* RCC AHB1 peripheral reset register (RCC_AHB1RSTR) Address offset: 0x10 */
  volatile uint32_t AHB2RSTR;     /* RCC AHB2 peripheral reset register (RCC_AHB2RSTR) Address offset: 0x14 */
  volatile uint32_t AHB3RSTR;     /* RCC AHB3 peripheral reset register (RCC_AHB3RSTR) Address offset: 0x18 */
  volatile uint32_t RES0;         /* reserved for future use Address offset: 0x1C */
  volatile uint32_t APB1RSTR;     /* RCC APB1 peripheral reset register (RCC_APB1RSTR) Address offset: 0x20 */
  volatile uint32_t APB2RSTR;     /* RCC APB2 peripheral reset register (RCC_APB2RSTR) Address offset: 0x24 */
  volatile uint32_t RES[2];       /* reserved for future use Address offset :0x28,0x2C */ 
  volatile uint32_t AHB1ENR;      /* RCC AHB1 peripheral clock enable register (RCC_AHB1ENR) Address offset: 0x30 */
  volatile uint32_t AHB2ENR;      /* RCC AHB2 peripheral clock enable register (RCC_AHB2ENR) Address offset: 0x34 */
  volatile uint32_t AHB3ENR;      /* RCC AHB3 peripheral clock enable register (RCC_AHB3ENR) Address offset: 0x38 */
  volatile uint32_t RES2;         /* Reserved for future use Address offset : 0x3C */
  volatile uint32_t APB1ENR;      /* RCC APB1 peripheral clock enable register(RCC_APB1ENR) Address offset: 0x40 */
  volatile uint32_t APB2ENR;      /* RCC APB2 peripheral clock enable register (RCC_APB2ENR) Address offset: 0x44 */
  volatile uint32_t RES1[2];      /* Reserved for future use :0x48 :0x4c */
  volatile uint32_t AHB1LPENR;    /* RCC AHB1 peripheral clock enable in low power mode register Address offset: 0x50 */
  volatile uint32_t AHB2LPENR;    /* RCC AHB2 peripheral clock enable in low power mode register Address offset: 0x54 */
  volatile uint32_t AHB3LPENR;    /* RCC AHB3 peripheral clock enable in low power mode register Address offset: 0x58 */
  volatile uint32_t RES3;         /* Reserved for futur use Address offset : 0x5C */
  volatile uint32_t APB1LPENR;    /* RCC APB1 peripheral clock enable in low power mode register Address offset: 0x60 */
  volatile uint32_t APB2LPENR;    /* RCC APB2 peripheral clock enabled in low power mode Address offset: 0x64 */
  volatile uint32_t RES4[2];      /* Reserved for Future Use Address offset: 0x68,0x6c */
  volatile uint32_t RCC_BDCR;     /* RCC Backup domain control register (RCC_BDCR) Address offset: 0x70 */
  volatile uint32_t RCC_CSR;      /* RCC clock control & status register (RCC_CSR) Address offset: 0x74 */
  volatile uint32_t RES5[2];      /* Reserved for future Use Address offset :0x78,0x7C */
  volatile uint32_t RCC_SSCGR;    /* RCC spread spectrum clock generation register (RCC_SSCGR) Address offset: 0x80 */
  volatile uint32_t PLLI2SCFGR;   /* RCC PLLI2S configuration register (RCC_PLLI2SCFGR) Address offset: 0x84 */
}RCC_RegDef_t;


/*
   *Defining register structure of EXTI
*/
typedef struct {
    volatile uint32_t EXTI_IMR;   /* Interrupt mask register (EXTI_IMR) */
    volatile uint32_t EXTI_EMR;   /* Event mask register (EXTI_EMR) */
    volatile uint32_t EXTI_RTSR;  /* Rising trigger selection register (EXTI_RTSR)*/
    volatile uint32_t EXTI_FTSR;  /* Falling trigger selection register (EXTI_FTSR) */
    volatile uint32_t EXTI_SWIER; /* Software interrupt event register (EXTI_SWIER) */
    volatile uint32_t EXTI_PR;    /* Pending register (EXTI_PR)*/
}EXTI_RegDef_t;

/*
   *Defining Syatem Config register structure
*/

typedef struct {
    volatile uint32_t SYSCFG_MEMRMP; /*     */
    volatile uint32_t SYSCFG_PMC;
    volatile uint32_t SYSCFG_EXTICR[4];
    volatile uint32_t reserve[2];
    volatile uint32_t SYSCFG_CMPCR;
}SYSCFG_RegDef_t;

/*
   *defining register structure for the USART
*/

typedef struct {
    volatile uint32_t USART_SR;
    volatile uint32_t USART_DR;
    volatile uint32_t USART_BRR;
    volatile uint32_t USART_CR1;
    volatile uint32_t USART_CR2;
    volatile uint32_t USART_CR3;
    volatile uint32_t USART_GTPR;
}USART_Reg_Def_t;


/*
   *Defining NVIC registers structure
   */
typedef struct {
   volatile uint32_t NVIC_ISER[8]; /* Interrupt Set-enable Registers */
   volatile uint32_t NVIC_ICER[8]; /* Interrupt clear-enable Registers */
   volatile uint32_t NVIC_ISPR[8]; /* Interrupt Set-pending  Registers */
   volatile uint32_t NVIC_ICPR[8]; /* Interrupt clear-pending Registers */
   volatile uint32_t NVIC_IABR[8]; /* Interrupt active-bit Registers */
   volatile uint32_t NVIC_IPR[60]; /* Interrupt prority  Registers */
   volatile uint32_t STIR;         /* Software Trigger Interrupt Register */
}NVIC_Reg_Def_t;
/*
   *definig NVIC
*/

#define NVIC ((NVIC_Reg_Def_t*) HAL_NIVIC_BASEADDR) 

/*
   *Defining EXTI 
*/

#define EXTI ((EXTI_RegDef_t*) HAL_EXTI_BASEADDR)

/* 
   *Defining SYSCFG
*/

#define SYSCFG ((SYSCFG_RegDef_t*)HAL_SYSCFG_BASEADDR)

/*
  * defining gpio port strcture with theire based adress 
*/

#define GPIOA ((GPIO_RegDef_t *)HAL_GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t *)HAL_GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t *)HAL_GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t *)HAL_GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t *)HAL_GPIOE_BASEADDR)
#define GPIOF ((GPIO_RegDef_t *)HAL_GPIOF_BASEADDR)
#define GPIOG ((GPIO_RegDef_t *)HAL_GPIOG_BASEADDR)
#define GPIOH ((GPIO_RegDef_t *)HAL_GPIOH_BASEADDR)
#define GPIOI ((GPIO_RegDef_t *)HAL_GPIOI_BASEADDR)


/* 
 * defining RCC 
*/

#define RCC ((RCC_RegDef_t*)HAL_RCC_BASEADDR)

/* 
  *Defining macros for peripheral clock enable 
*/

/* clock enable macros for gpios */
#define GPIOA_PCLK_EN() (RCC->AHB1ENR |= ( 1 << 0))  
#define GPIOB_PCLK_EN() (RCC->AHB1ENR |= ( 1 << 1))  
#define GPIOC_PCLK_EN() (RCC->AHB1ENR |= ( 1 << 2))  
#define GPIOD_PCLK_EN() (RCC->AHB1ENR |= ( 1 << 3))  
#define GPIOE_PCLK_EN() (RCC->AHB1ENR |= ( 1 << 4))  
#define GPIOF_PCLK_EN() (RCC->AHB1ENR |= ( 1 << 5))  
#define GPIOG_PCLK_EN() (RCC->AHB1ENR |= ( 1 << 6))  
#define GPIOH_PCLK_EN() (RCC->AHB1ENR |= ( 1 << 7))  
#define GPIOI_PCLK_EN() (RCC->AHB1ENR |= ( 1 << 8))  

/* 
  *Defining macros to enable clock for I2C 
*/

#define I2C1_PCLK_EN() (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN() (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN() (RCC->APB1ENR |= (1 << 23))

/*
  *Defining macros for enabling clock for USART
*/

#define USART1_PCLK_EN() (RCC->APB2ENR |= (1 << 4))
#define USART6_PCLK_EN() (RCC->APB2ENR |= (1 << 5))
#define USART2_PCLK_EN() (RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN() (RCC->APB1ENR |= (1 << 18))
#define USART4_PCLK_EN() (RCC->APB1ENR |= (1 << 19))
#define USART5_PCLK_EN() (RCC->APB1ENR |= (1 << 20))
#define USART6_PCLK_EN() (RCC->APB2ENR |= (1 << 5))

/*
  *defing macros for enabling clock for SPI
*/

#define SPI1_PCLK_EN() (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN() (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN() (RCC->APB1ENR |= (1 << 15))

/*
   *enable clock for syscfg
*/

#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 14))
#define SYSCFG_PCLK_DIS() (RCC->APB2ENR &= ~(1 << 14))

/* 
  *Defining macros for peripheral clock enable 
*/

/* clock enable macros for gpios */
#define GPIOA_PCLK_DIS() (RCC->AHB1ENR &= ~( 1 << 0))  
#define GPIOB_PCLK_DIS() (RCC->AHB1ENR &= ~( 1 << 1))  
#define GPIOC_PCLK_DIS() (RCC->AHB1ENR &= ~( 1 << 2))  
#define GPIOD_PCLK_DIS() (RCC->AHB1ENR &= ~( 1 << 3))  
#define GPIOE_PCLK_DIS() (RCC->AHB1ENR &= ~( 1 << 4))  
#define GPIOF_PCLK_DIS() (RCC->AHB1ENR &= ~( 1 << 5))  
#define GPIOG_PCLK_DIS() (RCC->AHB1ENR &= ~( 1 << 6))  
#define GPIOH_PCLK_DIS() (RCC->AHB1ENR &= ~( 1 << 7))  
#define GPIOI_PCLK_DIS() (RCC->AHB1ENR &= ~( 1 << 8))  

/* 
  *Defining macros to enable clock for I2C 
*/

#define I2C1_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 23))

/*
  *Defining macros for disabling clock for USART
*/

#define USART1_PCLK_DIS() (RCC->APB2ENR &= ~(1 << 4))
#define USART6_PCLK_DIS() (RCC->APB2ENR &= ~(1 << 5))
#define USART2_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 18))
#define USART4_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 19))
#define USART5_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 20))
#define USART6_PCLK_DIS() (RCC->APB2ENR &= ~(1 << 5))

/*
  *defing macros for disabling clock for SPI
*/

#define SPI1_PCLK_DIS() (RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 15))
#endif

/*
   *intializing differnt USART with there base addresses
*/

#define USART1  ((USART_Reg_Def_t*)HAL_USART1_BASEADDR)
#define USART2  ((USART_Reg_Def_t*)HAL_USART2_BASEADDR)
#define USART3  ((USART_Reg_Def_t*)HAL_USART3_BASEADDR)
#define USART4  ((USART_Reg_Def_t*)HAL_USART4_BASEADDR)
#define USART5  ((USART_Reg_Def_t*)HAL_USART5_BASEADDR)
#define USART6  ((USART_Reg_Def_t*)HAL_USART6_BASEADDR)




#define SET         1
#define RESET       0
#define ENABLE      1
#define DISABLE     RESET
#define SET_PIN     SET
#define RESET_PIN   RESET
