/**
* This file contains the logic to implement a simple treewalk,
* using the Process Worker Type Framework.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

#include "../pwt/pwt.h"
#include "../pwt/manager.h"							// needed for manager utility work calls
#include "../pwt/worker.h"			       				// needed for worker utility work calls
#include "appoption.h"
#include "debug.h"								// apps/debug.h file
#include "pathinfo.h"								// definition of PathWork structure
#include "fileinfo.h"								// definition of FileInfo structure
#include "fchunktbl.h"								// implementation of file chunk table
#include "cmp.h"

// Internal/Private variables
static FchunkTbl *cmp_chunktab;							// an internal table to keep track of file chunks

// Internal/Private routines and functions
void cmp_senddone(WorkItem *itembuf, FileWorkStat *fstat, options o);
void cmp_sendpaths(WorkItem *itembuf, options o);
char *basepath(char *path, char *prefix, char **buf);
size_t compute_transfer_length(FilePair *fpair, options o);
off_t compute_transfer_offset(FilePair *fpair, options o);

//
// Initialization Functions/Routines
//

/**
* Function to process arguments on the command line. Primarily the
* arguments processed are non-option arguments. This processing may
* have an effect on options already set.
*
* @param cp_o	an AppOptions structure
*
* @return Zero is returned if there are issues with processing
* 	the given AppOptions structure. Otherwise non-zero is
* 	returned.
*/
int cmp_process_args(AppOptions *cp_o) {

	cp_o->buffersize = 1048576;						// SHOULD BE A CONFIG PARAMETER!
	cp_o->start_chunking = 104857600;					// SHOULD BE A CONFIG PARAMETER!
	if(strIsBlank(cp_o->start_path) && 
	   strIsBlank(cp_o->dest_path) && cp_o->argc < 2) {			// Check that we have two paths to compare
	  PWT_UERR_MSG("Not enough files or directories to compare!\n");
	  return 0;
	}
	if((!strIsBlank(cp_o->start_path) || !strIsBlank(cp_o->dest_path)) &&
	   cp_o->argc > 1) {							// Another check
	  PWT_UERR_MSG("Too many files or directories to compare!\n");
	  return 0;
	}

	if(strIsBlank(cp_o->start_path)) {					// populate the start path
	  strcpy(cp_o->start_path, cp_o->args[0]);
	  cp_o->args++;								// move the argument array up by one
	  if(!(cp_o->argc--))							// reduce argument count by 1
	    cp_o->args = (char **)NULL;						// make sure don't go off end of args array
	}

	if(strIsBlank(cp_o->dest_path)) {					// populate the dest path
	  strcpy(cp_o->dest_path, cp_o->args[0]);
	  cp_o->args++;								// move the argument array up by one
	  if(!(cp_o->argc--))							// reduce argument count by 1
	    cp_o->args = (char **)NULL;						// make sure don't go off end of args array
	}
	return 1;
}

//
// Routines for the Manager 
//

/**
* Function to initialize and start the first piece of work
* of the compare. This function also initialized the job's
* PerfStat structure, and may do some initial reporting.
*
* This logic will be executed by the manager process.
*
* @param o		the options structure holding the global
*			options values and other shared variables
* @param perf		a PerfStat structure containing performance
*			statistics for the overall job.
* @param sched		the Scheduler sturcture used by the
*			manager. Typically this is a structure
*			that is internal to the manager's logic
*
* @return PWT_SUCCESS if work successfuly started. PWT_FAILURE
*	is returned if not.
*/
int cmp_startwork(options o, PerfStat *perf, Scheduler *sched) {
	int rc = PWT_SUCCESS;							// return code
	int r = 0;								// rank of available worker process
	char tsbuf[PERF_TS_LEN];						// buffer to hold a timestamp
	WorkItem *work = workitem_new(o.rank);					// WorkItem buffer
	AppOptions *cp_o = (AppOptions *)o.app_ops;				// Treewalk options

	cmp_chunktab = fchunktbl_create(((hash_size)17), def_hashfunc);		// initialize file chunk table

	workitem_update_dowork(work, treewalk_statpath);			// first task is to stat the starting path
	workitem_update_path(work, cp_o->start_path);				// set the starting path in the work item
	sched->schedule_work(sched,work,o);

	printf("Job started at: %s\n", perfstat_get_timestamp(perf,PERF_START_TIME,tsbuf));
	work = (WorkItem*)NULL;							// work is now on a work queue - reuse pointer as buffer

	sched->assign_work(sched,&work,&r);					// Start Work
	if(work)								//   there is actual work to do!
	  send_workitem(work,o.rank,r);						//   send item to first available proc
	else
	  rc = PWT_FAILURE;							//   no work - failed to start properly

	work = workitem_del(work);						//   Once sent, manager is done with item -> throw away
	return(rc);
}

