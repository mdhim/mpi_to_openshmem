/**
* A structure used to keep track of performance statistics of an
* application.
*/
#ifndef __PERFSTAT_H
#define __PERFSTAT_H

#include <unistd.h>
#include <sys/time.h>

#include "pwt_types.h"

#define PERF_TS_LEN 21
#define _PERFSTAT_TYPE_ ((long)20130214)	// value used to mark structure as a PerfStat

enum perf_counter_idx {				// an enum that defines certain indexes into a PerfStat array that hold counters
     PERF_DIRS_READ = 0,			// number of directories read
     PERF_FILES_COPIED,				// number of files copied
     PERF_FILES_MATCHED,			// number of of positive matches when comparing files
     PERF_STAT_CALLS,				// number of directories, files, and links stated
     PERF_CMP_CALLS,				// number of compare operations
     PERF_MAX_COUNTERS				// special index that is actually the size of the counter array. Should always be LAST enum entry!
};
typedef enum perf_counter_idx PerfCntIdx;

enum perf_size_idx {				// an enum that defines certain indexes into a PerfStat array that holds byte counts
     PERF_BYTES_COPIED = 0,			// number of bytes copied
     PERF_MAX_SIZES				// special index that is actually the size of the byte count array. Should always be LAST enum entry!
};
typedef enum perf_size_idx PerfSizeIdx;

enum perf_time_idx {				// an enum that defines certain indexes into a PerfStat array that holds times
     PERF_START_TIME = 0,			// start time of application/task in seconds since the epoch
     PERF_END_TIME,				// end time of application/task in seconds since the epoch
     PERF_MAX_TIMES				// special index that is actually the size of the times array. Should always be LAST enum entry!
};
typedef enum perf_size_idx PerfTimeIdx;

struct perf_stats {				// a structure to hold statistics used to compute performance
    long type;					// holds a value that marks this structure as a PerfStat
    struct timeval times[PERF_MAX_TIMES];	// array of time in seconds
    size_t sizes[PERF_MAX_SIZES];		// array of byte counts
    double elapsizes[PERF_MAX_SIZES];		// amount of time generating byte counts
    long counters[PERF_MAX_COUNTERS];		// array of counters
    double elapcounters[PERF_MAX_COUNTERS];	// amount of time generating count
};


/* functions to create and manage PerfStats */
PerfStat *perfstat_add(PerfStat *psSum, PerfStat *psInc);
PerfStat *perfstat_new();
PerfStat *perfstat_del(PerfStat *ps);
double perfstat_compute_elapsetime(PerfStat *ps);
double *perfstat_get_elapbytes(PerfStat *ps);
double *perfstat_get_elapcounters(PerfStat *ps);
size_t *perfstat_get_bytes(PerfStat *ps);
long *perfstat_get_counters(PerfStat *ps);
char *perfstat_get_timestamp(PerfStat *ps, PerfTimeIdx idx, char *timebuf);
void perfstat_elapsed_dirsread(PerfStat *ps);
void perfstat_elapsed_stats(PerfStat *ps);
void perfstat_end_time(PerfStat *ps);
void perfstat_inc_bytes(PerfStat *ps, PerfSizeIdx idx, size_t bcount);
void perfstat_inc_counter(PerfStat *ps, PerfCntIdx idx);
void perfstat_inc_dirsread(PerfStat *ps);
void perfstat_inc_stats(PerfStat *ps);
void perfstat_set_elapbytes(PerfStat *ps, PerfSizeIdx idx);
void perfstat_set_elapcounter(PerfStat *ps, PerfCntIdx idx);
void perfstat_set_time(PerfStat *ps, PerfTimeIdx idx);
void perfstat_start_time(PerfStat *ps);
void perfstat_print(PerfStat *ps);

/* WorkItem support functions */
void perfstat_attach(PerfStat *ps, WorkItem *item);
int workitem_hasPerfStat(WorkItem *item);

#endif
