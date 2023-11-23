#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AFIO_interface.h"
#include "AFIO_Privit.h"


void AFIO_SetEXTILineNum(u8 ExtiLine , u8 ExtiPinNum)
{
	
	u8 RegIndex = 0;  
	RegIndex = 	ExtiLine / 4 ;
	ExtiLine =ExtiLine%4;
	AFIO->EXTICR[RegIndex] &= ~ ((0b1111) << (4*ExtiLine));
	AFIO->EXTICR[RegIndex] |=  ((ExtiPinNum) << (4*ExtiLine));
}

/*

void AFIO_SetEXTILineNum(u8 ExtiLine ,u8 ExtiPinNum)
{
	u8 RegIndex=0;
	
	if(ExtiLine <=3)
	{
		RegIndex=0;		
	}
	
	else if(ExtiLine<=7)
	{
		RegIndex=1;
		ExtiLine-=4;
	}
	else if (ExtiLine<=11)
	{
		RegIndex=2;
		ExtiLine-=8;
	}
	else if(ExtiLine<=15)
	{
		RegIndex=3;
		ExtiLine-=12;		
	}
	AFIO->EXTICR[RegIndex] &~= ~ ((0b1111) << (4 * ExtiLine));
	AFIO->EXTICR[RegIndex] |=  ((ExtiPinNum) << (4 * ExtiLine));	
	
	
}





ExtiLine
0,1,2,3  	 --> EXTICR[0]
4,5,6,7  	 --> EXTICR[1]
8,9,10,11 	 --> EXTICR[2]
12,13,14,15  --> EXTICR[3]


	APIN	0b0000	=0
	BPIN	0b0001	=1
	CPIN	0b0010	=2



ex: external interupt on pin B6
	ExtiLine=6
	Bpin=0b0001
	RegIndex=1
	new ExtiLine=6-4=2
	
	EXTICR[1]= BPIN(0b0001)<<(4*2)
	
	
*/