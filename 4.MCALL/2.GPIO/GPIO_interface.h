/***********************************************************************/
/*	AUTHOR  : Reda Galal 											   */
/*  Data    : 17 JUL 2023											   */
/*  dis	    : GPIO_interface										   */
/*  version : V01													   */
/***********************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H



void GPIO_SetPinDirection(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Mode);
void GPIO_SetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Value);
u8 GPIO_GetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN );



#endif
