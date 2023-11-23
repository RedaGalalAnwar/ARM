/**************************************************************/
/*	Author  : Reda Galal Anwer 					***************/
/*	Data    : 22/9/2023							***************/
/*	Dis     : STK_interface				        ***************/
/* 	Version : V01								***************/
/**************************************************************/


#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_



/* Apply Clock Choise From Configuration File 
   Disable SysTick interrupt
   Disable SysTick 					*/
 
void STK_Init(void);
void STK_SetBusyWait(u32 Ticks );
void delay_ms(u32 ticks); // we can use it if source clk is  AHP/8
void STK_SetIntervalSingle( u32 Ticks, void (*Copy_ptr)(void) );
void STK_SetIntervalPeriodic( u32 Ticks, void (*Copy_ptr)(void) );
void STK_StopInterval(void);
u32  STK_GetElapsedTime(void);
u32  STK_GetRemainingTime(void);


#endif 