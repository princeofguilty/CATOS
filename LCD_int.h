#ifndef LCD_INT_H_
#define LCD_INT_H_

#define LCD_u8CLEAR_DISPLAY			0x01
#define LCD_u8RETURN_HOME			0x02

void LCD_vidWriteData(u8 Copy_Data);

void LCD_vidSendCommand(u8 Copy_Command);

void LCD_vidWriteString(u8 Copy_String[]);

void LCD_vidInit(u8 PORTcfg, u8 PORTview, u8 start_pin_cfg);

void LCD_vidGoTo(u8 Copy_Row, u8 Copy_Column);

void LCD_vidRefresh();
void LCD_vidShiftLineUp();


#endif /* LCD_INT_H_ */
