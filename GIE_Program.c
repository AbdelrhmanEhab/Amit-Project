/*
 * GIE_Program.c
 *
 *  Created on: Oct 1, 2021
 *      Author: gerges
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"GIE_Private.h"
void GIE_voidEnable(void)
{
	SET_BIT(SREG,7);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,7);
}
