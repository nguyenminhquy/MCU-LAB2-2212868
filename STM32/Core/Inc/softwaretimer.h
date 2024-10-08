/*
 * softwaretimer.h
 *
 *  Created on: Oct 6, 2024
 *      Author: Admin
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_


extern int timer0_flag, timer0_counter, TIMER_CYCLE;
extern int timer1_flag, timer1_counter;
void setTimer0(int duration);
void setTimer1(int duration) ;
void timer_run();

#endif /* INC_SOFTWARETIMER_H_ */
