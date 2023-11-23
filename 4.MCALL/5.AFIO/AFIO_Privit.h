/**************************************************************/
/*	Author : Reda Galal Anwer  					***************/
/*	Data    : 20/9/2023							***************/
/*	Dis     : AFIO_privit			     	    ***************/
/* 	Version : V01								***************/
/**************************************************************/



#ifndef AFIO_PRIVIT_H_
#define AFIO_PRIVIT_H_



typedef struct{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
	
}AFIO_t;


#define AFIO ((volatile AFIO_t *) 0x40010000 )


#endif 