/**************************************************************/
/*	Author : Reda Galal Anwer  					***************/
/*	Data    : 24/9/2023							***************/
/*	Dis     : UART_privit			     	    ***************/
/* 	Version : V01								***************/
/**************************************************************/

#ifndef UART_PRIVIT_H_
#define UART_PRIVIT_H_


typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR[3];
	volatile u32 GTPR;
}USART_Register;


#define 	USART1 		((USART_Register *) 0x40013800)


#define Baud_Rate_9600 			0
#define Baud_Rate_115200		1


#endif 