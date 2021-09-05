/*
 * boot.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Princ
 */


#include "STD_TYPES.h"
#include "ATMEGA32_REGISTERS.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include <avr/delay.h>

#define LCD_CFG_PORT u8PORTC
#define LCD_VIEW_PORT u8PORTD
#define LCD_CFG_START_PIN 0

#define TASKS_NUM 5

typedef enum {Dormant, Ready, Running, Waiting, ISR, Delay, Empty} STATES;

u8 task_index=0;

typedef struct{
	u8 id;
	u8 periodicity;
	u8 priority;
	u8 firstDelay;
	pFunc *function;
	STATES state;

}OS_tasks;

OS_tasks tasks[TASKS_NUM] = {0,0,0,0,0,Empty};

void LCD_Boot(){
	LCD_vidInit(LCD_CFG_PORT, LCD_VIEW_PORT, LCD_CFG_START_PIN);
	LCD_NewMessage("LCD: boot ok!");
}


void OS_boot(){
	LCD_Boot();
	LCD_NewMessage("OS: boot ok!");
}


void OS_add_task(u8 id, u8 priority, pFunc *function, u8 periodicity, u8 firstDelay){

	for(int i=0; i<TASKS_NUM; i++){
		if (tasks[i].state == Empty){
			task_index = i;
			break;
		}
	}

	tasks[++task_index].id = id;
	tasks[task_index].priority = priority;
	tasks[task_index].function = function;
	tasks[task_index].periodicity = periodicity;
	tasks[task_index].firstDelay = firstDelay;
}


int main(){
	OS_boot();
	LCD_NewMessage("test");
	return 0;
}
