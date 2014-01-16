#ifndef __MANAGER_H
#define __MANAGER_H

#include "pwt.h"
#include "workitem.h"

/* PWT functions */
int manager_init(options o);
void manager_run(options o);
int manager_fini(void);

/* Native Work functions */
void manager_workdone(WorkItem *data, options o);

/* Utilities */
void manager_set_rankidle(WorkItem *data);
void manager_update_jobperf(PerfStat *perfdata);

#endif
