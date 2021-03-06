#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/delay.h>
#include "DIO_int.h"
#include "LCD_int.h"
#include "ATMEGA32_REGISTERS.h"

#define ROWS 2
#define COLUMNS 16

u8 PORTcfg_int;
u8 PORTview_int;
u8 CFG_pin_0, CFG_pin_1, CFG_pin_2;


u8 LastLine[17]={'\0'};

void LCD_vidWriteData(u8 Copy_Data)
{
	DIO_vidSetPinVal(PORTcfg_int,CFG_pin_0,DIO_u8HIGH);
	DIO_vidSetPinVal(PORTcfg_int,CFG_pin_1,DIO_u8LOW);
	DIO_vidSetPortVal(PORTview_int,Copy_Data);
	DIO_vidSetPinVal(PORTcfg_int,CFG_pin_2,DIO_u8HIGH);
	_delay_ms(2);
	DIO_vidSetPinVal(PORTcfg_int,CFG_pin_2,DIO_u8LOW);

}

void LCD_vidSendCommand(u8 Copy_Command)
{
	DIO_vidSetPinVal(PORTcfg_int,CFG_pin_0,DIO_u8LOW);
	DIO_vidSetPinVal(PORTcfg_int,CFG_pin_1,DIO_u8LOW);
	DIO_vidSetPortVal(PORTview_int,Copy_Command);
	DIO_vidSetPinVal(PORTcfg_int,CFG_pin_2,DIO_u8HIGH);
	_delay_ms(2);
	DIO_vidSetPinVal(PORTcfg_int,CFG_pin_2,DIO_u8LOW);
}

void LCD_vidWriteString(u8 *Copy_String)
{
	for (int i=0;Copy_String[i]!='\0' && i<17;i++){
		LCD_vidWriteData(Copy_String[i]);
//		LastLine[i] = Copy_String[i];
	}
}

void LCD_NewMessage(u8 Message[]){
	LCD_vidSendCommand(LCD_u8CLEAR_DISPLAY);
	LCD_vidGoTo(0,0);
	LCD_vidWriteString(LastLine);
	LCD_vidGoTo(1,0);
	LCD_vidWriteString(Message);
	for (int i=0; Message[i]!='\0' && i<17; i++)
		LastLine[i] = Message[i];
}

//void LCD_vidRefresh(){
//	LCD_vidGoTo(0,0);
//	for(int i=0; i<ROWS; i++){
//		for(int j=0; j<COLUMNS; j++){
//			LCD_vidWriteData(LCD_content[i][j]);
//		}
//	}
//
//	LCD_vidGoTo(Cursor_Row, Cursor_Column);
//}

//void LCD_vidShiftLineUp(){
//	for(int i=0; i<ROWS-1; i++){
//		for(int j=0; j<COLUMNS; j++)
//		{
//			LCD_content[i][j] = LCD_content[i+1][j];
//		}
//	}
//	for(int j=0; j<COLUMNS; j++)
//	{
//		LCD_content[ROWS-1][j] = ' ';
//	}
//	LCD_vidRefresh();
//	LCD_vidGoTo(ROWS-1,0);
//}

void LCD_vidInit(u8 PORTcfg, u8 PORTview, u8 start_pin_cfg)
{

	PORTcfg_int = PORTcfg;
	PORTview_int = PORTview;
	CFG_pin_0 = start_pin_cfg;
	CFG_pin_1 = ++start_pin_cfg;
	CFG_pin_2 = ++start_pin_cfg;

	DIO_vidSetPinDirection(PORTcfg_int,CFG_pin_0,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(PORTcfg_int,CFG_pin_1,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(PORTcfg_int,CFG_pin_2,DIO_u8OUTPUT);
	DIO_vidSetPortDirection(PORTview_int,0xFF);

	_delay_ms(50); /* Step_1 */
	LCD_vidSendCommand(0b00111000); /* Step_2 */
	_delay_ms(1); /* Step_3 */
	LCD_vidSendCommand(0b00001111); /* Step_4 */
	_delay_ms(1); /* Step_5 */
	LCD_vidSendCommand(LCD_u8CLEAR_DISPLAY); /* Step_6 */
	_delay_ms(2); /* Step_7 */
	LCD_vidSendCommand(0b00000110); /* Step_8 */
}

void LCD_vidGoTo(u8 Copy_Row, u8 Copy_Column)
{
	if (Copy_Column>=0 && Copy_Column<=15)
		switch(Copy_Row)
		{
		case 0:
			LCD_vidSendCommand((0b10000000)+Copy_Column);
			break;
		case 1:
			LCD_vidSendCommand((0b11000000)+Copy_Column);
			break;
		}
}
