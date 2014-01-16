#ifndef __WORKER_H
#define __WORKER_H

#include "pwt.h"
#include "workitem.h"

/* PWT functions */
int worker_init(options o);
void worker_run(options o);
int worker_fini(void);

/* Native Work functions */
void worker_exit(WorkItem *data, options o);

/* Utility Worker functions */
void worker_senddone(WorkItem *itembuf, PerfStat *perf, options o);
int worker_sendrequest(int target, int rque, options o);

#endif
