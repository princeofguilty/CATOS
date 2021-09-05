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

#define LCD_CFG_PORT u8PORTA
#define LCD_VIEW_PORT u8PORTB
#define LCD_CFG_START_PIN 5


void LCD_Boot(){
	LCD_vidInit(LCD_CFG_PORT, LCD_VIEW_PORT, LCD_CFG_START_PIN);

}

void boot(){

}

int main(){
	return 0;
}
