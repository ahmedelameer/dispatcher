
#ifndef TMU_CONFIG_H_
#define TMU_CONFIG_H_

#include "Timers.h"
#define MAX_SIZE_OF_TASKS 10

typedef enum{

	one_shot,
	periodic

}periodicity_enum;


typedef enum{

	Not_Active,
	Active

}status_enum;


typedef struct{

	void (*func_name) (void);
	uint16_t time_delay;
	periodicity_enum periodicity;
	status_enum status;

}Buff_strct;

extern Buff_strct TMU_buffer [MAX_SIZE_OF_TASKS];


#endif /* TMU_CONFIG_H_ */


