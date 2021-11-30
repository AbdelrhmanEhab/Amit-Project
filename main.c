/*
 * main.c
 *
 *  Created on: Nov 23, 2021
 *      Author: compucity
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Interface.h"
#include"servo_Interface.h"
#include<util/delay.h>

int main(void)
{
	u64 FrontDistance;

	u32 distance;

	servo_voidTIMERInit();
	servo_voidUltrInit();

	while(1)
	{

		distance=servo_f64UltraRead();
		FrontDistance = distance;
		if(distance >=20) // for going forward
			{
			    forward();


			}
			else
			{


				push_break();
				navigate();
			}
	}
}


