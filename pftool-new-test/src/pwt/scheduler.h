
#ifndef __SCHEDULER_H
#define __SCHEDULER_H

#include "workq.h"						// currently holds WorkItem definitions

/* A structure to hold scheduler data */
struct sched_data {
    scheduler_schedule_t schedule_work;				// function to put a WorkItem on a WorkQ
    scheduler_assign_t assign_work;				// function to allocate a worker process and return the next WorkItem
    workitem_do_t stop_proc;					// function used to stop worker processes. Used by scheduler_stop_processes().
    int process_count;						// number of worker processes
    int *processes;						// pointer to an array to hold worker process statuses
    int workq_count;						// number of work queues
    WorkQ **workq;						// an array of WorkQ pointers
};

/* functions to create and manage the Scheduler */
Scheduler *scheduler_new(options o);
Scheduler *scheduler_del(Scheduler *sched);
void scheduler_update_assignwork(Scheduler *sched, scheduler_assign_t schedfunc);
void scheduler_update_schedulework(Scheduler *sched, scheduler_schedule_t schedfunc);
void scheduler_update_stopproc(Scheduler *sched, workitem_do_t stopfunc);
void scheduler_set_processidle(Scheduler *sched, int proc_num);
void scheduler_stop_processes(Scheduler *sched, int src_rank);
int scheduler_canAssignWork(Scheduler *sched);
int scheduler_workDone(Scheduler *sched);

/* Scheduler task functions */
void scheduler_addwork(Scheduler *sched, WorkItem *item, options o);
void scheduler_ackwork(Scheduler *sched, WorkItem *item, options o);
void scheduler_getwork(Scheduler *sched, WorkItem **item, int *rank);

#endif
