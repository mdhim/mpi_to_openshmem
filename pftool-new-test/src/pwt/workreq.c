
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

#include "workreq.h"
#include "workitem.h"						// needed to interface with a WorkItem.

#define MICROS_PER_SECOND ((double)1000000.0)

//
// WorkRequest functions
//

/**
* Initializes or clears a WorkRequest buffer. Ideal for
* statically allocated buffers.
*
* @param wr	pointer to a new/repurposed WorkRequest buffer
*/
void workreq_clear(WorkRequest *wr) {
	bzero(wr,sizeof(WorkRequest));				// clear out the buffer
	wr->type = _WORKREQ_TYPE_;				// set the type

	return;
}

/**
* Creates a new WorkRequest.
*
* @return a new WorkRequest
*/
WorkRequest *workreq_new() {
	WorkRequest *wr = (WorkRequest *)malloc(sizeof(WorkRequest));

	workreq_clear(wr);				// initializes all counters and times to zero
	return(wr);
}

/**
* Deallocates a WorkRequest. 
*
* @param wr	the WorkRequest to deallocate
*
* @return a NULL WorkRequest pointer
*/
WorkRequest *workreq_del(WorkRequest *wr) {
	if(wr) free(wr);
	return((WorkRequest *)NULL);
}

/**
* Routine to show that a work request is accepted
* by the calling logic. This is implemented by
* clearing the value of sleep_seconds.
*
* @param wr	the WorkRequest to accept
*/
void workreq_accept(WorkRequest *wr) {
	wr->sleep_seconds = (time_t)0;
	return;
}

/**
* Routine to show that a work request is accepted
* by the calling logic. This is implemented by
* setting the value of sleep_seconds.
*
* @param wr	the WorkRequest to accept
*/
void workreq_deny(WorkRequest *wr) {
	if(!wr->sleep_seconds)		// first time
	  wr->sleep_seconds = (time_t)2;
	else if(wr->sleep_seconds < WORKREQ_DEADLOCK_LIMIT)
	  wr->sleep_seconds *= (time_t)2;

	return;
}

/**
* Tests to see if a WorkRequest is considered
* deadlocked. That is - has not been accepted
* after "x" number of tries. A NULL WorkRequest
* is not considered deadlocked.
*
* @param wr	the WorkRequest to test
*
* @return non-zero if it is deadlocked. Otherwise
*	zero is returned.
*/
int workreq_isDeadlocked(WorkRequest *wr) {
	return(wr && wr->sleep_seconds >= WORKREQ_DEADLOCK_LIMIT);
}
/**
* Tests to see if a WorkRequest has been accepted
* or not. If it as not been acceoted, then the value
* of sleep_seconds is returned. A NULL WorkRequest
* is considered as accepted.
*
* @param wr	the WorkRequest to test
*
* @return non-zero if it is not accepted. Otherwise
*	zero is returned.
*/
int workreq_notAccepted(WorkRequest *wr) {
	if(!wr) return(0);
	return(wr->sleep_seconds);
}

//
// WorkItem Support functions
//

/**
* Attach or assign a WorkRequest structure to a WorkItem.
* If item is NULL or wr is NULL, then nothing is done.
* Uses workitem_update_work().
*
* @param wr	the WorkRequest structure to
*		update with
* @param item	the WorkItem to update
*/
void workreq_attach(WorkRequest *wr, WorkItem *item) {
	workitem_update_work(item,(void *)wr,sizeof(WorkRequest));
	return;
}

/**
* A function to return a work item's work request.
* If the buffer pointer is NULL, then the work
* item does not have a work request. Uses
* workitem_get_work().
*
* @param item           the item to reference
*
* @return the pointer to the item's work request
*/
WorkRequest *workitem_get_workreq(WorkItem *item) {
        return((WorkRequest *)workitem_get_work(item));
}

/**
* a function to test if a work item has an allocated
* WorkRequest structure.
*
* @param item		the item to test
*
* @return non-zero if a WorkRequest structure is allocated.
*	zero is returned otherwise, including if the
*	item is NULL.
*/
int workitem_hasWorkRequest(WorkItem *item) {
	if(item) return(item->workdata && ((WorkRequest *)item->workdata)->type == _WORKREQ_TYPE_);
	return(0);
}

