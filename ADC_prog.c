#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_int.h"
#include"ADC_int.h"
#include "ATMEGA32_REGISTERS.h"

void ADC_Init (void)
{
	ADCSRA_REG.Bits.BIT_7 = 1;



	ADCSRA_REG.Bits.BIT_0 = 1;
	ADCSRA_REG.Bits.BIT_1 = 1;
	ADCSRA_REG.Bits.BIT_2 = 1;



	ADMUX_REG.Bits.BIT_7 = 0;
	ADMUX_REG.Bits.BIT_6 = 1;



	ADMUX_REG.Bits.BIT_5 = 0;
}

u16 ADC_Read (u8 channel)
{
	u16 Local_Result;

	ADMUX_REG.Whole_Register &= ADC_ADMUX_CHANNEL_CLEAR_MASK;
	ADMUX_REG.Whole_Register |= channel;

	ADCSRA_REG.Bits.BIT_6=1;
	while((ADCSRA_REG.Bits.BIT_6));

	Local_Result = ADCL_REG.Whole_Register;
	Local_Result |=(((u16)ADCH_REG.Whole_Register)<<8);

	return Local_Result;
}


