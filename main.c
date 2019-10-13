/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed ELameer
 */

#include"tmu.h"


void Toggle_first_led (void);
void Toggle_second_led (void);
void Toggle_third_led (void);



int main(void)
{
	DDRC = 0XFF;

    PORTC=1;
	TMU_Init();
	PORTC=2;
	TMU_Start (10,Toggle_first_led,periodic);
	PORTC=5;
	TMU_Start (3,Toggle_second_led,periodic);
	PORTC=7;
	TMU_Start (4,Toggle_third_led,periodic);
	PORTC=3;
	SREG|=(1<<7);
	while(1)
	{

		TMU_Dispatch();

	}


}


void Toggle_first_led (void)
{

	PORTC ^= ( 1<< PINC4);

}

void Toggle_second_led (void)
{

	PORTC ^= ( 1<< PINC5);

}

void Toggle_third_led (void)
{

	PORTC ^= ( 1<< PINC6);

}




