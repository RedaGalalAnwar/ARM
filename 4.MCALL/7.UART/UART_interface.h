/**************************************************************/
/*	Author  : Reda Galal Anwer 					***************/
/*	Data    : 24/9/2023							***************/
/*	Dis     : UART_interface				    ***************/
/* 	Version : V01								***************/
/**************************************************************/


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/* Defining Macros */

#define USART_U8_8_BIT_WORD					0
#define USART_U8_9_BIT_WORD					1

#define USART_U8_PARITY_DISABLED			0
#define USART_U8_PARITY_ENABLED				1

#define USART_U8_EVEN_PARITY				0
#define USART_U8_ODD_PARITY					1

#define USART_U8_PE_DISABLED				0
#define USART_U8_PE_ENABLED					1


/*******************/

void USART_Init(void);

void USART_Transmit(char* word);

u8 USART_Receive(void);

#endif 