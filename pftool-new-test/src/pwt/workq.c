
#include <stdlib.h>

#include "workitem.h"
#include "workq.h"

//
// WorkQ Functions
//

/**
* Creates a new WorkQ.
*
* @return a new WorkQ
*/
WorkQ *workq_new() {
	WorkQ *q = (WorkQ *)malloc(sizeof(WorkQ));

	q->count = 0;
	q->max = (-1);					// initially set to unlimited
	q->tail = (WorkQEntry *)NULL;
	q->head = q->tail;
	return(q);
}

/**
* Deallocates a WorkQ. If the WorkQ is
* not empty, a warning is printed, and
* all existing entries are deallocated
* prior to deallocating the WorkQ.
*
* @param q	the WorkQ to deallocate
*
* @return a NULL WorkQ pointer
*/
WorkQ *workq_del(WorkQ *q) {
	while(!workq_empty(q)) {
	  WorkItem *w = workq_remove(q);

	  w = workitem_del(w);
	}
	if(q) free(q);

	return((WorkQ *)NULL);
}

/**
* Adds a WorkItem to the end of the WorkQ. If the 
* WorkItem is null, then nothing is
* added.
*
* @param q	the WorkQ to add to
* @param item	the WorkItem to add
*/
void workq_add(WorkQ *q, WorkItem *item) {
	if (q && item) {
	  WorkQEntry *nentry = (WorkQEntry *)malloc(sizeof(WorkQEntry));

	  nentry->item = item;
	  nentry->next = (WorkQEntry *)NULL;

	  if(q->tail) q->tail->next = nentry;			// link new entry into queue
	  q->tail = nentry;
	  if(!q->count) q->head = nentry;			// First entry in queue
	  q->count++;
	}
	return;
}

/**
* Removes an item from the head of the WorkQ. A
* NULL WorkItem pointer is returned if WorkQ is
* empty. Note that the entry for the WorkQ is
* deallocated.
*
* @param q	the WorkQ to remove from
*
* @return the WorkItem at the head of the WorkQ.
*/
WorkItem *workq_remove(WorkQ *q) {
	WorkItem *item = (WorkItem *)NULL;
	WorkQEntry *entry;

	if(q && q->head) {					// Quick test to make sure we have a valid queue
	  entry = q->head;
	  q->head = entry->next;
	  q->count--;
	  if(q->count <= 0) {					// removed the last entry
	    q->tail = q->head;					// should be pointing to null
	    q->count = 0;
	  }

	  item = entry->item;
	  free(entry);
	}
	return(item);
}

/**
* Tests to see if the give WorkQ is empty. A non-zero
* value is returned if this is the case. This includes
* the case that the WorkQ pointer is NULL as well.
*
* @param q	the WorkQ to test
*
* @return non-zero if WorkQ is empty. Zero otherwise.
*/
int workq_empty(WorkQ *q) {
	return(!q || (!q->count && !q->head));
}

/**
* Tests to see if the give WorkQ is full. A non-zero
* value is returned if this is the case. Note that if
* the WorkQ pointer is NULL, or the max field is < 0,
* then it is considered NOT full, and zero is returned.
*
* @param q	the WorkQ to test
*
* @return non-zero if WorkQ is full (count >= max). Zero otherwise.
*/
int workq_full(WorkQ *q) {
	return(q && q->max >= 0 && q->max <= q->count);
}

/**
* Sets the maximum number entries allowed in
* queue. If the given number is set to less than
* zero, then the queue maximum is considered 
* unlimited.If the queue is NULL, nothing is
* done.
*
* @param q	the WorkQ to set
* @param l	the limit to set max to
*/
void workq_set_max(WorkQ *q, int l) {
	if(q) q->max = l;
	return;
}
