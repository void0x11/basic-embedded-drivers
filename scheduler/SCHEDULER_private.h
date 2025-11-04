/***********************************/
/* SWC:     SCHEDULER Driver       */
/* Author:  Ahmed Amin             */
/* Version: V1                     */
/* Date:    28 June 2024           */
/***********************************/
/*File Gaurd*/
#ifndef SCHEDULER_PRIVATE_H
#define SCHEDULER_PRIVATE_H

static void Scheduler_SchedulerWork(void);

typedef struct 
{
    void (*pf)(void);
    u32 TeskPeriodicity;
    u32 TaskFristDelay;
}TCB_T;

TCB_T Tasks_Arr[NO_OF_TESKS]={NULL};


#endif