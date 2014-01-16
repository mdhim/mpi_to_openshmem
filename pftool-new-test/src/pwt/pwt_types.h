/**
* Contains basic declarations of all types used
* within the PWT library. This file was developed
* to alleveate convoluted header logic.
*/
#ifndef __PWT__TYPES_H
#define __PWT__TYPES_H

/* Declarations for pwt and options. Defined in pwt.h */
struct pwt;
typedef struct pwt pwt;
struct options;
typedef struct options options;

/* Declaration of the PerfStat type. Defined in perfstat.h */
struct perf_stats;
typedef struct perf_stats PerfStat;

/* Declaration of the WorkRequest type. Defined in workreq.h */
struct work_request;
typedef struct work_request WorkRequest;

/* Declaration of the WorkItem type and associated function types. Defined in wortkitem.h */
struct work_item;
typedef struct work_item WorkItem;
/*    type for do_work() function */
typedef void (*workitem_do_t)(WorkItem *data, options o);

/* Declaration of the Scheduler type and associated function types. Defined in scheduler.h */
struct sched_data;
typedef struct sched_data Scheduler;
/* type for schedule_work() function. This function should have logic that assigns a WorkItem to a WorkQ */
typedef void (*scheduler_schedule_t)(Scheduler *sched, WorkItem *item, options o);
/* type for assign_work() function. This function should have logic that allocates a worker process, 
and returns it with the next WorkItem to do */
typedef void (*scheduler_assign_t)(Scheduler *sched, WorkItem **item, int *rank);

#endif
