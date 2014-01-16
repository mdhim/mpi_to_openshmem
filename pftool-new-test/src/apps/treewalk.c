/**
* This file contains the logic to implement a simple treewalk,
* using the Process Worker Type Framework.
*/

#include <time.h>

#include "../pwt/pwt.h"
#include "../pwt/worker.h"								// needed for worker utility work calls
#include "appoption.h"
#include "pathinfo.h"								// definition of PathWork structure
#include "fileinfo.h"								// definition of FileInfo structure
#include "treewalk.h"

// Internal/Private routines and functions
void tw_senddirs(WorkItem *itembuf, options o);
void tw_senddone(WorkItem *itembuf, PerfStat *perf, options o);
void tw_sendpaths(WorkItem *itembuf, options o);
char *printmode (mode_t aflag, char *buf);

//
// Initialization Functions/Routines
//

/**
* Function to process arguments on the command line. Primarily the
* arguments processed are non-option arguments. This processing may
* have an effect on options already set.
*
* @param twp_o	an AppOptions structure
*
* @return Zero is returned if there are issues with processing
* 	the given AppOptions structure. Otherwise non-zero is
* 	returned.
*/
int treewalk_process_args(AppOptions *twp_o) {

	if(strIsBlank(twp_o->start_path) && !twp_o->argc) {			// Check that we have root dir to walk
	  fprintf(stderr,"No tree given to walk!\n");
	  return 0;
	}

	if(strIsBlank(twp_o->start_path)) {
	  strcpy(twp_o->start_path, twp_o->args[0]);
	  twp_o->args++;							// move the argument array up by one
	  if(!(twp_o->argc--))							// reduce argument count by 1
	    twp_o->args = (char **)NULL;					// make sure don't go off end of args array
	}
	return 1;
}

//
// Routines for the Manager 
//

/**
* Function to initialize and start the first piece of work
* of the treewalk. This function also initialized the job's
* PerfStat structure, and may do some initial reporting.
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
int treewalk_startwork(options o, PerfStat *perf, Scheduler *sched) {
	int rc = PWT_SUCCESS;							// return code
	int i;									// loop index
	int r = 0;								// rank of available worker process
	char tsbuf[PERF_TS_LEN];						// buffer to hold a timestamp
	WorkItem *work = workitem_new(o.rank);					// WorkItem buffer
	AppOptions *twp_o = (AppOptions *)o.app_ops;				// Treewalk options

	workitem_update_dowork(work, treewalk_statpath);			// first task is to stat the starting path
	workitem_update_path(work, twp_o->start_path);				// set the starting path in the work item
	sched->schedule_work(sched,work,o);

	if(twp_o->args && twp_o->argc) 						// check for non-option arguments
	  for(i=0; i<twp_o->argc; i++) {
	     work = workitem_new(o.rank);

	     workitem_update_dowork(work, treewalk_statpath);			// task is to stat the path
	     workitem_update_path(work, twp_o->args[i]);
	     sched->schedule_work(sched,work,o);
	  }

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
* @param o		the options structure holding the global
*			options values and other shared variables
* @param perf		a PerfStat structure containing performance
*			statistics for the overall job.
*/
void treewalk_endwork(options o, PerfStat *perf) {
	char tsbuf[PERF_TS_LEN];						// buffer to hold a timestamp

	if(perf) {								// compute final report
	  long *counts = perfstat_get_counters(perf);
	  double *count_times = perfstat_get_elapcounters(perf);
	  double d_rate = (count_times[PERF_DIRS_READ] > 0.0)?
				counts[PERF_DIRS_READ]/count_times[PERF_DIRS_READ]:
				(double)(-1.0);
	  double s_rate = (count_times[PERF_STAT_CALLS] > 0.0)?
				counts[PERF_STAT_CALLS]/count_times[PERF_STAT_CALLS]:
				(double)(-1.0);

	  printf("Total Directories read: %ld  (%12.3f dirs/sec)\n",counts[PERF_DIRS_READ],d_rate);
	  printf("Total stat() calls: %ld  (%12.3f stats/sec)\n",counts[PERF_STAT_CALLS],s_rate);
	  printf("Total time: %12.3f seconds\n",perfstat_compute_elapsetime(perf));
	  printf("Job ended at: %s\n", perfstat_get_timestamp(perf,PERF_END_TIME,tsbuf));	// need to be called after perfstat_compute_elapsetime()
	}
	else
	  printf("No data to report!\n");
	return;
}

//
// Routines for the Worker
//

// Command/Communication functions

