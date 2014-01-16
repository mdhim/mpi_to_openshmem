
#include "pathinfo.h"

//
// PathWork functions
//

/**
* Initializes or clears a PathWork buffer. Ideal for
* statically allocated buffers.
*
* @param pkbuf	pointer to a new/repurposed PathWork buffer
*/
void pathwork_clear(PathWork *pkbuf) {
	int i;							// loop index

	bzero(pkbuf,sizeof(PathWork));				// clear out the buffer

	pkbuf->type = _PATHWORK_TYPE_;				// set the type
	for(i=0; i<PATH_BUFFER_MAX; i++)
	   pkbuf->buf[i].type = _PATHINFO_TYPE_;		// set all PathInfo structures to right type
	return;
}

/**
* Creates a new PathWork buffer.
*
* @return a new PathWork buffer
*/
PathWork *pathwork_new() {
	PathWork *newbuf = (PathWork *)malloc(sizeof(PathWork));

	pathwork_clear(newbuf);
	return(newbuf);
}

/**
* Deallocates a PathWork buffer.
*
* @param pkbuf		the buffer to deallocate
*
* @return a NULL PathWork pointer
*/
PathWork *pathwork_del(PathWork *pkbuf) {
	if(pkbuf) free(pkbuf);
	return((PathWork *)NULL);
}

/**
* Routine to add a path to the PathWork buffer. If
* the buffer or the new path is NULL, nothing is
* done.
*
* @param pkbuf		the buffer to add the path to
* @param newpath	the path to add
*/
void pathwork_add_path(PathWork *pkbuf, char *newpath) {
	if(pkbuf && newpath)
	  strncpy(pkbuf->buf[pkbuf->size++].path,newpath,PATHSIZE_PLUS);
	return;
}

/**
* Function to test to see if a PathWork buffer is completely full.
* 
* @param pkbuf		the buffer to test
*
* @return non-zero if all entries in the buffer have paths in them.
*	zero is returned if not. If pkbuf is NULL, then zero is
*	returned.
*/
int pathwork_isFull(PathWork *pkbuf) {
	if(pkbuf) return(pkbuf->size >= PATH_BUFFER_MAX);
	return(0);
}

/**
* Function to test to see if a PathWork buffer is empty. 
* 
* @param pkbuf		the buffer to test
*
* @return non-zero if no entries in the buffer have paths in them.
*	zero is returned if not. If pkbuf is NULL, then
*	non-zero is returned.
*/
int pathwork_isEmpty(PathWork *pkbuf) {
	if(pkbuf) return(pkbuf->size <= 0);
	return(1);
}

//
// WorkItem Support functions
//

/**
* Attach or assign a PathWork structure to a WorkItem.
* If item is NULL or pkbuf is NULL, then nothing is done.
* Uses workitem_update_work().
*
* @param pkbuf	the PathWork structure to
*		update with
* @param item	the WorkItem to update
*/
void pathwork_attach(PathWork *pkbuf, WorkItem *item) {
	workitem_update_work(item,(void *)pkbuf,sizeof(PathWork));
	return;
}

/**
* A function to return a work item's path buffer.
* If the buffer pointer is NULL, then the work
* item does not have a path buffer. Uses
* workitem_get_work().
*
* @param item		the item to reference
*
* @return the pointer to the item's path buffer
*/
PathWork *workitem_get_pathbuffer(WorkItem *item) {
	return((PathWork *)workitem_get_work(item));
}

/**
* A function to test if a work item has an allocated
* PathWork structure.
*
* @param item		the item to test
*
* @return non-zero if a PathWork structure is allocated.
*	zero is returned otherwise, including if the
*	item is NULL.
*/
int workitem_hasPathbuffer(WorkItem *item) {
	if(item) return(item->workdata && ((PathWork *)item->workdata)->type == _PATHWORK_TYPE_);
	return(0);
}
