/**************************************************************/
/*	Author : Reda Galal Anwer  					***************/
/*	Data    : 18/9/2023							***************/
/*	Dis     : EXTI_CONFIG			     	    ***************/
/* 	Version : V01								***************/
/**************************************************************/



#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_


/*
EXTI_LINE0
EXTI_LINE1
EXTI_LINE2
EXTI_LINE3
.
.
.
.
EXTI_LINE15
*/

#define  EXTI_LINE    EXTI_LINE0   /* 0:15 */

/*
FALLING_EDGE
RISING_EDGE
ON_CHANGE
*/
#define	 EXTI_SENSE_MODE    FALLING_EDGE



#endif 