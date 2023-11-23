/**********************************************************************/
/*	AUTHOR  : Reda Galal 											  */
/*	Date    : 17 JUL 2023											  */
/*  dis     : RCC_privit											  */
/*  version : V01													  */
/**********************************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/*Register Definitions*/

// Processor Clock control
#define RCC_CR                *((volatile u32*)0x40021000)
#define RCC_CFGR              *((volatile u32*)0x40021004)

#define PLLXTPRE 17
#define PLLSRC   16
//

#define RCC_CIR               *((volatile u32*)0x40021008)
#define RCC_APB2RSTR          *((volatile u32*)0x4002100C)
#define RCC_APB1RSTR          *((volatile u32*)0x40021010)

// Peripheral clock control
#define RCC_AHBENR            *((volatile u32*)0x40021014)
#define RCC_APB2ENR           *((volatile u32*)0x40021018)
#define RCC_APB1ENR           *((volatile u32*)0x4002101C)
//

#define RCC_BDCR              *((volatile u32*)0x40021020)
#define RCC_CSR               *((volatile u32*)0x40021024)



/*Clock types*/
#define		RCC_HSI               0
#define		RCC_HSE_CRYSTAL       10
#define		RCC_HSE_RC            20
#define		RCC_PLL               30


/*PLL input options*/
#define	    RCC_PLL_HSI_DIV_2     40
#define	    RCC_PLL_HSE_DIV_2     50
#define		RCC_PLL_HSE           60


/*HSI ON mask (RCC_CR)*/
#define     RCC_HSI_ON_MASK    	            0x00000081
/*HSI Crystal ON mask (RCC_CR)*/
#define     RCC_HSE_CRYSTAL_ON_MASK       	0x00010000
/*HSE RC ON mask (RCC_CR)*/
#define     RCC_HSE_RC_ON_MASK              0x00050000
/*PLL input HSI mask (RCC_CR)*/
#define RCC_PLL_INPUT_HSI_MASK             	0x01000081
/*PLL input HSE crystal mask (RCC_CR)*/
#define RCC_PLL_INPUT_HSE_CRYSTAL_MASK     	0x01010000
/*PLL input HSE RC mask (RCC_CR)*/
#define RCC_PLL_INPUT_HSE_RC_MASK           0x01050000

#define RCC_MAX_PLL_MUL 16

#define RCC_HSE_SEL_MASK                  0x00000001
#define RCC_HSI_SEL_MASK                  0x00000000


#endif

