#ifndef __PWT_H
#define __PWT_H
/* pwt or Proc Worker Type
 * acts like an object that operates
 * using an event loop and handles work
 * based on its type
 */

#include "libpwt.h"
#include "pwt_types.h"


/* General defines used within the pwt framework */
#define PWT_SUCCESS 0
#define PWT_FAILURE -1

#define PWT_STRINGIFY(x) #x
#define PWT_TOSTRING(x)  PWT_STRINGIFY(x)

#define PWT_ERR_AT __FILE__ " ("PWT_TOSTRING(__LINE__)")"
#define PWT_UERR_PREFIX "[PWT ERROR]: "
#define PWT_IERR_PREFIX "[PWT ERROR: "PWT_ERR_AT"]: "

/* user error message */
#define PWT_UERR_MSG(pfargs...)            \
do {                                         \
      fprintf(stderr, PWT_UERR_PREFIX);    \
      fprintf(stderr, pfargs);               \
} while (0)


/* internal error message */
#define PWT_IERR_MSG(pfargs...)           \
do {                                         \
      fprintf(stderr, PWT_IERR_PREFIX);    \
            fprintf(stderr, pfargs);         \
} while (0)

/* enum to define various Process Worker Types */
typedef enum {
  MANAGER_TYPE = 0,
  WORKER_TYPE
} pwt_type;

/* types that define standard functions/routines used by objects of the pwt framework */
typedef int (*pwt_init_fn_t)(options o);
typedef int (*pwt_fini_fn_t)(void);
typedef void (*pwt_run_fn_t)(options o);
typedef int (*pwt_start_fn_t)(options o, PerfStat *ps, Scheduler *s);
typedef void (*pwt_end_fn_t)(options o, PerfStat *ps);

/* Structure to hold application option values and other "shared" variables used by the framework */
struct options{
  int rank;				// process id or index
  int nproc;				// total number of processes
  int nqueues;				// total number of work queues used by the manager
  scheduler_schedule_t schedule_work;	// function to put a WorkItem on a work queue
  scheduler_assign_t assign_work;	// function to allocate a worker process and return the next WorkItem
  pwt_start_fn_t startwork;		// function that can be called to initalize or start the work. Typically used by MANAGER types
  pwt_end_fn_t endwork;			// function that can be called to finalize or report on the work done. Typically used by MANAGER types
  void *app_ops;			// a pointer to a structure that holds application specific options.
};

/* the Process Worker Type structure */
struct pwt {
  pwt_init_fn_t    init;
  pwt_run_fn_t     run;
  pwt_fini_fn_t    fini;
};

/* functions to create and manage process worker types */
pwt *pwt_new(pwt_type t);
int pwt_del(pwt *pwt_instance);


#include "perfstat.h"							// included as convience for application files
#include "workreq.h"							// needed for scheduler logic
#include "converse.h"							// needed for the MPI communication calls
#include "scheduler.h"							// needed because pwt.h does not contain Scheduler definition

#endif
