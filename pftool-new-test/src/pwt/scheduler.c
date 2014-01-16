
#include "pwt.h"
#include "scheduler.h"
#include "converse.h"								// needed for scheduler_stop_prcoesses()

// Internal/Private routines and functions
int *processing_initialize(int nproc);
int processing_get_idle(int *proc_status, int sidx, int nidx);
void processing_set_idle(int *proc_status, int proc_num);
void processing_set_active(int *proc_status, int proc_num);
int processing_complete(int *proc_status, int nproc);
void processing_destroy(int *proc_status);


//
// Scheduler management functions
//

/**
* Allocates memory and initializes a Scheduler
* Note that the schedule_work and assign_work 
* function pointers are initialized to default
* functions, if the options structure does not
* have any function pointers to them.
*
* @param o	the options structure holding the global
*		options values and other shared variables
*
* @return a Scheduler structure
*/
Scheduler *scheduler_new(struct options o) {
	Scheduler *sched = (Scheduler *)malloc(sizeof(Scheduler));
	int i;

	bzero(sched,sizeof(Scheduler));					// initialize the structure

	scheduler_update_assignwork(sched,(o.assign_work?o.assign_work:&scheduler_getwork));
	scheduler_update_schedulework(sched,(o.schedule_work?o.schedule_work:&scheduler_addwork));
	sched->process_count = o.nproc;					// set number of processess
	sched->workq_count = o.nqueues;					// set number of work queues
	sched->processes = processing_initialize(sched->process_count);
	processing_set_active(sched->processes, o.rank);		// set the calling rank as active

	if(!sched->workq_count) sched->workq_count = 1;			// will always have at least one work queue!
	sched->workq = (WorkQ **)malloc(sched->workq_count * sizeof(WorkQ *));	// allocate the work queue array
	for(i=0; i<sched->workq_count; i++)
	   sched->workq[i] = workq_new();

	return(sched);
}

/**
* Frees the memory associated with a Scheduler.
*
* @param item	the item to free
*
* @returns a NULL Scheduler pointer
*/
Scheduler *scheduler_del(Scheduler *sched) {
	int i;

	if(sched) {
	  free(sched->processes);
	  for(i=0; i<sched->workq_count; i++)
	     sched->workq[i] = workq_del(sched->workq[i]);
	  free(sched);
	}
	return((Scheduler *)NULL);
}

/**
* Routine to mark a process in the scheduler's process
* array as idle.
*
* @param sched		the scheduler to update
* @param proc_num	the worker process number or rank
*			to update
*/
void scheduler_set_processidle(Scheduler *sched, int proc_num) {
	if(sched)
	  processing_set_idle(sched->processes,proc_num);
	return;
}

/**
* Update or replaces the schedule_work function pointer.
* If either parameter is null, nothing is done.
*
* @param sched		the scheduler to update
* @param schedfunc	the function pointer to update
*			with
*/
void scheduler_update_schedulework(Scheduler *sched, scheduler_schedule_t schedfunc) {
	if(sched && schedfunc)
	   sched->schedule_work = schedfunc;
	return;
}

/**
* Update or replaces the stop_proc function pointer.
* If either parameter is null, nothing is done.
*
* @param sched		the scheduler to update
* @param stopfunc	the function pointer to update
*			with
*/
void scheduler_update_stopproc(Scheduler *sched, workitem_do_t stopfunc) {
	if(sched && stopfunc)
	   sched->stop_proc = stopfunc;
	return;
}

/**
* Update or replaces the assign_work function pointer.
* If either parameter is null, nothing is done.
*
* @param sched		the scheduler to update
* @param schedfunc	the function pointer to update
*			with
*/
void scheduler_update_assignwork(Scheduler *sched, scheduler_assign_t schedfunc) {
	if(sched && schedfunc)
	   sched->assign_work = schedfunc;
	return;
}

/**
* Routine to send an exit work item to all processes in the process
* array for this scheduler.
*
* @param sched		the scheduler to update
* @param src_rank	the calling process or rank
*/
void scheduler_stop_processes(Scheduler *sched, int src_rank) {
	WorkItem item_buffer;					// a WorkItem buffer to use
	int i;							// loop counter

	bzero(&item_buffer,sizeof(WorkItem));			// clear out the statically allocated WorkItem structure used to send request to the worker
	workitem_update_originator(&item_buffer,src_rank);
	workitem_update_dowork(&item_buffer,sched->stop_proc);

	for(i=0; i<sched->process_count; i++)			// send the stop command to each of the processes
	   if( i != src_rank)					// ... but not to the calling proceess!
	     send_workitem(&item_buffer,src_rank,i);
    return;
}

