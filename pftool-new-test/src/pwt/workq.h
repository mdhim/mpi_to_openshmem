
#ifndef __WORKQ_H
#define __WORKQ_H

#include "pwt_types.h"

/* Queue to hold work for PFTOOL */
struct work_q_entry {
  WorkItem *item;			// the work item
  struct work_q_entry *next;		// next entry in the queue
};
typedef struct work_q_entry WorkQEntry;

struct work_q {
  int count;				// number of entries in the queue
  int max;				// maximum number of entries allowed in queue. < 0 means unlimited
  WorkQEntry *head;			// first entry in queue
  WorkQEntry *tail;			// last entry in queue
};
typedef struct work_q WorkQ;

/* functions to create and manage a work queue */
WorkQ *workq_new();
WorkQ *workq_del(WorkQ *q);
void workq_add(WorkQ *q, WorkItem *item);
WorkItem *workq_remove(WorkQ *q);
int workq_empty(WorkQ *q);
int workq_full(WorkQ *q);
void workq_set_max(WorkQ *q, int l);

#endif