/**
* Routine to wrap up any work done - primarily by manager. Also
* report on over all perfromance of job.
*
* This logic will be executed by the manager process.
*
* @param o		the options structure holding the global
*			options values and other shared variables
* @param perf		a PerfStat structure containing performance
*			statistics for the overall job.
*/
void cmp_endwork(options o, PerfStat *perf) {
	char tsbuf[PERF_TS_LEN];						// buffer to hold a timestamp

	fchunktbl_destroy(cmp_chunktab);					// deallocate the file chunk table

	if(perf) {								// compute final report
	  long *counts = perfstat_get_counters(perf);
	  double *count_times = perfstat_get_elapcounters(perf);
	  double d_rate = (count_times[PERF_DIRS_READ] > 0.0)?
				counts[PERF_DIRS_READ]/count_times[PERF_DIRS_READ]:
				(double)(-1.0);
	  double s_rate = (count_times[PERF_STAT_CALLS] > 0.0)?
				counts[PERF_STAT_CALLS]/count_times[PERF_STAT_CALLS]:
				(double)(-1.0);
	  double c_rate = (count_times[PERF_CMP_CALLS] > 0.0)?
				counts[PERF_CMP_CALLS]/count_times[PERF_CMP_CALLS]:
				(double)(-1.0);

	  printf("Total Directories read: %ld  (%12.3f dirs/sec)\n",counts[PERF_DIRS_READ],d_rate);
	  printf("Total stat() calls: %ld  (%12.3f stats/sec)\n",counts[PERF_STAT_CALLS],s_rate);
	  printf("Total compare calls: %ld  (%12.3f compares/sec) - %ld matched\n",counts[PERF_CMP_CALLS],c_rate, counts[PERF_FILES_MATCHED]);
	  printf("Total time: %12.3f seconds\n",perfstat_compute_elapsetime(perf));
	  printf("Job ended at: %s\n", perfstat_get_timestamp(perf,PERF_END_TIME,tsbuf));	// need to be called after perfstat_compute_elapsetime()
	}
	else
	  printf("No data to report!\n");
	return;
}

/**
* This method takes the place of manager_workdone(). It allows for the updating
* of data sturctures used by the compare logic that are contiained in the manager
* rank. Note that this methods needs to do the same thing as manager_workdone().
* Currently it calls manager_set_rankidle() and manager_update_perfdata() to do this.
*
* This logic will be executed by the manager process.
*
* @param data	A Work Item that contains
*		information about the worker rank
* @param o	the options structure holding the global
*		options values and other shared variables
*/
void cmp_workdone(WorkItem *data, struct options o) {
	AppOptions *cp_o = (AppOptions *)o.app_ops;			// compare options

	manager_set_rankidle(data);					// need to update the rank to idle in the process table
	if(workitem_hasFileworkstat(data)) {				// handle compare data, update chunk table and print results of compare
	  FilePair fpair = ((FileWorkStat *)data->workdata)->files;
	  PerfStat perf = ((FileWorkStat *)data->workdata)->perf;
	  int isChunked = (fpair.chunknum >= 0);			// has a chunk number -> file is chunked!

	  if(!fpair.matched) {
	    int notify = 1;						// a flag to see if we should print the mis-match
	    char *fmt = (cp_o->verbose)?"%s DOES NOT MATCH %s\n":"%s %s differs\n";

	    if(isChunked) { 						// if chunked, set up for removal, since we know it does not match
	      if(fchunktbl_update(cmp_chunktab,fpair.src.path,0) < 0)	// If there is no record in chunk table -> don't notify of mis-match
		notify = 0;
	    }
	    if(notify) printf(fmt,fpair.src.path,fpair.dest.path);
	  }
	  else {							// We have a MATCH!
	    int chunks_left = 0;					// by default, there are no chunks to process

	    if(isChunked) {						// file is chunked
	      if((chunks_left = fchunktbl_get(cmp_chunktab,fpair.src.path)) > 0) {	// chunks to process should never be zero at this point.
		chunks_left--;								// decrement the number of chunks to process
		fchunktbl_update(cmp_chunktab,fpair.src.path,chunks_left);		//   - and update
	        PRINT_FILE_DEBUG("Manager Rank %d: cmp_workdone() Updated chunk table entry for %s (chunks_left = %d)\n", o.rank, fpair.src.path, chunks_left);
	      }
	    }
	    if(cp_o->verbose && !chunks_left) 				// print a match if verbose is on and there are no more chunks to processes
	      printf("%s MATCHES %s\n",fpair.src.path,fpair.dest.path);
	  }

	  if(isChunked) {						// clean up chunk table, if needed
	    if(fchunktbl_get(cmp_chunktab,fpair.src.path) == 0)	{	// if chunks to process is 0 -> remove file's entry in chunk table
	      fchunktbl_remove(cmp_chunktab,fpair.src.path);
	      PRINT_FILE_DEBUG("Manager Rank %d: cmp_workdone() Removed chunk table entry for %s\n", o.rank, fpair.src.path);
	    }
	  }
	  manager_update_jobperf(&perf);				// finally, update job's PerfStat structure
	}
	return;
}

