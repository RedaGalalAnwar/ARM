#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_privit.h"
#include "GPIO_Config.h"


void GPIO_SetPinDirection(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Mode)
{
	switch(Copy_u8PORT)
	{
	 case GPIOA :
				if(Copy_u8PIN<=7)
				{
					GPIOA_CRL &=~((0b1111)<<(Copy_u8PIN * 4));
					GPIOA_CRL |=((Copy_u8Mode)<<(Copy_u8PIN * 4));
				}
				else if(Copy_u8PIN<=15)
				{
					Copy_u8PIN = Copy_u8PIN - 8 ;
					GPIOA_CRH &=~((0b1111)<<(Copy_u8PIN * 4));
					GPIOA_CRH |=((Copy_u8Mode)<<(Copy_u8PIN * 4));
				}
				break;
	
	 case GPIOB :
				if(Copy_u8PIN<=7)
				{
					GPIOB_CRL &=~((0b1111)<<(Copy_u8PIN * 4));
					GPIOB_CRL |=((Copy_u8Mode)<<(Copy_u8PIN * 4));
				}
				else if(Copy_u8PIN<=15)
				{
					Copy_u8PIN = Copy_u8PIN - 8 ;
					GPIOB_CRH &=~((0b1111)<<(Copy_u8PIN * 4));
					GPIOB_CRH |=((Copy_u8Mode)<<(Copy_u8PIN * 4));
				}	
				break;
	
	
	 case GPIOC :
				if(Copy_u8PIN<=7)
				{
					GPIOC_CRL &=~((0b1111)<<(Copy_u8PIN * 4));
					GPIOC_CRL |=((Copy_u8Mode)<<(Copy_u8PIN * 4));
				}
				else if(Copy_u8PIN<=15)
				{
					Copy_u8PIN = Copy_u8PIN - 8 ;
					GPIOC_CRH &=~((0b1111)<<(Copy_u8PIN * 4));
					GPIOC_CRH |=((Copy_u8Mode)<<(Copy_u8PIN * 4));
				}	
				break;
				
	 default :  break;
	}
}

void GPIO_SetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Value)
{
	switch(Copy_u8PORT)
	{
		case GPIOA :
					if(Copy_u8Value==GPIO_HIGH)
					{
						SET_BIT(GPIOA_ODR ,Copy_u8PIN);
					}
					else if(Copy_u8Value==GPIO_LOW)
					{
						CLR_BIT(GPIOA_ODR ,Copy_u8PIN);
					}
					break;
		
		case GPIOB :
					if(Copy_u8Value==GPIO_HIGH)
					{
						SET_BIT(GPIOB_ODR ,Copy_u8PIN);
					}
					else if(Copy_u8Value==GPIO_LOW)
					{
						CLR_BIT(GPIOB_ODR ,Copy_u8PIN);
					}
					break;		
		
		case GPIOC :
					if(Copy_u8Value==GPIO_HIGH)
					{
						SET_BIT(GPIOC_ODR ,Copy_u8PIN);
					}
					else if(Copy_u8Value==GPIO_LOW)
					{
						CLR_BIT(GPIOC_ODR ,Copy_u8PIN);
					}
					break;	
			
		default :	break;
		
		
	}
	
	
	
}



u8 GPIO_GetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN )
{
	u8 result ;
	
	switch(Copy_u8PORT)
	{
		case GPIOA :
		
			result = GET_BIT( GPIOA_IDR , Copy_u8PIN );
		
				  break;
		case GPIOB :
		
			result = GET_BIT( GPIOB_IDR , Copy_u8PIN );
				
				  break;
		case GPIOC :
		
			result = GET_BIT( GPIOC_IDR , Copy_u8PIN );
				
				  break;
					
		default : break;
	}
	
	return result;
}
