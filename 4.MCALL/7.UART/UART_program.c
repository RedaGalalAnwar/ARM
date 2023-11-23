#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_interface.h"
#include "UART_Privit.h"
#include "UART_Config.h"



void USART_Init(void)
{
	
	#if 	Baud_Rate ==	Baud_Rate_9600		
	USART1 -> BRR = 0x341;	
	#elif 	Baud_Rate ==	Baud_Rate_115200
	USART1 -> BRR = 0x45;
	#else
		#error ("Wrong Baud Rate !")	
	#endif
	
	/*Enable Rx */
	SET_BIT((USART1-> CR[0]), 3);			/* Enabling Transmitter */
	/*Enable Tx */
	SET_BIT((USART1-> CR[0]), 2);			/* Enabling Receiver */
	/*Enable USART1 */
	SET_BIT((USART1-> CR[0]), 13);			/* Enabling USART */

	/* Clear Status Register */
	USART1 -> SR = 0;				
}

/********************************************************************************/

/*void USART1_Transmit(u8 arr[])
{
	u8 i = 0;
	while(arr[i] != '\0'){
		USART1 -> DR = arr[i];
		while((GET_BIT((USART1 -> SR), 6)) == 0);
	// or 	while((USART1 -> SR & 0x40) == 0);  
		i++;
	}
	
}
*/

void USART_Transmit(char* word)
{
	u8 i = 0;
	while(word[i] != '\0'){
		USART1 -> DR = word[i];
		while((GET_BIT((USART1 -> SR), 6)) == 0);
		i++;
	}
	
}

/**************************************************************************/

u8 USART_Receive(void)
{
	u16 timeout = 0; 
	u8 Loc_u8ReceivedData = 0;
	while((GET_BIT((USART1 -> SR), 5)) == 0)
	{
		timeout++;
		
		if (timeout == 10000)	
		{
			/*impossible that fun retutn 255 as ascii table from 0 : 127 */ 
			Loc_u8ReceivedData = 255;
			break;
		}	
	}
	if (Loc_u8ReceivedData == 0) /* check out condition for varity */
	{	
	/* or 	while((USART1 -> SR & (1<<5)) == 0);  */
	Loc_u8ReceivedData = USART1 -> DR;
	}
	return (Loc_u8ReceivedData);
}