
#include"tmu.h"





uint8_t last_active = 0;
uint8_t flag=0;

Buff_strct TMU_buffer [MAX_SIZE_OF_TASKS];

int flags[MAX_SIZE_OF_TASKS]={0};


void interrrupt_call (void)
{
		flag = 1;
		for(int i = 0; i < last_active; i++)
		flags[i]++;

}



void TMU_Init(void)
{
	timer_init();
	set_interrupt_call_back(interrrupt_call);

}





void TMU_Start (uint8_t delay_time ,void (*func) (void),periodicity_enum periodicity)
{
	if ( last_active < MAX_SIZE_OF_TASKS - 1 )
	{
		last_active++;
		TMU_buffer [last_active].func_name   = func;
		TMU_buffer [last_active].time_delay	= delay_time;
		TMU_buffer [last_active].periodicity = periodicity;
		TMU_buffer [last_active].status		= Active;

		/* retvalue = OK; */
	}
	/*
	else
		retvalue = NOK;

	return retvalue;

	*/
}



void TMU_Stop ( void (*func)(void) )
{

	for (int i = 0; i < last_active; i++)
	if(TMU_buffer [i].func_name == func)
	{
	TMU_buffer [i] = TMU_buffer [last_active];  /***if the stopped function not the last one, write the last struct over this func ***/
	flags[i] = flags[last_active];
	last_active--;   /*** decrement the last actived array ***/
	break;
	}

}

void TMU_Dispatch (void)
{

	if (flag == 1)
	{
		for (int i = 0 ; i < last_active; i++ )
		{
				if (flags[i] == TMU_buffer[i].time_delay)
				{
					flags[i] = 0;

					(*TMU_buffer[i].func_name)();

				}


		}
		flag = 0;
	}



}


/** Timer.c **/

/*
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

ISR(){

	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)();
	}
}


void set_interrupt_call_back (void (*int_callback_func) (void) )
{

	g_callBackPtr = int_callback_func;

}


*/

/****************/