/**
* This function determines if a scheduler can assign work to
* do. The two conditions that need to be met in order for this
* to be true is:
*	1. There are WorkItems in one or more of the scheduler's work queues
*	2. There are one or more idle worker processes
*
* @param sched		the scheduler to test
*
* @return non-zero if work can be done. Zero otherwise
*/
int scheduler_canAssignWork(Scheduler *sched) {
	int i;
	int canWork = 0;				// a flag indicating that work can be assigned

	if(sched) {
	  for(i = 0; i<sched->workq_count; i++)
	    if(!workq_empty(sched->workq[i])) {
	      canWork = 1;
	      break;
	    }
	  if(canWork)					// now test for idle processes
	    canWork = (processing_get_idle(sched->processes,0,sched->process_count) >= 0);
	}
	return(canWork);
}

/**
* This function determines if all the work assigned to a
* scheduler is done. The two conditions that need to be met
* in order for this to be true is:
*	1. There are no WorkItems in all of the scheduler's work queues
*	2. All processes, but the calling process (i.e. this process) is
*	   marked as idle
*
* @param sched		the scheduler to test
*
* @return non-zero if work is done. Zero otherwise
*/
int scheduler_workDone(Scheduler *sched) {
	int i;
	int isDone = 1;					// a flag indicating that all work is done

	if(sched) {
	  for(i = 0; i<sched->workq_count; i++)
	    if(!workq_empty(sched->workq[i])) {
	      isDone = 0;
	      break;
	    }
	  if(isDone)					// now test that all processes are idle
	    isDone = processing_complete(sched->processes,sched->process_count);
	}
	return(isDone);
}

//
// Scheduler task functions
//

/**
* Routine to add work to a work queue in the scheduler.
*
* @param sched		the Scheduler to add work to
* @param item		the WorkItem to add
* @param o		the options structure holding the global
*			options values and other shared variables
*/
void scheduler_addwork(Scheduler *sched, WorkItem *item, options o) {
	int idx = item->qidx;					// index if the work queue to add to

	if(idx >= sched->workq_count)				// if item's index > # of work queues -> use the highest queue
	  idx = sched->workq_count -1;
	if(workitem_hasWorkRequest(item)) 			// worker sent a request first
	  scheduler_ackwork(sched,item,o);			//    handle request, then add to queue
	else {
	  PRINT_SCHED_DEBUG("Manager Rank %d: scheduler_addwork() Adding work item from rank %d to work queue #%d\n", 
					o.rank, item->originator, idx);
	  workq_add(sched->workq[idx], item);			// simply and dangerously add it to queue
	}

	return;
}

/**
* Routine to add work to a work queue in the scheduler, provided
* there is room in the work queue. This form of the function requires
* a worker process to request that work be added to a work queue, 
* prior to sending the actual work. This routine will accept or
* deny, based on resources in the queue.
*
* @param sched		the Scheduler to add work to
* @param item		the WorkItem to add
* @param o		the options structure holding the global
*			options values and other shared variables
*/
void scheduler_ackwork(Scheduler *sched, WorkItem *item, options o) {
	int idx = item->qidx;					// index if the work queue to add to

	if(idx >= sched->workq_count)				// if item's index > # of work queues -> use the highest queue
	  idx = sched->workq_count -1;

	if(workitem_hasWorkRequest(item)) {			// can handle this item
	  WorkRequest *request = workitem_get_workreq(item);	// a request to add work to a queue
	  WorkItem *newwork;					// a point holding the new work to be added
	  int worker_rank = item->originator;
	  int isFull = workq_full(sched->workq[idx]);		// flag to indicate if work queue is full

	  if(isFull)
	    workreq_deny(request);
  	  else
	    workreq_accept(request);
	  PRINT_SCHED_DEBUG("Manager Rank %d: scheduler_ackwork() Work request from rank %d is %s\n",
					o.rank, item->originator, (request->sleep_seconds?"DENIED":"accepted"));
	  send_workitem(item,o.rank,worker_rank);		// send an acknowledgement to worker process
	  if(!isFull) {						// if request accepted
	    newwork = get_workitem(o.rank,worker_rank);

	    PRINT_SCHED_DEBUG("Manager Rank %d: scheduler_ackwork() Adding work item from rank %d to work queue #%d\n", 
					o.rank, newwork->originator, idx);
	    workq_add(sched->workq[idx], newwork);		// add new work to queue
	  }
	  item = workitem_del(item);				// free the original work item holding the WorkRequest
	} // end handling request

	return;
}

