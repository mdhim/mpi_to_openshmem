#include <stdio.h>
#include <stdlib.h>
#include "pwt.h"
//#include "converse.h"							// needed for MPI comunication functions.
#include "worker.h"
#include "manager.h"							// needed for manager native work calls

// Internal/Private variables

static int all_done = 0;						// flag to indicate that main work loop is done

/**
* Function to initialize a worker process.
*
* @param o	the options structure holding the global
*		options values and other shared variables
*/
int worker_init(options o){
  PRINT_MPI_DEBUG("Worker Rank %d: I am initialized!\n", o.rank);
  return PWT_SUCCESS;
}

/**
* Routine that runs all of the logic for the worker
* process.
*
* @param o	the options structure holding the global
*		options values and other shared variables
*/
void worker_run(options o){
  int probecount = 0;							// count of calls to MPI_Iprobe()
  WorkItem *work;							// the item of work to perform

	// Worker Loop - wait for manager messages, then act on them
  while (!all_done) {
	while(!message_ready(o.rank)) {
		probecount++;
		usleep(1);						// give manager a chance!
		printf("worker::worker_run, waiting for message to be ready, rank: %d\n",o.rank);
		if (probecount >= 100){
		  return;
		}
	} // end message loop
	printf("worker::worker_run, after loop\n");
	//return;
	work = receive_workitem(o.rank);				// Recieve message/work from manager
	printf("worker::worker_run, after receive_workitem\n");
	work->do_work(work,o);						// do the work!
	printf("worker::worker_run, after do_work\n");
	work = workitem_del(work);					// throw work item away.
  } // end work loop
  PRINT_MPI_DEBUG("Worker Rank %d: I am done!\n", o.rank);
  return;
}

int worker_fini(void){
  return PWT_SUCCESS;
}

//
// Command/Communication functions
//

/**
* Routine to tell the manager that work or a task is complete.
* This is a general routine that application logic can use as
* needed. Note that care should be taken when using statically
* allocated structures with WorkItems, since workitem_update_dowork()
* will attempt to free any workdata previously attached to the
* WorkItem, before assigning perf to it.
*
* @param itembuf	a Work Item structure to act as a buffer
* @param perf		a PerfStat structure to pass along to the 
*			manager
* @param o		the options structure holding the global
*			options values and other shared variables
*/
void worker_senddone(WorkItem *itembuf, PerfStat *perf, options o) {
	int target = itembuf->originator;			// the target rank, which should be in the Work Item buffer!

	PRINT_MPI_DEBUG("Worker Rank %d: worker_senddone() called.\n", o.rank);
	workitem_set_managerrun(itembuf,1);
	workitem_update_dowork(itembuf,manager_workdone);
	perfstat_attach(perf,itembuf);

	send_workitem(itembuf,o.rank,target);
	return;
}

/**
* Function to send a request to add work to a work queue.
* Currently the logic of this function blocks until the
* request is accepted. However since this function has
* a return code, that behavior may be redesigned.
*
* @param target		the rank of the target process - 
*			usually the manger process
* @param rque		the index to the desired work queue
* @param o		the options structure holding the global
*			options values and other shared variables
*
* @return non-zero if/when the request is accepted.
*	Zero otherwise.
*/
int worker_sendrequest(int target, int rque, options o) {
	WorkItem reqbuf;					// initial WorkItem buffer that holds the request to add
	WorkRequest wr;						// initialbuffer to work request data
	WorkItem *respbuf = (WorkItem*)NULL;			// pointer to the manager's response WorkItem
	WorkRequest *respwr;					// pointer to the manager's response WorkRequest 
	time_t secs;

	bzero(&reqbuf,sizeof(WorkItem));			// clear static buffer and initialize WorkItem
	workitem_update_queue(&reqbuf,rque);			// specify the requested queue
	workreq_clear(&wr);
	reqbuf.originator = o.rank;
	workreq_attach(&wr,&reqbuf);

	send_workitem(&reqbuf,o.rank,target);			// send initial request
	respbuf = get_workitem(o.rank,target);
	respwr = workitem_get_workreq(respbuf);
	while(workitem_hasWorkRequest(respbuf) &&
	      (secs = workreq_notAccepted(respwr))) {
	  sleep(secs);
	  respbuf->originator = o.rank;				// make sure we have the right originator
	  send_workitem(respbuf,o.rank,target);			// use respbuf to send another request
	  respbuf = workitem_del(respbuf);			// We are now done with the respbuf. We'll get a new one here pretty quick!
	  respbuf = receive_workitem(o.rank);			//   like NOW!
	  respwr = workitem_get_workreq(respbuf);

	  if(workreq_isDeadlocked(respwr))
	    fprintf(stderr,"Worker Rank %d: DeadLocked with Manager Rank %d!\n",o.rank, target);
	}

	if(respbuf) workitem_del(respbuf);			// clean up an respbuf buffer
	return(1);
}
//
// Worker work functions
//

/**
* Routine that sets the all_done flag, causing the
* worker to exit. Makes sure exit call is coming from
* the manager.
*
* @param data	A Work Item that is basically
*		superfulous for this routine
* @param o	the options structure holding the global
*		options values and other shared variables
*/
void worker_exit(WorkItem *data, options o) {
	PRINT_MPI_DEBUG("Worker Rank %d: worker_exit() Requested from rank %d\n", o.rank, data->originator);
	if(data->originator == MANAGER_PROC) all_done = 1;
	return;
}

