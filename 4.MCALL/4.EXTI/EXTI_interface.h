/**************************************************************/
/*	Author  : Reda Galal Anwer 					***************/
/*	Data    : 18/9/2023							***************/
/*	Dis     : EXTI_interface				    ***************/
/* 	Version : V01								***************/
/**************************************************************/


#ifndef EXTI_INTERFACE_H_
#define EXTI_interface


/* Line and Mode */
void EXTI_Init();	//if i want to do a static interrupt
void EXTI_SetSignalLatch (u8 EXTILine,u8 SenseMode); 	//change mode in run time
void EXTI_EnableEXTI (u8 EXTILine);
void EXTI_DisableEXTI (u8 EXTILine);
void EXTI_SwTrigger(u8 EXTILine);


void EXTI0_SetCallBack(void (*ptr0)(void));
void EXTI1_SetCallBack(void (*ptr1)(void));
void EXTI2_SetCallBack(void (*ptr2)(void));
void EXTI3_SetCallBack(void (*ptr3)(void));
void EXTI4_SetCallBack(void (*ptr4)(void));
void EXTI9_5_SetCallBack(void (*ptr9_5)(void));
void EXTI15_10_SetCallBack(void (*ptr15_10)(void));

#endif