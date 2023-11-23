/**************************************************************/
/*	Author : Reda Galal Anwer  					***************/
/*	Data    : 22/9/2023							***************/
/*	Dis     : STK_privit			     	    ***************/
/* 	Version : V01								***************/
/**************************************************************/


#ifndef STK_PRIVIT_H_
#define STK_PRIVIT_H_


typedef struct
{
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
}STK_Type;


#define     STK    ((STK_Type*)0xE000E010)


#define     STK_SRC_AHB           0
#define     STK_SRC_AHB_8         1

#define     STK_SINGLE_INTERVAL    0
#define     STK_PERIOD_INTERVAL    1




#endif 