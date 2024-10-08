/*
 * lab22.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Admin
 */


#include"lab22.h"
//int hour = 15;
//int minute = 8;
//int second = 50;
int cnt=1; int cnt1=100;
int states=0; int i=0;int index_led=0;
int led_buffer [4] = {1 , 2 , 3 , 4};
static uint8_t LED7_SEG[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
void display7SEG_A(int index)
{
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, ((LED7_SEG[index] >> 0) & 0x01));
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, ((LED7_SEG[index] >> 1) & 0x01));
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, ((LED7_SEG[index] >> 2) & 0x01));
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, ((LED7_SEG[index] >> 3) & 0x01));
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, ((LED7_SEG[index] >> 4) & 0x01));
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, ((LED7_SEG[index] >> 5) & 0x01));
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, ((LED7_SEG[index] >> 6) & 0x01));
}
void update7SEG(int index)
{
	switch(index){
		case 0: {
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
	            break;
	        }
	        case 1: {
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
	            break;
	        }
	        case 2: {
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
	            break;
	        }
	        case 3:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
	            break;
	        default:
	            break;
	    }
    display7SEG_A(led_buffer[index++]);
}
void enableseg(int index){
	 switch (index) {
	        case 0: {
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
	            break;
	        }
	        case 1: {
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
	            break;
	        }
	        case 2: {
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
	            break;
	        }
	        case 3:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
	            break;
	        default:
	            break;
	    }
}
void clearLED(){
	  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2
		                             | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5
		                             | GPIO_PIN_6 , GPIO_PIN_SET);
}

void ex1(){
	cnt--;
	if(cnt<=0){
		cnt=100;
		HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
		if(states==1){
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
		} else{
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
		}
		states=!states;
		clearLED();
		display7SEG_A(states+1);
	}
}
void ex2(){
	cnt--;
	if ( cnt == 50 || cnt == 0) {
		if(cnt==0){
	        cnt = 100;
	        HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5|GPIO_PIN_4);
		}
				enableseg(states);
				clearLED();
				display7SEG_A(i);
				i++;
	        if (i >= 4)
	            i = 0;
	        states++;
	        if (states >= 4)
	            states = 0;
	    }

}
void ex3(){
	cnt1--;
	    if (cnt1 <= 0)
	    {
	        update7SEG(index_led++);
	        if (index_led >= 4)
	            index_led = 0;
	    }
}
void ex45(){
	cnt1--;
		if (cnt1 <= 0)
		{
			if (index_led > 1)
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
		    update7SEG(index_led++);
		    if (index_led >= 4)
		        index_led = 0;
		    cnt1 = 100;
		}
}
