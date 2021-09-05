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
	LCD_vidWriteString("abc");
	_delay_ms(500);
	LCD_vidGoTo(1,0);
	LCD_vidWriteString("xyz");
	_delay_ms(200);
	LCD_vidShiftLineUp();
	LCD_vidWriteString("123");
	_delay_ms(500);
	return 0;
}
