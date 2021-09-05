
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ATMEGA32_REGISTERS.h"
#include "GPT_int.h"
#include <avr/interrupt.h>


pFunc InternalCBFs[2];

pFunc InternalCBFs1[2];

void GPT_vidInit (void)
{
#if GPT_MODE == NORMAL
	TCCR0_REG.Bits.BIT_3 = 0;
	TCCR0_REG.Bits.BIT_6 = 0;
#elif GPT_MODE == CTC
	TCCR0_REG.Bits.BIT_3 = 1;
	TCCR0_REG.Bits.BIT_6 = 0;

	TCCR0_REG.Whole_Register &= OC0_MODE_CLEAR_MASK;
	TCCR0_REG.Whole_Register |= OC0_MODE;

	if(OCR0_VALUE <= 255)
	{
		OCR0_REG.Whole_Register = OCR0_VALUE;
	}
#endif

	TCCR1A_REG.Whole_Register = 0x00;
	OCR1A_REG = 1000;
	TCNT1_REG = 0;
	TIMSK_REG.Bits.BIT_4 = 1;
	TCCR1B_REG.Bits.BIT_1 = 1;
	TCCR1B_REG.Bits.BIT_3 = 1;

}


void GPT_vidStopTimer(void)
{
	TCCR0_REG.Whole_Register &= 0xf8;
}


void GPT_vidStartTimer(void)
{
	TCCR0_REG.Whole_Register &= CS_CLEAR_MASK;
	TCCR0_REG.Whole_Register |= CS_MODE;
}


void GPT_vidLoadTimer(u8 Copy_u8PreloadVlaue)
{
	TCNT0_REG.Whole_Register = Copy_u8PreloadVlaue;
}

void GPT_vidEnableNotification(void)
{
#if GPT_MODE == NORMAL
	TIMSK_REG.Bits.BIT_0 = 0;
#elif GPT_MODE == CTC
	TIMSK_REG.Bits.BIT_1 = 1;
#endif
}


void GPT_vidDisableNotification(void)
{
#if GPT_MODE == NORMAL
	TIMSK_REG.Bits.BIT_0 = 0;
#elif GPT_MODE == CTC
	TIMSK_REG.Bits.BIT_1 = 0;
#endif
}


void GPT_vidSetCallBack(pFunc CBF , u8 interruptID)
{
	if(CBF)
	{
		InternalCBFs[interruptID] = CBF;
	}
}


ISR(TIMER0_OVF_vect)
{
	if(InternalCBFs[0])
	{
		InternalCBFs[0]();
	}
}

ISR(TIMER0_COMP_vect)
{
	if(InternalCBFs[1])
	{
		InternalCBFs[1]();
	}
}
