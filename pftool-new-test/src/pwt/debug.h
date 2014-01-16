
#ifndef      __LIBPWT_DEBUG_H
#define      __LIBPWT_DEBUG_H

// See pwt.c for definitions of debug variables
// See libpwt.h for declarations of debug variables

#define PRINT_MPI_DEBUG(format, args...) { if(pwt_mpi_debug) fprintf(stderr, "MPI_DEBUG: "format, ##args);}
#define PRINT_POLL_DEBUG(format, args...) { if(pwt_poll_debug) fprintf(stderr, "POLL_DEBUG: "format, ##args);}
#define PRINT_SCHED_DEBUG(format, args...) { if(pwt_sched_debug) fprintf(stderr, "SCHED_DEBUG: "format, ##args);}
#define PwtMpiDebug(val) {pwt_mpi_debug = val;}
#define PwtPollDebug(val) {pwt_poll_debug = val;}
#define PwtSchedDebug(val) {pwt_sched_debug = val;}

#endif


