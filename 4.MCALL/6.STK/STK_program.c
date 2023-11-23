#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "STK_Privit.h"
#include "STK_Config.h"


/* Define Callback Global Variable */
static void(*STK_CallBack)(void);

/* Define Variable for interval mode */
static u8 STK_u8ModeOfInterval;


/**********************************************************************/

void STK_Init(void)
{
#if STK_CLK_SRC == STK_SRC_AHB
    /* Disable STK - Disable STK Interrupt - Set clock source AHB */
	STK -> CTRL = 0x00000004;
#else
    /* Disable STK - Disable STK Interrupt - Set clock source AHB/8 */
	STK -> CTRL = 0;
	
#endif
}


/**********************************************************************/


void STK_SetBusyWait(u32 Ticks )
{
	/* Load ticks to load register */
	STK -> LOAD = Ticks;
	
	/* Start Timer */
	SET_BIT(STK->CTRL, 0);
	
	/* Wait till flag is raised */
	while( (GET_BIT(STK->CTRL,16)) == 0);
	
	/* Stop Timer */
	CLR_BIT(STK->CTRL, 0);
	STK -> LOAD = 0;
	STK -> VAL  = 0;
	
}

/*************************************************************************/
void delay_ms(u32 ticks)
{
	ticks=ticks*1000;
		/* Load ticks to load register */
	STK -> LOAD = ticks;
	
	/* Start Timer */
	SET_BIT(STK->CTRL, 0);
	
	/* Wait till flag is raised */
	while( (GET_BIT(STK->CTRL,16)) == 0);
	
	/* Stop Timer */
	CLR_BIT(STK->CTRL, 0);
	STK -> LOAD = 0;
	STK -> VAL  = 0;
}

/*************************************************************************/

void STK_SetIntervalSingle( u32 Ticks, void (*Copy_ptr)(void) )
{
	/* Disable Timer */
	CLR_BIT(STK->CTRL,0);
	STK -> VAL = 0;

	/* Load ticks to load register */
	STK -> LOAD = Ticks;
		
	/* Save CallBack */
	STK_CallBack = Copy_ptr;
	
	/* Set Mode to Single */
	STK_u8ModeOfInterval = STK_SINGLE_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL, 1);
	
		/* Start Timer */
	SET_BIT(STK->CTRL, 0);
}

/***************************************************************************/

void STK_SetIntervalPeriodic( u32 Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	STK -> LOAD = Ticks;
		
	/* Save CallBack */
	STK_CallBack = Copy_ptr;
	
	/* Set Mode to Single */
	STK_u8ModeOfInterval = STK_PERIOD_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL, 1);
	
		/* Start Timer */
	SET_BIT(STK->CTRL, 0);
}

/*****************************************************************************/

void STK_StopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(STK->CTRL, 1);
	
	/* Stop Timer */
	SET_BIT(STK->CTRL, 0);
	STK -> LOAD = 0;
	STK -> VAL  = 0;
}

/****************************************************************************/
u32  STK_GetElapsedTime(void)
{
	u32 ElapsedTime;
	
	ElapsedTime = STK->LOAD  -  STK ->VAL ;
	
	return ElapsedTime;
}

/****************************************************************************/

u32  STK_GetRemainingTime(void)
{
	u32 RemainTime;
	
	RemainTime = STK -> VAL ;
	
	return RemainTime;
}


/******************************************************************************/

void SysTick_Handler(void)
{
	u8 Temporary ;
	
	if (STK_u8ModeOfInterval == STK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(STK->CTRL, 1);
	
		/* Stop Timer */
		SET_BIT(STK->CTRL, 0);
		STK -> LOAD = 0;
		STK -> VAL  = 0;
	}
	
	/* Callback notification */
	STK_CallBack();
	
	/* Clear interrupt flag by reading it */
	Temporary = GET_BIT(STK->CTRL,16);
}