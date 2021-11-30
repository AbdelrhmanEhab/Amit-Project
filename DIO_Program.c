/*
 * DIO_Program.c
 *
 *  Created on: Sep 11, 2021
 *      Author: gerges
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Private.h"
#include"DIO_Interface.h"
u8 DIO_u8SetPinDirection(u8 Copy_u8PinNumber,u8 Copy_u8PortNumber,u8 Copy_u8Direction)
{
	u8 Error_State=OK;
	if(Copy_u8PinNumber<8)
	{
		switch(Copy_u8PortNumber)
		{
		case DIO_PORTA:
			if(Copy_u8Direction==PIN_OUTPUT)
			{
			}
			else if(Copy_u8Direction==PIN_INPUT)
			{
				CLR_BIT(DDRA,Copy_u8PinNumber);
			}
			else
			{
				Error_State=NOK;
			}
			break;
		case DIO_PORTB:
			if(Copy_u8Direction==PIN_OUTPUT)
			{
				SET_BIT(DDRB,Copy_u8PinNumber);
			}
			else if(Copy_u8Direction==PIN_INPUT)
			{
				CLR_BIT(DDRB,Copy_u8PinNumber);
			}
			else
			{
				Error_State=NOK;
			}
			break;
		case DIO_PORTC:
			if(Copy_u8Direction==PIN_OUTPUT)
			{
				SET_BIT(DDRC,Copy_u8PinNumber);
			}
			else if(Copy_u8Direction==PIN_INPUT)
			{
				CLR_BIT(DDRC,Copy_u8PinNumber);
			}
			else
			{
				Error_State=NOK;
			}
			break;
		case DIO_PORTD:
			if(Copy_u8Direction==PIN_OUTPUT)
			{
				SET_BIT(DDRD,Copy_u8PinNumber);
			}
			else if(Copy_u8Direction==PIN_INPUT)
			{
				CLR_BIT(DDRD,Copy_u8PinNumber);
			}
			else
			{
				Error_State=NOK;
			}
			break;
		default:
			Error_State=NOK;
			break;
		}
	}
	else
	{
		Error_State=NOK;
	}
	return Error_State;
}
u8 DIO_u8SetPinValue(u8 Copy_u8PinNumber,u8 Copy_u8PortNumber,u8 Copy_u8Value)
{
	u8 Error_State=OK;
	if(Copy_u8PinNumber<8)
	{
		switch(Copy_u8PortNumber)
		{
		case DIO_PORTA:
			if(Copy_u8Value==HIGH)
			{
				SET_BIT(PORTA,Copy_u8PinNumber);
			}
			else if(Copy_u8Value==LOW)
			{
				CLR_BIT(PORTA,Copy_u8PinNumber);
			}
			else
			{
				Error_State=NOK;
			}
			break;
		case DIO_PORTB:
			if(Copy_u8Value==HIGH)
			{
				SET_BIT(PORTB,Copy_u8PinNumber);
			}
			else if(Copy_u8Value==LOW)
			{
				CLR_BIT(PORTB,Copy_u8PinNumber);
			}
			else
			{
				Error_State=NOK;
			}
			break;
		case DIO_PORTC:
			if(Copy_u8Value==HIGH)
			{
				SET_BIT(PORTC,Copy_u8PinNumber);
			}
			else if(Copy_u8Value==LOW)
			{
				CLR_BIT(PORTC,Copy_u8PinNumber);
			}
			else
			{
				Error_State=NOK;
			}
			break;
		case DIO_PORTD:
			if(Copy_u8Value==HIGH)
			{
				SET_BIT(PORTD,Copy_u8PinNumber);
			}
			else if(Copy_u8Value==LOW)
			{
				CLR_BIT(PORTD,Copy_u8PinNumber);
			}
			else
			{
				Error_State=NOK;
			}
			break;
		default:
			Error_State=NOK;
			break;
		}
	}
	else
	{
		Error_State=NOK;
	}
	return Error_State;
}

u8 DIO_u8SetPortDirection(u8 Copy_u8PortNumber,u8 Copy_u8Direction)
{
	u8 Error_State=OK;
	switch(Copy_u8PortNumber)
	{
	case DIO_PORTA:
		if(Copy_u8Direction==PORT_OUTPUT)
		{
			DDRA=PORT_OUTPUT;
		}
		else if(Copy_u8Direction==PORT_INPUT)
		{
			DDRA=PORT_INPUT;
		}
		else
		{
			Error_State=NOK;
		}
		break;
	case DIO_PORTB:
		if(Copy_u8Direction==PORT_OUTPUT)
		{
			DDRB=PORT_OUTPUT;
		}
		else if(Copy_u8Direction==PORT_INPUT)
		{
			DDRB=PORT_INPUT;
		}
		else
		{
			Error_State=NOK;
		}
		break;
	case DIO_PORTC:
		if(Copy_u8Direction==PORT_OUTPUT)
		{
			DDRC=PORT_OUTPUT;
		}
		else if(Copy_u8Direction==PORT_INPUT)
		{
			DDRC=PORT_INPUT;
		}
		else
		{
			Error_State=NOK;
		}
		break;
	case DIO_PORTD:
		if(Copy_u8Direction==PORT_OUTPUT)
		{
			DDRD=PORT_OUTPUT;
		}
		else if(Copy_u8Direction==PORT_INPUT)
		{
			DDRD=PORT_INPUT;
		}
		else
		{
			Error_State=NOK;
		}
		break;
	default:
		Error_State=NOK;
		break;
	}
	return Error_State;
}
u8 DIO_u8SetPortValue(u8 Copy_u8PortNumber,u8 Copy_u8Value)
{
	u8 Error_State=OK;
	if(Copy_u8Value<=255)
	{
		switch(Copy_u8PortNumber)
		{
		case DIO_PORTA:
			PORTA=Copy_u8Value;
			break;
		case DIO_PORTB:
			PORTB=Copy_u8Value;
			break;
		case DIO_PORTC:
			PORTC=Copy_u8Value;
			break;
		case DIO_PORTD:
			PORTD=Copy_u8Value;
			break;
		default:
			Error_State=NOK;
			break;
		}
	}
	else
	{
		Error_State=NOK;
	}
	return Error_State ;
}

u8 DIO_u8GetPinValue(u8 Copy_u8PinNumber,u8 Copy_u8PortNumber,u8* u8PtrToValue)
{
	u8 Error_State=OK;
	if((Copy_u8PinNumber<8)&&(u8PtrToValue!=NULL_POINTER))
	{
		switch(Copy_u8PortNumber)
		{
		case DIO_PORTA:
			*u8PtrToValue=GET_BIT(PINA,Copy_u8PinNumber);
			break;
		case DIO_PORTB:
			*u8PtrToValue=GET_BIT(PINB,Copy_u8PinNumber);
			break;
		case DIO_PORTC:
			*u8PtrToValue=GET_BIT(PINC,Copy_u8PinNumber);
			break;
		case DIO_PORTD:
			*u8PtrToValue=GET_BIT(PIND,Copy_u8PinNumber);
			break;
		default:
			Error_State=NOK;
		}
	}
	return Error_State;
}
u8 DIO_u8Set4PinsDirection(u8 Copy_u8PortNumber,u8 Copy_u8PinMode,u8 Copy_u8Direction)
{
	u8 Error_State=OK;
	switch(Copy_u8PortNumber)
	{
	case DIO_PORTA:
		if((Copy_u8PinMode==MSB_PINS)&&(Copy_u8Direction==PIN_OUTPUT))
		{
			DDRA|=0xF0;
		}
		else if((Copy_u8PinMode==MSB_PINS)&&(Copy_u8Direction==PIN_INPUT))
		{
			DDRA&=0x0F;
		}
		else if((Copy_u8PinMode==LSB_PINS)&&(Copy_u8Direction==PIN_OUTPUT))
		{
			DDRA|=0x0F;
		}
		else if((Copy_u8PinMode==LSB_PINS)&&(Copy_u8Direction==PIN_INPUT))
		{
			DDRA&=0xF0;
		}
		else
		{
			Error_State=NOK;
		}
		break;
	case DIO_PORTB:
		if((Copy_u8PinMode==MSB_PINS)&&(Copy_u8Direction==PIN_OUTPUT))
		{
			DDRB|=0xF0;
		}
		else if((Copy_u8PinMode==MSB_PINS)&&(Copy_u8Direction==PIN_INPUT))
		{
			DDRB&=0x0F;
		}
		else if((Copy_u8PinMode==LSB_PINS)&&(Copy_u8Direction==PIN_OUTPUT))
		{
			DDRB|=0x0F;
		}
		else if((Copy_u8PinMode==LSB_PINS)&&(Copy_u8Direction==PIN_INPUT))
		{
			DDRB&=0xF0;
		}
		else
		{
			Error_State=NOK;
		}
		break;
	case DIO_PORTC:
		if((Copy_u8PinMode==MSB_PINS)&&(Copy_u8Direction==PIN_OUTPUT))
		{
			DDRC|=0xF0;
		}
		else if((Copy_u8PinMode==MSB_PINS)&&(Copy_u8Direction==PIN_INPUT))
		{
			DDRC&=0x0F;
		}
		else if((Copy_u8PinMode==LSB_PINS)&&(Copy_u8Direction==PIN_OUTPUT))
		{
			DDRC|=0x0F;
		}
		else if((Copy_u8PinMode==LSB_PINS)&&(Copy_u8Direction==PIN_INPUT))
		{
			DDRC&=0xF0;
		}
		else
		{
			Error_State=NOK;
		}
		break;
	case DIO_PORTD:
		if((Copy_u8PinMode==MSB_PINS)&&(Copy_u8Direction==PIN_OUTPUT))
		{
			DDRD|=0xF0;
		}
		else if((Copy_u8PinMode==MSB_PINS)&&(Copy_u8Direction==PIN_INPUT))
		{
			DDRD&=0x0F;
		}
		else if((Copy_u8PinMode==LSB_PINS)&&(Copy_u8Direction==PIN_OUTPUT))
		{
			DDRD|=0x0F;
		}
		else if((Copy_u8PinMode==LSB_PINS)&&(Copy_u8Direction==PIN_INPUT))
		{
			DDRD&=0xF0;
		}
		else
		{
			Error_State=NOK;
		}
		break;
	default:
		Error_State=NOK;
	}
	return Error_State;
}
u8 DIO_u8Set4PinsValue(u8 Copy_u8PortNumber,u8 Copy_u8PinMode,u8 Copy_u8Value)
{
	u8 Error_State=OK;
	switch(Copy_u8PortNumber)
	{
	case DIO_PORTA:
		if(Copy_u8PinMode==MSB_PINS)
		{
			Copy_u8Value=0xF0;
			PORTA&=0x0F;
			PORTA|=(Copy_u8Value<<4);
		}
		else if(Copy_u8PinMode==LSB_PINS)
		{
			Copy_u8Value&=0x0F;
			PORTA&=0xF0;
			PORTA|=Copy_u8Value;
		}
		else
		{
			Error_State=NOK;
		}
		break;
	case DIO_PORTB:
		if(Copy_u8PinMode==MSB_PINS)
		{
			PORTB&=0x0F;
			PORTB|=(Copy_u8Value<<4);
		}
		else if(Copy_u8PinMode==LSB_PINS)
		{
			Copy_u8Value&=0x0F;
			PORTB&=0xF0;
			PORTB|=Copy_u8Value;
		}
		else
		{
			Error_State=NOK;
		}
		break;
	case DIO_PORTC:
		if(Copy_u8PinMode==MSB_PINS)
		{
			PORTC&=0x0F;
			PORTC|=(Copy_u8Value<<4);
		}
		else if(Copy_u8PinMode==LSB_PINS)
		{
			Copy_u8Value&=0x0F;
			PORTC&=0xF0;
			PORTC|=Copy_u8Value;
		}
		else
		{
			Error_State=NOK;
		}
		break;
	case DIO_PORTD:
		if(Copy_u8PinMode==MSB_PINS)
		{
			PORTD&=0x0F;
			PORTD|=(Copy_u8Value<<4);
		}
		else if(Copy_u8PinMode==LSB_PINS)
		{
			Copy_u8Value&=0x0F;
			PORTD&=0xF0;
			PORTD|=Copy_u8Value;
		}
		else
		{
			Error_State=NOK;
		}
		break;
	default:
		Error_State=NOK;
	}
	return Error_State;
}
