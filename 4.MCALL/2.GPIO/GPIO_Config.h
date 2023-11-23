/***********************************************************************/
/*	AUTHOR  : Reda Galal 											   */
/*  Data    : 17 JUL 2023											   */
/*  dis	    : GPIO_CONFIG    										   */
/*  version : V01													   */
/***********************************************************************/
#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

#define GPIO_LOW	0
#define GPIO_HIGH	1

#define GPIOA 		0
#define GPIOB		1
#define GPIOC		2

#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7
#define PIN8		8
#define PIN9		9
#define PIN10		10
#define PIN11		11
#define PIN12		12
#define PIN13		13
#define PIN14		14
#define PIN15		15


#define INPUT_analog					0b0000
#define INPUT_floating					0b0100
#define INPUT_push_UP_DOWN 				0b1000


#define OUTPUT_SPEED_10MHZ_PP			0b0001
#define OUTPUT_SPEED_10MHZ_OD			0b0101
#define OUTPUT_SPEED_10MHZ_AF_PP		0b1001
#define OUTPUT_SPEED_10MHZ_AF_OD		0b1101


#define OUTPUT_SPEED_2MHZ_PP			0b0010
#define OUTPUT_SPEED_2MHZ_OD			0b0110
#define OUTPUT_SPEED_2MHZ_AF_PP			0b1010
#define OUTPUT_SPEED_2MHZ_AF_OD			0b1110


#define OUTPUT_SPEED_50MHZ_PP			0b0011
#define OUTPUT_SPEED_50MHZ_OD			0b0111
#define OUTPUT_SPEED_50MHZ_AF_PP		0b1011
#define OUTPUT_SPEED_50MHZ_AF_OD		0b1111




#endif