/**
* Routine to send a Work Item of directories to the originating process,
* which is typically the manager process. Note that a PathWork buffer
* is cleared if the work item has one.
*
* @param itembuf	a Work Item structure to act as a buffer
* @param o		the options structure holding the global
*			options values and other shared variables
*/
void tw_senddirs(WorkItem *itembuf, options o) {
	int target = itembuf->originator;			// the target rank, which should be in the Work Item buffer!

	if(worker_sendrequest(target,0,o)) {
	  PRINT_MPI_DEBUG("Worker Rank %d: tw_senddirs() sending %d directories to Rank %d\n", o.rank, ((itembuf->workdata)?((PathWork *)itembuf->workdata)->size:1), target);
  	  workitem_set_managerrun(itembuf,0);
	  workitem_update_dowork(itembuf,treewalk_readdir);

	  send_workitem(itembuf,o.rank,target);
	  if(workitem_hasPathbuffer(itembuf))			// if a PathWork buffer was used -> clear it. 
	    pathwork_clear((PathWork *)itembuf->workdata);
	}
	return;
}

/**
* Routine to tell the manager that work or a task is complete.
*
* @param itembuf	a Work Item structure to act as a buffer
* @param perf		a PerfStat structure to pass along to the 
*			manager
* @param o		the options structure holding the global
*			options values and other shared variables
*/
void tw_senddone(WorkItem *itembuf, PerfStat *perf, options o) {
	if(workitem_hasPathbuffer(itembuf))			// this logic assumes that the PathWork buffer is statically allocated
	   itembuf->workdata = (void *)NULL;			// remove this line if using a dynamically allocated PathWork structure

	worker_senddone(itembuf,perf,o);
	return;
}

/**
* Routine to send a Work Item of paths to the originating process,
* which is typically the manager process. These paths are ready for
* stat-ing.
*
* @param itembuf	a Work Item structure to act as a buffer
* @param o		the options structure holding the global
*			options values and other shared variables
*/
void tw_sendpaths(WorkItem *itembuf, options o) {
	int target = itembuf->originator;			// the target rank, which should be in the Work Item buffer!

	if(worker_sendrequest(target,0,o)) {
	  PRINT_MPI_DEBUG("Worker Rank %d: tw_senddirs() sending %d directories to Rank %d\n", o.rank, ((itembuf->workdata)?((PathWork *)itembuf->workdata)->size:1), target);
	  workitem_set_managerrun(itembuf,0);
	  workitem_update_dowork(itembuf,treewalk_statpath);

	  send_workitem(itembuf,o.rank,target);
	  if(workitem_hasPathbuffer(itembuf))			// if a PathWork buffer was used -> clear it. 
	    pathwork_clear((PathWork *)itembuf->workdata);
	}
	return;
}

/**
* Function to process a file, based on type of operation being 
* performed. By default, this prints the path. Stat information 
* for the file may be printed if the verbose option is turned 
* on. Output from this function can be turned off with the quiet
* option. Then only statistics are reported by the treewalk.
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
int treewalk_process_file(FileInfo *infile, PerfStat *perf, options o) {
	AppOptions *twp_o = (AppOptions *)o.app_ops;			// Treewalk options

	if(twp_o->quiet) return(0);					// don't want any output, so simply return

	if(!infile || strIsBlank(infile->path)) {
	  fprintf(stderr,"Worker Rank %d: treewalk_process_file() cannot print path. Blank path or no file information\n",o.rank);
	  return(-1);
	}

	if(!twp_o->verbose)						// No verbose -> just want the path
	  printf("%s\n",infile->path);
	else {								// stat info in ls-like format
	  if(infile->exists < 0)					// if exists flag < 0  -> no stat structure
	    printf("[  no stat information! ] %s\n", infile->path);
	  else {							// print the whole enchilada
	    struct tm sttm;
    	    char modebuf[15], timebuf[30];

	    printmode(infile->st.st_mode, modebuf);
 	    memcpy(&sttm, localtime(&infile->st.st_mtime), sizeof(sttm));
	    strftime(timebuf, sizeof(timebuf), "%a %b %d %Y %T", &sttm);

	    printf("%s %6d %6d %21zd %s %s\n", 
			modebuf, infile->st.st_uid, infile->st.st_gid, (size_t) infile->st.st_size, timebuf, infile->path);
	  }
	}
	return(0);
}

/**
* Prints the mode from a stat structure in an "ls-like format".
*
* @param aflag		raw access bits
* @param buf		a character buffer to put
*			resulting string in.
*
* @return a pointer to buf
*/
char *printmode (mode_t aflag, char *buf) {
    // print the mode in a regular 'pretty' format
    static int m0[] = { 1, S_IREAD >> 0, 'r', '-' };
    static int m1[] = { 1, S_IWRITE >> 0, 'w', '-' };
    static int m2[] = { 3, S_ISUID | S_IEXEC, 's', S_IEXEC, 'x', S_ISUID, 'S', '-' };
    static int m3[] = { 1, S_IREAD >> 3, 'r', '-' };
    static int m4[] = { 1, S_IWRITE >> 3, 'w', '-' };
    static int m5[] = { 3, S_ISGID | (S_IEXEC >> 3), 's',
                        S_IEXEC >> 3, 'x', S_ISGID, 'S', '-'
                      };
    static int m6[] = { 1, S_IREAD >> 6, 'r', '-' };
    static int m7[] = { 1, S_IWRITE >> 6, 'w', '-' };
    static int m8[] = { 3, S_ISVTX | (S_IEXEC >> 6), 't', S_IEXEC >> 6, 'x', S_ISVTX, 'T', '-' };
    static int *m[] = { m0, m1, m2, m3, m4, m5, m6, m7, m8 };
    int i, j, n;
    int *p = (int *) 1;;
    buf[0] = S_ISREG (aflag) ? '-' : S_ISDIR (aflag) ? 'd' : S_ISLNK (aflag) ? 'l' : S_ISFIFO (aflag) ? 'p' : S_ISCHR (aflag) ? 'c' : S_ISBLK (aflag) ? 'b' : S_ISSOCK (aflag) ? 's' : '?';
    for (i = 0; i <= 8; i++) {
        for (n = m[i][0], j = 1; n > 0; n--, j += 2) {
            p = m[i];
            if ((aflag & p[j]) == p[j]) {
                j++;
                break;
            }
        }
        buf[i + 1] = p[j];
    }
    buf[10] = '\0';
    return buf;
}

