
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

#include "perfstat.h"
#include "workitem.h"						// needed to interface with a WorkItem.

#define MICROS_PER_SECOND ((double)1000000.0)

//
// PerfStat functions
//

/**
* Creates a new PerfStat.
*
* @return a new PerfStat
*/
PerfStat *perfstat_new() {
	PerfStat *ps = (PerfStat *)malloc(sizeof(PerfStat));

	bzero(ps,sizeof(PerfStat));				// initializes all counters and times to zero
	ps->type = _PERFSTAT_TYPE_;				// make sure structure is marked as a PerfStat
	return(ps);
}

/**
* Deallocates a PerfStat. 
*
* @param ps	the PerfStat to deallocate
*
* @return a NULL PerfStat pointer
*/
PerfStat *perfstat_del(PerfStat *ps) {
	if(ps) free(ps);
	return((PerfStat *)NULL);
}

/**
* Increments a byte count in a PerfStat structure
* by the given bcount. If the PerfStat pointer in NULL,
* or idx >= PERF_MAX_SIZES then nothing is 
* done.
*
* @param ps	the PerfStat to increment
* @param idx	the index into the size array
*/
void perfstat_inc_bytes(PerfStat *ps, PerfSizeIdx idx, size_t bcount) {
	if(ps && idx < PERF_MAX_SIZES)
	  ps->sizes[idx] += bcount;
	return;
} 

/**
* Increments a counter in a PerfStat structure
* by one. If the PerfStat pointer in NULL,
* or idx >= PERF_MAX_COUNTERS then nothing is 
* done.
*
* @param ps	the PerfStat to increment
* @param idx	the index into the counter array
*/
void perfstat_inc_counter(PerfStat *ps, PerfCntIdx idx) {
	if(ps && idx < PERF_MAX_COUNTERS)
	  ps->counters[idx]++;
	return;
} 

/**
* Sets a time with the current time in seconds since the
* epoch. If the PerfStat pointer in NULL, or idx >= PERF_MAX_TIMES 
* then nothing is  done.
*
* @param ps	the PerfStat to set
* @param idx	the index into the times array
*/
void perfstat_set_time(PerfStat *ps, PerfTimeIdx idx) {
	if(ps && idx < PERF_MAX_TIMES)
	  gettimeofday(&ps->times[idx],NULL);
	return;
}

/**
* Increments by one the stat counter in a PerfStat
* structure.
*
* @param ps	the PerfStat to increment
*/
void perfstat_inc_stats(PerfStat *ps) {
	perfstat_inc_counter(ps,PERF_STAT_CALLS);
	return;
}

/**
* Increments by one the directory read counter in a PerfStat
* structure.
*
* @param ps	the PerfStat to increment
*/
void perfstat_inc_dirsread(PerfStat *ps) {
	perfstat_inc_counter(ps,PERF_DIRS_READ);
	return;
}

/**
* Sets the start time entry in the times array.
*
* @param ps	the PerfStat to set
*/
void perfstat_start_time(PerfStat *ps) {
	perfstat_set_time(ps,PERF_START_TIME);
	return;
}

/**
* Sets the end time entry in the times array.
*
* @param ps	the PerfStat to set
*/
void perfstat_end_time(PerfStat *ps) {
	perfstat_set_time(ps,PERF_END_TIME);
	return;
}

/**
* Function to compute the elapsed time between the
* start and the end times. The result is in seconds
* and fractions of seconds. If there is no start time
* set, then not computation is done. If there is no
* end time, then the end time is set prior to computing
* the elapsed time.
*
* @param ps	the PerfStat to use
*
* @return the time in seconds between the start and end
*	times of the PerfStat structure. If the start time
*	id not set, then a negative number is returned.
*/
double perfstat_compute_elapsetime(PerfStat *ps) {
	double s,e;							// holds the times in double format

	if(ps->times[PERF_START_TIME].tv_sec == (time_t)0 &&		// no start time
	   ps->times[PERF_START_TIME].tv_usec == (suseconds_t)0)
	  return((double)(-1.0));

	if(ps->times[PERF_END_TIME].tv_sec == (time_t)0 &&		// no end time
	   ps->times[PERF_END_TIME].tv_usec == (suseconds_t)0)
	  perfstat_end_time(ps);

	s = (ps->times[PERF_START_TIME].tv_sec * MICROS_PER_SECOND + ps->times[PERF_START_TIME].tv_usec)/MICROS_PER_SECOND;
	e = (ps->times[PERF_END_TIME].tv_sec * MICROS_PER_SECOND + ps->times[PERF_END_TIME].tv_usec)/MICROS_PER_SECOND;
	return(e-s);
}

/**
* Sets the elapsed time for counters in a PerfStat structure.
* If the PerfStat pointer in NULL, or idx >= PERF_MAX_COUNTERS 
* then nothing is done.
*
* @param ps	the PerfStat to set
* @param idx	the index into the elapcounters array
*/
void perfstat_set_elapcounter(PerfStat *ps, PerfCntIdx idx) {
	if(ps && idx < PERF_MAX_COUNTERS)
	   ps->elapcounters[idx] = perfstat_compute_elapsetime(ps);
	return;
}

/**
* Sets the elapsed time for sizes or byte counts in a PerfStat 
* structure. If the PerfStat pointer in NULL, or idx >= PERF_MAX_COUNTERS 
* then nothing is done.
*
* @param ps	the PerfStat to set
* @param idx	the index into the elapsizes array
*/
void perfstat_set_elapbytes(PerfStat *ps, PerfSizeIdx idx) {
	if(ps && idx < PERF_MAX_SIZES)
	   ps->elapsizes[idx] = perfstat_compute_elapsetime(ps);
	return;
}

