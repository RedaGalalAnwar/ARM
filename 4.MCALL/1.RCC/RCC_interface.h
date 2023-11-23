/**********************************************************************/
/*	AUTHOR  : Reda Galal 											  */
/*	Date    : 17 JUL 2023											  */
/*  dis     : RCC_interface											  */
/*  version : V01													  */
/**********************************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define RCC_AHB    0
#define RCC_APB1   1
#define RCC_APB2   2


#define GPIOA_CLOCK_EN  2
#define GPIOB_CLOCK_EN  3
#define GPIOC_CLOCK_EN  4

void RCC_voidInitSysClock(void);
void RCC_voidEnableClock (u8 Copy_u8BusID , u8 Copy_u8PerID);
void RCC_voidDisableClock(u8 Copy_u8BusID , u8 Copy_u8PerID);





#endif