// Work functions

/**
* Routine to read a directory.
*
* @param data	A Work Item that contains
*		information about the directory
*		to read
* @param o	the options structure holding the global
*		options values and other shared variables
*/
void treewalk_readdir(WorkItem *data, options o) {
	DIR *dip;							// a directory pointer
	struct dirent *dit;						// pointer to a directory entry
	PathWork *dirbuf = workitem_get_pathbuffer(data);		// incoming path buffer
	PathWork outstat_buffer;					// A Path Work buffer to add new paths for stating to
	int orig_rank = data->originator;				// the originator of the work item
	PerfStat *perf = perfstat_new();				// a PerfStat structure to keep track of stats.
	WorkItem item_buffer;						// a temporary WorkItem buffer
	PathInfo only_path;						// a temporary PathInfo buffer
	char tmppath[PATHSIZE_PLUS];					// a temporary buffer to hold a path
	int totdirs;							// the total number of directories to read
	int i;

	PRINT_MPI_DEBUG("Worker Rank %d: worker_readdir() Requested from rank %d\n", o.rank, data->originator);
	bzero(&item_buffer,sizeof(WorkItem));				// clear out the statically allocated WorkItem structure used to send request to the manager
	pathwork_clear(&outstat_buffer);				// initialize the outstat buffer
	pathwork_attach(&outstat_buffer,&item_buffer);			// initialize the WorkItem structure used to send request to the manager
	workitem_update_originator(&item_buffer,orig_rank);		// make sure we send any work items back to the manager - or where ever

	if(workitem_hasPathbuffer(data))				// set up the read loop apropriately
	  totdirs = dirbuf->size;
	else {
	  strcpy(only_path.path,data->path);
	  totdirs = 1;
	}

	perfstat_start_time(perf);					// set start time
	for(i=0; i < totdirs; i++) {
		PathInfo pathinfo = (workitem_hasPathbuffer(data))?dirbuf->buf[i]:only_path;// should be a directory

		if ((dip = opendir(pathinfo.path)) == NULL) {
			PWT_UERR_MSG("Worker Rank %d: Failed to open dir %s\n", o.rank, pathinfo.path);
			perfstat_elapsed_dirsread(perf);		// compute elapsed time
			tw_senddone(&item_buffer,perf, o);		// NEED to tell manager we are done! Also clean up any allocated buffers
	   		return;
		}
//printf("Worker Rank %d: Reading directory %s\n",o.rank,pathinfo.path);
		while ((dit = readdir(dip)) != NULL) {
			if (strncmp(dit->d_name, ".", PATHSIZE_PLUS) != 0 && strncmp(dit->d_name, "..", PATHSIZE_PLUS) != 0) {
			   sprintf(tmppath,"%s/%s",pathinfo.path,dit->d_name);
			   pathwork_add_path(&outstat_buffer,tmppath);	// Added another path to stat
//			   workitem_update_path(&item_buffer,tmppath);

			   if(pathwork_isFull(&outstat_buffer))
			    tw_sendpaths(&item_buffer, o);		// item_buffer has a pointer to outstat_buffer. Once sent, outstat_buffer is cleared.
			} // end dot and dot dot condition
		} // dir read loop
		perfstat_inc_dirsread(perf);				// increment the number of directories read

		if (closedir(dip) == -1) {				// close the directory
		  PWT_UERR_MSG("Worker Rank %d: Failed to close dir %s\n", o.rank, pathinfo.path);
		  MPI_Abort(MPI_COMM_WORLD, -1);
       		}
	} // end dirbuf loop
	perfstat_end_time(perf);					// set end time

	if(!pathwork_isEmpty(&outstat_buffer))				// We have some paths to send
	  tw_sendpaths(&item_buffer, o);

	perfstat_elapsed_dirsread(perf);				// compute elapsed time
	tw_senddone(&item_buffer,perf,o);				// let manager know work is done
	perf = perfstat_del(perf);					// throw away perfstat structure
	return;
}

