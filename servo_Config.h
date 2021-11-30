/*
 * servo_Config.h
 *
 *  Created on: Nov 22, 2021
 *      Author: compucity
 */

#ifndef SERVO_CONFIG_H_
#define SERVO_CONFIG_H_


ICR1=4999;	//fPWM=50Hz (Period = 20ms Standard).

//OCR1A=97;	//0 position
OCR1A =255;
OCR1B =255;

#define PIN_TRIGGER 			1	//connected to port b
#define PIN_ECHO 				2	//connected to port b

#define RightMotorForward		6
#define RightMotorBackward		7

#define LeftMotorForward		4
#define LeftMotorBackward		5

#endif /* SERVO_CONFIG_H_ */
