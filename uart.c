#include <stdint.h>
#include <stdbool.h>
#include "stm32f4xx.h"
#include "uart.h"

#define PERI_CLK 16000000
#define BAUDRATE 115200
#define UE_EN    (1 << 13)
#define TX_EN    (1 << 3)
#define RX_EN    (1 << 2)
#define RXNE_IN_EN    (1 << 5)

extern volatile bool button_press;
volatile uint8_t key_value;

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
        if (button_press) {
            uint8_t data = USART2->USART_DR;
            if (data == 49) {
                uint8_t ret[3] = {data,'\r','\n'};
                for (int i =0;i<3;i++) {
                    while (!(USART2->USART_SR & (1 << 6))); // Wait for TXE
                    USART2->USART_DR = ret[i];
                }
                key_value = 1;
            } else if (data == 50) {
                uint8_t ret[3] = {data,'\r','\n'};
                for (int i =0;i<3;i++) {
                    while (!(USART2->USART_SR & (1 << 6))); // Wait for TXE
                    USART2->USART_DR = ret[i];
                }
                key_value = 2;
            } else {
                uint8_t ret[3] = {data,'\r','\n'};
                for (int i =0;i<3;i++) {
                    while (!(USART2->USART_SR & (1 << 6))); // Wait for TXE
                    USART2->USART_DR = ret[i];
                }
                printf("Press key 1 or 2 to run respective applications\r\n");
            }
        }
    }
}
