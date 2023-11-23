#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "NVIC_Privit.h"
#include "NVIC_Config.h"


void NVIC_EnableInterrupt(u8 num)
{
	
	if(num<=31)
	{
		NVIC_ISER0=(1<<num);
	}
	else if(num<=59)
	{
		num-=32;
		NVIC_ISER1=(1<<num);
	}
	else
	{
		/* return error */
	}
}

void NVIC_DisableInterrupt(u8 num)
{
		
	if(num<=31)
	{
		NVIC_ICER0=(1<<num);
	}
	else if(num<=59)
	{
		num-=32;
		NVIC_ICER1=(1<<num);
	}
	else
	{
		/* return error */
	}
		
}

void NVIC_SetPendingFlag(u8 num)
{
	
		if(num<=31)
	{
		NVIC_ISPR0=(1<<num);
	}
	else if(num<=59)
	{
		num-=32;
		NVIC_ISPR1=(1<<num);
	}
	else
	{
		/* return error */
	}
		
}

void NVIC_ClearPendingFlag(u8 num)
{
	
		if(num<=31)
	{
		NVIC_ICPR0=(1<<num);
	}
	else if(num<=59)
	{
		num-=32;
		NVIC_ICPR1=(1<<num);
	}
	else
	{
		/* return error */
	}
		
}

u8 NVIC_GetActiveFlag(u8 num)
{
	u8 result;
	if(num<=31)
	{
		result=GET_BIT(NVIC_IABR0,num);
	}
	else if(num<=59)
	{
		num-=32;
		result=GET_BIT(NVIC_IABR1,num);
	}
	else
	{
		/* return error */
	}
	
return result ;	
}

/***************************************************************/

void NVIC_GroupSubInit(void)
{
	SCB_AIRCR = NVIC_GROUP_SUB_DISTRIBUTION ;
	
}

void NVIC_voidSetPeriority(s8 PeripheralID , u8 GroupPriority,u8 SubPriority)
{							/*0x05FA0400 3 Group & 1 sub priority*/
	u8 Priority = SubPriority|(GroupPriority<<((NVIC_GROUP_SUB_DISTRIBUTION - 0x05FA0300)/256));
	/* Copy_s8PeripheralID < 0 ----> core peripheral 			*/

	/* external peripheral		*/ /*EXTI0 = 6*/
	if(PeripheralID >= 0 , PeripheralID <60)
	{
		NVIC_IPR[PeripheralID] = Priority << 4 ;
	}

	else
	{
		/* Report Error */
	}	

}