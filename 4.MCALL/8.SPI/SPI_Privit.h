/**************************************************************/
/*	Author : Reda Galal Anwer  					***************/
/*	Data    : 26/9/2023							***************/
/*	Dis     : SPI_privit			     	    ***************/
/* 	Version : V01								***************/
/**************************************************************/

#ifndef SPI_PRIVIT_H_
#define SPI_PRIVIT_H_

typedef struct
{
	volatile u32 CR1    ;
	volatile u32 CR2    ;
	volatile u32 SR     ;
	volatile u32 DR     ;
	volatile u32 CRCPR  ;
	volatile u32 RXCRCR ;
	volatile u32 TXCRCR ;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR  ; 
	
}SPI_Register;


#define MSPI1   ((SPI_Register*)0x40013000)

#endif 