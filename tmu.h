
#ifndef TMU_H_
#define TMU_H_


#include "tmu_config.h"



extern uint8_t BuffCount;


void TMU_Start (uint8_t delay_time ,void (*func) (void),periodicity_enum periodicity);
void TMU_Start (uint8_t time , void(*func_ptr)(void), uint8_t period);
void TMU_Stop ( void (*func)(void) );
void TMU_Dispatch (void);
void TMU_Init(void);

#endif /* TMU_H_ */