/**
* A manager task that adds an entry into the file chunk table.
*
* This logic will be executed by the manager process.
*
* @param data	A Work Item that contains
*		information about the entry to add
* @param o	the options structure holding the global
*		options values and other shared variables
*/
void cmp_addchunkfile(WorkItem *data, struct options o) {
	PRINT_MPI_DEBUG("Manager Rank %d: cmp_addchunkfile() called for Rank %d.\n", o.rank, data->originator);
	if(workitem_hasFilepair(data)) {
	  FilePair *fpair = (FilePair *)data->workdata;

	  PRINT_FILE_DEBUG("Manager Rank %d: cmp_addchunkfile() Inserting chunk table entry for %s\n",o.rank,fpair->src.path);
	  if(fchunktbl_insert(cmp_chunktab,fpair->src.path,fpair->chunknum) < 0)
	    PWT_UERR_MSG("Manager Rank %d: cmp_addchunkfile() Failed insert into chunk table for file [%s]!\n",o.rank,fpair->src.path);
	}
	else
	  PWT_UERR_MSG("Manager Rank %d: cmp_addchunkfile() does not have a WorkItem with a Filepair. File not added to chunk table!\n",o.rank);

	return;
}


//
// Routines for the Worker
//

// Command/Communication functions

/**
* Routine to tell the manager to add an entry to the file chunk
* table.
*
* @param itembuf	a Work Item structure to act as a buffer
* @param o		the options structure holding the global
*			options values and other shared variables,
*			including nprocs, which will be the number
*			chunks for the file.
*/
void cmp_sendchunkfileadd(WorkItem *itembuf, options o) {
	PRINT_MPI_DEBUG("Worker Rank %d: cmp_sendchunkfileadd() called.\n", o.rank);

	if(workitem_hasFilepair(itembuf)) {
	  ((FilePair *)itembuf->workdata)->chunknum = o.nproc;
	  workitem_set_managerrun(itembuf,1);
	  workitem_update_dowork(itembuf,cmp_addchunkfile);

	  send_workitem(itembuf,o.rank,itembuf->originator);
	}
	else
	  PWT_UERR_MSG("Worker Rank %d: cmp_sendchunkfileadd() does not have a WorkItem with a Filepair. Request NOT sent!\n",o.rank);
	return;
}

/**
* Routine to tell the manager that work or a task is complete.
*
* @param itembuf	a Work Item structure to act as a buffer
* @param fstat		a FileWorkStat structure to pass along to the 
*			manager
* @param o		the options structure holding the global
*			options values and other shared variables
*/
void cmp_senddone(WorkItem *itembuf, FileWorkStat *fstat, options o) {
	if(workitem_hasFilepair(itembuf))			// this logic assumes that the FilePair buffer is statically allocated
	   itembuf->workdata = (void *)NULL;			// remove this line if using a dynamically allocated FilePair structure

//	worker_senddone(itembuf,perf,o);
	PRINT_MPI_DEBUG("Worker Rank %d: cmp_senddone() called.\n", o.rank);
	workitem_set_managerrun(itembuf,1);
	workitem_update_dowork(itembuf,cmp_workdone);
	fileworkstat_attach(fstat,itembuf);

	send_workitem(itembuf,o.rank,itembuf->originator);	
	return;
}

