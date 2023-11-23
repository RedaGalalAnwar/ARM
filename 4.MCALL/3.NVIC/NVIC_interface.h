/**************************************************************/
/*	Author  : Reda Galal Anwer 					***************/
/*	Data    : 16/9/2023							***************/
/*	Dis     : NVIC_interface				    ***************/
/* 	Version : V01								***************/
/**************************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


void NVIC_EnableInterrupt(u8 num);
void NVIC_DisableInterrupt(u8 num);
void NVIC_SetPendingFlag(u8 num);
void NVIC_ClearPendingFlag(u8 num);
u8 NVIC_GetActiveFlag(u8 num);


/*****************************************************/
void NVIC_GroupSubInit(void);
void NVIC_voidSetPeriority(s8 PeripheralID , u8 GroupPriority,u8 SubPriority);


#endif