/**********************************************************************/
/*	AUTHOR  : Reda Galal 											  */
/*	Date    : 17 JUL 2023											  */
/*  dis     : RCC_Config											  */
/*  version : V01													  */
/**********************************************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/*
    Options : 
		   RCC_HSI
		   RCC_HSE_CRYSTAL
		   RCC_HSE_RC
		   RCC_PLL
*/

#define RCC_CLOCK_TYPE    RCC_HSI 


/* Note : Select value only if you have PLL as a clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
/*
	Options :
	       RCC_PLL_HSI_DIV_2
		   RCC_PLL_HSE_CRYSTAL_DIV_2
		   RCC_PLL_HSE_RC_DIV_2
		   RCC_PLL_HSE_CRYSTAL
		   RCC_PLL_HSE_RC
*/
#define RCC_PLL_INPUT      RCC_PLL_HSE_RC_DIV_2

/*Options : (2 : 16) */
#define RCC_PLL_MUL_VAL    4

#endif   

#endif