/**
* Routine to send a Work Item of a FilePair to the originating process,
* which is typically the manager process. This FilePair is ready for
* comparing.
*
* @param itembuf	a Work Item structure to act as a buffer
* @param o		the options structure holding the global
*			options values and other shared variables
*/
void cmp_sendpaths(WorkItem *itembuf, options o) {
	int target = itembuf->originator;			// the target rank, which should be in the Work Item buffer!

	if(worker_sendrequest(target,1, o)) {
	  PRINT_MPI_DEBUG("Worker Rank %d: cmp_sendpaths() sending FilePair to Rank %d\n", o.rank, target);
	  workitem_set_managerrun(itembuf,0);
	  workitem_update_dowork(itembuf,cmp_compare);
	  workitem_update_queue(itembuf,1);			// give comapre work a higher queue - not necessarily needed

	  send_workitem(itembuf,o.rank,target);
	}
	return;
}

/**
* Function to process a file, based on type of operation being 
* performed. This logic prepares a FilePair for comparing two
* files. It then sends a cmp work request to the manager.
* If the files big enough to be chunked, it will send a cmp
* work request for each chunk.
*
* This logic is run by a worker process
*
* @param infile		a FileInfo structure containing the
*			file name and stat information
* @param perf		a PerfStat structure to be used to
* 			record any statistics resulting from
* 			processing a file
* @param o		the options structure holding the global
*			options values and other shared variables
*
* @return zero is returned if there are no problems process the
*	file. Non-zero is returned if there are!
*/
int cmp_process_file(FileInfo *infile, PerfStat *perf, options o) {
	char dpath[PATHSIZE_PLUS];					// destination path buffer
	FileInfo destfile;						// FileInfo structure for destination file
	FilePair *fpair;						// FilePair pointer
	WorkItem item_buffer;						// a temporary WorkItem buffer
	AppOptions *cp_o = (AppOptions *)o.app_ops;			// compare options
	int staterr = 0;						// holds any error from a stat() call

	if(!infile || strIsBlank(infile->path)) {
	  PWT_UERR_MSG("Worker Rank %d: cmp_process_file() cannot process path. Blank path or no file information\n",o.rank);
	  return(-1);
	}

	bzero(&item_buffer,sizeof(WorkItem));				// clear out the statically allocated WorkItem structure used to send request to the manager
	workitem_update_originator(&item_buffer,MANAGER_PROC);

	if(cp_o->recursive) {						// dest_path is or should be a directory
	  char *base = (char*)NULL;					// temporary buffer to hold the base path of file

	  basepath(infile->path,cp_o->start_path,(char**)&base);	// returns the base path of the file (without the start_path)
	  sprintf(dpath,"%s/%s",cp_o->dest_path,base);
	  if(base) free(base);
	}
	else
	  sprintf(dpath,"%s",cp_o->dest_path);

	fileinfo_init(&destfile,dpath,(struct stat *)NULL);		// inital the destfile structure
	if((staterr = fileinfo_lstat(&destfile))) {			// if non-zero -> stat() call for destination file  had problems!
	  PWT_UERR_MSG("Worker Rank %d: cmp_process_file() failed to stat destination path entry %s (errno = %d)\n", o.rank, destfile.path, staterr);
	  return(-1);
	}
	perfstat_inc_stats(perf);					// increment number of stats. Let calling function worry about perfstat_elapsed_stats() (elapsed stat time)

	fpair = filepair_new(infile,&destfile);				// allocate a file pair
	filepair_attach(fpair,&item_buffer);				// attach file pair to WorkItem buffer

	if(fileinfo_isChunkable(infile,cp_o) && !cp_o->meta_only) {	// Check to see if the file is chunkable - if so and we are doing content compare, chunk it.
	  int i;

	  PRINT_FILE_DEBUG("Worker Rank %d: cmp_process_file() Chunking file %s\n",o.rank, infile->path);
	  cmp_sendchunkfileadd(&item_buffer,o);				// nproc == # of chunks. cmp_sendchunkfileadd() will update buffer before sending to manager
	  for(i=0; i<o.nproc; i++) {					// loop through and send each chunk to the manager
	    fpair->chunknum = i;					//    update the chunknum field before sending ...
	    cmp_sendpaths(&item_buffer,o);
	  }
	}
	else
	  cmp_sendpaths(&item_buffer,o);				// send the file pair to the manager

	free(fpair);							// done with FilePair structure
	return(0);
}

