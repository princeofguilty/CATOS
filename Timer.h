#ifndef TIMER_H_
#define TIMER_H_

#define CTC					0
#define NORMAL 				1

// OC0 MODS
#define OC0_DISCONNECTED 	0
#define OC0_TOGGLE			0X10
#define OC0_CLEAR			0x20
#define OC0_SET				0X30

#define OC0_MODE_CLEAR_MASK	~(0X30)

// Clock Sources
#define  CS_STOPED			0X00
#define  CS_INT_0			0X01
#define  CS_INT_8			0X02
#define  CS_INT_64			0X03
#define  CS_INT_256			0X04
#define  CS_INT_1024		0X05

#define CS_EXT_FALLING_EDGE		0X06
#define CS_EXT_RISING_EDGE		0X07
#define CS_CLEAR_MASK		~(0X07)

//configuration

#define GPT_MODE	NORMAL
#define OC0_MODE	OC0_TOGGLE
#define CS_MODE		CS_INT_1024
#define OCR0_VALUE  100

void GPT_vidInit(void);
void GPT_vidStartTimer(void);
void GPT_vidStopTimer(void);
void GPT_vidLoadTimer(u8 Copy_u8value);
void GPT_vidEnableNotification(void);
void GPT_vidDisableNotification(void);

#endif /* TIMER_H_ */
