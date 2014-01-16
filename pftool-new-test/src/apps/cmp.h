
#ifndef __CMP_H
#define __CMP_H

#include "appoption.h"
#include "../str.h"
#include "fileinfo.h"
#include "treewalk.h"

//
// Option functions
//

/* Worker tasks */

int cmp_process_args(AppOptions *twp_o);
int cmp_process_file(FileInfo *finfo,PerfStat *perf,options o);

/* Manager tasks */

int cmp_startwork(options o, PerfStat *perf, Scheduler *sched);
void cmp_endwork(options o, PerfStat *perf);

//
// Work functions
//

/* Worker tasks */

void cmp_compare(WorkItem *data, options o);

/* Manager tasks */

void cmp_workdone(WorkItem *data, struct options o);
void cmp_addchunkfile(WorkItem *data, struct options o);

#endif
