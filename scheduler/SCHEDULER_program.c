/***********************************/
/* SWC:     SCHEDULER Driver       */
/* Author:  Ahmed Amin             */
/* Version: V1                     */
/* Date:    28 June 2024           */
/***********************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include "SCHEDULER_config.h"
#include "SCHEDULER_interface.h"
#include "SCHEDULER_private.h"
#include "STK_interface.h"
//#include "../include/00-LIB/STD_TYPES.h"
//#include "../include/00-LIB/BIT_MATH.h"

void Scheduler_voidSchedulerStart(void){
STK_voidInit();
STK_voidSetIntervalPeriodic(tick_time_us,&Scheduler_SchedulerWork);

}
void Scheduler_voidCreatTesk(u8 copy_u8TeskPriority,u32 copy_u32TeskPeriodicity,void (*PF)(void),u32 copy_u32TaskFristDelay){
    if(copy_u8TeskPriority>NO_OF_TESKS){
        //do nothing
    }
    else{
        Tasks_Arr[copy_u8TeskPriority].TeskPeriodicity=copy_u32TeskPeriodicity;
        Tasks_Arr[copy_u8TeskPriority].TaskFristDelay=copy_u32TaskFristDelay;
        Tasks_Arr[copy_u8TeskPriority].pf=PF;
    }
}

void Scheduler_voidSchedulerStop(void){
STK_voidDisableTimer();
}

static void Scheduler_SchedulerWork(void){
    u8 Local_u8counter;
    for(Local_u8counter=0;Local_u8counter<NO_OF_TESKS;Local_u8counter++){
        if(Tasks_Arr[Local_u8counter].TaskFristDelay==0){
                if (Tasks_Arr[Local_u8counter].pf!=NULL)
                {
                    Tasks_Arr[Local_u8counter].pf();
                }
                Tasks_Arr[Local_u8counter].TaskFristDelay=Tasks_Arr[Local_u8counter].TeskPeriodicity-1;
            }
        else{
            Tasks_Arr[Local_u8counter].TaskFristDelay--;
        }
    }
}
