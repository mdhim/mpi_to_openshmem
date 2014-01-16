
#ifndef __TREEWALK_H
#define __TREEWALK_H

#include "appoption.h"
#include "../str.h"
#include "fileinfo.h"

//
// Option functions
//

/* Worker tasks */

int treewalk_process_args(AppOptions *twp_o);
int treewalk_process_file(FileInfo *finfo,PerfStat *perf,options o);

/* Manager tasks */

int treewalk_startwork(options o, PerfStat *perf, Scheduler *sched);
void treewalk_endwork(options o, PerfStat *perf);


//
// Work functions
//

/* Worker tasks */

void treewalk_readdir(WorkItem *data, options o);
void treewalk_statpath(WorkItem *data, options o);

/* Manager tasks */

#endif
