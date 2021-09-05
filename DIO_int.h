#ifndef DIO_INT_H_
#define DIO_INT_H_

#define DIOHIGH 1
#define DIOLOW  0


#define u8PORTA		1
#define u8PORTB		2
#define u8PORTC		3
#define u8PORTD		4

#define DIO_u8PIN_0		0
#define DIO_u8PIN_1		1
#define DIO_u8PIN_2		2
#define DIO_u8PIN_3		3
#define DIO_u8PIN_4		4
#define DIO_u8PIN_5		5
#define DIO_u8PIN_6		6
#define DIO_u8PIN_7		7

#define DIO_u8INPUT		0
#define DIO_u8OUTPUT	1

#define DIO_u8HIGH		1
#define DIO_u8LOW		0

u8 DIO_u8GetPin(u8 Copy_PortX, u8 Copy_PinX);

void DIO_vidSetPinVal(u8 Copy_PortX, u8 Copy_PinX, u8 Copy_Value);

void DIO_vidSetPinDirection(u8 Copy_PortX, u8 Copy_PinX,u8 Copy_Direction);

void DIO_vidTogglePinVal(u8 Copy_PortX, u8 Copy_PinX);

void DIO_vidSetPortDirection(u8 Copy_PortX, u8 Copy_Direction);

void DIO_vidSetPortVal(u8 Copy_PortX, u8 Copy_Value);

#endif /* DIO_INT_H_ */
