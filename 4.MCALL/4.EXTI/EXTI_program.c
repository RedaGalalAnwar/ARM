#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_Privit.h"
#include "EXTI_Config.h"

static void (*EXTI0_CallBack)(void);
static void (*EXTI1_CallBack)(void);
static void (*EXTI2_CallBack)(void);
static void (*EXTI3_CallBack)(void);
static void (*EXTI4_CallBack)(void);
static void (*EXTI9_5_CallBack)(void);
static void (*EXTI15_10_CallBack)(void);





/********************** if i want to do a static interrupt **********/
void EXTI_Init()
{
	#if		EXTI_LINE == EXTI_LINE0
			SET_BIT(EXTI -> IMR , EXTI_LINE0 );
	#elif	EXTI_LINE == EXTI_LINE1
			SET_BIT(EXTI -> IMR , EXTI_LINE1 );
	#elif	EXTI_LINE == EXTI_LINE2
			SET_BIT(EXTI -> IMR , EXTI_LINE2 );
	#elif	EXTI_LINE == EXTI_LINE3
			SET_BIT(EXTI -> IMR , EXTI_LINE3 );
	#elif	EXTI_LINE == EXTI_LINE4
			SET_BIT(EXTI -> IMR , EXTI_LINE4 );
	#elif	EXTI_LINE == EXTI_LINE5
			SET_BIT(EXTI -> IMR , EXTI_LINE5 );
	#elif	EXTI_LINE == EXTI_LINE6
			SET_BIT(EXTI -> IMR , EXTI_LINE6 );
	#elif	EXTI_LINE == EXTI_LINE7
			SET_BIT(EXTI -> IMR , EXTI_LINE7 );
	#elif	EXTI_LINE == EXTI_LINE8
			SET_BIT(EXTI -> IMR , EXTI_LINE8 );
	#elif	EXTI_LINE == EXTI_LINE9
			SET_BIT(EXTI -> IMR , EXTI_LINE9 );
	#elif	EXTI_LINE == EXTI_LINE10
			SET_BIT(EXTI -> IMR , EXTI_LINE10 );
	#elif	EXTI_LINE == EXTI_LINE11
			SET_BIT(EXTI -> IMR , EXTI_LINE11 );
	#elif	EXTI_LINE == EXTI_LINE12
			SET_BIT(EXTI -> IMR , EXTI_LINE12 );
	#elif	EXTI_LINE == EXTI_LINE13
			SET_BIT(EXTI -> IMR , EXTI_LINE13 );
	#elif	EXTI_LINE == EXTI_LINE14
			SET_BIT(EXTI -> IMR , EXTI_LINE14 );
	#elif	EXTI_LINE == EXTI_LINE15
			SET_BIT(EXTI -> IMR , EXTI_LINE15 );			
	#else
		#error ("Wrong Externl Interrupt Line !")
	#endif
	
	
	#if		EXTI_SENSE_MODE == FALLING_EDGE
			SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#elif	EXTI_SENSE_MODE == RISING_EDGE
			SET_BIT(EXTI -> RTSR , EXTI_LINE);
	#elif	EXTI_SENSE_MODE == ON_CHANGE
			SET_BIT(EXTI -> RTSR , EXTI_LINE);
			SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#else
		#error ("Wrong Externl Interrupt Sense Mode !")
	#endif
	;	
}

/*************************************************************************************/

void EXTI_EnableEXTI (u8 EXTILine)
{
	SET_BIT(EXTI ->IMR , EXTILine);
}

/**************************************************************************************/

void EXTI_DisableEXTI (u8 EXTILine)
{
	CLR_BIT(EXTI ->IMR , EXTILine);
}

/**************************************************************************************/

void EXTI_SwTrigger(u8 EXTILine)
{
	SET_BIT(EXTI -> SWIER ,  EXTILine);
}

/**************************************************************************************/


/******************* change mode in run time  *****************************************/ 
void EXTI_SetSignalLatch(u8 EXTILine , u8 SENSE_MODE)  
{
	switch(SENSE_MODE)
	{
		case	RISING_EDGE		:	SET_BIT(EXTI -> RTSR , EXTILine);	break;
		case	FALLING_EDGE	:	SET_BIT(EXTI -> FTSR , EXTILine);	break;
		case	ON_CHANGE		:	SET_BIT(EXTI -> RTSR , EXTILine);	
									SET_BIT(EXTI -> FTSR , EXTILine);	break;
	}
	SET_BIT(EXTI -> IMR , EXTILine);
}


/************************************************************************************/


void EXTI0_SetCallBack(void (*ptr0)(void))
{
	EXTI0_CallBack = ptr0 ;
	
}	



void EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	/*	Clear pending Bit For EXTI0		*/
	SET_BIT(EXTI -> PR , 0);	
}	


/*****************************************************************************/

void EXTI1_SetCallBack(void (*ptr1)(void))
{
	EXTI1_CallBack = ptr1 ;
	
}	



void EXTI1_IRQHandler(void)
{
	EXTI1_CallBack();
	/*	Clear pending Bit For EXTI1		*/
	SET_BIT(EXTI -> PR , 1);	
}	

/*****************************************************************************/

void EXTI2_SetCallBack(void (*ptr2)(void))
{
	EXTI2_CallBack = ptr2 ;
	
}	



void EXTI2_IRQHandler(void)
{
	EXTI2_CallBack();
	/*	Clear pending Bit For EXTI2		*/
	SET_BIT(EXTI -> PR , 2);	
}	

/*****************************************************************************/

void EXTI3_SetCallBack(void (*ptr3)(void))
{
	EXTI3_CallBack = ptr3 ;
	
}	



void EXTI3_IRQHandler(void)
{
	EXTI3_CallBack();
	/*	Clear pending Bit For EXTI3		*/
	SET_BIT(EXTI -> PR , 3);	
}	

/*****************************************************************************/

void EXTI4_SetCallBack(void (*ptr4)(void))
{
	EXTI4_CallBack = ptr4 ;
	
}	



void EXTI4_IRQHandler(void)
{
	EXTI4_CallBack();
	/*	Clear pending Bit For EXTI4		*/
	SET_BIT(EXTI -> PR , 4);	
}	

/*****************************************************************************/

void EXTI9_5_SetCallBack(void (*ptr9_5)(void))
{
	EXTI9_5_CallBack = ptr9_5 ;
	
}	



void EXTI9_5_IRQHandler(void)
{
	EXTI9_5_CallBack();
	/*	Clear pending Bit For EXTI9_5		*/
	SET_BIT(EXTI -> PR , 5);
	SET_BIT(EXTI -> PR , 6);
	SET_BIT(EXTI -> PR , 7);
	SET_BIT(EXTI -> PR , 8);
	SET_BIT(EXTI -> PR , 9);
	
}	

/*****************************************************************************/

void EXTI15_10_SetCallBack(void (*ptr15_10)(void))
{
	EXTI15_10_CallBack = ptr15_10 ;
	
}	

void EXTI15_10_IRQHandler(void)
{
	EXTI15_10_CallBack();
	/*	Clear pending Bit For EXTI15_10		*/
	SET_BIT(EXTI -> PR , 10);
	SET_BIT(EXTI -> PR , 11);
	SET_BIT(EXTI -> PR , 12);
	SET_BIT(EXTI -> PR , 13);
	SET_BIT(EXTI -> PR , 14);
	SET_BIT(EXTI -> PR , 15);
}	