/**
* Routine to stat a path and assign action, based on
* the global command and type.
*
* @param data	A Work Item that contains
*		information about the directory
*		to read
* @param o	the options structure holding the global
*		options values and other shared variables
*/
void treewalk_statpath(WorkItem *data, options o) {
	PathWork *pathbuf = workitem_get_pathbuffer(data);		// incoming path buffer
	AppOptions *twp_o = (AppOptions *)o.app_ops;			// Treewalk options
	PathWork outdir_buffer;						// A Path Work buffer to add new directories to read
	int orig_rank = data->originator;				// the originator of the work item
	PerfStat *perf = perfstat_new();				// a PerfStat structure to keep track of stats.
	struct stat st_buffer;						// a temporary stat buffer
	WorkItem item_buffer;						// a temporary WorkItem buffer
	PathInfo only_path;						// a temporary PathInfo buffer
	int totpaths;							// total paths to stat
	int i;

	PRINT_MPI_DEBUG("Worker Rank %d: treewalk_statpath() Requested from rank %d\n", o.rank, data->originator);
	bzero(&item_buffer,sizeof(WorkItem));				// clear out the statically allocated WorkItem structure used to send request to the manager
	pathwork_clear(&outdir_buffer);					// initialize the outdir buffer
	pathwork_attach(&outdir_buffer,&item_buffer);			// initialize the WorkItem structure used to send request to the manager
	workitem_update_originator(&item_buffer,orig_rank);		// make sure we send any work items back to the manager - or where ever

	if(workitem_hasPathbuffer(data))				// set up the read loop appropriately
	  totpaths = pathbuf->size;
	else {
	  strcpy(only_path.path,data->path);
	  totpaths = 1;
	}

//printf("Worker Rank %d: Number of paths to stat is %d\n",o.rank,totpaths);
	perfstat_start_time(perf);					// set start time
	for(i=0; i < totpaths; i++) {
		PathInfo pathinfo = (workitem_hasPathbuffer(data))?pathbuf->buf[i]:only_path;// should be a path to stat

		if (lstat(pathinfo.path, &st_buffer) == -1) {
		   PWT_UERR_MSG("Worker Rank %d: Failed to stat path entry %s\n", o.rank, pathinfo.path);
        	   MPI_Abort(MPI_COMM_WORLD, -1);
		}

		perfstat_inc_stats(perf);				// increment number stats 
		if (S_ISDIR(st_buffer.st_mode))				// it is a directory - put in the outdir_buffer
		  pathwork_add_path(&outdir_buffer,pathinfo.path);
		else {							// process file, based on given function
		  if(twp_o->processfile) {				// if process file function is assigned -> use that function
		    FileInfo fbuf;

		    fileinfo_init(&fbuf,pathinfo.path,&st_buffer);
		    twp_o->processfile(&fbuf,perf,o);
		  }
		  else if(twp_o->verbose)
		    printf("Worker Rank %d: stat-ed file %s\n", o.rank, pathinfo.path);
		}

		if(pathwork_isFull(&outdir_buffer))			// item_buffer has a pointer to outdir_buffer. Once sent, outdir_buffer is cleared.
		  tw_senddirs(&item_buffer, o);


	} // end path buffer loop
	perfstat_end_time(perf);					// set end time

	if(!pathwork_isEmpty(&outdir_buffer))				// We have some directories to send
	  tw_senddirs(&item_buffer, o);

	perfstat_elapsed_stats(perf);					// compute elapsed time
	tw_senddone(&item_buffer,perf,o);				// let manager know work is done
	perf = perfstat_del(perf);					// throw away perfstat structure
	return;
}
