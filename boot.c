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


void LCD_Boot(){
	LCD_vidInit(LCD_CFG_PORT, LCD_VIEW_PORT, LCD_CFG_START_PIN);

}

void boot(){

}

int main(){
	LCD_Boot();
	LCD_NewMessage("OS: booting!");
	LCD_NewMessage("OS: Hello World!");
	LCD_NewMessage("OS: NEWLINE!");


	return 0;
}
