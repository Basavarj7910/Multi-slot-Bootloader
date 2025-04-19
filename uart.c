#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"

#define PERI_CLK 16000000
#define BAUDRATE 115200
#define UE_EN    (1 << 13)
#define TX_EN    (1 << 3)
#define RX_EN    (1 << 2)
#define RXNE_IN_EN    (1 << 5)


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
   /* selecting gpio mode as alternate function for GPIO3A */
   GPIOA->MODER &= ~(3 << 6); 
   GPIOA->MODER |= (1 << 7);       
   /* selcting AF7(UART) as alternate function for UPIO2A */
   GPIOA->AFR[0] &= ~(0xf << 8);   
   GPIOA->AFR[0] |= (0x07 << 8);   
   /* selcting AF7(UART) as alternate function for UPIO3A */
   GPIOA->AFR[0] &= ~(0xf << 12);   
   GPIOA->AFR[0] |= (0x07 << 12);   
   /* selcting baudarate  */
   set_baudrate(PERI_CLK, BAUDRATE);
   /* enable the uart_tx */
   USART2->USART_CR1 |= TX_EN;
   /* enable the uart_rx_interrupt */
   USART2->USART_CR1 |= RXNE_IN_EN;
   NVIC->NVIC_ISER[1] |= ( 1 << 6);
   /* enable the uart_rx */
   USART2->USART_CR1 |= RX_EN;
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

void USART2_IRQHandler() {
    if (USART2->USART_SR & ( 1 << 5)) {
        uint8_t data = USART2->USART_DR;
        if (data == 49) {
            printf("key pressed is 1\r\n");
        } else if (data == 50) {
            printf("key pressed is 2\r\n");
        } else {
            printf("other key is pressed\r\n");
        }
    }
}
