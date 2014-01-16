#include <stdio.h>
#include <stdlib.h>
#include "pwt.h"
#include "converse.h"							// needed for MPI communication functions
#include "scheduler.h"							// should include workq and associated functions
#include "manager.h"
#include "worker.h"							// needed for declaration of native work functions

// Internal/Private variables
static Scheduler *dispatch;						// pointer to the primary scheduler
static PerfStat *jobstats;						// pointer to the collected statistics for the job
static int manager_rank;						// hold the rank of the manager.

// Internal/Private routines and functions

/**
* Function to initialize a manager process.
*
* @param o	the options structure holding the global
*		options values and other shared variables
*/
int manager_init(options o){
  manager_rank = o.rank;						// save off manager's rank
  jobstats = perfstat_new();						// initialize the job's statistics structure
  dispatch = scheduler_new(o);						// initialize the main scheduler

  scheduler_update_stopproc(dispatch,&worker_exit);			// set the work function to stop the worker processes
  perfstat_start_time(jobstats);					// start job elapse time - on the off chance the startwork() does not.

  PRINT_MPI_DEBUG("Manager Rank %d: I'm intialized!\n", manager_rank);
  return PWT_SUCCESS;
}

/**
* Routine that runs all of the logic for the manager
* process.
*
* @param o	the options structure holding the global
*		options values and other shared variables
*/
void manager_run(options o){
  int all_done = 0;							// a flag to indicate that all the work is done
  WorkItem *work = (WorkItem*)NULL;					// a pointer to the current work item being processed by the manager
  int probecount = 0;							// count of calls to message_ready()

//GDB_STOP
	// Create first work item from options and start work
  if(!o.startwork || (o.startwork(o,jobstats,dispatch) != PWT_SUCCESS)) {	// Start Work
    printf("Manager Rank %d: Failed to start work!\n", o.rank);
    PWT_IERR_MSG("Manager Rank %d: Failed to start work!\n", o.rank);
    return;
  }

	// Manager Loop - wait for worker messages, then act on it
  while(1) {	
	while(!message_ready(o.rank)) {					// loop to look for message - if no message ...
		int worker_rank;					// idle worker process

		probecount++;
		if(probecount % 3000 == 1) {				// poll debugging
                  PRINT_POLL_DEBUG("Manager Rank %d: Waiting for a message\n", o.rank);
            	}
		printf ("Manager Rank %d: Waiting for a message\n", o.rank);

		// if no message -> send more work out
		if(scheduler_canAssignWork(dispatch)) {			// there is work and we have idle workers ...
		  dispatch->assign_work(dispatch,&work,&worker_rank);	// get next work item
		  send_workitem(work,o.rank,worker_rank);		// send the work item to the worker
		  work = workitem_del(work);				// manager is done with item -> throw work item away
		}
		if((all_done = scheduler_workDone(dispatch)))		// work all done?  we are done waiting for messages
		  break;
		usleep(1);						// give the workers a chance!
	} // end message loop
	if(all_done) break;						// work all done? we are out of here!

	work = receive_workitem(o.rank);				// Receive message from worker
	if(work->manager_run) {						// If manager is to run this item -> then do it
	  work->do_work(work,o);
	  work = workitem_del(work);					// manager is done -> throw work item away
	}
	else {								// Add it to work queue
	  PRINT_MPI_DEBUG("Manager Rank %d: Adding work item from rank %d to work queue #%d\n", o.rank, work->originator,work->qidx);
	  dispatch->schedule_work(dispatch,work,o);
	}
  } // end work loop
  
  if(o.endwork) o.endwork(o,jobstats);					// do any specialized cleanup and reporting
  return; 
}

int manager_fini(void){
  scheduler_stop_processes(dispatch,manager_rank);			// stop all worker processes

  scheduler_del(dispatch);						// clean up scheduler
  jobstats = perfstat_del(jobstats);					// clean up the job's statistics structure

  PRINT_MPI_DEBUG("Manager Rank %d: I'm out of here!\n", manager_rank);
  return PWT_SUCCESS;
}


//
// Work Routines for the Manager - put here because they work on static structures within this file
//

/**
* Routine that indicates to the manager a worker process
* or rank is done with its work.
*
* @param data	A Work Item that contains
*		information about the worker rank
* @param o	the options structure holding the global
*		options values and other shared variables
*/
void manager_workdone(WorkItem *data, struct options o) {
	PRINT_MPI_DEBUG("Manager Rank %d: manager_workdone() Requested from rank %d\n", o.rank, data->originator);
	manager_set_rankidle(data);

	if(workitem_hasPerfStat(data))
	  manager_update_jobperf((PerfStat *)data->workdata);
	return;
}


//
// Utility Routines used by the Manager - put here because they may work on static structures within this file
//

/**
* Updates the Job's Scheduler structure by setting the
* originator's process or rank's entry to idle.
* 
* @param data	A Work Item that contains
*		information about the worker rank
*/
void manager_set_rankidle(WorkItem *data) {
	scheduler_set_processidle(dispatch,data->originator);
	return;
}

/**
* Routine that updates the Job's PerfStat structure.
*
* @param perfdata	a PerfStat structure used to update the
* 			job's stat totals
*/
void manager_update_jobperf(PerfStat *perfdata) {
	if(perfdata)							// make sure we have data to update with
	   jobstats = perfstat_add(jobstats,perfdata);
	return;
}
