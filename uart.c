#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"

#define PERI_CLK 16000000
#define BAUDRATE 115200
#define UE_EN    (1 << 13)
#define TX_EN    (1 << 3)



uint32_t calculate_baudrate(uint32_t peri_clk, uint32_t baudrate) 
{
    return ((peri_clk + (baudrate / 2U))/baudrate);
}

void set_baudrate(uint32_t peri_clk, uint32_t baudrate)
{
    USART2->USART_BRR = calculate_baudrate(peri_clk, baudrate);
}


void uart_init()
{
   /* enable the USART2 peripheral clk */
   USART2_PCLK_EN();         
   /* enable the GPIOA peripheral clk */
   GPIOA_PCLK_EN();                
   /* selecting gpio mode as alternate function for GPIO2A */
   GPIOA->MODER &= ~(3 << 4); 
   GPIOA->MODER |= (1 << 5);       
   /* selcting AF7(UART) as alternate function for UPIO2A */
   GPIOA->AFR[0] &= ~(0xf << 8);   
   GPIOA->AFR[0] |= (0x07 << 8);   
   /* selcting baudarate  */
   set_baudrate(PERI_CLK, BAUDRATE);
   /* enable the uart_tx */
   USART2->USART_CR1 |= TX_EN;
   /* enable the uart2 */
   USART2->USART_CR1 |= UE_EN;
}

void printf(char *data)
{
    while (*data) {
        while (!(USART2->USART_SR & (1 << 6))); // Wait for TXE
        USART2->USART_DR = *data++;
    }
}



