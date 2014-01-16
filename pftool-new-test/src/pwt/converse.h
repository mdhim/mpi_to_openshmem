#ifndef __CONVERSE_H
#define __CONVERSE_H

#include "workitem.h"

void send_workitem(WorkItem *item, int source_rank, int target_rank);
WorkItem *get_workitem(int local_rank, int remote_rank);
WorkItem *receive_workitem(int local_rank);
int message_ready(int local_rank);

#endif
