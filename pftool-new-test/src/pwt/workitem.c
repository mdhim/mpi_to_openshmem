
#include "workitem.h"

//
// WorkItem functions
//

/**
* Allocates memory and initializes a Work Item.
* Note that the do_work function pointer is
* initialized as null.
*
* @param orig_rank	the rank or process number of
*			of the process creating this
*			item.
*
* @return a WorkItem structure
*/
WorkItem *workitem_new(int orig_rank) {
	WorkItem *item = (WorkItem *)malloc(sizeof(WorkItem));

//	item->do_work = (*workitem_do_t)NULL;
	item->do_work = NULL;
	item->originator = orig_rank;
	item->manager_run = 0;
	item->qidx = 0;					// set to lowest work queue
	item->path[0] = '\0';				// set to empty string

	item->workdata_size = 0;
	item->workdata = (void *)NULL;
	return(item);
}

/**
* Frees the memory associated with a Work Item.
*
* @param item	the item to free
*
* @returns a NULL WorkItem pointer
*/
WorkItem *workitem_del(WorkItem *item) {
	if(item) {
	  if(item->workdata) free(item->workdata);
	  free(item);
	}
	return((WorkItem *)NULL);
}

/**
* A function to return a work item's workdata pointer.
* If the workdata pointer is NULL, then the work
* item does not have data to work on.
*
* @param item		the item to reference
*
* @return the pointer to the item's path buffer
*/
void *workitem_get_work(WorkItem *item) {
	return((item)?item->workdata:NULL);
}

/**
* Update or replaces the do_work function pointer.
* If either parameter is null, nothing is done.
*
* @param item		the item to update
* @param workfunc	the function pointer to update
*			with
*/
void workitem_update_dowork(WorkItem *item, workitem_do_t workfunc) {
	if(item && workfunc)
	  item->do_work = workfunc;
	return;	
}

/**
* Updates or replaces the path with the given string.
*
* @param item		the item to update
* @param newpath	the new path to update with
*/
void workitem_update_path(WorkItem *item, char *newpath) {
	strncpy(item->path,newpath,PATHSIZE_PLUS);
	return;
}

/**
* Update or replaces the originator rank
* If the item is null, nothing is done.
*
* @param item		the item to update
* @param orig_rank	the rank or process number of
*			of the process creating this
*			item.
*/
void workitem_update_originator(WorkItem *item, int orig_rank) {
	if(item) item->originator = orig_rank;
	return;	
}

/**
* Update or replaces the desired queue index.
* If the item is null, nothing is done.
*
* @param item		the item to update
* @param q_idx		the index of the desired
*			work queue to place this
*			item when add to a work queue
*/
void workitem_update_queue(WorkItem *item, int q_idx) {
	if(item) item->qidx = q_idx;
	return;	
}

/**
* Updates or replaces the structure pointed to by
* workdata for the given WorkItem. If item is NULL 
* or buf is NULL, then nothing is done. This is the
* generalized workdata update routine.
*
* @param item	the item to update
* @param buf	the PerfStat structure to
*		update with
* @param size	the size of the structure (in char)
* @param type	the WorkdataType of the structure
*/
void workitem_update_work(WorkItem *item, void *buf, int size) {
	if(item) {
	  if(buf) {
	    if(item->workdata) free(item->workdata);
	    item->workdata = buf;
	    item->workdata_size = size;
	  }
	}
	return;
}

/**
* Sets the manager run flag for the given item.
* This flag tells the manager if it should run
* the do_work() function of the item or not.
*
* @param item		the item to update
* @param flagval	a boolean value (0 or 1)
*/
void workitem_set_managerrun(WorkItem *item, int flagval) {
	if(item) item->manager_run = flagval;
	return;
}

