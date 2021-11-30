/*
 * servo_Interface.h
 *
 *  Created on: Nov 22, 2021
 *      Author: compucity
 */

#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

void servo_voidTIMERInit(void);

void servo_voidUltrInit(void);

f64 servo_f64UltraRead(void);

void enableMotor(void);
void Forward(void);
void Backward(void);
void spin(void);
void right(void);
void left(void);
void push_break(void);
void navigate(void);

#endif /* SERVO_INTERFACE_H_ */