/**
* Sets the elapse time for the stat counter in a PerfStat
* structure.
*
* @param ps	the PerfStat to set
*/
void perfstat_elapsed_stats(PerfStat *ps) {
	perfstat_set_elapcounter(ps,PERF_STAT_CALLS);
	return;
}

/**
* Sets the elapse time for the directory read counter in a PerfStat
* structure.
*
* @param ps	the PerfStat to set
*/
void perfstat_elapsed_dirsread(PerfStat *ps) {
	perfstat_set_elapcounter(ps,PERF_DIRS_READ);
	return;
}

/**
* This routine takes two PerfStat structures and adds the
* counters and byte counts, and other fields from one to 
* another. If either PerfStat is NULL, then nothing is
* done.
*
* @param psSum		the PerfStat structure that holds
*			the sums, totals, etc.
* @param psInc		the PerfStat structure that holds
*			the values to increment
*
* @return the updated psSum. Note that if psSum is NULL,
*	then NULL is returned.
*/
PerfStat *perfstat_add(PerfStat *psSum, PerfStat *psInc) {
	if(psSum && psInc) {
	  PerfCntIdx c;						// index for counter array
	  PerfSizeIdx s;					// index for the byte counts array

	  for(c=PERF_DIRS_READ; c<PERF_MAX_COUNTERS; c++) {	// loop over counter array
	     psSum->counters[c] += psInc->counters[c];
	     psSum->elapcounters[c] += psInc->elapcounters[c];
	  }
	  for(s=PERF_BYTES_COPIED; s<PERF_MAX_SIZES; s++) {	// loop over byte counts or sizes array
	     psSum->sizes[s] += psInc->sizes[s];
	     psSum->elapsizes[s] += psInc->elapsizes[s];
	  }
	}
	return(psSum);
}

/**
* Function to return counters array.
*
* @param ps	the PerfStat structure to query
* 
* @return the counters array from the PerfStat structure.
*/
long *perfstat_get_counters(PerfStat *ps) {
	return(ps->counters);
}

/**
* Function to return sizes array.
*
* @param ps	the PerfStat structure to query
* 
* @return the sizes array from the PerfStat structure.
*/
size_t *perfstat_get_bytes(PerfStat *ps) {
	return(ps->sizes);
}

/**
* Function to return elapcounters array.
*
* @param ps	the PerfStat structure to query
* 
* @return the elapcounters array from the PerfStat structure.
*/
double *perfstat_get_elapcounters(PerfStat *ps) {
	return(ps->elapcounters);
}

/**
* Function to return elapsizes array.
*
* @param ps	the PerfStat structure to query
* 
* @return the elapsizes array from the PerfStat structure.
*/
double *perfstat_get_elapbytes(PerfStat *ps) {
	return(ps->elapsizes);
}

/**
* Prints the statistics to stdout. 
*
* @param ps	the PerfStat structure to print
*/
void perfstat_print(PerfStat *ps) {
	if(ps) {
	  double dir_rate = ps->counters[PERF_DIRS_READ]/ps->elapcounters[PERF_DIRS_READ];
	  double stat_rate = ps->counters[PERF_STAT_CALLS]/ps->elapcounters[PERF_STAT_CALLS];
	  double jobtime = perfstat_compute_elapsetime(ps);

	  printf("Total Directories read: %ld  (%12.3f dirs/sec)\n",ps->counters[PERF_DIRS_READ],dir_rate);
	  printf("Total stat() calls: %ld  (%12.3f stats/sec)\n",ps->counters[PERF_STAT_CALLS],stat_rate);
	  printf("Total Files copied: %ld\n",ps->counters[PERF_FILES_COPIED]);
	  printf("Total bytes transferred: %ld\n",ps->sizes[PERF_BYTES_COPIED]);
	  printf("Total time: %12.3f seconds\n",jobtime);
	}
	return;
}

/**
* Prints a time in a timestamp format.
*
* @param ps		the PerfStat structure to print
* @param idx		the index into the times array
* @param timebuf	a buffer to put the timestamp in.
*			If NULL, then a buffer is allocated.
*
* @return the time specified by idx in a timestamp format.
*/
char *perfstat_get_timestamp(PerfStat *ps, PerfTimeIdx idx, char *timebuf) {
	char *buf;

	buf = (timebuf)? timebuf: ((char *)malloc(PERF_TS_LEN));

	if(ps && idx < PERF_MAX_TIMES) {
	  struct tm loctime;

	  localtime_r(&ps->times[idx].tv_sec, &loctime);
	  strftime(buf, PERF_TS_LEN, "%d %b %Y %T", &loctime);
	}
	else
	  strcpy(buf,"No Time Found!");

	return(buf);
}


//
// WorkItem Support functions
//

/**
* Attach or assign a PerfStat structure to a WorkItem.
* If item is NULL or ps is NULL, then nothing is done.
* Uses workitem_update_work().
*
* @param ps	the PerfStat structure to
*		update with
* @param item	the WorkItem to update
*/
void perfstat_attach(PerfStat *ps, WorkItem *item) {
	workitem_update_work(item,(void *)ps,sizeof(PerfStat));
	return;
}

/**
* a function to test if a work item has an allocated
* PerfStat structure.
*
* @param item		the item to test
*
* @return non-zero if a PerfStat structure is allocated.
*	zero is returned otherwise, including if the
*	item is NULL.
*/
int workitem_hasPerfStat(WorkItem *item) {
	if(item) return(item->workdata && ((PerfStat *)item->workdata)->type == _PERFSTAT_TYPE_);
	return(0);
}

