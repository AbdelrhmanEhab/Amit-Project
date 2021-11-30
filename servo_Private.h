/*
 * servo_Private.h
 *
 *  Created on: Nov 23, 2021
 *      Author: compucity
 */

#ifndef SERVO_PRIVATE_H_
#define SERVO_PRIVATE_H_

/*Timer 1 registers*/
#define TCCR1A		(*(volatile u8 * )(0X4F))
#define TCCR1B		(*(volatile u8 * )(0X4E))
#define TCNT1		(*(volatile u16 * )(0x4D))
#define ICR1		(*(volatile u16 * )(0X46))
#define OCR1A		(*(volatile u16 * )(0X4A))
#define OCR1B		(*(volatile u16 * )(0X48))
#define TIMSK	 	(*(volatile u8 * )(0x59))
#define TIFR	 	(*(volatile u8 * )(0x58))


/*servo timer1*/
#define WGM11	1
#define COM1B1	5
#define COM1A1	7



#define WGM13	4
#define WGM12	3
#define CS10	0
#define CS11	1

#define ICF1	5
#define TOV1	2


void motorA_forward(void);
void motorA_backward(void);
void motorA_stop(void);
void motorB_forward(void);
void motorB_backward(void);
void motorB_stop(void);

void motorA_on(void);
void motorA_off(void);
void motorB_on(void);
void motorB_off(void);

#endif /* SERVO_PRIVATE_H_ */
