/*
 * RTO_private.h
 *
 *  Created on: Sep 2, 2021
 *      Author: Princ
 */

#ifndef RTO_PRIVATE_H_
#define RTO_PRIVATE_H_

typedef struct
{
	//	periodicity
	u16 u16Periodicity;
	//	first delay
	u16 u16FirstDelay;
	void(*pfun) (void);
} Task_TCB;

static void RTO_voidScheduler(void);

#endif /* RTO_PRIVATE_H_ */
