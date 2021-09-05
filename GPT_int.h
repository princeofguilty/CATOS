#ifndef GPT_INT_H_
#define GPT_INT_H_

#define CTC                        0
#define NORMAL                     1

#define u8TIMER_0			 	   0
#define u8TIMER_1 				   1

/* OC0 Modes */
#define OC0_DISCONNECTED           0
#define OC0_TOGGLE                 0X10
#define OC0_CLEAR                  0X20
#define OC0_SET                    0X30


#define OC0_MODE_CLEAR_MASK       ~(0X30)


/* Clock Sources */

#define CS_STOPED                  0X00
#define CS_INT_0                   0x01
#define CS_INT_8                   0x02
#define CS_INT_64                  0x03
#define CS_INT_256                 0x04
#define CS_INT_1024                0x05

#define CS_EXT_FALLING_EDGE        0X06
#define CS_EXT_RISING_EDGE         0X07

#define CS_CLEAR_MASK            ~(0x07)




#define GPT_MODE       NORMAL
#define OC0_MODE       OC0_TOGGLE
#define CS_MODE        CS_INT_8
#define OCR0_VALUE     200



void GPT_vidInit(void);
void GPT_vidStartTimer(void);
void GPT_vidStopTimer(void);
void GPT_vidLoadTimer(u8 Copy_u8PreloadValue);
void GPT_vidEnableNotification(void);
void GPT_vidDisableNotification(void);
void GPT_vidSetCallBack(pFunc CBF ,u8 interruptID);

#endif /* GPT_INT_H_ */
