/*
 * servo_Program.c
 *
 *  Created on: Nov 22, 2021
 *      Author: compucity
 */
		/*ADD necessary libraries*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Interface.h"
#include"GIE_Interface.h"
#include"servo_Config.h"
#include"servo_Private.h"
#include<util/delay.h>

u32 TimerOverflow=0;
void servo_voidTIMERInit(void)	/*active the timer to generate PWM*/
{
	//NON Inverted PWM
	SET_BIT(TCCR1A,COM1A1);
	SET_BIT(TCCR1A,COM1B1);
	SET_BIT(TCCR1A,WGM11);

	//PRESCALER=64 MODE 14(FAST PWM)
	/*SET_BIT(TCCR1B,WGM13);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,CS11);
	//SET_BIT(TCCR1B,CS10);*/
	_delay_ms(3000);
							//active pin OC1A&OC1B as output
	DIO_u8SetPinDirection(PIN3,DIO_PORTD,PIN_OUTPUT);
	//DIO_u8SetPinDirection(PIN2,DIO_PORTB,PIN_OUTPUT);
}

void servo_voidUltrInit(void)	/*function to turn ultrasonic on(timer)*/
{
	SET_BIT(TIMSK,5);	//Interrupt pin enable
	GIE_voidEnable();	//global interrupt enable
	TCCR1A=0x00;
	DIO_u8SetPinDirection(PIN_TRIGGER,DIO_PORTB,PIN_OUTPUT);
	DIO_u8SetPinDirection(PIN_ECHO,DIO_PORTB,PIN_INPUT);

}

f64 servo_f64UltraRead(void)	/*function to read the distance from echo pin*/
{
	OCR1A = ICR1 - 2600; //~90 deg center
	f32 count;
	f64 distance;
	//trigger the ultrasonic
	DIO_u8SetPinValue(PIN_TRIGGER,DIO_PORTB,LOW);
	_delay_ms(2);
	DIO_u8SetPinValue(PIN_TRIGGER,DIO_PORTB,HIGH);
	_delay_ms(10);
	DIO_u8SetPinValue(PIN_TRIGGER,DIO_PORTB,LOW);
	_delay_ms(2);

	TCNT1 = 0;			// Clear Timer counter
	TCCR1B = 0x41;		//capture on rising edge
	CLR_BIT(TIFR,ICF1);	//Clear ICP flag (Input Capture flag)
	CLR_BIT(TIFR,TOV1);	//Clear Timer Overflow flag

	while(GET_BIT(TIFR,ICF1)==0);	//wait for interrupt to occure(overflow)
	TCNT1 = 0;	/* Clear Timer counter */
	TCCR1B = 0x01;	/* Capture on falling edge */
	CLR_BIT(TIFR,ICF1);	/* Clear ICP flag (Input Capture flag) */
	CLR_BIT(TIFR,TOV1);	/* Clear Timer Overflow flag */
	TimerOverflow = 0;/* Clear Timer overflow count */

	/* Wait for falling edge */
	while(GET_BIT(TIFR,ICF1)==0);
	count = ICR1 + (65535 * TimerOverflow);	/* Take count */
	/* 8MHz Timer freq, sound speed =343 m/s */
	distance = (double)count / 466.47;
	return distance;
}



ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;	/* Increment Timer Overflow count */
	OCR1A = 255;
	OCR1B = 255;
}



void motorA_forward()
{

	DIO_u8SetPinValue(PIN6,DIO_PORTD,HIGH);
	DIO_u8SetPinValue(PIN7,DIO_PORTD,LOW);
}

void motorA_backward()
{
	DIO_u8SetPinValue(PIN6,DIO_PORTD,LOW);
	DIO_u8SetPinValue(PIN7,DIO_PORTD,HIGH);
}

void motorA_stop()
{
	DIO_u8SetPinValue(PIN6,DIO_PORTD,LOW);
	DIO_u8SetPinValue(PIN7,DIO_PORTD,LOW);
}

void motorB_forward()
{
	DIO_u8SetPinValue(PIN3,DIO_PORTD,LOW);
	DIO_u8SetPinValue(PIN4,DIO_PORTD,HIGH);
}

void motorB_backward()
{
	DIO_u8SetPinValue(PIN4,DIO_PORTD,LOW);
	DIO_u8SetPinValue(PIN3,DIO_PORTD,HIGH);

}

void motorB_stop()
{
	DIO_u8SetPinValue(PIN4,DIO_PORTD,LOW);
	DIO_u8SetPinValue(PIN3,DIO_PORTD,LOW);
}

void motorA_on()
{
	OCR1A =255;
}

void motorA_off()
{
	OCR1A = 0;
}

void motorB_on()
{
	OCR1B =255;
}

void motorB_off()
{
	OCR1B = 0;
}

//Movment Functions
void forward()
{
	motorA_forward();
	motorB_forward();

}

void backward()
{
	motorA_backward();
	motorB_backward();
	_delay_ms(500);
}
void spin()
{
	motorA_forward();
	motorB_backward();
	_delay_ms(500);
}

void right()
{
	motorA_stop();
	motorB_forward();
	_delay_ms(500);
}

void left()
{
	motorA_forward();
	motorB_stop();
	_delay_ms(500);
}


void enableMotor()
{
	motorA_on();
	motorB_on();
}
void push_break()
{
	motorA_stop();
	motorB_stop();

}
void navigate()
{
	f64 LeftDistance,distance,RightDistance;
	OCR1A = ICR1 - 3800; // move servo to left ~155 DEG
	_delay_ms(2000);
	distance=servo_f64UltraRead();
	LeftDistance = distance;

	OCR1A = ICR1 - 1700; // ~15-20 degrees
	_delay_ms(2000);
	distance=servo_f64UltraRead();
	RightDistance = distance;

	if( (RightDistance - LeftDistance) < 7)
	{
		backward(700);
		right(700);
		spin(500);
	}
	else if(RightDistance < LeftDistance)
	{
		left(500);
	}
	else if(LeftDistance < RightDistance)
		right(500);
}

