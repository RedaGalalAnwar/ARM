/**************************************************************/
/*	Author  : Reda Galal Anwer 					***************/
/*	Data    : 26/9/2023							***************/
/*	Dis     : SPI_interface				        ***************/
/* 	Version : V01								***************/
/**************************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


void SPI_Init(void); 


/*

u8 receive;

SPI_SendReceiveSynch(0x50,receive);


this code will send 50 and receive data at the same time 

because spi send and receive in the same time 

*/
void SPI_SendReceiveSynch(u8 DataTransmit, u8 *DataReceived);

void SPI_SendReceiveAsynch(u8 Copy_u8DataToTransmit, void (*CallBack)(u8));


#endif

