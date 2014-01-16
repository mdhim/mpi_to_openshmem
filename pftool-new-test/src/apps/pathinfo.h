
#ifndef __PATHINFO_H
#define __PATHINFO_H

#include "../pwt/pwt.h"				// needed for definition of WorkItem

#define _PATHINFO_TYPE_	((long)19631111)	// value used to mark structure as a PathInfo
#define _PATHWORK_TYPE_	((long)19631125)	// value used to mark structure as a PathWork
#define PATH_BUFFER_MAX 50			// maximum number of PathInfo structures in a PathWork buffer

/* structure to hold path information */
struct path_info {
	long type;			// holds a value that marks this structure as a PathInfo
	char path[PATHSIZE_PLUS];
};
typedef struct path_info PathInfo;

struct path_workbuffer {
	long type;			// holds a value that marks this structure as a PathWork
	int size;			// size or number of items in buffer
	PathInfo buf[PATH_BUFFER_MAX];	// the buffer of PathInfo structures
};
typedef struct path_workbuffer PathWork;

/* functions to create and manage PathWork buffers */
PathWork *pathwork_new();
PathWork *pathwork_del(PathWork *pkbuf);
void pathwork_init(PathWork *pkbuf);
void pathwork_add_path(PathWork *pkbuf, char *newpath);
void pathwork_clear(PathWork *pkbuf);
int pathwork_isFull(PathWork *pkbuf);
int pathwork_isEmpty(PathWork *pkbuf);

/* WorkItem support functions */
void pathwork_attach(PathWork *pkbuf, WorkItem *item);
PathWork *workitem_get_pathbuffer(WorkItem *item);
int workitem_hasPathbuffer(WorkItem *item);

#endif
