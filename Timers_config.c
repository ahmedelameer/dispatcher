/*
 * Timers_config.c
 *
 *  Created on: ??�/??�/????
 *      Author: Mohamed ELameer
 */


#include "Timer_config.h"

/*timers_type
 * ,interrupt                                FOR      EACH        TIMER
 * ,clock
 * ,wave generation
 * ,out put compare
 * ,out compare output as value */


Timer_config Timers_setup[MAX_num_of_timers]=
{
		{NA,NA,NA,NA,NA,NA,NA,NA,NA},//added //external int
		{NA,NA,NA,Timer0,EN_INT,F_cpu_8,WG_CTC,128,NPWM_Normal},//added		//delay
		{NA,NA,NA,NA,NA,NA,NA,200,NA}// ADDED
};




