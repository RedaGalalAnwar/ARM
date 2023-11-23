//include LIB
#include "STD_TYPES.h"
#include "BIT_MATH.h"

//include lower layer files
// .... we are in MCAL 

//include driver files
#include "RCC_interface.h"
#include "RCC_privit.h"
#include "RCC_Config.h"



void RCC_voidInitSysClock(void)
{
	//check for clock type selection
	/*if user select the HSI*/
#if RCC_CLOCK_TYPE == RCC_HSI
	// enable ESI 
	RCC_CR   = RCC_HSI_ON_MASK;
	// select HSI
	RCC_CFGR = RCC_HSI_SEL_MASK; 
	/*if user select the RCC_HSE_CRYSTAL */
#elif RCC_CLOCK_TYPE ==	RCC_HSE_CRYSTAL
	// enable ESE 
	RCC_CR = RCC_HSE_CRYSTAL_ON_MASK;
	// select HSE
	RCC_CFGR = RCC_HSE_SEL_MASK;
	/*if user select the RCC_HSE_RC */
#elif RCC_CLOCK_TYPE ==	RCC_HSE_RC
	// enable ESE 
	RCC_CR = RCC_HSE_RC_ON_MASK;
	// select HSE
	RCC_CFGR = RCC_HSE_SEL_MASK;	
	/*if user select the PLL*/
#elif RCC_CLOCK_TYPE ==	RCC_PLL

	/* Set multiplication value */
#if RCC_PLL_MUL_VAL <= RCC_MAX_PLL_MUL
	RCC_CFGR &=~((0b1111)<<18);
	RCC_CFGR |= ((RCC_PLL_MUL_VAL-2)<<18);
#else
#error("Wrong PLL multiplication")
#endif

	/*PLL ON*/
#if   RCC_PLL_INPUT == RCC_PLL_HSI_DIV_2
	RCC_CR = RCC_HSI_ON_MASK;
	CLR_BIT(RCC_CFGR,PLLSRC); // HSI/2
	RCC_CR = RCC_PLL_INPUT_HSI_MASK;//PLL on

#elif RCC_PLL_INPUT == RCC_PLL_HSE_CRYSTAL_DIV_2
	RCC_CR = RCC_HSE_CRYSTAL_ON_MASK ;
	SET_BIT(RCC_CFGR,PLLXTPRE); //divide HSE
	RCC_CR = RCC_PLL_INPUT_HSE_CRYSTAL_MASK; //PLL on or SET_BIT(RCC_CR,PLLON);

#elif RCC_PLL_INPUT == RCC_PLL_HSE_RC_DIV_2
	RCC_CR = RCC_HSE_RC_ON_MASK;
	SET_BIT(RCC_CFGR,PLLXTPRE); //divide HSE
	RCC_CR = RCC_PLL_INPUT_HSE_RC_MASK //PLL on

#elif RCC_PLL_INPUT == RCC_PLL_HSE_CRYSTAL
	RCC_CR = RCC_HSE_CRYSTAL_ON_MASK ;
	CLR_BIT(RCC_CFGR,PLLXTPRE); //HSE not be divided
	RCC_CR = RCC_PLL_INPUT_HSE_CRYSTAL_MASK //PLL on

#elif RCC_PLL_INPUT == RCC_PLL_HSE_RC
	RCC_CR = RCC_HSE_RC_ON_MASK;
	CLR_BIT(RCC_CFGR,PLLXTPRE); //HSE not be divided
	RCC_CR = RCC_PLL_INPUT_HSE_RC_MASK //PLL on

#else
#error("Wrong PLL input")
#endif

			RCC_CFGR |= (0b10); //Select PLL

#else
#error("Wrong clock type")
#endif	
}



void RCC_voidEnableClock(u8 Copy_u8BusID , u8 Copy_u8PerID)
{
	if(Copy_u8PerID <= 31)
	{
		switch(Copy_u8BusID)
		{
		case RCC_AHB  : SET_BIT(RCC_AHBENR ,Copy_u8PerID);  break;
		case RCC_APB1 : SET_BIT(RCC_APB1ENR,Copy_u8PerID);  break;
		case RCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_u8PerID);  break;
		}
	}
	else
	{
		//return error
	}
}

void RCC_voidDisableClock(u8 Copy_u8BusID , u8 Copy_u8PerID)
{
	if(Copy_u8PerID <= 31)
	{
		switch(Copy_u8BusID)
		{
		case RCC_AHB  : CLR_BIT(RCC_AHBENR ,Copy_u8PerID);  break;
		case RCC_APB1 : CLR_BIT(RCC_APB1ENR,Copy_u8PerID);  break;
		case RCC_APB2 : CLR_BIT(RCC_APB2ENR,Copy_u8PerID);  break;
		}
	}
	else
	{
		//return error
	}
}