// Work functions

/**
* This function strips the given prefix path off the given path, if the 
* given path is prefixed by the given prefix path. If the buffer is given,
* then the resulting path is put into the buffer. Otherwise the buffer
* is allocated. In any event, a pointer to the buffer holding the resulting
* path is returned.
*
* If the given prefix is not found in the given path, then a copy of the 
* given path is stored into the buffer.
*
* Note the given path or prefix path parameters are NOT altered in any way.
*
* @param path		the path to test
* @param prefix		the prefix path to strip off the path
* @param buf		a buffer to hold the resulting path
*
* @return a pointer to the resulting path.
*/
char *basepath(char *path, char *prefix, char **buf) {
	char *rstr;							// the pointer into path of the end of the prefix

	if(!(*buf)) *buf = (char*)malloc(PATHSIZE_PLUS * sizeof(char));
	bzero(*buf,PATHSIZE_PLUS);

	if(!(rstr = strstr(path,prefix)))
	  rstr = path;
	else
	  rstr += (strlen(prefix) +1);					// get past any trailing "/"
	strncpy(*buf,rstr,PATHSIZE_PLUS-1);
	return(*buf);
}

/**
* Computes the length of the data to transferred or compare. This
* method takes into account that files of certain lengths may be chunked.
*
* Currently, this method is only called when doing a file content compare.
* 
* @param fpair		a FilePair structure that contains the metadata
* 			for the file to process
* @param o		an options structure that contains, amoung other
* 			things, chunk size information
*
* @return the length in bytes to transfer. A negative number is returned
* 	if that length could not be determined
*/
size_t compute_transfer_length(FilePair *fpair, options o) {
	size_t len = fpair->src.st.st_size;				// the computed transfer length

	if(fpair->chunknum >= 0) {					// has a chunk number -> file is chunked!
	  len = (size_t)(fpair->src.st.st_size/o.nproc);		// compute the size of the chunk
	  if((fpair->chunknum +1) == o.nproc)				// if the last chunk -> add any trailing bytes to length
	    len += ((size_t)(fpair->src.st.st_size%o.nproc));
	}
	return(len);
}
 
/**
* Computes the offset within a file to start processing. Files that are
* not chunked, this function returns 0. Otherwise the chunk number is used
* to compute the appropriate offset.
*
* Currently, this method is only called when doing a file content compare.
*
* @param fpair		a FilePair structure that contains the metadata
* 			for the file to process
* @param o		an options structure that contains, amoung other
* 			things, chunk size information
*
* @return the offset to start processing. A negative number is returned
* 	if that offset could not be determined
*/
off_t compute_transfer_offset(FilePair *fpair, options o) {
	off_t offset = 0;						// the computed offset into the file

	if(fpair->chunknum >= 0) {					// has a chunk number -> file is chunked!
	  size_t csize = (size_t)(fpair->src.st.st_size/o.nproc);	// compute the size of the chunk

	  offset = (off_t)(csize * fpair->chunknum);			//  ... now compute the offset into the file
	}
	return(offset);
}

