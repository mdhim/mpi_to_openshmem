/**
* A structure used to request the addition of work to
* a work queue
*/
#ifndef __WORKREQ_H
#define __WORKREQ_H

#include <time.h>

#include "pwt_types.h"

#define WORKREQ_DEADLOCK_LIMIT (time_t)16	// number of sleep seconds after which a work request (and the worker making the request) is considered deadlocked
#define _WORKREQ_TYPE_ ((long)19651122)		// value used to mark structure as a WorkRequest

struct work_request {				// a structure to hold  worker's request to add work to a work queue
    long type;					// holds a value that marks this structure as a WorkRequest
    time_t sleep_seconds;			// hold the number of seconds for a worker process to sleep. If zero, then request accepted
};


/* functions to create and manage WorkRequests */
WorkRequest *workreq_new();
WorkRequest *workreq_del(WorkRequest *wr);
void workreq_accept(WorkRequest *wr);
void workreq_clear(WorkRequest *wr);
void workreq_deny(WorkRequest *wr);
int workreq_isDeadlocked(WorkRequest *wr);
int workreq_notAccepted(WorkRequest *wr);

/* WorkItem support functions */
void workreq_attach(WorkRequest *wr, WorkItem *item);
int workitem_hasWorkRequest(WorkItem *item);
WorkRequest *workitem_get_workreq(WorkItem *item);

#endif
