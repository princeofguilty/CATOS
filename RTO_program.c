#include "STD_TYPES.h"
#include "ATMEGA32_REGISTERS.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "GPT_int.h"

#include "RTO_Interface.h"
#include "RTO_Private.h"
#include "RTO_config.h"


Task_TCB TASKS[RTO_NUMBER_OF_TASKS];


void RTOS_voidStartScheduler()
{
	GPT_vidInit();
}

RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, u16 Copy_u16Firstdelay, void(*Copy_ptrtofun)(void))
{
	TASKS[Copy_u8Priority].u16Periodicity=Copy_u16Periodicity;
	TASKS[Copy_u8Priority].u16FirstDelay=Copy_u16Firstdelay;
	TASKS[Copy_u8Priority].pfun=Copy_ptrtofun;
}

static void RTO_voidScheduler()
{
	u8 counter;
	for (counter=0; counter<RTO_NUMBER_OF_TASKS;counter++)
	{
		if (TASKS[counter].u16FirstDelay==0)
		{
			TASKS[counter].pfun();
			TASKS[counter].u16FirstDelay=TASKS[counter].u16Periodicity-1;
		}
		else
			TASKS[counter].u16FirstDelay--;
	}
}
void RTO_voidStartSchedulr(){}

void RTOS_voidInit(void)
{

}