/**
* Compares two paths (files) given in the FilePair structure
* in the WorkItem. 
*
* @param data	A Work Item that contains
*		information about the two files
*		to compare
* @param o	the options structure holding the global
*		options values and other shared variables
*/
void cmp_compare(WorkItem *data, options o) {
	FilePair *filebuf = workitem_get_filepair(data);		// incoming files to compare
	AppOptions *cp_o = (AppOptions *)o.app_ops;			// Compare options
	int orig_rank = data->originator;				// the originator of the work item
	PerfStat *perf = perfstat_new();				// a PerfStat structure to keep track of stats.
	FileWorkStat filestat;						// a temporary FileWorkStat buffer
	WorkItem item_buffer;						// a temporary WorkItem buffer
	int err = 0;							// a flag to indicate if an error occurred
//	int i;

	PRINT_MPI_DEBUG("Worker Rank %d: cmp_compare() Requested from rank %d\n", o.rank, data->originator);
	bzero(&item_buffer,sizeof(WorkItem));				// clear out the statically allocated WorkItem structure used to send request to the manager
	workitem_update_originator(&item_buffer,orig_rank);		// make sure we send any work items back to the manager - or where ever

	perfstat_start_time(perf);					// set start time
	if(filebuf->dest.exists < 0) {					// if dest exists flag < 0 -> no stat structure for dest file
	   PWT_UERR_MSG("Worker Rank %d: cmp_compare() Stat buffer for destination path entry %s is empty!\n", o.rank, filebuf->dest.path);
	   err = 1;
	}

	perfstat_inc_counter(perf,PERF_CMP_CALLS);			// increment the comparison calls
	if(filebuf->dest.exists) {					// we have a file to compare ...
	  int match_size = 						// Compare files sizes
			(filebuf->src.st.st_size == filebuf->dest.st.st_size);
	  int match_meta =  						// Compare meta data - which includes looking at mtimes
			(match_size && filebuf->src.st.st_mtime == filebuf->dest.st.st_mtime);

	  if(match_size && !cp_o->meta_only) {				// do file content comparison
// If content option is selected, compare file contents
	    int sfd = open(filebuf->src.path, O_RDONLY);
	    int dfd = open(filebuf->dest.path, O_RDONLY);

	    if(sfd > 0 && dfd > 0) {					// successfully opened the 2 files
	      char *sbuf, *dbuf;					// buffers for the src and dest files
	      size_t completed = 0;					// # of bytes that have been compared
	      size_t bufsize = cp_o->buffersize;			// the size of the buffer used in the compare
	      size_t length = compute_transfer_length(filebuf,o);
	      off_t offset = compute_transfer_offset(filebuf,o);
	      int no_match = 0;						// flag to indicate that there is "no match" with files. If set -> files do NOT match

	      sbuf = (char *)malloc(bufsize *sizeof(char));
	      dbuf = (char *)malloc(bufsize *sizeof(char));
	      while(completed < length && !err && !no_match) {		// loop to compare contents. Loop while there are bytes to compare and no read errors and bytes are matching
		size_t rbytes;						// number of bytes read

		bzero(sbuf,bufsize); bzero(sbuf,bufsize);
		if((length - completed) < bufsize)			// handle any trailing bytes, when bytes left to compare < bufsize
		  bufsize = length - completed;
		if((rbytes = pread(sfd, sbuf, bufsize, completed+offset)) != bufsize) {
	      	  PWT_UERR_MSG("Worker Rank %d: Failed to read %zd bytes from %s. bytes read = %zd (errno = %d)\n",
				o.rank, bufsize, filebuf->src.path, rbytes, errno);
		  err = 1;
		  continue;
		}
		if((rbytes = pread(dfd, dbuf, bufsize, completed+offset)) != bufsize) {
	      	  PWT_UERR_MSG("Worker Rank %d: Failed to read %zd bytes from %s. bytes read = %zd (errno = %d)\n",
				o.rank, bufsize, filebuf->dest.path, rbytes, errno);
		  err = 1;
		  continue;
		}

		no_match = memcmp(sbuf,dbuf,bufsize); 
		completed += bufsize;					// increment completed
	      } // End of compare loop

	      free(sbuf); free(dbuf);
	      filebuf->matched = (!no_match);				// set the match flag. Value would be opposite no_match flag, which was set in the compare loop.
	    }
	    else 
	      PWT_UERR_MSG("Worker Rank %d: Failed to open one or more files for compare. src,fd = (%s, %d), dest,fd = (%s, %d) (errno = %d)\n",
				o.rank, filebuf->src.path, sfd, filebuf->dest.path, dfd, errno);

	    if(sfd > 0) close(sfd);
	    if(dfd > 0) close(dfd);
	  } // End of content match logic
	  else
	    filebuf->matched = match_meta;				// we are only matching the meta data

	  if(filebuf->matched)
            perfstat_inc_counter(perf,PERF_FILES_MATCHED);		// increment the matched files, if files do match!
	} // End compare logic

	perfstat_end_time(perf);					// set end time

// if this compare is part of a copy or transfer, add logic at this point to send the file pair back to manager rank, based on match

	perfstat_set_elapcounter(perf,PERF_CMP_CALLS);			// compute the elapsed time for compare calls
	fileworkstat_init(&filestat,filebuf,perf);			// prepare to send the data for a workdone message
	cmp_senddone(&item_buffer,&filestat,o);				// let manager know work is done
	perf = perfstat_del(perf);					// throw away perfstat structure
	return;
}
