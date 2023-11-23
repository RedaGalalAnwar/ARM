/**************************************************************/
/*	Author : Reda Galal Anwer  					***************/
/*	Data    : 16/9/2023							***************/
/*	Dis     : NVIC_privit			     	    ***************/
/* 	Version : V01								***************/
/**************************************************************/


#ifndef NVIC_PRIVIT_H_
#define NVIC_PRIVIT_H_


#define NVIC_ISER0    *((u32*)0xE000E100)
#define NVIC_ISER1    *((u32*)0xE000E104)

#define NVIC_ICER0    *((u32*)0xE000E180)
#define NVIC_ICER1    *((u32*)0xE000E184)

#define NVIC_ISPR0    *((u32*)0xE000E200)
#define NVIC_ISPR1    *((u32*)0xE000E204)

#define NVIC_ICPR0    *((u32*)0xE000E280)
#define NVIC_ICPR1    *((u32*)0xE000E284)


#define  NVIC_IABR0   *((volatile u32*)0xE000E300)
#define  NVIC_IABR1   *((volatile u32*)0xE000E304)

#define NVIC_IPR     ((volatile u8*)0xE000E400)



/*********************************************************************/

#define NVIC_GROUP_4_SUB_0      0x05FA0300	// 4 Bits For Group  (IPR)=> Group
#define NVIC_GROUP_3_SUB_1      0x05FA0400	// 3 Bits For Group 1 Bit For Sub
#define NVIC_GROUP_2_SUB_2      0x05FA0500	// 2 Bits For Group 2 Bit For Sub
#define NVIC_GROUP_1_SUB_3      0x05FA0600	// 1 Bits For Group 3 Bit For Sub
#define NVIC_GROUP_0_SUB_4      0x05FA0700	// 0 Group 4 Bit For Sub

/* SCB_base_Adress  0xE000ED00  */

#define SCB_AIRCR   *((volatile u32*)0xE000ED00 + 0x0C )

#endif