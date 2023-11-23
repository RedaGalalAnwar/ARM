#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_Privit.h"
#include "SPI_Config.h"

void (*CallBack)(u8);


void SPI_Init(void)
{
/* CPOL=0 */ 	 /* CPHA=1   */    /* Prescalar=CLK/2=4MHZ */   	/* SPI Enable  */	  /* MSB first */
	MSPI1->CR1 = 0x0347;
}


void SPI_SendReceiveSynch(u8 DataTransmit, u8 *DataReceived)
{
	/* Clear For Slave Select Pin */
	GPIO_SetPinValue(SPI_SLAVE_PIN,GPIO_LOW);
	
	/* Send Data */
	MSPI1 -> DR = DataTransmit;
	
	/* Wait Busy Flag to finish */
	while (GET_BIT(MSPI1 -> SR, 7) == 1);

 	/* Return to the rec eived data */
	*DataReceived = MSPI1 -> DR;
	
	/* Set Salve Select Pin */
	GPIO_SetPinValue(SPI_SLAVE_PIN,GPIO_HIGH);
}