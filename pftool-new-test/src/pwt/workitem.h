
#ifndef __WORKITEM_H
#define __WORKITEM_H

#include "libpwt.h"
#include "pwt_types.h"			// Declaration of the WorkItem and do_work() function type

/* work item structure definition */
struct work_item {
  workitem_do_t   do_work;		// A function that actually does the action/work
  int originator;			// the rank or process number of the process where the item was created
  int manager_run;			// a flag to indicate if the manager process or rank should execute the do_work() of this item
  int qidx;				// queue index of the preferred work queue to put this item in when adding to a work queue
  char path[PATHSIZE_PLUS];		// the initial or primary path entry
  int workdata_size;			// the size of the work data in chars. Used when packing and unpacking.
  void *workdata;			// a pointer to the data used for the WorkItem. Can be a variety of types ...
};

/* functions to create and manage work items */

WorkItem *workitem_new(int orig_rank);
WorkItem * workitem_del(WorkItem *item);
void *workitem_get_work(WorkItem *item);
void workitem_update_dowork(WorkItem *item, workitem_do_t workfunc);
void workitem_update_path(WorkItem *item, char *newpath);
void workitem_update_originator(WorkItem *item, int orig_rank);
void workitem_update_queue(WorkItem *item, int q_idx);
void workitem_update_work(WorkItem *item, void *buf, int size);
void workitem_set_managerrun(WorkItem *item, int flagval);

#endif