/**
* Routine to return work and a process to run it on. The scheduler
* starts with the highest indexed work queue, and returns work from that
* first. It works its way down in the queues. This means that the higher
* the queue index, the higher priority the work item.
*
* @param sched		the Scheduler to retreive work to
* @param item		a pointer to a WorkItem buffer. This 
*			is an OUT parameter
* @param rank		a pointer to the program number or rank
*			of the worker process designated to
*			do the selected WorkItem. This is
*			an OUT parameter
*/
void scheduler_getwork(Scheduler *sched, WorkItem **item, int *rank) {
	int i;
	int idle_proc = processing_get_idle(sched->processes,0,sched->process_count);
	
	*item = (WorkItem *)NULL;					// initialize return values
	*rank = -1;

	if(idle_proc >= 0) {						// We have an available process to do the work

	  for(i = sched->workq_count-1; i >= 0; i--)
	     if(!workq_empty(sched->workq[i])) {
	       *item = workq_remove(sched->workq[i]);
	       if(*item) break;
	     }

	  if(*item) {							// if we have a Work Item -> mark selected process active
	    processing_set_active(sched->processes,idle_proc);
	    *rank = idle_proc;
	  }
	  PRINT_SCHED_DEBUG("Manager Rank %d: scheduler_getwork() Removing work item from work queue #%d and assigning it to rank %d\n", 
					0, i, *rank);
	} // end valid proc test
	return;
}

//
// Worker Process table utility functions
//

/**
* Function to initalize an array to hold the 
* status of the worker processes.
*
* @param nproc		the number of worker processes
*
* @return an array to hold worker parocess
*	status information
*/
int *processing_initialize(int nproc) {
    int i;
    int *status_array = malloc(nproc * sizeof(int));

    for (i = 0; i < nproc; i++)
       status_array[i] = 0;
    return(status_array);
}

/**
* Function to return the program number or rank
* of an idle worker process with in a given range
* of program numbers.
*
* @param proc_status	the array holding worker process
*			status
* @param sidx		the startng index to check 
* @param nidx		the number of indexes to look at
*			for an idle process
*
* @return the first number (index) in the status array that indicates
*	it is idle. If no process is idle, a number < 0
*	is returned.
*/
int processing_get_idle(int *proc_status, int sidx, int nidx) {
    int eidx = sidx + nidx;				// nidx is a length eidx is the actual exclusive end index
    int i;

    for(i = sidx; i < eidx; i++)
       if(!proc_status[i]) return i;
    return(-1); 
}

/**
* Routine to set a worker process status as active.
*
* @param proc_status	the array holding worker process
*			status
* @param proc_num	the worker process number or rank
*			to update
*/
void processing_set_active(int *proc_status, int proc_num) {
    proc_status[proc_num] = 1;
    return;
}

/**
* Routine to set a worker process status as idle.
*
* @param proc_status	the array holding worker process
*			status
* @param proc_num	the worker process number or rank
*			to update
*/
void processing_set_idle(int *proc_status, int proc_num) {
    proc_status[proc_num] = 0;
    return;
}

/**
* Function to look at all the worker processes and
* see if they are idle or not. This function uses
* an array to keep track. If there is only one 
* process active, it is assumed to be the entry for
* the calling process, and therefore is ignored
*
* @param proc_status	the array holding worker process
*			status
* @param nproc		the number of worker processes
*
* @returns non-zero is returned if all worker processes are idle. Otherwise
*	zero is returned.
*/
int processing_complete(int *proc_status, int nproc) {
    int i;
    int count = 0;

    for (i = 0; i < nproc; i++)
        if (proc_status[i] == 1) count++;
    return(count <= 1);
}

/**
* Routine to free an array holding the statuses of
* worker processes.
*
* @param proc_status	the array holding worker process
*/
void processing_destroy(int *proc_status) {
     if(proc_status) free(proc_status);
     return;
}
