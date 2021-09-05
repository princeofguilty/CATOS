#ifndef ATMEGA32_REGISTERS_H_
#define ATMEGA32_REGISTERS_H_

typedef union {
	struct{
		u8 BIT_0 : 1;
		u8 BIT_1 : 1;
		u8 BIT_2 : 1;
		u8 BIT_3 : 1;
		u8 BIT_4 : 1;
		u8 BIT_5 : 1;
		u8 BIT_6 : 1;
		u8 BIT_7 : 1;
	}Bits;
	u8 Whole_Register;
}tuniReg;


#define SREG_REG		(*((volatile tuniReg*)(0x5F)))
//DIOA

#define PORTA_REG		*((volatile u8*)(0x3B))
#define DDRA_REG		*((volatile u8*)(0x3A))
#define PINA_REG		*((volatile u8*)(0x39))
//DIOB

#define PORTB_REG		*((volatile u8*)(0x38))
#define DDRB_REG		*((volatile u8*)(0x37))
#define PINB_REG		*((volatile u8*)(0x36))
//DIOc

#define PORTC_REG		*((volatile u8*)(0x35))
#define DDRC_REG		*((volatile u8*)(0x34))
#define PINC_REG		*((volatile u8*)(0x33))
//DIOD

#define PORTD_REG		*((volatile u8*)(0x32))
#define DDRD_REG		*((volatile u8*)(0x31))
#define PIND_REG		*((volatile u8*)(0x30))
//interupt reg

#define MCUCR_REG		(*((volatile tuniReg*)(0x55)))
#define GICR_REG		(*((volatile tuniReg*)(0x5B)))
#define GIFR_REG		(*((volatile tuniReg*)(0x5A)))
//
#define ADMUX_REG       (*((volatile tuniReg*)(0x27)))
#define ADCSRA_REG       (*((volatile tuniReg*)(0x26)))
#define ADCH_REG       (*((volatile tuniReg*)(0x25)))
#define ADCL_REG       (*((volatile tuniReg*)(0x24)))

//timer0 reg
#define OCR0_REG		(*((volatile tuniReg*)(0x5C)))
#define TIMSK_REG		(*((volatile tuniReg*)(0x59)))
#define TCCR0_REG		(*((volatile tuniReg*)(0x53)))
#define TCNT0_REG		(*((volatile tuniReg*)(0x52)))

#define TCCR1A_REG      (*((volatile tuniReg*)(0x4F)))
#define TCCR1B_REG      (*((volatile tuniReg*)(0x4E)))

#define TCNT1_REG      (*((volatile u16*)(0x4C)))
#define OCR1A_REG      (*((volatile u16*)(0x4A)))
#define OCR1B_REG      (*((volatile u16*)(0x48)))
#define ICR1_REG       (*((volatile u16*)(0x46)))

// WATCH DOG REG
#define WDP_REG	(*((volatile tuniReg*)0x41)) //WATCH DOG TIMER BIT
// USART
#define  UDR_REG (*((volatile tuniReg*)0x2C))
#define  UCSRA_REG (*((volatile tuniReg*)0x2B)) // UART Control and Status register A
#define  UCSRB_REG (*((volatile tuniReg*)0x2A))  //  UART Control and Status register B
#define  UBRRL_REG (*((volatile tuniReg*)0x29))



// lehom nafs el adress bas bn8yar Bit 3ashan ne3raf ne3mel access lel etneent
#define UCSRC_REG      (*((volatile tuniReg*)(0x40)))
#define UBRRH_REG      (*((volatile tuniReg*)(0x40)))

//I2C

#define TWAR_REG       (*((volatile tuniReg*)0x22))
#define TWBR_REG       (*((volatile tuniReg*)0x20))
#define TWDR_REG       (*((volatile tuniReg*)0x23))
#define TWSR_REG       (*((volatile tuniReg*)0x21))
#define TWCR_REG       (*((volatile tuniReg*)0x56))


#define WDP_REG	        (*((volatile tuniReg*)0x41))

//SPI
#define SPCR_REG (*((volatile u8*)0x2d))
#define SPSR_REG (*((volatile u8*)0x2e))
#define SPDR_REG (*((volatile u8*)0x2f))


#endif /* ATMEGA32_REGISTERS_H_ */
